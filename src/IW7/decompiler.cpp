// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "IW7.hpp"

namespace IW7
{

auto decompiler::output() -> std::vector<std::uint8_t>
{
    std::vector<std::uint8_t> output;

    auto data = std::make_unique<utils::byte_buffer>(0x100000);
    data->write_string("// IW7 PC GSC\n// Decompiled by https://github.com/xensik/gsc-tool\n");
    data->write_string(program_->print());

    output.resize(data->pos());
    std::memcpy(output.data(), data->buffer().data(), output.size());

    return output;
}

void decompiler::decompile(const std::string& file, std::vector<gsc::function_ptr>& functions)
{
    filename_ = file;
    program_ = std::make_unique<gsc::node_program>();

    for (auto& func : functions)
    {
        auto name = std::make_unique<gsc::node_name>(func->name.substr(4));
        auto params = std::make_unique<gsc::node_parameters>();
        auto block = std::make_unique<gsc::node_block>();
        func_ = std::make_unique<gsc::node_thread>(std::move(name),std::move(params),std::move(block));

        labels_ = func->labels;
        params_ = 0;
        create_local_vars_.clear();
        stack_local_vars_.clear();
        expr_labels_.clear();
        stack_ = std::stack<gsc::node_ptr>();
        
        this->decompile_function(func);

        program_->definitions.push_back(gsc::define_ptr(std::move(func_)));
    }
}

void decompiler::decompile_function(const gsc::function_ptr& func)
{
    this->decompile_statements(func);

    if(unhandled_function(func->name))
        return;

    auto& block = func_->block;

    gsc::context ctx;
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.back().as_node->loc.begin.line);
    block->stmts.pop_back(); // remove last return

    blocks_.push_back(ctx);
    this->decompile_block(block);
    blocks_.pop_back();
}

