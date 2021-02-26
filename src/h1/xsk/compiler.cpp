// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "parser.hpp"
#include "lexer.hpp"

namespace xsk::gsc::h1
{

auto compiler::output() -> std::vector<gsc::function_ptr>
{
    return std::move(assembly_);
}

void compiler::compile(const std::string& file, std::vector<std::uint8_t>& data)
{
    filename_ = file;

    auto result = parse_buffer(filename_, data);

    compile_program(result);
}

void compiler::set_readf_callback(std::function<std::vector<std::uint8_t>(const std::string&)> func)
{
    callback_readf_ = func;
}

auto compiler::parse_buffer(const std::string& file, std::vector<std::uint8_t>& data) -> gsc::program_ptr
{
    yyscan_t scanner;
    gsc::location loc;
    gsc::program_ptr result(nullptr);
    
    loc.initialize(&file);
    // Add the two NULL terminators, required by flex.
    data.push_back(0);
    data.push_back(0);

    if (h1_lex_init(&scanner))
        exit(1);

    YY_BUFFER_STATE yybuffer = h1__scan_buffer(reinterpret_cast<char*>(data.data()), data.size(), scanner);

    parser parser(scanner, loc, result);
    
    if(parser.parse() || result == nullptr)
    {
        throw gsc::comp_error(loc, "An unknown error ocurred while parsing gsc file.");
    }

    h1__delete_buffer(yybuffer, scanner);
    h1_lex_destroy(scanner);

    return result;
}

auto compiler::parse_file(const std::string& file) -> gsc::program_ptr
{
    auto buffer = callback_readf_(file);
    auto result = parse_buffer(file, buffer);

    return result;
}

void compiler::compile_program(const gsc::program_ptr& program)
{
    assembly_.clear();
    includes_.clear();
    animtrees_.clear();
    constants_.clear();
    local_functions_.clear();
    index_ = 1;

    for(const auto& def : program->definitions)
    {
        if(def.as_node->type == gsc::node_t::thread)
        {
            local_functions_.push_back(def.as_thread->name->value);
        }
    }

    for(const auto& include : program->includes)
    {
        emit_include(include);
    }

    for(const auto& def : program->definitions)
    {
        emit_define(def);  
    }

#ifdef DEBUG_GSC_COMPILER
    print_debug_info();
#endif
}

void compiler::emit_include(const gsc::include_ptr& include)
{
    const auto& path = include->file->value;

    for(const auto& inc : includes_)
    {
        if(inc.name == path)
        {
            throw gsc::comp_error(include->loc, "error duplicated include file '" + path + "'.");
        }
    }

    if(map_known_includes(path)) return;

    try
    {
        auto program = parse_file(path);

        std::vector<std::string> funcs;

        for(const auto& def : program->definitions)
        {
            if(def.as_node->type == gsc::node_t::thread)
            {
                funcs.push_back(def.as_thread->name->value);
            }
        }

        if(funcs.size() == 0)
        {
            throw gsc::comp_error(include->loc, "error empty include file '" + path + "'.");
        }

        includes_.push_back(include_t(path, funcs));
    }
    catch(const std::exception& e)
    {
        throw gsc::comp_error(include->loc, "error parsing include file '" + path + "': " + e.what());
    }
}

void compiler::emit_define(const gsc::define_ptr& define)
{
    switch(define.as_node->type)
    {
        case gsc::node_t::usingtree: emit_usingtree(define.as_usingtree); break;
        case gsc::node_t::constant:  emit_constant(define.as_constant); break;
        case gsc::node_t::thread:    emit_thread(define.as_thread); break;
        default: break;
    }
}

void compiler::emit_usingtree(const gsc::usingtree_ptr& animtree)
{
    animtrees_.push_back({ animtree->animtree->value, false });
}

void compiler::emit_constant(const gsc::constant_ptr& constant)
{
    constants_.insert({ constant->name->value, std::move(constant->value) });
}

void compiler::emit_thread(const gsc::thread_ptr& thread)
{
    function_ = std::make_unique<gsc::function>();
    function_->index = index_;
    function_->name = thread->name->value;

    auto ctx = std::make_unique<gsc::context>();
    stack_idx_ = 0;
    label_idx_ = 0;
    local_stack_.clear();
    calc_local_vars(ctx, thread);

    emit_parameters(ctx, thread->params);
    emit_stmt_list(ctx, thread->block, true);
    emit_opcode(ctx, opcode::OP_End);

    function_->size = index_ - function_->index;
    assembly_.push_back(std::move(function_));
}

void compiler::emit_parameters(const gsc::context_ptr& ctx, const gsc::parameters_ptr& params)
{
    for(const auto& param : params->list)
    {
        initialize_variable(ctx, param);
        emit_opcode(ctx, opcode::OP_SafeCreateVariableFieldCached, variable_create_index(ctx, param));     
    }

    emit_opcode(ctx, opcode::OP_checkclearparams);
}

void compiler::emit_stmt(const gsc::context_ptr& ctx, const gsc::stmt_ptr& stmt, bool last)
{
    switch(stmt.as_node->type)
    {
        case gsc::node_t::stmt_list:             emit_stmt_list(ctx, stmt.as_list, last); break;
        case gsc::node_t::stmt_call:             emit_stmt_call(ctx, stmt.as_call); break;
        case gsc::node_t::stmt_assign:           emit_stmt_assign(ctx, stmt.as_assign); break;
        case gsc::node_t::stmt_endon:            emit_stmt_endon(ctx, stmt.as_endon); break;
        case gsc::node_t::stmt_notify:           emit_stmt_notify(ctx, stmt.as_notify); break;
        case gsc::node_t::stmt_wait:             emit_stmt_wait(ctx, stmt.as_wait); break;
        case gsc::node_t::stmt_waittill:         emit_stmt_waittill(ctx, stmt.as_waittill); break;
        case gsc::node_t::stmt_waittillmatch:    emit_stmt_waittillmatch(ctx, stmt.as_waittillmatch); break;
        case gsc::node_t::stmt_waittillframeend: emit_stmt_waittillframeend(ctx, stmt.as_waittillframeend); break;
        case gsc::node_t::stmt_waitframe:        emit_stmt_waitframe(ctx, stmt.as_waitframe); break;
        case gsc::node_t::stmt_if:               emit_stmt_if(ctx, stmt.as_if, last); break;
        case gsc::node_t::stmt_ifelse:           emit_stmt_ifelse(ctx, stmt.as_ifelse, last); break;
        case gsc::node_t::stmt_while:            emit_stmt_while(ctx, stmt.as_while); break;
        case gsc::node_t::stmt_for:              emit_stmt_for(ctx, stmt.as_for); break;
        case gsc::node_t::stmt_foreach:          emit_stmt_foreach(ctx, stmt.as_foreach); break;
        case gsc::node_t::stmt_switch:           emit_stmt_switch(ctx, stmt.as_switch); break;
        case gsc::node_t::stmt_case:             emit_stmt_case(ctx, stmt.as_case); break;
        case gsc::node_t::stmt_default:          emit_stmt_default(ctx, stmt.as_default); break;
        case gsc::node_t::stmt_break:            emit_stmt_break(ctx, stmt.as_break); break;
        case gsc::node_t::stmt_continue:         emit_stmt_continue(ctx, stmt.as_continue); break;
        case gsc::node_t::stmt_return:           emit_stmt_return(ctx, stmt.as_return); break;
        default: break;
    }
}

void compiler::emit_stmt_list(const gsc::context_ptr& ctx, const gsc::stmt_list_ptr& stmt, bool last)
{
    for (const auto& entry : stmt->stmts)
    {
        bool last_ = (&entry == &stmt->stmts.back() && last) ? true : false;
        emit_stmt(ctx, entry, last_);
    }
}

void compiler::emit_stmt_call(const gsc::context_ptr& ctx, const gsc::stmt_call_ptr& stmt)
{
    if(stmt->expr->func.as_node->type == gsc::node_t::expr_call_function)
    {
        const auto& name = stmt->expr->func.as_func->name->value;

        if(name == "assert" || name == "assertex" || name == "assertmsg") return;
    }

    emit_expr_call(ctx, stmt->expr);
    emit_opcode(ctx, opcode::OP_DecTop);
}

void compiler::emit_stmt_assign(const gsc::context_ptr& ctx, const gsc::stmt_assign_ptr& stmt)
{
    emit_expr_assign(ctx, stmt->expr);
}

void compiler::emit_stmt_endon(const gsc::context_ptr& ctx, const gsc::stmt_endon_ptr& stmt)
{
    emit_expr(ctx, stmt->expr);
    emit_expr(ctx, stmt->obj);
    emit_opcode(ctx, opcode::OP_endon);
}

void compiler::emit_stmt_notify(const gsc::context_ptr& ctx, const gsc::stmt_notify_ptr& stmt)
{
    emit_opcode(ctx, opcode::OP_voidCodepos);
    
    std::reverse(stmt->args->list.begin(), stmt->args->list.end());
    
    for(const auto& arg : stmt->args->list)
    {
        emit_expr(ctx, arg);
    }

    emit_expr(ctx, stmt->expr);
    emit_expr(ctx, stmt->obj);
    emit_opcode(ctx, opcode::OP_notify);
}

void compiler::emit_stmt_wait(const gsc::context_ptr& ctx, const gsc::stmt_wait_ptr& stmt)
{
    emit_expr(ctx, stmt->expr);
    emit_opcode(ctx, opcode::OP_wait);
}

void compiler::emit_stmt_waittill(const gsc::context_ptr& ctx, const gsc::stmt_waittill_ptr& stmt)
{
    emit_expr(ctx, stmt->expr);
    emit_expr(ctx, stmt->obj);
    emit_opcode(ctx, opcode::OP_waittill);

    std::reverse(stmt->args->list.begin(), stmt->args->list.end());

    for(const auto& arg : stmt->args->list)
    {
        create_variable(ctx, arg.as_name);
        emit_opcode(ctx, opcode::OP_SafeSetWaittillVariableFieldCached, variable_access_index(ctx, arg.as_name));
    }

    emit_opcode(ctx, opcode::OP_clearparams);
}

void compiler::emit_stmt_waittillmatch(const gsc::context_ptr& ctx, const gsc::stmt_waittillmatch_ptr& stmt)
{
    emit_expr_arguments(ctx, stmt->args);
    emit_expr(ctx, stmt->expr);
    emit_expr(ctx, stmt->obj);
    emit_opcode(ctx, opcode::OP_waittillmatch);
    emit_opcode(ctx, opcode::OP_clearparams);
}

void compiler::emit_stmt_waittillframeend(const gsc::context_ptr& ctx, const gsc::stmt_waittillframeend_ptr& stmt)
{
    emit_opcode(ctx, opcode::OP_waittillFrameEnd);
}

void compiler::emit_stmt_waitframe(const gsc::context_ptr& ctx, const gsc::stmt_waitframe_ptr& stmt)
{
    emit_opcode(ctx, opcode::OP_waitFrame);
}

void compiler::emit_stmt_if(const gsc::context_ptr& ctx, const gsc::stmt_if_ptr& stmt, bool last)
{
    auto end_loc = create_label();

    if(stmt->expr.as_node->type == gsc::node_t::expr_not)
    {
        emit_expr(ctx, stmt->expr.as_not->rvalue);
        emit_opcode(ctx, opcode::OP_JumpOnTrue, end_loc);
    }
    else
    {
        emit_expr(ctx, stmt->expr);
        emit_opcode(ctx, opcode::OP_JumpOnFalse, end_loc);
    }

    ctx->transfer(stmt->ctx);
    stmt->ctx->is_last = last;

    emit_stmt(stmt->ctx, stmt->stmt, last);

    last ? emit_opcode(ctx, opcode::OP_End) : emit_remove_local_vars(stmt->ctx);

    insert_label(end_loc);
}

void compiler::emit_stmt_ifelse(const gsc::context_ptr& ctx, const gsc::stmt_ifelse_ptr& stmt, bool last)
{
    auto else_loc = create_label();
    auto end_loc = create_label();

    if(stmt->expr.as_node->type == gsc::node_t::expr_not)
    {
        emit_expr(ctx, stmt->expr.as_not->rvalue);
        emit_opcode(ctx, opcode::OP_JumpOnTrue, else_loc);
    }
    else
    {
        emit_expr(ctx, stmt->expr);
        emit_opcode(ctx, opcode::OP_JumpOnFalse, else_loc);
    }

    ctx->transfer(stmt->ctx_if);
    stmt->ctx_if->is_last = last;

    emit_stmt(stmt->ctx_if, stmt->stmt_if, last);

    emit_remove_local_vars(stmt->ctx_if);

    last ? emit_opcode(ctx, opcode::OP_End) : emit_opcode(ctx, opcode::OP_jump, end_loc);

    insert_label(else_loc);

    ctx->transfer(stmt->ctx_else);
    stmt->ctx_else->is_last = last;

    emit_stmt(stmt->ctx_else, stmt->stmt_else, last);

    last ? emit_opcode(ctx, opcode::OP_End) : emit_remove_local_vars(stmt->ctx_else);

    insert_label(end_loc);

    std::vector<gsc::context*> childs({ stmt->ctx_if.get(), stmt->ctx_else.get() });
    ctx->init_from_child(childs);
}

void compiler::emit_stmt_while(const gsc::context_ptr& ctx, const gsc::stmt_while_ptr& stmt)
{
    auto break_loc = create_label();
    auto continue_loc = create_label();

    ctx->transfer(stmt->ctx);
    stmt->ctx->is_loop = true;
    stmt->ctx->loc_break = break_loc;
    stmt->ctx->loc_continue = continue_loc;

    emit_create_local_vars(stmt->ctx);

    auto begin_loc = insert_label();

    bool const_cond = is_constant_condition(stmt->expr);

    emit_expr(ctx, stmt->expr);
    emit_opcode(ctx, opcode::OP_JumpOnFalse, break_loc);

    emit_stmt(stmt->ctx, stmt->stmt, false);

    insert_label(continue_loc);
    emit_opcode(ctx, opcode::OP_jumpback, begin_loc);

    insert_label(break_loc);

    if(const_cond)
    {
        std::vector<gsc::context*> childs({ stmt->ctx.get() });
        ctx->init_from_child(childs);
    }
}

void compiler::emit_stmt_for(const gsc::context_ptr& ctx, const gsc::stmt_for_ptr& stmt)
{
    auto break_loc = create_label();
    auto continue_loc = create_label();

    if(stmt->pre_expr.as_node->type != gsc::node_t::null)
        emit_expr_assign(ctx, stmt->pre_expr.as_assign);

    ctx->transfer(stmt->ctx);
    stmt->ctx->is_loop = true;
    stmt->ctx->loc_break = break_loc;
    stmt->ctx->loc_continue = continue_loc;

    emit_create_local_vars(stmt->ctx);

    auto begin_loc = insert_label();

    bool const_cond = false;

    if(stmt->expr.as_node->type != gsc::node_t::null)
    { 
        const_cond = is_constant_condition(stmt->expr);
        emit_expr(ctx, stmt->expr);
        emit_opcode(ctx, opcode::OP_JumpOnFalse, break_loc);
    }
    else const_cond = true;

    emit_stmt(stmt->ctx, stmt->stmt, false);

    insert_label(continue_loc);

    if(stmt->post_expr.as_node->type != gsc::node_t::null)
        emit_expr_assign(ctx, stmt->post_expr.as_assign);

    emit_opcode(ctx, opcode::OP_jumpback, begin_loc);
    
    insert_label(break_loc);

    if(const_cond)
    {
        std::vector<gsc::context*> childs({ stmt->ctx.get() });
        ctx->init_from_child(childs);
    }
}

void compiler::emit_stmt_foreach(const gsc::context_ptr& ctx, const gsc::stmt_foreach_ptr& stmt)
{
    auto break_loc = create_label();
    auto continue_loc = create_label();

    emit_expr(ctx, stmt->container);
    emit_local_variable_ref(ctx, stmt->array, true);
    emit_local_variable(ctx, stmt->array);
    emit_opcode(ctx, opcode::OP_CallBuiltin1, "getfirstarraykey");
    create_variable(ctx, stmt->element);
    emit_local_variable_ref(ctx, stmt->key, true);

    ctx->transfer(stmt->ctx);
    stmt->ctx->is_loop = true;
    stmt->ctx->loc_break = break_loc;
    stmt->ctx->loc_continue = continue_loc;

    emit_create_local_vars(stmt->ctx); // this should be before key set...

    auto begin_loc = insert_label();

    emit_local_variable(ctx, stmt->key);
    emit_opcode(ctx, opcode::OP_CallBuiltin1, "isdefined");
	emit_opcode(ctx, opcode::OP_JumpOnFalse, break_loc);
    emit_local_variable(ctx, stmt->key);
    emit_opcode(ctx, opcode::OP_EvalLocalArrayCached, variable_access_index(ctx, stmt->array));
    emit_local_variable_ref(ctx, stmt->element, true);

    emit_stmt(stmt->ctx, stmt->stmt, false);

    insert_label(continue_loc);
    emit_local_variable(ctx, stmt->key);
	emit_local_variable(ctx, stmt->array);
	emit_opcode(ctx, opcode::OP_CallBuiltin2, "getnextarraykey");
	emit_local_variable_ref(ctx, stmt->key, true);
    emit_opcode(ctx, opcode::OP_jumpback, begin_loc);

    insert_label(break_loc);
    emit_clear_local_variable(ctx, stmt->array);
    if(!stmt->use_key) emit_clear_local_variable(ctx, stmt->key);
}

void compiler::emit_stmt_switch(const gsc::context_ptr& ctx, const gsc::stmt_switch_ptr& stmt)
{
    auto jmptable_loc = create_label();
    auto break_loc = create_label();

    ctx->transfer(stmt->ctx);
    stmt->ctx->is_switch = true;
    stmt->ctx->loc_break = break_loc;

    emit_expr(ctx, stmt->expr);
    emit_opcode(ctx, opcode::OP_switch, jmptable_loc);
    
    emit_stmt_list(stmt->ctx, stmt->stmt, false);

    insert_label(jmptable_loc);

    std::vector<std::string> data;
    data.push_back(utils::string::va("%d", stmt->ctx->case_id.size()));
    
    auto i = 0;
    for(auto& id : stmt->ctx->case_id)
    {
        if(id != "default")
        {
            data.push_back("case");
            data.push_back(id);
            data.push_back(stmt->ctx->case_loc.at(i));
            i++;
        }
        else
        {
            data.push_back(id);
            data.push_back(stmt->ctx->case_loc.at(i));
            i++;
        }   
    }

    emit_opcode(ctx, opcode::OP_endswitch, data);

    auto offset =  7 * stmt->ctx->case_id.size();
    function_->instructions.back()->size += offset;
    index_ += offset;

    insert_label(break_loc);
}

void compiler::emit_stmt_case(const gsc::context_ptr& ctx, const gsc::stmt_case_ptr& stmt)
{
    if(!ctx->is_switch)
    {
        throw gsc::comp_error(stmt->loc, "illegal case statement outside a switch");
    }

    if(stmt->value.as_node->type == gsc::node_t::data_integer)
    {
        auto loc = insert_label();
        ctx->case_id.push_back(stmt->value.as_integer->value);
        ctx->case_loc.push_back(loc);
    }
    else if(stmt->value.as_node->type == gsc::node_t::data_string)
    {
        auto loc = insert_label();
        ctx->case_id.push_back(stmt->value.as_string->value);
        ctx->case_loc.push_back(loc);
    }
    else
    {
        throw gsc::comp_error(stmt->loc, "illegal case type");
    }
}

void compiler::emit_stmt_default(const gsc::context_ptr& ctx, const gsc::stmt_default_ptr& stmt)
{
    if(!ctx->is_switch)
    {
        throw gsc::comp_error(stmt->loc, "illegal default statement outside a switch");
    }

    auto loc = insert_label();
    ctx->case_id.push_back("default");
    ctx->case_loc.push_back(loc);
}

void compiler::emit_stmt_break(const gsc::context_ptr& ctx, const gsc::stmt_break_ptr& stmt)
{
    if(ctx->loc_break == "")
    {
        throw gsc::comp_error(stmt->loc, "illegal break statement outside a loop");
    }

    emit_remove_local_vars(ctx);
    emit_opcode(ctx, opcode::OP_jump, ctx->loc_break);
}

void compiler::emit_stmt_continue(const gsc::context_ptr& ctx, const gsc::stmt_continue_ptr& stmt)
{
    if(ctx->loc_continue == "")
    {
        throw gsc::comp_error(stmt->loc, "illegal continue statement outside a loop");
    }

    emit_remove_local_vars(ctx);
    emit_opcode(ctx, opcode::OP_jump, ctx->loc_continue);
}

void compiler::emit_stmt_return(const gsc::context_ptr& ctx, const gsc::stmt_return_ptr& stmt)
{
    if(stmt->expr.as_node->type == gsc::node_t::null)
    {
        emit_opcode(ctx, opcode::OP_End);
        return; 
    }
    
    emit_expr(ctx, stmt->expr);
    emit_opcode(ctx, opcode::OP_Return);
}

void compiler::emit_expr(const gsc::context_ptr& ctx, const gsc::expr_ptr& expr)
{
    switch(expr.as_node->type)
    {
        case gsc::node_t::expr_and:              emit_expr_and(ctx, expr.as_and); break;
        case gsc::node_t::expr_or:               emit_expr_or(ctx, expr.as_or); break;
        case gsc::node_t::expr_equality:         emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_inequality:       emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_less:             emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_greater:          emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_less_equal:       emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_greater_equal:    emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_bitwise_or:       emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_bitwise_and:      emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_bitwise_exor:     emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_shift_left:       emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_shift_right:      emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_add:              emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_sub:              emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_mult:             emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_div:              emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_mod:              emit_expr_binary(ctx, expr.as_binary); break;
        case gsc::node_t::expr_complement:       emit_expr_complement(ctx, expr.as_complement); break;
        case gsc::node_t::expr_not:              emit_expr_not(ctx, expr.as_not); break;
        case gsc::node_t::expr_call:             emit_expr_call(ctx, expr.as_call); break;
        case gsc::node_t::expr_function:         emit_expr_function(ctx, expr.as_function); break;
        case gsc::node_t::expr_add_array:        emit_expr_add_array(ctx, expr.as_add_array); break;
        case gsc::node_t::expr_array:            emit_array_variable(ctx, expr.as_array); break;
        case gsc::node_t::expr_field:            emit_field_variable(ctx, expr.as_field); break;
        case gsc::node_t::expr_size:             emit_expr_size(ctx, expr.as_size); break;
        case gsc::node_t::data_thisthread:       emit_opcode(ctx, opcode::OP_GetThisthread); break;
        case gsc::node_t::data_empty_array:      emit_opcode(ctx, opcode::OP_EmptyArray); break;
        case gsc::node_t::data_undefined:        emit_opcode(ctx, opcode::OP_GetUndefined); break;
        case gsc::node_t::data_game:             emit_opcode(ctx, opcode::OP_GetGame); break;
        case gsc::node_t::data_self:             emit_opcode(ctx, opcode::OP_GetSelf); break;
        case gsc::node_t::data_anim:             emit_opcode(ctx, opcode::OP_GetAnim); break;
        case gsc::node_t::data_level:            emit_opcode(ctx, opcode::OP_GetLevel); break;
        case gsc::node_t::data_animation:        emit_animation(ctx, expr.as_animation); break;
        case gsc::node_t::data_animtree:         emit_animtree(ctx, expr.as_animtree); break;
        case gsc::node_t::data_name:             emit_local_variable(ctx, expr.as_name); break;
        case gsc::node_t::data_istring:          emit_istring(ctx, expr.as_istring); break;
        case gsc::node_t::data_string:           emit_string(ctx, expr.as_string); break;
        case gsc::node_t::data_vector:           emit_vector(ctx, expr.as_vector); break;
        case gsc::node_t::data_float:            emit_float(ctx, expr.as_float); break;
        case gsc::node_t::data_integer:          emit_integer(ctx, expr.as_integer); break;
        case gsc::node_t::data_false:            emit_false(ctx, expr.as_false); break;
        case gsc::node_t::data_true:             emit_true(ctx, expr.as_true); break;
        default: throw gsc::comp_error(expr.as_node->loc, "unknown expression"); break;
    }
}

void compiler::emit_expr_assign(const gsc::context_ptr& ctx, const gsc::expr_assign_ptr& expr)	
{
    if(expr->type == gsc::node_t::expr_increment)
    {
        emit_variable_ref(ctx, expr->lvalue, false);
        emit_opcode(ctx, opcode::OP_inc);
        emit_opcode(ctx, opcode::OP_SetVariableField);
    }
    else if(expr->type == gsc::node_t::expr_decrement)
    {
        emit_variable_ref(ctx, expr->lvalue, false);
        emit_opcode(ctx, opcode::OP_dec);
        emit_opcode(ctx, opcode::OP_SetVariableField);
    }
    else if(expr->type == gsc::node_t::expr_assign_equal)
    {
        if(expr->rvalue.as_node->type == gsc::node_t::data_undefined)
        {
            emit_expr_clear_variable(ctx, expr->lvalue);
        }
        else
        {
            emit_expr(ctx, expr->rvalue);
            emit_variable_ref(ctx, expr->lvalue, true);
        }
    }
    else
    {
        emit_expr(ctx, expr->lvalue);
        emit_expr(ctx, expr->rvalue);

        switch(expr->type)
        {
            case gsc::node_t::expr_assign_add:           emit_opcode(ctx, opcode::OP_plus); break;
            case gsc::node_t::expr_assign_sub:           emit_opcode(ctx, opcode::OP_minus); break;
            case gsc::node_t::expr_assign_mult:          emit_opcode(ctx, opcode::OP_multiply); break;
            case gsc::node_t::expr_assign_div:           emit_opcode(ctx, opcode::OP_divide); break;
            case gsc::node_t::expr_assign_mod:           emit_opcode(ctx, opcode::OP_mod); break;
            case gsc::node_t::expr_assign_shift_left:    emit_opcode(ctx, opcode::OP_shift_left); break;
            case gsc::node_t::expr_assign_shift_right:   emit_opcode(ctx, opcode::OP_shift_right); break;
            case gsc::node_t::expr_assign_bitwise_or:    emit_opcode(ctx, opcode::OP_bit_or); break;
            case gsc::node_t::expr_assign_bitwise_and:   emit_opcode(ctx, opcode::OP_bit_and); break;
            case gsc::node_t::expr_assign_bitwise_exor:  emit_opcode(ctx, opcode::OP_bit_ex_or); break;
            default: throw gsc::comp_error(expr->loc, "unknown assign operation"); break;
        }

        emit_variable_ref(ctx, expr->lvalue, true);
    }  
}

void compiler::emit_expr_binary(const gsc::context_ptr& ctx, const gsc::expr_binary_ptr& expr)
{
    emit_expr(ctx, expr->lvalue);
    emit_expr(ctx, expr->rvalue);

    switch(expr->type)
    {
        case gsc::node_t::expr_equality:         emit_opcode(ctx, opcode::OP_equality); break;
        case gsc::node_t::expr_inequality:       emit_opcode(ctx, opcode::OP_inequality); break;
        case gsc::node_t::expr_less:             emit_opcode(ctx, opcode::OP_less); break;
        case gsc::node_t::expr_greater:          emit_opcode(ctx, opcode::OP_greater); break;
        case gsc::node_t::expr_less_equal:       emit_opcode(ctx, opcode::OP_less_equal); break;
        case gsc::node_t::expr_greater_equal:    emit_opcode(ctx, opcode::OP_greater_equal); break;
        case gsc::node_t::expr_bitwise_or:       emit_opcode(ctx, opcode::OP_bit_or); break;
        case gsc::node_t::expr_bitwise_and:      emit_opcode(ctx, opcode::OP_bit_and); break;
        case gsc::node_t::expr_bitwise_exor:     emit_opcode(ctx, opcode::OP_bit_ex_or); break;
        case gsc::node_t::expr_shift_left:       emit_opcode(ctx, opcode::OP_shift_left); break;
        case gsc::node_t::expr_shift_right:      emit_opcode(ctx, opcode::OP_shift_right); break;
        case gsc::node_t::expr_add:              emit_opcode(ctx, opcode::OP_plus); break;
        case gsc::node_t::expr_sub:              emit_opcode(ctx, opcode::OP_minus); break;
        case gsc::node_t::expr_mult:             emit_opcode(ctx, opcode::OP_multiply); break;
        case gsc::node_t::expr_div:              emit_opcode(ctx, opcode::OP_divide); break;
        case gsc::node_t::expr_mod:              emit_opcode(ctx, opcode::OP_mod); break;
        default: throw gsc::comp_error(expr->loc, "unknown binary expression"); break;
    }
}

void compiler::emit_expr_and(const gsc::context_ptr& ctx, const gsc::expr_and_ptr& expr)
{
    auto label = create_label();

    emit_expr(ctx, expr->lvalue);
    emit_opcode(ctx, opcode::OP_JumpOnFalseExpr, label);
    emit_expr(ctx, expr->rvalue);
    emit_opcode(ctx, opcode::OP_CastBool);

    insert_label(label);
}

void compiler::emit_expr_or(const gsc::context_ptr& ctx, const gsc::expr_or_ptr& expr)
{
    auto label = create_label();

    emit_expr(ctx, expr->lvalue);
    emit_opcode(ctx, opcode::OP_JumpOnTrueExpr, label);
    emit_expr(ctx, expr->rvalue);
    emit_opcode(ctx, opcode::OP_CastBool);

    insert_label(label);
}

void compiler::emit_expr_complement(const gsc::context_ptr& ctx, const gsc::expr_complement_ptr& expr)
{
    emit_expr(ctx, expr->rvalue);
    emit_opcode(ctx, opcode::OP_BoolComplement);
}

void compiler::emit_expr_not(const gsc::context_ptr& ctx, const gsc::expr_not_ptr& expr)
{
    emit_expr(ctx, expr->rvalue);
    emit_opcode(ctx, opcode::OP_BoolNot);
}

void compiler::emit_expr_call(const gsc::context_ptr& ctx, const gsc::expr_call_ptr& expr)
{
    if(expr->func.as_node->type == gsc::node_t::expr_call_pointer)
    {
        emit_expr_call_pointer(ctx, expr);
    }
    else
    {
        emit_expr_call_function(ctx, expr);
    }
}

void compiler::emit_expr_call_pointer(const gsc::context_ptr& ctx, const gsc::expr_call_ptr& expr)
{
    bool thread = expr->thread;
    bool child = expr->child;
    bool method = expr->obj.as_node->type != gsc::node_t::null ? true : false;
    bool builtin = builtin = expr->func.as_pointer->builtin;
    std::uint32_t args = expr->func.as_pointer->args->list.size();

    if(thread && child || thread && builtin || child && builtin)
        throw gsc::comp_error(expr->loc, "function call have more than 1 type (thread, childthread, builtin)");

    if(!thread && !child && !builtin) emit_opcode(ctx, opcode::OP_PreScriptCall);

    emit_expr_arguments(ctx, expr->func.as_pointer->args);

    if(method) emit_expr(ctx, expr->obj);

    emit_expr(ctx, expr->func.as_pointer->expr);
    emit_expr_call_pointer_type(ctx, args, builtin, method, thread, child);
}

void compiler::emit_expr_call_pointer_type(const gsc::context_ptr& ctx, int args, bool builtin, bool method, bool thread, bool child)
{
    if(builtin && !method)
    {
        emit_opcode(ctx, opcode::OP_CallBuiltinPointer, utils::string::va("%d", args));
    }
    else if(builtin && method)
    {
        emit_opcode(ctx, opcode::OP_CallBuiltinMethodPointer, utils::string::va("%d", args));
    }
    else if(thread && !method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptThreadCallPointer, utils::string::va("%d", args));
    } 
    else if(thread && method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptMethodThreadCallPointer, utils::string::va("%d", args));
    }
    else if (child && !method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptChildThreadCallPointer, utils::string::va("%d", args));
    }
    else if(child && method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptMethodChildThreadCallPointer, utils::string::va("%d", args));
    }
    else
    {
        method ? emit_opcode(ctx, opcode::OP_ScriptMethodCallPointer) : emit_opcode(ctx, opcode::OP_ScriptFunctionCallPointer);
    }
}

