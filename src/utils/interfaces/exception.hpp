// Copyright 2021 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#ifndef _GSC_EXCEPTION_HPP_
#define _GSC_EXCEPTION_HPP_

namespace gsc
{

class error : public std::runtime_error
{
public:
    error(const std::string& what) : std::runtime_error(what) { }
};

class asm_error : public std::runtime_error
{
public:
    asm_error(const std::string& what) : std::runtime_error("[assembler]: "s + what) { }
};

class disasm_error : public std::runtime_error
{
public:
    disasm_error(const std::string& what) : std::runtime_error("[disassembler]: "s + what) { }
};

class comp_error : public std::runtime_error
{
public:
    comp_error(gsc::location loc, const std::string& what)
        : std::runtime_error("[compiler]:"s + std::to_string(loc.begin.line) + ": " + what) { }
};

class decomp_error : public std::runtime_error
{
public:
    decomp_error(const std::string& what) : std::runtime_error("[decompiler]: "s + what) { }
};

} // namespace gsc

#endif // _GSC_EXCEPTION_HPP_