void decompiler::decompile_statements(const gsc::function_ptr& func)
{
    for (auto& inst : func->instructions)
    {
        auto loc = gsc::location(&filename_, inst->index);

        const auto itr = func->labels.find(inst->index);

        if (itr != func->labels.end())
        {
            for(auto& loc : expr_labels_)
            {
                if(loc == itr->second)
                {
                    decompile_expr();
                    break;
                }
            }
        }

        switch (opcode(inst->opcode))
        {
        case opcode::OP_End:
        {
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_return>(loc, std::make_unique<gsc::node>()));
            func_->block->stmts.push_back(std::move(stmt));
        }
        break;
        case opcode::OP_Return:
        {
            auto expr = std::move(stack_.top());
            stack_.pop();
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_return>(expr->loc, std::move(expr)));
            func_->block->stmts.push_back(std::move(stmt));
        }
        break;
        case opcode::OP_GetZero:
        {
            auto node = std::make_unique<gsc::node_integer>(loc, "0");
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetByte:		
        case opcode::OP_GetUnsignedShort:
        case opcode::OP_GetInteger:
        {
            auto node = std::make_unique<gsc::node_integer>(loc, inst->data[0]);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetNegByte:
        case opcode::OP_GetNegUnsignedShort:
        {
            auto node = std::make_unique<gsc::node_integer>(loc, "-" + inst->data[0]);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetFloat:
        {
            auto node = std::make_unique<gsc::node_float>(loc, inst->data[0]);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetVector:
        {
            auto x = gsc::expr_ptr(std::make_unique<gsc::node_float>(loc, inst->data[0]));
            auto y = gsc::expr_ptr(std::make_unique<gsc::node_float>(loc, inst->data[1]));
            auto z = gsc::expr_ptr(std::make_unique<gsc::node_float>(loc, inst->data[2]));
            auto node = std::make_unique<gsc::node_vector>(loc, std::move(x), std::move(y), std::move(z));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetString:
        {
            auto node = std::make_unique<gsc::node_string>(loc, inst->data[0]);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetIString:
        {
            auto node = std::make_unique<gsc::node_istring>(loc, inst->data[0]);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetUndefined:
        {
            auto node = std::make_unique<gsc::node_undefined>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EmptyArray:
        {
            auto node = std::make_unique<gsc::node_empty_array>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetLevel:
        case opcode::OP_GetLevelObject:
        {
            auto node = std::make_unique<gsc::node_level>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetAnim:
        case opcode::OP_GetAnimObject:
        {
            auto node = std::make_unique<gsc::node_anim>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetSelf:
        case opcode::OP_GetSelfObject:
        {
            auto node = std::make_unique<gsc::node_self>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetGame:
        case opcode::OP_GetGameRef:
        {
            auto node = std::make_unique<gsc::node_game>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetAnimation:
        {
            auto tree = utils::string::unquote(inst->data[0]);

            if(tree != "")
            {
                auto treename = std::make_unique<gsc::node_string>(loc, inst->data[0]);
                auto animtree = std::make_unique<gsc::node_usingtree>(loc, std::move(treename));
                program_->definitions.push_back(gsc::define_ptr(std::move(animtree)));
            }
            auto node = std::make_unique<gsc::node_animation>(loc, utils::string::unquote(inst->data[1]));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetAnimTree:
        {
            auto tree = utils::string::unquote(inst->data[0]);

            if(tree != "")
            {
                auto treename = std::make_unique<gsc::node_string>(loc, inst->data[0]);
                auto animtree = std::make_unique<gsc::node_usingtree>(loc, std::move(treename));
                program_->definitions.push_back(gsc::define_ptr(std::move(animtree)));
            }
        }
        break;
        case opcode::OP_GetThisthread:
        {
            auto node = std::make_unique<gsc::node_thisthread>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_GetBuiltinFunction:
        case opcode::OP_GetBuiltinMethod:
        {
            auto file = std::make_unique<gsc::node_file>(loc);
            auto func = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_function>(loc, std::move(file), std::move(func));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_GetLocalFunction:
        {
            auto file = std::make_unique<gsc::node_file>(loc);
            auto func = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto stmt = std::make_unique<gsc::node_expr_function>(loc, std::move(file), std::move(func));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_GetFarFunction:
        {
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[0]);
            auto func = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto stmt = std::make_unique<gsc::node_expr_function>(loc, std::move(file), std::move(func));
            stack_.push(std::move(stmt));
        };
        break;
        case opcode::OP_CreateLocalVariable:
        {
            const auto itr = std::find(create_local_vars_.begin(), create_local_vars_.end(), "var" + inst->data[0]);

            if (itr != create_local_vars_.end())
            {
                const auto itr = std::find(stack_local_vars_.begin(), stack_local_vars_.end(), "var" + inst->data[0]);
                if (itr == stack_local_vars_.end())
                {
                    stack_local_vars_.push_back(*itr);
                }
            }
            else
            {
                create_local_vars_.push_back("var" + inst->data[0]);
                stack_local_vars_.push_back("var" + inst->data[0]);
            }

            // for locations
            const auto it = func->labels.find(inst->index);

            if (it != func->labels.end())
            {
                auto stmt = std::make_unique<gsc::node>();
                stmt->loc = loc;
                func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
            }	
        }
        break;
        case opcode::OP_RemoveLocalVariables:
        {
            auto count = std::atoi(inst->data[0].data());
            while(count)
            {
                stack_local_vars_.pop_back();
                count--;
            }

            auto stmt = std::make_unique<gsc::node>();
            stmt->loc = loc;
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_EvalLocalVariableCached0:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached1:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 2));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached2:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 3));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached3:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 4));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached4:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 5));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached5:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 6));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableCached:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0])));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalArrayCached:
        {
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0]))));
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalArray:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalNewLocalArrayRefCached0:
        {
            const auto itr = std::find(create_local_vars_.begin(), create_local_vars_.end(), "var" + inst->data[0]);
            
            if (itr != create_local_vars_.end())
            {
                stack_local_vars_.push_back(*itr);
            }
            else
            {
                create_local_vars_.push_back("var" + inst->data[0]);
                stack_local_vars_.push_back("var" + inst->data[0]);
            }

            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1)));
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalArrayRefCached0:
        {
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1)));
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));	
        }
        break;
        case opcode::OP_EvalLocalArrayRefCached:
        {
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0]))));
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalArrayRef:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto node = std::make_unique<gsc::node_expr_array>(key.as_node->loc, std::move(obj), std::move(key));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_ClearArray:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto key = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = key.as_node->loc;
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_expr_array>(loc, std::move(obj), std::move(key)));
            auto rvalue = gsc::expr_ptr(std::make_unique<gsc::node_undefined>(loc));
            auto expr = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_assign>(loc, std::move(expr)));
            func_->block->stmts.push_back(std::move(stmt));
        }
        break;
        case opcode::OP_AddArray:
        {
            auto var = std::move(stack_.top());
            stack_.pop();
            auto array = std::move(stack_.top());
            stack_.pop();
            
            if (array->type == gsc::node_t::data_empty_array)
            {
                auto args = std::make_unique<gsc::node_expr_arguments>(loc);
                args->list.push_back(std::move(var));
                auto expr = std::make_unique<gsc::node_expr_add_array>(array->loc, std::move(args));
                stack_.push(std::move(expr));
            }
            else if (array->type == gsc::node_t::expr_add_array)
            {
                (*(gsc::expr_add_array_ptr*)&array)->args->list.push_back(std::move(var));
                stack_.push(std::move(array));
            }
            else
            {
                throw gsc::decomp_error("unknown add array type (could be an array variable name?)");
            }
        }
        break;
        case opcode::OP_PreScriptCall:
        {
            auto node = std::make_unique<gsc::node_asm_prescriptcall>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_ScriptLocalFunctionCall2:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalFunctionCall:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalMethodCall:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalThreadCall:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[1]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalChildThreadCall:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[1]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, true, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalMethodThreadCall:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[1]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptLocalMethodChildThreadCall:
        {
            // TODO: child things...
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0].substr(4));
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[1]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, true, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFarFunctionCall2:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[0]);
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFarFunctionCall:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[0]);

            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFarMethodCall:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[0]);

            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFarThreadCall:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[2]);
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[1]);

            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFarMethodThreadCall:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[2]);
            auto file = std::make_unique<gsc::node_file>(loc, inst->data[1]);

            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptFunctionCallPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = exprf.as_node->loc;
            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptMethodCallPointer:
        {		
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_prescriptcall)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptThreadCallPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = exprf.as_node->loc;
            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptChildThreadCallPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = exprf.as_node->loc;
            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, true, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptMethodThreadCallPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, true, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_ScriptMethodChildThreadCallPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, false, std::move(exprf), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, true, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = exprf.as_node->loc;

            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, true, std::move(exprf), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethodPointer:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto exprf = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_pointer>(loc, true, std::move(exprf), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin0:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin1:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 1; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }
            
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin2:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 2; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }
            
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin3:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 3; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }
            
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin4:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 4; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }
            
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin5:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 5; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }
            
            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltin:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node>());
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod0:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod1:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 1; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod2:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 2; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod3:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 3; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod4:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 4; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod5:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto file = std::make_unique<gsc::node_file>(loc);

            for (size_t i = 5; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_CallBuiltinMethod:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto name = std::make_unique<gsc::node_name>(loc, inst->data[1]);
            auto file = std::make_unique<gsc::node_file>(loc);

            auto argnum = std::stoul(inst->data[0]);

            for (size_t i = argnum; i > 0; i--)
            {
                auto var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
                args->list.push_back(std::move(var));
            }

            auto func = gsc::expr_call_type_ptr(std::make_unique<gsc::node_expr_call_function>(loc, std::move(file), std::move(name), std::move(args)));
            auto expr = std::make_unique<gsc::node_expr_call>(loc, false, false, std::move(obj) ,std::move(func));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_DecTop:
        {
            auto expr = std::move(stack_.top());
            stack_.pop();
            loc = expr->loc;
            auto stmt = std::make_unique<gsc::node_stmt_call>(loc, std::move(*(gsc::expr_call_ptr*)&expr));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_inc:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_increment>(loc, std::move(lvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_dec:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_decrement>(loc, std::move(lvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_bit_or:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_bitwise_or>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_bit_ex_or:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_bitwise_exor>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_bit_and:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_bitwise_and>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_equality:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_equality>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_inequality:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_inequality>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_less:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_less>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_greater:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_greater>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_less_equal:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_less_equal>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_greater_equal:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_greater_equal>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_shift_left:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_shift_left>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_shift_right:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_shift_right>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_plus:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_add>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_minus:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_sub>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_multiply:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_mult>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_divide:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_div>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_mod:
        {
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_mod>(loc, std::move(lvalue), std::move(rvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_wait:
        {
            auto expr = std::move(stack_.top());
            stack_.pop();
            loc = expr->loc;
            auto stmt = std::make_unique<gsc::node_stmt_wait>(loc, std::move(expr));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_waittillFrameEnd:
        {
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_waittillframeend>(loc));
            func_->block->stmts.push_back(std::move(stmt));
        }
        break;
        case opcode::OP_waittill:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto nstr = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = nstr.as_node->loc;
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto stmt = std::make_unique<gsc::node_stmt_waittill>(loc, std::move(obj) , std::move(nstr), std::move(args));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_waittillmatch:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto expr = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = expr.as_node->loc;

            gsc::expr_arguments_ptr args = std::make_unique<gsc::node_expr_arguments>();
            args->loc = loc;

            while(stack_.size() > 0)
            {
                auto node = std::move(stack_.top());
                stack_.pop();
                args->loc = node->loc;
                args->list.push_back(std::move(node));
                
            }
            loc = args->loc;

            auto stmt = std::make_unique<gsc::node_stmt_waittillmatch>(loc, std::move(obj), std::move(expr), std::move(args));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_clearparams:
        {
            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            auto var = std::move(stack_.top());
            stack_.pop();

            while(var->type != gsc::node_t::stmt_waittill && var->type != gsc::node_t::stmt_waittillmatch)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
            }

            if(var->type == gsc::node_t::stmt_waittill)
            {
                (*(gsc::stmt_waittill_ptr*)&var)->args = std::move(args);
            }

            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(var)));
        }
        break;
        case opcode::OP_checkclearparams:
        {
            // no needed
        }
        break;
        case opcode::OP_notify:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto nstr = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();

            auto args = std::make_unique<gsc::node_expr_arguments>(loc);
            
            auto var = std::move(stack_.top());
            stack_.pop();
            loc = var->loc;
            while(var->type != gsc::node_t::asm_voidcodepos)
            {
                args->list.push_back(std::move(var));
                var = std::move(stack_.top());
                stack_.pop();
                loc = var->loc;
            }

            auto stmt = std::make_unique<gsc::node_stmt_notify>(loc, std::move(obj) , std::move(nstr), std::move(args));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_endon:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto nstr = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = nstr.as_node->loc;
            auto stmt = std::make_unique<gsc::node_stmt_endon>(loc, std::move(obj) , std::move(nstr));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_voidCodepos:
        {
            auto node = std::make_unique<gsc::node_asm_voidcodepos>(loc);
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_vector:
        {
            auto x = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto y = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            auto z = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = z.as_node->loc;
            auto expr = std::make_unique<gsc::node_vector>(loc, std::move(x), std::move(y),  std::move(z));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_size:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_size>(loc, std::move(lvalue));
            stack_.push(std::move(expr));
        }
        break;		
        case opcode::OP_EvalLevelFieldVariable:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_level>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalAnimFieldVariable:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_anim>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalSelfFieldVariable:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_self>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalFieldVariable:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalLevelFieldVariableRef:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_level>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalAnimFieldVariableRef:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_anim>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalSelfFieldVariableRef:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_self>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_EvalFieldVariableRef:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto stmt = std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field));
            stack_.push(std::move(stmt));
        }
        break;
        case opcode::OP_ClearFieldVariable:
        {
            auto obj = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = obj.as_node->loc;
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto expr = gsc::expr_ptr(std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field)));
            auto undef = gsc::expr_ptr(std::make_unique<gsc::node_undefined>(loc));
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(expr), std::move(undef));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::make_unique<gsc::node_stmt_assign>(loc, std::move(e))));
        }
        break;
        case opcode::OP_SafeCreateVariableFieldCached:
        {
            create_local_vars_.push_back("var" + inst->data[0]);
            stack_local_vars_.push_back("var" + inst->data[0]);
            func_->params->list.push_back(std::make_unique<gsc::node_name>(loc, stack_local_vars_.back()));
        }
        break;
        case opcode::OP_SafeSetWaittillVariableFieldCached:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0])));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableRefCached0:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.back());
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_EvalLocalVariableRefCached:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0])));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_SetLevelFieldVariableField:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_level>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field)));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc,std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_SetVariableField:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;

            if(lvalue.as_node->type == gsc::node_t::expr_increment)
            {
                auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(lvalue.as_increment));
                func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
            }
            else if(lvalue.as_node->type == gsc::node_t::expr_decrement)
            {
                auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(lvalue.as_decrement));
                func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
            }
            else
            {
                auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
                stack_.pop();
                loc = rvalue.as_node->loc;
                auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
                auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
                func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
            }
        }
        break;
        case opcode::OP_SetAnimFieldVariableField:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_anim>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field)));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_SetSelfFieldVariableField:
        {
            auto obj = gsc::expr_ptr(std::make_unique<gsc::node_self>(loc));
            auto field = std::make_unique<gsc::node_name>(loc, inst->data[0]);
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_expr_field>(loc, std::move(obj), std::move(field)));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_SetLocalVariableFieldCached0:
        {
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.back()));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_SetNewLocalVariableFieldCached0:
        {
            const auto itr = std::find(create_local_vars_.begin(), create_local_vars_.end(), "var" + inst->data[0]);
            
            if (itr != create_local_vars_.end())
            {
                stack_local_vars_.push_back(*itr);
            }
            else
            {
                create_local_vars_.push_back("var" + inst->data[0]);
                stack_local_vars_.push_back("var" + inst->data[0]);
            }

            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.back()));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_SetLocalVariableFieldCached:
        {
            auto lvalue = gsc::expr_ptr(std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0]))));
            auto rvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = rvalue.as_node->loc;
            auto e = std::make_unique<gsc::node_expr_assign_equal>(loc, std::move(lvalue), std::move(rvalue));
            auto stmt = std::make_unique<gsc::node_stmt_assign>(loc, std::move(e));
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_ClearLocalVariableFieldCached:
        {
            // TODO: used in for, foreach
            // make a null node to save locations
            auto stmt = std::make_unique<gsc::node>();
            stmt->loc = loc;
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_ClearLocalVariableFieldCached0:
        {
            // TODO: used in for, foreach
            // make a null node to save locations
            auto stmt = std::make_unique<gsc::node>();
            stmt->loc = loc;
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(stmt)));
        }
        break;
        case opcode::OP_EvalLocalVariableObjectCached:
        {
            auto node = std::make_unique<gsc::node_name>(loc, stack_local_vars_.at(stack_local_vars_.size() - 1 - std::stoul(inst->data[0])));
            stack_.push(std::move(node));
        }
        break;
        case opcode::OP_CastFieldObject:
        {
            //continue;
        }
        break;
        case  opcode::OP_CastBool:
        {
            //continue;
        }
        break;
        case opcode::OP_BoolNot:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_not>(loc, std::move(lvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_BoolComplement:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_expr_complement>(loc, std::move(lvalue));
            stack_.push(std::move(expr));
        }
        break;
        case opcode::OP_switch:
        {
            auto expr = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = expr.as_node->loc;
            auto sw = std::make_unique<gsc::node_asm_switch>(loc, std::move(expr), inst->data[0]);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(sw)));
        }
        break;
        case opcode::OP_endswitch:
        {
            auto count = inst->data[0];
            inst->data.erase(inst->data.begin());
            auto data = inst->data;
            auto end = std::make_unique<gsc::node_asm_endswitch>(loc, data, count);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(end)));
        }
        break;
        case opcode::OP_jump:
        {
            auto expr = std::make_unique<gsc::node_asm_jump>(loc, inst->data[0]);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(expr)));

        }
        break;
        case opcode::OP_jumpback:
        {
            auto expr = std::make_unique<gsc::node_asm_jump_back>(loc, inst->data[0]);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(expr)));
        }
        break;
        case opcode::OP_JumpOnTrue:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto e_not = gsc::expr_ptr(std::make_unique<gsc::node_expr_not>(loc, std::move(lvalue)));
            auto expr = std::make_unique<gsc::node_asm_jump_cond>(loc, std::move(e_not), inst->data[0]);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(expr)));
        }
        break;
        case opcode::OP_JumpOnFalse:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_asm_jump_cond>(loc, std::move(lvalue), inst->data[0]);
            func_->block->stmts.push_back(gsc::stmt_ptr(std::move(expr)));
        }
        break;
        case opcode::OP_JumpOnTrueExpr:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_asm_jump_true_expr>(loc, std::move(lvalue), inst->data[0]);
            stack_.push(std::move(expr));
            expr_labels_.push_back(inst->data[0]);
        }
        break;
        case opcode::OP_JumpOnFalseExpr:
        {
            auto lvalue = gsc::expr_ptr(std::move(stack_.top()));
            stack_.pop();
            loc = lvalue.as_node->loc;
            auto expr = std::make_unique<gsc::node_asm_jump_false_expr>(loc, std::move(lvalue), inst->data[0]);
            stack_.push(std::move(expr));
            expr_labels_.push_back(inst->data[0]);
        }
        break;
        default:
            throw gsc::decomp_error("unhandled opcode " + resolver::opcode_name(inst->opcode));
        break;
        }
    }
}