void compiler::emit_expr_call_function(const gsc::context_ptr& ctx, const gsc::expr_call_ptr& expr)
{
    bool thread = expr->thread;
    bool child = expr->child;
    bool method = expr->obj.as_node->type != gsc::node_t::null ? true : false;
    std::uint32_t args = expr->func.as_func->args->list.size();
    auto name = expr->func.as_func->name->value;
    auto file = expr->func.as_func->file->value;

    bool builtin = false, far = false, local = false;

    if(file != "") far = true;
    else
    {
        if(is_local_call(name)) local = true;
        else if(method && is_builtin_method(name)) builtin = true;
        else if(!method && is_builtin_func(name)) builtin = true;
        else
        {
            for(const auto& inc : includes_)
            {
                for(const auto& fun : inc.funcs)
                {
                    if(name == fun)
                    {
                        far = true;
                        file = inc.name;
                        break;
                    }
                }
            }

            if(!builtin && !far && !local)
                throw gsc::comp_error(expr->loc, "unknown function call " + name);
        }
    }

    if(thread && child || thread && builtin || child && builtin)
        throw gsc::comp_error(expr->loc, "function call have more than 1 type (thread, childthread, builtin)");

    if(!thread && !child && !builtin && !(!method && args == 0)) 
        emit_opcode(ctx, opcode::OP_PreScriptCall);

    emit_expr_arguments(ctx, expr->func.as_func->args);

    if(method) emit_expr(ctx, expr->obj);

    if(builtin) emit_expr_call_function_builtin(ctx, name, args, method);
    else if(local) emit_expr_call_function_local(ctx, name, args, method, thread, child);
    else if(far) emit_expr_call_function_far(ctx, file, name, args, method, thread, child);
}

