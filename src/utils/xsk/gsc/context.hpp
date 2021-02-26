// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc
{

struct context;
using context_ptr = std::unique_ptr<context>;

struct local_var
{
    std::string name;
    std::uint8_t create;
    bool init;
};

struct context
{
    bool is_last;
    bool is_loop;
    bool is_switch;
    std::string loc_end;
    std::string loc_break;
    std::string loc_continue;

    std::vector<std::string> case_id;
    std::vector<std::string> case_loc;

    std::uint32_t local_vars_create_count;
    std::uint32_t local_vars_public_count;
    std::vector<local_var> local_vars;
    
	context() : is_last(false), is_loop(false), is_switch(false), 
        local_vars_create_count(0), local_vars_public_count(0) { }

    void transfer(const context_ptr& child)
    {
        child->loc_break = this->loc_break;
        child->loc_continue = this->loc_continue;

        for (std::uint32_t i = 0; i < child->local_vars_public_count || i < this->local_vars_create_count; i++ )
        {
            auto pos = child->find_variable(i, this->local_vars.at(i).name);

            if ( pos < 0 )
            {
                child->local_vars.insert(child->local_vars.begin() + i, this->local_vars.at(i));
            }
            else
            {
                auto& v = child->local_vars;
                if (pos > std::int32_t(i))
                    std::rotate(v.rend() - pos - 1, v.rend() - pos, v.rend() - i);
                else		
                    std::rotate(v.begin() + pos, v.begin() + pos + 1, v.begin() + i + 1);
                child->local_vars.at(i).init = this->local_vars.at(i).init;
            }
        }

        child->local_vars_create_count = this->local_vars_create_count;
    }

    void copy(const context_ptr& child)
    {
        child->local_vars = this->local_vars;
        child->local_vars_create_count = this->local_vars_create_count;
        child->local_vars_public_count = 0;
    }

    void append(const std::vector<context*>& childs)
    {
        bool glob = true;
        for (std::size_t i = 0; i < childs.at(0)->local_vars.size(); i++ )
        {
            glob = true;
            auto& var =  childs.at(0)->local_vars.at(i);

            if (this->find_variable(0, var.name) < 0)
            {
                for (std::size_t childIndex = 1; childIndex < childs.size(); childIndex++ )
                {
                   if (childs.at(childIndex)->find_variable(0, var.name) < 0)
                   {
                       glob = false;
                   }
                }
                if(glob)
                {
                    this->local_vars.push_back(var);
                }
            }
        }
    }

    void merge(const std::vector<context*>& childs)
    {
        for (std::size_t childIndex = 0; childIndex < childs.size(); childIndex++ )       
        {
            auto child = childs[childIndex];

            child->local_vars_public_count = this->local_vars.size();
            for (std::size_t i = 0; i < this->local_vars.size(); i++ )
            {
                auto& name = this->local_vars.at(i).name;

                auto pos = child->find_variable(i, name);
                if ( pos < 0 )
                {
                    child->local_vars.insert(child->local_vars.begin() + pos, this->local_vars.at(i));
                }
            }
        }
    }

    void init_from_child(const std::vector<context*>& childs)
    {
        auto localVarsCreateCount = childs[0]->local_vars_public_count;

        for (std::size_t childIndex = 1; childIndex < childs.size(); ++childIndex )
        {
            auto childBlock = childs[childIndex];
            if ( childBlock->local_vars_public_count < localVarsCreateCount )
                localVarsCreateCount = childBlock->local_vars_public_count;
        }

        this->local_vars_create_count = localVarsCreateCount;

        bool init = true;
        for (std::uint32_t i = 0; i < localVarsCreateCount; i++ )
        {
            init = true;
            if(!this->local_vars.at(i).init)
            {
                for (std::size_t childIndex = 0; childIndex < childs.size(); childIndex++ )
                {
                    auto childBlock = childs[childIndex];

                    if(!childBlock->local_vars.at(i).init)
                    {
                        init = false;
                    }
                }
                if (init) this->local_vars.at(i).init = true;
            }
        }
    }

    auto find_variable(std::size_t start, const std::string& name) -> std::int32_t
    {
        for (std::size_t i = start; i < local_vars.size(); ++i )
        {
            if ( local_vars.at(i).name == name )
                return i;
        }
        return -1;
    }
};

} // namespace xsk::gsc