void decompiler::decompile_expr()
{
    auto expr = std::move(stack_.top());
    stack_.pop();

    auto jump_expr = std::move(stack_.top());
    stack_.pop();
    auto loc = jump_expr->loc;
    
    if(jump_expr->type == gsc::node_t::asm_jump_true_expr)
    {
        auto lvalue = std::move((*(gsc::asm_jump_true_expr_ptr*)&jump_expr)->expr);
        auto rvalue = gsc::expr_ptr(std::move(expr));
        auto e = std::make_unique<gsc::node_expr_or>(loc, std::move(lvalue), std::move(rvalue));
        stack_.push(std::move(e));
    }
    else if(jump_expr->type == gsc::node_t::asm_jump_false_expr)
    {
        auto lvalue = std::move((*(gsc::asm_jump_false_expr_ptr*)&jump_expr)->expr);
        auto rvalue = gsc::expr_ptr(std::move(expr));
        auto e = std::make_unique<gsc::node_expr_and>(loc, std::move(lvalue), std::move(rvalue));
        stack_.push(std::move(e));
    }
    else
    {
        throw gsc::decomp_error("TRIED TO DECOMPILE INVALID JUMP EXPR!");
    }
}

void decompiler::decompile_block(const gsc::block_ptr& block)
{
    this->decompile_search_infinite(block);
    this->decompile_search_loop(block);
    this->decompile_search_switch(block);
    this->decompile_search_ifelse(block);
    this->decompile_break_continue(block);
    this->decompile_nulls(block);
}