void compiler::emit_expr_call_function_builtin(const gsc::context_ptr& ctx, const std::string& func, int args, bool method)
{
    if(method)
    {
        switch(args)
        {
            case 0: emit_opcode(ctx, opcode::OP_CallBuiltinMethod0, func); break;
            case 1: emit_opcode(ctx, opcode::OP_CallBuiltinMethod1, func); break;
            case 2: emit_opcode(ctx, opcode::OP_CallBuiltinMethod2, func); break;
            case 3: emit_opcode(ctx, opcode::OP_CallBuiltinMethod3, func); break;
            case 4: emit_opcode(ctx, opcode::OP_CallBuiltinMethod4, func); break;
            case 5: emit_opcode(ctx, opcode::OP_CallBuiltinMethod5, func); break;
            default: emit_opcode(ctx, opcode::OP_CallBuiltinMethod, { utils::string::va("%d", args), func }); break;
        }
    }
    else
    {
        switch(args)
        {
            case 0: emit_opcode(ctx, opcode::OP_CallBuiltin0, func); break;
            case 1: emit_opcode(ctx, opcode::OP_CallBuiltin1, func); break;
            case 2: emit_opcode(ctx, opcode::OP_CallBuiltin2, func); break;
            case 3: emit_opcode(ctx, opcode::OP_CallBuiltin3, func); break;
            case 4: emit_opcode(ctx, opcode::OP_CallBuiltin4, func); break;
            case 5: emit_opcode(ctx, opcode::OP_CallBuiltin5, func); break;
            default: emit_opcode(ctx, opcode::OP_CallBuiltin, { utils::string::va("%d", args), func }); break;
        }
    }
}

