// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#ifndef _GSC_CONTEXT_HPP_
#define _GSC_CONTEXT_HPP_

namespace gsc
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

        for (auto i = 0; i < child->local_vars_public_count || i < this->local_vars_create_count; i++ )
        {
            auto pos = child->find_variable(i, this->local_vars.at(i).name);

            if ( pos < 0 )
            {
                child->local_vars.insert(child->local_vars.begin() + pos, this->local_vars.at(i));
            }
            else
            {
                child->local_vars.at(pos).init = this->local_vars.at(i).init;
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
        for (auto i = 0; i < childs.at(0)->local_vars.size(); ++i )
        {
            glob = true;
            auto& var =  childs.at(0)->local_vars.at(i);

            if (this->find_variable(0, var.name) < 0)
            {
                for (auto childIndex = 1; childIndex < childs.size(); childIndex++ )
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
        for (auto childIndex = 0; childIndex < childs.size(); childIndex++ )       
        {
            auto child = childs[childIndex];

            child->local_vars_public_count = this->local_vars.size();
            for (auto i = 0; i < this->local_vars.size(); i++ )
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

        for (auto childIndex = 1; childIndex < childs.size(); ++childIndex )
        {
            auto childBlock = childs[childIndex];
            if ( childBlock->local_vars_public_count < localVarsCreateCount )
                localVarsCreateCount = childBlock->local_vars_public_count;
        }

        this->local_vars_create_count = localVarsCreateCount;

        bool init = true;
        for (auto i = 0; i < localVarsCreateCount; i++ )
        {
            init = true;
            if(!this->local_vars.at(i).init)
            {
                for (auto childIndex = 0; childIndex < childs.size(); childIndex++ )
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

    auto find_variable(int start, const std::string& name) -> int
    {
        for (auto i = start; i < local_vars.size(); ++i )
        {
            if ( local_vars.at(i).name == name )
                return i;
        }
        return -1;
    }
};

} // namespace gsc

#endif // _GSC_CONTEXT_HPP_