void decompiler::decompile_nulls(const gsc::block_ptr& block)
{
    auto index = 0;
    while(index < block->stmts.size())
    {
        if(block->stmts.at(index).as_node->type == gsc::node_t::null)
        {
            block->stmts.erase(block->stmts.begin() + index);
        }
        else index++;
    }
}

void decompiler::decompile_search_infinite(const gsc::block_ptr& block)
{
    std::int32_t index = block->stmts.size() - 1;

    while(index >= 0)
    {
        if(block->stmts.at(index).as_node->type == gsc::node_t::asm_jump_back)
        {
            auto break_loc = last_location_index(block, index) ?  blocks_.back().loc_end : utils::string::va("loc_%X", block->stmts.at(index+1).as_node->loc.begin.line);
            auto begin_loc = block->stmts.at(index).as_jump_back->value;
            auto start = find_location_index(block, begin_loc);

            if(block->stmts.at(start).as_node->type != gsc::node_t::asm_jump_cond)
            {
                decompile_infinite(block, start, index);
                index = start;
            }
            else if (block->stmts.at(start).as_cond->value != break_loc)
            {
                decompile_infinite(block, start, index);
                index = start;
            }
        }
        
        index--;
    }
}

void decompiler::decompile_search_loop(const gsc::block_ptr& block)
{
    auto index = 0;

    while(index < block->stmts.size())
    {
        auto& stmt = block->stmts.at(index);

        if(stmt.as_node->type == gsc::node_t::asm_jump_cond)
        {
            std::uint32_t end;
            if(stmt.as_cond->value == blocks_.back().loc_end)
            {
                end = block->stmts.size() - 1;
            }
            else
            {
                end = find_location_index(block, stmt.as_cond->value) - 1;
            }
            
            if(block->stmts.at(end).as_node->type == gsc::node_t::asm_jump_back
                && utils::string::va("loc_%X", block->stmts.at(index).as_node->loc.begin.line) == block->stmts.at(end).as_jump_back->value)
            {
                decompile_loop(block, index, end);
                index = 0;
            }
        }
        index++;
    }
}