void compiler::emit_expr_call_function_local(const gsc::context_ptr& ctx, const std::string& func, int args, bool method, bool thread, bool child)
{
    if(thread && !method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalThreadCall, { func, utils::string::va("%d", args) });
    }
    else if(thread && method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalMethodThreadCall, { func, utils::string::va("%d", args) });
    }
    else if(child && !method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalChildThreadCall, { func, utils::string::va("%d", args) });
    }
    else if(child && method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalMethodChildThreadCall, { func, utils::string::va("%d", args) });
    }
    else if(method && !thread && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalMethodCall, func);
    }
    else if(!thread && !child && !method && args == 0)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalFunctionCall2, func);
    }
    else if(!thread && !child && !method && args != 0)
    {
        emit_opcode(ctx, opcode::OP_ScriptLocalFunctionCall, func);
    }
}

void compiler::emit_expr_call_function_far(const gsc::context_ptr& ctx, const std::string& file, const std::string& func, int args, bool method, bool thread, bool child)
{
    if(thread && !method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarThreadCall, { utils::string::va("%d", args), file, func });
    }
    else if(thread && method && !child)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarMethodThreadCall, { utils::string::va("%d", args), file, func });
    }
    else if(child && !method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarChildThreadCall, { utils::string::va("%d", args), file, func });
    }
    else if(child && method && !thread)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarMethodChildThreadCall, { utils::string::va("%d", args), file, func });
    }
    else if(!thread && !child && method)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarMethodCall, { file, func });
    }
    else if(!thread && !child && !method && args == 0)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarFunctionCall2, { file, func });
    }
    else if(!thread && !child && !method && args != 0)
    {
        emit_opcode(ctx, opcode::OP_ScriptFarFunctionCall, { file, func });
    }
}

