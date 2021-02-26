// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc::s2
{

class resolver
{
public:
    static auto opcode_id(const std::string& name) -> std::uint8_t;
    static auto opcode_name(std::uint8_t id) -> std::string;

    static auto function_id(const std::string& name) -> std::uint16_t;
    static auto function_name(std::uint16_t id) -> std::string;

    static auto method_id(const std::string& name) -> std::uint16_t;
    static auto method_name(std::uint16_t id) -> std::string;

    static auto file_id(const std::string& name) -> std::uint16_t;
    static auto file_name(std::uint16_t id) -> std::string;

    static auto token_id(const std::string& name) -> std::uint16_t;
    static auto token_name(std::uint16_t id) -> std::string;

    static auto find_function(const std::string& name) -> bool;
    static auto find_method(const std::string& name) -> bool;
};

} // namespace xsk::gsc::s2