void decompiler::decompile_search_switch(const gsc::block_ptr& block)
{
    auto index = 0;

    while(index < block->stmts.size())
    {
        if(block->stmts.at(index).as_node->type == gsc::node_t::asm_switch)
        {
            decompile_switch(block, index);
        }

        index++;
    }
}

void decompiler::decompile_search_ifelse(const gsc::block_ptr& block)
{
    auto index = 0;

    while(index < block->stmts.size())
    {
        auto& stmt = block->stmts.at(index);

        if(stmt.as_node->type == gsc::node_t::asm_jump_cond)
        {
            std::uint32_t end;
            if(stmt.as_cond->value == blocks_.back().loc_end)
            {
                end = block->stmts.size() - 1;
            }
            else
            {
                end = find_location_index(block, stmt.as_cond->value) - 1;
            }
            
            auto last_loc = blocks_.back().loc_end;

            if(block->stmts.at(end).as_node->type == gsc::node_t::asm_jump)
            {
                // if block is a loop check break, continue
                if(block->stmts.at(end).as_jump->value == blocks_.back().loc_continue)
                {
                    // last if/else inside a loop still trigger this :(
                    decompile_if(block, index, end);
                }
                else if(block->stmts.at(end).as_jump->value == blocks_.back().loc_break)
                {
                    decompile_if(block, index, end);
                }
                else if(block->stmts.at(end).as_jump->value == blocks_.back().loc_end)
                {
                    decompile_ifelse(block, index, end);
                }
                else if(block->stmts.at(end).as_jump->value == stmt.as_cond->value)
                {
                    decompile_if(block, index, end); // if block, have a last empty else inside
                }
                else
                {
                    decompile_ifelse(block, index, end);
                }
            }
            else if(block->stmts.at(end).as_node->type == gsc::node_t::stmt_return
                && block->stmts.at(end).as_return->expr.as_node->type == gsc::node_t::null)
            {
                if(blocks_.back().loc_break != "" || blocks_.back().loc_continue != "")
                {
                    decompile_if(block, index, end); // inside a loop cant be last
                }
                else if(end - index  == 1)
                {
                    decompile_if(block, index, end); // only one explicit return
                }
                else if(block->stmts.back().as_node->type != gsc::node_t::stmt_return)
                {
                    decompile_if(block, index, end); // block end is not a last return
                }
                else if(blocks_.back().is_last && block->stmts.back().as_node->type != gsc::node_t::stmt_return)
                {
                    decompile_if(block, index, end); // inside a last block but is not and inner last
                }
                else if(find_location_reference(block, end, block->stmts.size(), last_loc))
                {
                    decompile_if(block, index, end); // reference to func end after the if
                }
                else
                {
                    decompile_last_ifelse(block, index, end); // special case
                }
            }
            else
            {
                decompile_if(block, index, end);
            }
        }
        index++;
    }
}