void compiler::emit_expr_arguments(const gsc::context_ptr& ctx, const gsc::expr_arguments_ptr& args)
{
    std::reverse(args->list.begin(), args->list.end());

    for(auto& arg : args->list)
    {
        emit_expr(ctx, arg);
    }
}

void compiler::emit_expr_function(const gsc::context_ptr& ctx, const gsc::expr_function_ptr& expr)
{
    bool far = false, local = false, builtin = false, method = false;
    auto name = expr->name->value;
    auto file = expr->file->value;

    if(file != "")
    {
        far = true;
    }
    else if(is_builtin_method(name))
    {
        builtin = true;
        method = true;
    }
    else if(is_builtin_func(name))
    {
        builtin = true;
    }
    else if(is_local_call(name))
    {
        local = true;
    }

    if(local)
    {
        emit_opcode(ctx, opcode::OP_GetLocalFunction, name);
    }
    else if(far)
    {
        emit_opcode(ctx, opcode::OP_GetFarFunction, { file, name } );
    }
    else if(builtin && method)
    {
        emit_opcode(ctx, opcode::OP_GetBuiltinMethod, name);
    }
    else if(builtin && !method)
    {
        emit_opcode(ctx, opcode::OP_GetBuiltinFunction, name);
    }
}

void compiler::emit_expr_clear_variable(const gsc::context_ptr& ctx, const gsc::expr_ptr& lvalue)
{
    switch(lvalue.as_node->type)
    {
    case gsc::node_t::expr_array:
        emit_expr(ctx, lvalue.as_array->key);
        lvalue.as_array->obj.as_node->type == gsc::node_t::data_game ? emit_opcode(ctx, opcode::OP_GetGameRef) : emit_variable_ref(ctx, lvalue.as_array->obj, false);
        emit_opcode(ctx, opcode::OP_ClearArray);
        break;
    case gsc::node_t::expr_field:
        emit_object(ctx, lvalue.as_field->obj);
        emit_opcode(ctx, opcode::OP_ClearFieldVariable,lvalue.as_field->field->value);
        break;
    case gsc::node_t::data_name:
        emit_opcode(ctx, opcode::OP_GetUndefined);
        emit_local_variable_ref(ctx, lvalue.as_name, true);
        break;
    default:
        throw gsc::comp_error(lvalue.as_node->loc, "unknown clear variable lvalue");
        break;
    }
}

void compiler::emit_expr_add_array(const gsc::context_ptr& ctx, const gsc::expr_add_array_ptr& expr)
{
    if(expr->args->list.size() <= 0)
    {
        throw gsc::comp_error(expr->loc, "invalid empty add array. did u mean '[]' ?");
    }

    emit_opcode(ctx, opcode::OP_EmptyArray);

    for(const auto& arg : expr->args->list)
    {
        emit_expr(ctx, arg);
        emit_opcode(ctx, opcode::OP_AddArray);
    }
}

void compiler::emit_expr_size(const gsc::context_ptr& ctx, const gsc::expr_size_ptr& expr)
{
    emit_variable(ctx, expr->obj);
    emit_opcode(ctx, opcode::OP_size);
}

void compiler::emit_variable_ref(const gsc::context_ptr& ctx, const gsc::expr_ptr& expr, bool set)
{
    switch(expr.as_node->type)
    {
        case gsc::node_t::expr_array: emit_array_variable_ref(ctx, expr.as_array, set); break;
        case gsc::node_t::expr_field: emit_field_variable_ref(ctx, expr.as_field, set); break;
        case gsc::node_t::data_name: emit_local_variable_ref(ctx, expr.as_name, set); break;
        default: throw gsc::comp_error(expr.as_node->loc, "invalid variable reference type."); break;
    }
}

void compiler::emit_array_variable_ref(const gsc::context_ptr& ctx, const gsc::expr_array_ptr& expr, bool set)
{
    emit_expr(ctx, expr->key);

    switch(expr->obj.as_node->type)
    {
    case gsc::node_t::data_game:
        emit_opcode(ctx, opcode::OP_GetGameRef);
        emit_opcode(ctx, opcode::OP_EvalArrayRef);
        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
        break;
    case gsc::node_t::expr_array:
    case gsc::node_t::expr_field:
        emit_variable_ref(ctx, expr->obj, false);
        emit_opcode(ctx, opcode::OP_EvalArrayRef);      
        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
        break;
    case gsc::node_t::data_name:
    {
        if(!variable_initialized(ctx, expr->obj.as_name))
        {
            initialize_variable(ctx, expr->obj.as_name);
            emit_opcode(ctx, opcode::OP_EvalNewLocalArrayRefCached0, variable_create_index(ctx, expr->obj.as_name));

            if(!set)
            {
                throw gsc::comp_error(expr->loc, "INTERNAL: VAR CREATED BUT NOT SET!");
            }
        }
        else if(variable_stack_index(ctx, expr->obj.as_name) == 0)
        {
            emit_opcode(ctx, opcode::OP_EvalLocalArrayRefCached0);
        }
        else
        {
            emit_opcode(ctx, opcode::OP_EvalLocalArrayRefCached, variable_access_index(ctx, expr->obj.as_name));
        }

        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
    }
        break;
    case gsc::node_t::expr_call:
        throw gsc::comp_error(expr->loc, "call result can't be referenced.");
        break;
    default:
        throw gsc::comp_error(expr->loc, "unknown array object type");
        break;
    }
}

void compiler::emit_field_variable_ref(const gsc::context_ptr& ctx, const gsc::expr_field_ptr&  expr, bool set)
{
    const auto& field = expr->field->value;

    switch(expr->obj.as_node->type)
    {
    case gsc::node_t::data_level:
        set ? emit_opcode(ctx, opcode::OP_SetLevelFieldVariableField, field) : emit_opcode(ctx, opcode::OP_EvalLevelFieldVariableRef, field);
        break;
    case gsc::node_t::data_anim:
        set ? emit_opcode(ctx, opcode::OP_SetAnimFieldVariableField, field) : emit_opcode(ctx, opcode::OP_EvalAnimFieldVariableRef, field);
        break;
    case gsc::node_t::data_self:
        set ? emit_opcode(ctx, opcode::OP_SetSelfFieldVariableField, field) : emit_opcode(ctx, opcode::OP_EvalSelfFieldVariableRef, field);
        break;
    case gsc::node_t::expr_array:
        emit_array_variable(ctx, expr->obj.as_array);
        emit_opcode(ctx, opcode::OP_CastFieldObject);
        emit_opcode(ctx, opcode::OP_EvalFieldVariableRef, field);
        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
        break;
    case gsc::node_t::expr_field:
        emit_field_variable(ctx, expr->obj.as_field);
        emit_opcode(ctx, opcode::OP_CastFieldObject);
        emit_opcode(ctx, opcode::OP_EvalFieldVariableRef, field);
        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
        break;
    case gsc::node_t::data_name:
        emit_opcode(ctx, opcode::OP_EvalLocalVariableObjectCached, variable_access_index(ctx, expr->obj.as_name));
        emit_opcode(ctx, opcode::OP_EvalFieldVariableRef, field);
        if(set) emit_opcode(ctx, opcode::OP_SetVariableField);
        break;
    case gsc::node_t::expr_call:
        throw gsc::comp_error(expr->loc, "function call result can't be referenced");
        break;
    default:
        throw gsc::comp_error(expr->loc, "unknown field variable object type");
        break;
    }
}