void decompiler::decompile_break_continue(const gsc::block_ptr& block)
{
    auto index = 0;

    while(index < block->stmts.size())
    {
        if(block->stmts.at(index).as_node->type == gsc::node_t::asm_jump)
        {
            auto loc = block->stmts.at(index).as_node->loc;
            auto jump_loc = block->stmts.at(index).as_jump->value;
    
            if(jump_loc == blocks_.back().loc_continue)
            {
                block->stmts.erase(block->stmts.begin() + index);
                auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_continue>(loc));
                block->stmts.insert(block->stmts.begin() + index, std::move(stmt));
            }
            else if(jump_loc == blocks_.back().loc_break)
            {
                block->stmts.erase(block->stmts.begin() + index);
                auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_break>(loc));
                block->stmts.insert(block->stmts.begin() + index, std::move(stmt));
            }
        }

        index++;
    }
}

void decompiler::decompile_if(const gsc::block_ptr& block, std::uint32_t begin, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_end = block->stmts.at(begin).as_cond->value;
    ctx.loc_break = blocks_.back().loc_break;
    ctx.loc_continue = blocks_.back().loc_continue;

    auto loc = block->stmts.at(begin).as_node->loc;
    auto expr = std::move(block->stmts.at(begin).as_cond->expr);

    block->stmts.erase(block->stmts.begin() + begin); // remove condition

    auto if_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = begin; i < end; i++)
    {
        if_block->stmts.push_back(std::move(block->stmts[begin]));
        block->stmts.erase(block->stmts.begin() + begin);
    }

    blocks_.push_back(ctx);
    decompile_block(if_block);
    blocks_.pop_back();

    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_if>(loc, std::move(expr), std::move(if_block)));
    block->stmts.insert(block->stmts.begin() + begin, std::move(stmt));
}

void decompiler::decompile_ifelse(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.at(end).as_node->loc.begin.line);
    ctx.loc_break = blocks_.back().loc_break;
    ctx.loc_continue = blocks_.back().loc_continue;

    auto loc = block->stmts.at(start).as_node->loc;
    auto expr = std::move(block->stmts.at(start).as_cond->expr);

    block->stmts.erase(block->stmts.begin() + start); // remove condition
    end = end - 1;

    auto if_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++) // skip the jump
    {
        if_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx);
    decompile_block(if_block);
    blocks_.pop_back();

    auto end_loc = block->stmts.at(start).as_jump->value;

    block->stmts.erase(block->stmts.begin() + start); // remove jump

    std::uint32_t end_index;

    if(end_loc == blocks_.back().loc_end)
    {
        end_index = block->stmts.size();
    }
    else
    {
        end_index = find_location_index(block, end_loc);
    }

    gsc::context ctx2;
    ctx2.loc_end = end_loc;
    ctx2.loc_break = blocks_.back().loc_break;
    ctx2.loc_continue = blocks_.back().loc_continue;

    auto else_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end_index; i++)
    {
        else_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx2);
    decompile_block(else_block);
    blocks_.pop_back();

    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_ifelse>(loc, std::move(expr), std::move(if_block), std::move(else_block)));
    block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
}

void decompiler::decompile_last_ifelse(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    gsc::context ctx;
    ctx.is_last = true;

    auto inner_end = find_location_index(block, block->stmts.at(start).as_cond->value) - 1;
    ctx.loc_end = utils::string::va("loc_%X",block->stmts.at(inner_end).as_node->loc.begin.line);
    auto loc = block->stmts.at(start).as_node->loc;
    auto expr = std::move(block->stmts.at(start).as_cond->expr);

    block->stmts.erase(block->stmts.begin() + start); // remove condition
    end = end - 1;

    auto if_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++)
    {
        if_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    block->stmts.erase(block->stmts.begin() + start); // remove if block return;

    blocks_.push_back(ctx);
    decompile_block(if_block);
    blocks_.pop_back();

    if(start == block->stmts.size())
    {
        auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_if>(loc, std::move(expr), std::move(if_block)));
        block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
    }
    else
    {
        gsc::context ctx2;
        ctx2.is_last = true;

        auto else_block = std::make_unique<gsc::node_block>(loc);

        end = block->stmts.size();
        ctx2.loc_end = utils::string::va("loc_%X", block->stmts.at(end - 1).as_node->loc.begin.line); // return is the block end

        for(auto i = start; i < end; i++)
        {
            else_block->stmts.push_back(std::move(block->stmts[start]));
            block->stmts.erase(block->stmts.begin() + start);
        }

        else_block->stmts.pop_back(); // remove else return;

        blocks_.push_back(ctx2);
        decompile_block(else_block);
        blocks_.pop_back();

        auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_ifelse>(loc, std::move(expr), std::move(if_block), std::move(else_block)));
        block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
    }
}

void decompiler::decompile_infinite(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_break = last_location_index(block, end) ? blocks_.back().loc_end : utils::string::va("loc_%X", block->stmts.at(end+1).as_node->loc.begin.line);
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.at(end).as_node->loc.begin.line);
    ctx.loc_continue = utils::string::va("loc_%X", block->stmts.at(end).as_node->loc.begin.line);

    auto loc = block->stmts.at(start).as_node->loc;

    block->stmts.erase(block->stmts.begin() + end); // remove jump back

    auto for_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++)
    {
        for_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx);
    decompile_block(for_block);
    blocks_.pop_back();

    auto expr = gsc::expr_ptr(std::make_unique<gsc::node>());
    auto pre_expr = gsc::expr_ptr(std::make_unique<gsc::node>());
    auto post_expr = gsc::expr_ptr(std::make_unique<gsc::node>());
    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_for>(loc, std::move(pre_expr), std::move(expr), std::move(post_expr), std::move(for_block)));
    block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
}

void decompiler::decompile_loop(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    auto& last_stmt = block->stmts.at(end-1);
    if(last_stmt.as_node->type == gsc::node_t::stmt_assign)
    {
        if(last_stmt.as_assign->expr->type == gsc::node_t::expr_assign_equal)
        {
            auto& rval = last_stmt.as_assign->expr->rvalue;
            if(rval.as_node->type == gsc::node_t::expr_call)
            {
                if(rval.as_call->func.as_node->type == gsc::node_t::expr_call_function)
                {
                    if(utils::string::to_lower(rval.as_call->func.as_func->name->value) == "getnextarraykey")
                    {
                        auto ref2 = utils::string::va("loc_%X", block->stmts.at(start).as_node->loc.begin.line);
                        if(find_location_reference(block, 0, start, ref2))
                        {
                            // begin is at condition, not pre-expr
                            //decompile_while(block, start, end);
                            //return;
                        }
                        else
                        {
                            decompile_foreach(block, start, end);
                            return;
                        }
                    }
                }
            }
        }

        if(start > 0) // while at func start
        {
            auto& first_stmt = block->stmts.at(start - 1);
            if(first_stmt.as_node->type == gsc::node_t::stmt_assign)
            {
                auto ref = utils::string::va("loc_%X", block->stmts.at(end).as_node->loc.begin.line);
                auto ref2 = utils::string::va("loc_%X", block->stmts.at(start).as_node->loc.begin.line);

                if(find_location_reference(block, start, end, ref))
                {
                    // continue is at jumpback, not post-expr
                    decompile_while(block, start, end);
                    return;
                }
                else if(find_location_reference(block, 0, start, ref2))
                {
                    // begin is at condition, not pre-expr
                    decompile_while(block, start, end);
                    return;
                }
                else
                {
                    decompile_for(block, start, end);
                    return;
                }	
            }
        }
    }
    
    decompile_while(block, start, end);
}

void decompiler::decompile_while(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_break = block->stmts.at(start).as_cond->value;
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.at(end).as_node->loc.begin.line);
    ctx.loc_continue = utils::string::va("loc_%X",block->stmts.at(end).as_node->loc.begin.line);

    auto loc = block->stmts.at(start).as_node->loc;
    auto expr = std::move(block->stmts.at(start).as_cond->expr);

    block->stmts.erase(block->stmts.begin() + end); // remove jump back
    block->stmts.erase(block->stmts.begin() + start); // remove condition
    end = end - 1;

    auto while_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++)
    {
        while_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx);
    decompile_block(while_block);
    blocks_.pop_back();

    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_while>(loc, std::move(expr), std::move(while_block)));
    block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
}

void decompiler::decompile_for(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_break = block->stmts.at(start).as_cond->value;
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.at(end - 1).as_node->loc.begin.line);
    ctx.loc_continue = utils::string::va("loc_%X", block->stmts.at(end - 1).as_node->loc.begin.line);

    auto loc = block->stmts.at(start - 1).as_node->loc;
    auto expr = std::move(block->stmts.at(start).as_cond->expr);
    auto pre_expr = gsc::expr_ptr(std::move(block->stmts.at(start - 1).as_assign->expr));
    auto post_expr = gsc::expr_ptr(std::move(block->stmts.at(end - 1).as_assign->expr));

    start = start - 1;
    end = end - 2;
    for(auto i = start; i < start + 2; i++) // remove prologue (pre-expr, condition)
    {
        block->stmts.erase(block->stmts.begin() + start);
    }

    end = end - 1; // set end in post-expr
    for(auto i = end; i < end + 2; i++) // remove epilogue (post-expr, jump back)
    {
        block->stmts.erase(block->stmts.begin() + end);
    }

    auto for_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++)
    {
        for_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx);
    decompile_block(for_block);
    blocks_.pop_back();

    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_for>(loc, std::move(pre_expr), std::move(expr), std::move(post_expr), std::move(for_block)));
    block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
}