void compiler::emit_local_variable_ref(const gsc::context_ptr& ctx, const gsc::name_ptr& expr, bool set)
{
    const auto itr = constants_.find(expr->value);

    if (itr != constants_.end())
    {
        throw gsc::comp_error(expr->loc, "variable name already defined as constant " + expr->value);
    }

    if(set)
    {
        if(!variable_initialized(ctx, expr))
        {
            initialize_variable(ctx, expr);
            emit_opcode(ctx, opcode::OP_SetNewLocalVariableFieldCached0, variable_create_index(ctx, expr));
        }
        else if(variable_stack_index(ctx, expr) == 0)
        {
            emit_opcode(ctx, opcode::OP_SetLocalVariableFieldCached0);
        }
        else
        {
            emit_opcode(ctx, opcode::OP_SetLocalVariableFieldCached, variable_access_index(ctx, expr));
        }
    }
    else
    {
        auto index = variable_stack_index(ctx, expr);

        if(index == 0)
            emit_opcode(ctx, opcode::OP_EvalLocalVariableRefCached0);
        else
            emit_opcode(ctx, opcode::OP_EvalLocalVariableRefCached, variable_access_index(ctx, expr));
    }
}

void compiler::emit_variable(const gsc::context_ptr& ctx, const gsc::expr_ptr& expr)
{
    // for obj.size
    switch(expr.as_node->type)
    {
        case gsc::node_t::expr_array: emit_array_variable(ctx, expr.as_array); break;
        case gsc::node_t::expr_field: emit_field_variable(ctx, expr.as_field); break;
        case gsc::node_t::data_name: emit_local_variable(ctx, expr.as_name); break;
        case gsc::node_t::expr_call:  emit_expr_call(ctx, expr.as_call); break;
        default: throw gsc::comp_error(expr.as_node->loc, "invalid variable type."); break;
    }
}

void compiler::emit_array_variable(const gsc::context_ptr& ctx, const gsc::expr_array_ptr& expr)
{
    emit_expr(ctx, expr->key);

    if(expr->obj.as_node->type == gsc::node_t::data_name)
    {
        emit_opcode(ctx, opcode::OP_EvalLocalArrayCached, variable_access_index(ctx, expr->obj.as_name));
    }
    else
    {
        emit_expr(ctx, expr->obj);
        emit_opcode(ctx, opcode::OP_EvalArray);
    }
}

void compiler::emit_field_variable(const gsc::context_ptr& ctx, const gsc::expr_field_ptr& expr)
{
    const auto& field = expr->field->value;

    switch(expr->obj.as_node->type)
    {
    case gsc::node_t::data_level:
        emit_opcode(ctx, opcode::OP_EvalLevelFieldVariable, field);
        break;
    case gsc::node_t::data_anim:
        emit_opcode(ctx, opcode::OP_EvalAnimFieldVariable, field);
        break;
    case gsc::node_t::data_self:
        emit_opcode(ctx, opcode::OP_EvalSelfFieldVariable, field);
        break;
    case gsc::node_t::expr_array:
        emit_array_variable(ctx, expr->obj.as_array);
        emit_opcode(ctx, opcode::OP_CastFieldObject);
        emit_opcode(ctx, opcode::OP_EvalFieldVariable, field);  
        break;
    case gsc::node_t::expr_field:
        emit_field_variable(ctx, expr->obj.as_field);
        emit_opcode(ctx, opcode::OP_CastFieldObject);
        emit_opcode(ctx, opcode::OP_EvalFieldVariable, field);
        break;
    case gsc::node_t::expr_call:
        emit_expr_call(ctx, expr->obj.as_call);
        emit_opcode(ctx, opcode::OP_CastFieldObject);
        emit_opcode(ctx, opcode::OP_EvalFieldVariable, field);
        break;
    case gsc::node_t::data_name:
        emit_opcode(ctx, opcode::OP_EvalLocalVariableObjectCached, variable_access_index(ctx, expr->obj.as_name));
        emit_opcode(ctx, opcode::OP_EvalFieldVariable, field);
        break;
    default:
       throw gsc::comp_error(expr->loc, "unknown field variable object type");
        break;
    }
}

void compiler::emit_local_variable(const gsc::context_ptr& ctx, const gsc::name_ptr& expr)
{
    // is constant ( should only allow: string, loc string, number, vector)
    const auto itr = constants_.find(expr->value);

    if (itr != constants_.end())
    {
        const auto& value = itr->second;
        emit_expr(ctx, value);
        return;
    }

    // is local var
    auto index = variable_stack_index(ctx, expr);

    switch(index)
    {
        case 0: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached0); break;
        case 1: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached1); break;
        case 2: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached2); break;
        case 3: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached3); break;
        case 4: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached4); break;
        case 5: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached5); break;
        default: emit_opcode(ctx, opcode::OP_EvalLocalVariableCached, variable_access_index(ctx, expr)); break;
    }
}

void compiler::emit_clear_local_variable(const gsc::context_ptr& ctx, const gsc::name_ptr& expr)
{
    auto index = variable_stack_index(ctx, expr);

    if(index == 0)
    {
        emit_opcode(ctx, opcode::OP_ClearLocalVariableFieldCached0);
    }
    else
    {
        emit_opcode(ctx, opcode::OP_ClearLocalVariableFieldCached, variable_access_index(ctx, expr));
    }
}

void compiler::emit_create_local_vars(const gsc::context_ptr& ctx)
{
    auto count = ctx->local_vars.size() - ctx->local_vars_create_count;

    for(auto i = ctx->local_vars_create_count; i < count; i++)
    {
        auto data = utils::string::va("%d", ctx->local_vars_create_count);
        emit_opcode(ctx, opcode::OP_CreateLocalVariable, data);
        ctx->local_vars.at(i).init = true;
        ctx->local_vars_create_count++;
    }
}

void compiler::emit_remove_local_vars(const gsc::context_ptr& ctx)
{
    auto count = ctx->local_vars_create_count - ctx->local_vars_public_count;

    if(count > 0)
    {
        auto data = utils::string::va("%d", count);
        emit_opcode(ctx, opcode::OP_RemoveLocalVariables, data);
    }
}

void compiler::emit_object(const gsc::context_ptr& ctx, const gsc::expr_ptr& expr)
{
    // need revision used for clear variable
    switch(expr.as_node->type)
    {
        case gsc::node_t::data_level:
            emit_opcode(ctx, opcode::OP_GetLevelObject);
            break;
        case gsc::node_t::data_anim:
            emit_opcode(ctx, opcode::OP_GetAnimObject);
            break;
        case gsc::node_t::data_self:
            emit_opcode(ctx, opcode::OP_GetSelfObject);
            break;
        case gsc::node_t::data_name:
            emit_opcode(ctx, opcode::OP_EvalLocalVariableObjectCached, variable_access_index(ctx, expr.as_name));
            break;
        case gsc::node_t::expr_call:
            emit_expr_call(ctx, expr.as_call);
            emit_opcode(ctx, opcode::OP_CastFieldObject);
            break;
        // array ?
        // field ?
        default:
            throw gsc::comp_error(expr.as_node->loc, "unknown object type");
            break;
    }
}

void compiler::emit_animtree(const gsc::context_ptr& ctx, const gsc::animtree_ptr& animtree)
{
    if(animtrees_.size() == 0)
    {
        throw gsc::comp_error( animtree->loc, "trying to use animtree without specified using animtree");
    }

    auto& tree = animtrees_.back();

    if(tree.loaded)
    {
        emit_opcode(ctx, opcode::OP_GetAnimTree, "''");
    }
    else
    {
        emit_opcode(ctx, opcode::OP_GetAnimTree, tree.name);
        tree.loaded = true;
    }
}

void compiler::emit_animation(const gsc::context_ptr& ctx, const gsc::animation_ptr& animation)
{
    if(animtrees_.size() == 0)
    {
        throw gsc::comp_error(animation->loc, "trying to use animation without specified using animtree");
    }

    auto& tree = animtrees_.back();

    if(tree.loaded)
    {
        emit_opcode(ctx, opcode::OP_GetAnimation, { "''", animation->value });
    }
    else
    {
        emit_opcode(ctx, opcode::OP_GetAnimation, { tree.name, animation->value });
        tree.loaded = true;
    }
}

void compiler::emit_istring(const gsc::context_ptr& ctx, const gsc::istring_ptr& str)
{
    emit_opcode(ctx, opcode::OP_GetIString, str->value);
}

void compiler::emit_string(const gsc::context_ptr& ctx, const gsc::string_ptr& str)
{
    emit_opcode(ctx, opcode::OP_GetString, str->value);
}

void compiler::emit_vector(const gsc::context_ptr& ctx, const gsc::vector_ptr& vec)
{
    std::vector<std::string> data;

    bool expr = false;

    if(vec->x.as_node->type == gsc::node_t::data_integer)
        data.push_back(vec->x.as_integer->value);
    else if(vec->x.as_node->type == gsc::node_t::data_float)
        data.push_back(vec->x.as_float->value);
    else expr = true;

    if(vec->y.as_node->type == gsc::node_t::data_integer)
        data.push_back(vec->y.as_integer->value);
    else if(vec->y.as_node->type == gsc::node_t::data_float)
        data.push_back(vec->y.as_float->value);
    else expr = true;

    if(vec->z.as_node->type == gsc::node_t::data_integer)
        data.push_back(vec->z.as_integer->value);
    else if(vec->z.as_node->type == gsc::node_t::data_float)
        data.push_back(vec->z.as_float->value);
    else expr = true;

    if(!expr)
    {
         emit_opcode(ctx, opcode::OP_GetVector, data);
    }
    else
    {
        emit_expr(ctx, vec->z);
        emit_expr(ctx, vec->y);
        emit_expr(ctx, vec->x);
        emit_opcode(ctx, opcode::OP_vector);
    }
}