void decompiler::decompile_foreach(const gsc::block_ptr& block, std::uint32_t begin, std::uint32_t end)
{
    gsc::context ctx;
    ctx.loc_break = block->stmts.at(begin).as_cond->value;
    ctx.loc_end = utils::string::va("loc_%X", block->stmts.at(end - 1).as_node->loc.begin.line);
    ctx.loc_continue = utils::string::va("loc_%X", block->stmts.at(end - 1).as_node->loc.begin.line);

    auto loc = block->stmts.at(begin - 2).as_node->loc;
    auto array = std::move(block->stmts[begin-2].as_assign->expr->rvalue);
    auto element = std::move(block->stmts[begin+1].as_assign->expr->lvalue.as_name);

    begin = begin - 2;
    end = end - 4;
    for(auto i = begin; i < begin + 4; i++) // remove prologue ( array, elem, cond, elemRef)
    {
        block->stmts.erase(block->stmts.begin() + begin);
    }

    end = end - 1; // set end to post-expr

    for(auto i = end; i < end + 2; i++) // remove epilogue ( post-expr, jump back)
    {
        block->stmts.erase(block->stmts.begin() + end);
    }

    auto foreach_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = begin; i < end; i++)
    {
        foreach_block->stmts.push_back(std::move(block->stmts[begin]));
        block->stmts.erase(block->stmts.begin() + begin);
    }

    blocks_.push_back(ctx);
    decompile_block(foreach_block);
    blocks_.pop_back();

    auto foreach_stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_foreach>(loc, std::move(element), std::move(array), std::move(foreach_block)));
    block->stmts.insert(block->stmts.begin() + begin, std::move(foreach_stmt));
}

void decompiler::decompile_switch(const gsc::block_ptr& block, std::uint32_t start)
{
    gsc::context ctx;
    ctx.loc_continue = blocks_.back().loc_continue;

    auto loc = block->stmts.at(start).as_node->loc;
    auto expr = std::move(block->stmts.at(start).as_asm_switch->expr);
    auto end_loc = block->stmts.at(start).as_asm_switch->value;
    auto end = find_location_index(block, end_loc);

    if(end == block->stmts.size() - 1)
    {
        ctx.loc_break = blocks_.back().loc_end;
    }
    else
    {
        ctx.loc_break = utils::string::va("loc_%X", block->stmts.at(end + 1).as_node->loc.begin.line);
    }

    // collect cases
    auto casenum = std::atol(block->stmts.at(end).as_asm_endswitch->count.data());
    auto data = block->stmts.at(end).as_asm_endswitch->data;
    auto idx = 0;

    for(auto i = 0; i < casenum; i++)
    {
        if(data.at(idx) == "case")
        {
            auto loc_str = data.at(idx+2);
            auto loc_idx = find_location_index(block, loc_str);
            auto value = gsc::expr_ptr(std::make_unique<gsc::node_string>(loc, data.at(idx+1)));
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_case>(loc, std::move(value)));
            block->stmts.insert(block->stmts.begin() + loc_idx, std::move(stmt));
            idx += 3;
        }
        else if(data.at(idx) == "default")
        {
            auto loc_str = data.at(idx+1);
            auto loc_idx = find_location_index(block, loc_str);
            auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_default>(loc));
            block->stmts.insert(block->stmts.begin() + loc_idx, std::move(stmt));
            idx += 2;
        }
    }

    end = find_location_index(block, end_loc) - 1; // update end;
    block->stmts.erase(block->stmts.begin() + start); // remove switch
    block->stmts.erase(block->stmts.begin() + end); // remove endswitch

    //decompile block
    auto sw_block = std::make_unique<gsc::node_block>(loc);

    for(auto i = start; i < end; i++)
    {
        sw_block->stmts.push_back(std::move(block->stmts[start]));
        block->stmts.erase(block->stmts.begin() + start);
    }

    blocks_.push_back(ctx);
    decompile_block(sw_block);
    blocks_.pop_back();

    auto stmt = gsc::stmt_ptr(std::make_unique<gsc::node_stmt_switch>(loc, std::move(expr), std::move(sw_block)));
    block->stmts.insert(block->stmts.begin() + start, std::move(stmt));
}

auto decompiler::find_location_reference(const gsc::block_ptr& block, std::uint32_t start, std::uint32_t end, const std::string& location) -> bool
{
    for(auto i = start; i < end; i++)
    {
        if(block->stmts.at(i).as_node->type == gsc::node_t::asm_jump_cond)
        {
            if(block->stmts.at(i).as_cond->value == location)
                return true;
        }
        else if(block->stmts.at(i).as_node->type == gsc::node_t::asm_jump)
        {
            if(block->stmts.at(i).as_jump->value == location)
                return true;
        }
    }

    return false;
}

auto decompiler::find_location_index(const gsc::block_ptr& block, const std::string& location) -> std::uint32_t
{
    auto index = 0;

    if(location == blocks_.back().loc_end)
        return block->stmts.size();

    for(auto& stmt : block->stmts)
    {
        if(stmt.as_node->loc.begin.line == std::stol(location.substr(4), 0, 16))
            return index;

        index++;
    }

    throw gsc::decomp_error("LOCATION NOT FOUND! (" + location + ")");
    return 0;
}

auto decompiler::last_location_index(const gsc::block_ptr& block, std::uint32_t index) -> bool
{
    if(index == block->stmts.size() - 1)
        return true;
    
    return false;
}

// testing stuff
std::vector<std::string> unhandled =
{
};

auto decompiler::unhandled_function(const std::string& function) -> bool
{
    if (std::find(std::begin(unhandled), std::end(unhandled), function) != std::end(unhandled))
        return true;

    return false;
}

} // namespace IW7