void compiler::emit_float(const gsc::context_ptr& ctx, const gsc::float_ptr& num)
{
    emit_opcode(ctx, opcode::OP_GetFloat, num->value);
}

void compiler::emit_integer(const gsc::context_ptr& ctx, const gsc::integer_ptr& num)
{
    auto value = std::atoi(num->value.data());

    if(value == 0)
    {
        emit_opcode(ctx, opcode::OP_GetZero);
    }
    else if(value > 0 && value < 256)
    {
        emit_opcode(ctx, opcode::OP_GetByte, num->value);
    }
    else if(value < 0 && value > -256)
    {
        emit_opcode(ctx, opcode::OP_GetNegByte, num->value.substr(1));
    }
    else if(value < 65536)
    {
        emit_opcode(ctx, opcode::OP_GetUnsignedShort, num->value);
    }
    else if(value < 0 && value > -65536)
    {
        emit_opcode(ctx, opcode::OP_GetNegUnsignedShort, num->value.substr(1));
    }
    else
    {
        emit_opcode(ctx, opcode::OP_GetInteger, num->value);
    } 
}

void compiler::emit_false(const gsc::context_ptr& ctx, const gsc::false_ptr& expr)
{
    emit_opcode(ctx, opcode::OP_GetZero);
}

void compiler::emit_true(const gsc::context_ptr& ctx, const gsc::true_ptr& expr)
{
    emit_opcode(ctx, opcode::OP_GetByte, "1");
}

void compiler::emit_opcode(const gsc::context_ptr& ctx, opcode op)
{
    function_->instructions.push_back(std::make_unique<gsc::instruction>());
    
    auto& inst = function_->instructions.back();
    inst->opcode = static_cast<std::uint8_t>(op);
    inst->size = opcode_size(std::uint8_t(op));
    inst->index = index_;

    index_ += inst->size;
}

void compiler::emit_opcode(const gsc::context_ptr& ctx, opcode op, const std::string& data)
{
    function_->instructions.push_back(std::make_unique<gsc::instruction>());
    
    auto& inst = function_->instructions.back();
    inst->opcode = static_cast<std::uint8_t>(op);
    inst->size = opcode_size(std::uint8_t(op));
    inst->index = index_;
    inst->data.push_back(data);

    index_ += inst->size;
}

void compiler::emit_opcode(const gsc::context_ptr& ctx, opcode op, const std::vector<std::string>& data)
{
    function_->instructions.push_back(std::make_unique<gsc::instruction>());
    
    auto& inst = function_->instructions.back();
    inst->opcode = static_cast<std::uint8_t>(op);
    inst->size = opcode_size(std::uint8_t(op));
    inst->index = index_;
    inst->data = data;

    index_ += inst->size;
}

void compiler::calc_local_vars(const gsc::context_ptr& ctx, const gsc::thread_ptr& thread)
{
    calc_local_vars_parameters(ctx, thread->params);
    calc_local_vars_stmt_list(ctx, thread->block);
}

void compiler::calc_local_vars_parameters(const gsc::context_ptr& ctx, const gsc::parameters_ptr& params)
{
    for(const auto& param : params->list)
    {
        register_variable(ctx, param->value);
    }
}

void compiler::calc_local_vars_stmt(const gsc::context_ptr& ctx, const gsc::stmt_ptr& stmt)
{
    switch (stmt.as_node->type)
    {
        case gsc::node_t::stmt_list:     calc_local_vars_stmt_list(ctx, stmt.as_list); break;
        case gsc::node_t::stmt_assign:   calc_local_vars_expr(ctx, stmt.as_assign->expr->lvalue); break;
        case gsc::node_t::stmt_waittill: calc_local_vars_waittill(ctx, stmt.as_waittill); break;
        case gsc::node_t::stmt_if:       calc_local_vars_if(ctx, stmt.as_if); break;
        case gsc::node_t::stmt_ifelse:   calc_local_vars_ifelse(ctx, stmt.as_ifelse); break;
        case gsc::node_t::stmt_while:    calc_local_vars_while(ctx, stmt.as_while); break;
        case gsc::node_t::stmt_for:      calc_local_vars_for(ctx, stmt.as_for); break;
        case gsc::node_t::stmt_foreach:  calc_local_vars_foreach(ctx, stmt.as_foreach); break;
        case gsc::node_t::stmt_switch:   calc_local_vars_switch(ctx, stmt.as_switch); break;
        default: break;
    }
}

void compiler::calc_local_vars_stmt_list(const gsc::context_ptr& ctx, const gsc::stmt_list_ptr& stmt)
{
    for (const auto& entry : stmt->stmts)
    {
        calc_local_vars_stmt(ctx, entry);
    }
}

void compiler::calc_local_vars_expr(const gsc::context_ptr& ctx, const gsc::expr_ptr& expr)
{
    if(expr.as_node->type == gsc::node_t::data_name)
    {
        register_variable(ctx, expr.as_name->value);
    }
    else if(expr.as_node->type == gsc::node_t::expr_array)
    {
        calc_local_vars_expr(ctx, expr.as_array->obj);
    }
}

void compiler::calc_local_vars_waittill(const gsc::context_ptr& ctx, const gsc::stmt_waittill_ptr& stmt)
{
    std::reverse(stmt->args->list.begin(), stmt->args->list.end());

    for(const auto& arg : stmt->args->list)
    {
        register_variable(ctx, arg.as_name->value);
    }

    std::reverse(stmt->args->list.begin(), stmt->args->list.end());
}

void compiler::calc_local_vars_if(const gsc::context_ptr& ctx, const gsc::stmt_if_ptr& stmt)
{
    auto if_ctx = std::make_unique<gsc::context>();

    ctx->copy(if_ctx);
    calc_local_vars_stmt(if_ctx, stmt->stmt);

    std::vector<gsc::context*> childs({ if_ctx.get() });
    
    ctx->merge(childs);

    stmt->ctx = std::move(if_ctx);
}

void compiler::calc_local_vars_ifelse(const gsc::context_ptr& ctx, const gsc::stmt_ifelse_ptr& stmt)
{
    auto if_ctx = std::make_unique<gsc::context>();
    auto else_ctx = std::make_unique<gsc::context>();

    ctx->copy(if_ctx);
    calc_local_vars_stmt(if_ctx, stmt->stmt_if);
    
    ctx->copy(else_ctx);
    calc_local_vars_stmt(else_ctx, stmt->stmt_else);
    
    std::vector<gsc::context*> childs({ if_ctx.get(), else_ctx.get() });

    ctx->append(childs);
    ctx->merge(childs);

    stmt->ctx_if = std::move(if_ctx);
    stmt->ctx_else = std::move(else_ctx);
}

void compiler::calc_local_vars_while(const gsc::context_ptr& ctx, const gsc::stmt_while_ptr& stmt)
{
    auto while_ctx = std::make_unique<gsc::context>();

    ctx->copy(while_ctx);
    calc_local_vars_stmt(while_ctx, stmt->stmt);

    std::vector<gsc::context*> childs({ while_ctx.get() });

    if(is_constant_condition(stmt->expr))
        ctx->append(childs);

    ctx->merge(childs);

    stmt->ctx = std::move(while_ctx);
}

void compiler::calc_local_vars_for(const gsc::context_ptr& ctx, const gsc::stmt_for_ptr& stmt)
{
    auto for_ctx = std::make_unique<gsc::context>();

    // TODO: modify this
    if(stmt->pre_expr.as_node->type == gsc::node_t::expr_assign_equal)
    {
        calc_local_vars_expr(ctx, stmt->pre_expr.as_assign->lvalue);
    }

    ctx->copy(for_ctx);
    calc_local_vars_stmt(for_ctx, stmt->stmt);

    std::vector<gsc::context*> childs({ for_ctx.get() });

    if(stmt->expr.as_node->type == gsc::node_t::null || is_constant_condition(stmt->expr))
        ctx->append(childs);

    ctx->merge(childs);

    stmt->ctx = std::move(for_ctx);
}

void compiler::calc_local_vars_foreach(const gsc::context_ptr& ctx, const gsc::stmt_foreach_ptr& stmt)
{
    auto foreach_ctx = std::make_unique<gsc::context>();

    label_idx_++;
    auto name = utils::string::va("temp_%d", label_idx_);
    stmt->array = std::make_unique<gsc::node_name>(name);
    register_variable(ctx, stmt->array->value);
    register_variable(ctx, stmt->element->value);

    if(!stmt->use_key)
    {
        label_idx_++;
        auto name2 = utils::string::va("temp_%d", label_idx_);
        stmt->key = std::make_unique<gsc::node_name>(name2);
    }

    register_variable(ctx, stmt->key->value);

    ctx->copy(foreach_ctx);
    calc_local_vars_stmt(foreach_ctx, stmt->stmt);

    std::vector<gsc::context*> childs({ foreach_ctx.get() });
    
    ctx->merge(childs);

    stmt->ctx = std::move(foreach_ctx);
}

void compiler::calc_local_vars_switch(const gsc::context_ptr& ctx, const gsc::stmt_switch_ptr& stmt)
{
    auto switch_ctx = std::make_unique<gsc::context>();

    ctx->copy(switch_ctx);
    calc_local_vars_stmt_list(switch_ctx, stmt->stmt);

    std::vector<gsc::context*> childs({ switch_ctx.get() });

    ctx->merge(childs);

    stmt->ctx = std::move(switch_ctx);
}

void compiler::register_variable(const gsc::context_ptr& ctx, const std::string& name)
{
    auto it = std::find_if(ctx->local_vars.begin(), ctx->local_vars.end(),
            [&](const gsc::local_var& v) { return v.name == name; });

    if(it == ctx->local_vars.end())
    {
        auto found = false;
        for(std::size_t i = 0; i < local_stack_.size(); i++)
        {
            if(local_stack_[i] == name)
            {
                ctx->local_vars.push_back({ name, static_cast<uint8_t>(i), false });
                found = true;
                break;
            }
        }

        if(!found)
        {
            ctx->local_vars.push_back({ name, stack_idx_, false });
            local_stack_.push_back(name);
            stack_idx_++;
        }
    }
}

void compiler::initialize_variable(const gsc::context_ptr& ctx, const gsc::name_ptr& name)
{
    for(std::uint32_t i = 0; i < ctx->local_vars.size(); i++)
    {
        if(ctx->local_vars[i].name == name->value)
        {
            if(!ctx->local_vars[i].init)
            {
                for(std::uint32_t j = 0; j < i; j++)
                {
                    if(!ctx->local_vars[j].init)
                    {
                        emit_opcode(ctx, opcode::OP_CreateLocalVariable, utils::string::va("%d", ctx->local_vars[j].create));
                        ctx->local_vars[j].init = true;
                        ctx->local_vars_create_count++;
                    }
                }
                ctx->local_vars[i].init = true;
                ctx->local_vars_create_count++;
                return;
            }
        }
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
}

void compiler::create_variable(const gsc::context_ptr& ctx, const gsc::name_ptr& name)
{
    for(std::size_t i = 0; i < ctx->local_vars.size(); i++)
    {
        auto& var = ctx->local_vars.at(i);
        if(var.name == name->value)
        {
            if(!var.init)
            {
                emit_opcode(ctx, opcode::OP_CreateLocalVariable, utils::string::va("%d", var.create));
                var.init = true;
                ctx->local_vars_create_count++;
            }
            return;
        }
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
}

auto compiler::variable_stack_index(const gsc::context_ptr& ctx, const gsc::name_ptr& name) -> std::uint8_t
{
    for(std::size_t i = 0; i < ctx->local_vars.size(); i++)
    {
        if(ctx->local_vars[i].name == name->value)
        {
            if(ctx->local_vars.at(i).init)
            {
                return ctx->local_vars_create_count - 1 - i;
            }

            throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not initialized.");
        }   
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
    return 0xFF;
}

auto compiler::variable_create_index(const gsc::context_ptr& ctx, const gsc::name_ptr& name) -> std::string
{
    for(std::size_t i = 0; i < ctx->local_vars.size(); i++)
    {
        if(ctx->local_vars[i].name == name->value)
            return utils::string::va("%d", ctx->local_vars[i].create);
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
    return "";
}

auto compiler::variable_access_index(const gsc::context_ptr& ctx, const gsc::name_ptr& name) -> std::string
{
    for(std::size_t i = 0; i < ctx->local_vars.size(); i++)
    {
        if(ctx->local_vars[i].name == name->value)
        {
            if(ctx->local_vars.at(i).init)
            {
                return utils::string::va("%d", ctx->local_vars_create_count - 1 - i);
            }

            throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not initialized.");
        }   
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
    return "";
}

auto compiler::variable_initialized(const gsc::context_ptr& ctx, const gsc::name_ptr& name) -> bool
{
    for(std::size_t i = 0; i < ctx->local_vars.size(); i++)
    {
        if(ctx->local_vars[i].name == name->value)
        {
            return ctx->local_vars.at(i).init;
        }
    }

    throw gsc::comp_error(name->loc, "local variable '" + name->value + "' not found.");
    return false;
}

auto compiler::is_local_call(const std::string& name) -> bool
{
    for(const auto& f : local_functions_)
    {
        if(f == name) return true;
    }

    return false;
}

auto compiler::is_builtin_call(const std::string& name) -> bool
{
    if(is_builtin_func(name)) return true;
    
    if(is_builtin_method(name)) return true;

    return false;
}

auto compiler::is_builtin_func(const std::string& name) -> bool
{
    return resolver::find_function(name);
}
auto compiler::is_builtin_method(const std::string& name) -> bool
{
    return resolver::find_method(name);
}

auto compiler::is_constant_condition(const gsc::expr_ptr& expr) -> bool
{
    switch(expr.as_node->type)
    {
        case gsc::node_t::data_true:
            return true;
        case gsc::node_t::data_false:
            throw gsc::comp_error(expr.as_node->loc, "condition can't be always false!");
        case gsc::node_t::data_integer:
        {
            auto num = std::stoi(expr.as_integer->value);
            if(num != 0)
                return true;
            else
                throw gsc::comp_error(expr.as_node->loc, "condition can't be always false!");
        }
        default:
            break;
    }

    return false;
}

auto compiler::create_label() -> std::string
{
    label_idx_++;
    auto name = utils::string::va("loc_%d", label_idx_);
    return name;
}

auto compiler::insert_label() -> std::string
{
    const auto itr = function_->labels.find(index_);

    if (itr != function_->labels.end())
    {
       return itr->second;
    }
    else
    {
        label_idx_++;
        auto name = utils::string::va("loc_%d", label_idx_);
        function_->labels.insert({index_, name});
        return name;
    }
}

void compiler::insert_label(const std::string& name)
{
    const auto itr = function_->labels.find(index_);

    if (itr != function_->labels.end())
    {
       // remap
       for(auto& inst : function_->instructions)
       {
           switch (opcode(inst->opcode))
           {
            case opcode::OP_JumpOnFalse:
            case opcode::OP_JumpOnTrue:
            case opcode::OP_JumpOnFalseExpr:
            case opcode::OP_JumpOnTrueExpr:
            case opcode::OP_jump:
            case opcode::OP_jumpback:
            case opcode::OP_switch:
                if(inst->data[0] == name)
                    inst->data[0] = itr->second;
                break;
            // end switch...
            default:
                break;
           }
       }
    }
    else
    {
        function_->labels.insert({index_, name});
    }
}

auto compiler::map_known_includes(const std::string& include) -> bool
{
    return false;
}

void compiler::print_debug_info()
{
    printf("----------------------------------");
    printf("files included: %zu", includes_.size());
    printf("animtrees used: %zu", animtrees_.size());
    printf("functions compiled: %zu",assembly_.size());

    for (auto& func : assembly_)
    {
        this->print_function(func);

        for (auto& inst : func->instructions)
        {
            const auto itr = func->labels.find(inst->index);

            if (itr != func->labels.end())
            {
                this->print_label(itr->second);
            }

            this->print_instruction(inst);
        }
    }

    printf("----------------------------------");
}

void compiler::print_opcodes(std::uint32_t index, std::uint32_t size)
{
    printf("    ");
}

void compiler::print_function(const gsc::function_ptr& func)
{
    printf("\n");
    printf("%s\n", func->name.data());
}

void compiler::print_instruction(const gsc::instruction_ptr& inst)
{
    switch (opcode(inst->opcode))
    {
    case opcode::OP_endswitch:
        this->print_opcodes(inst->index, 3);
        printf("%s", resolver::opcode_name(inst->opcode).data());
        printf(" %s\n", inst->data[0].data());
        {
            std::uint32_t totalcase = std::stoul(inst->data[0]);
            auto index = 0;
            for (auto casenum = 0u; casenum < totalcase; casenum++)
            {
                this->print_opcodes(inst->index, 7);
                if (inst->data[1 + index] == "case")
                {
                    printf("%s %s %s", inst->data[1 + index].data(), inst->data[1 + index + 1].data(), inst->data[1 + index + 2].data());
                    index += 3;
                }
                else if (inst->data[1 + index] == "default")
                {
                    printf("%s %s", inst->data[1 + index].data(), inst->data[1 + index + 1].data());
                    index += 2;
                }
                if (casenum != totalcase - 1)
                {
                    printf("\n");
                }
            }
        }
        break;
    default:
        this->print_opcodes(inst->index, inst->size);
        printf("%s", resolver::opcode_name(inst->opcode).data());
        for (auto& d : inst->data)
        {
            printf(" %s", d.data());
        }
        break;
    }

    printf("\n");
}

void compiler::print_label(const std::string& label)
{
    printf("  %s\n", label.data());
}

} // namespace xsk::gsc::h1
