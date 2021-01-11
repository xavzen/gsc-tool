// A Bison parser, made by GNU Bison 3.7.3.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 37 "IW7.parser.ypp"

    #include "IW7.hpp"
	#include "compiler_parser.hpp"
	#include "compiler_lexer.hpp"
	IW7::parser::symbol_type IW7lex(yyscan_t yyscanner, std::uint32_t *location);

#line 46 "./IW7/compiler_parser.cpp"

// Take the name prefix into account.
#define yylex   IW7lex



#include "compiler_parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if IW7DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !IW7DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !IW7DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "IW7.parser.ypp"
namespace IW7 {
#line 129 "./IW7/compiler_parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, std::uint32_t *location_yyarg, gsc::script_ptr& astout_yyarg)
#if IW7DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      yyscanner (yyscanner_yyarg),
      location (location_yyarg),
      astout (astout_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_animref: // animref
        value.YY_MOVE_OR_COPY< gsc::animref_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animtree: // animtree
        value.YY_MOVE_OR_COPY< gsc::animtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.YY_MOVE_OR_COPY< gsc::block_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< gsc::constant_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.YY_MOVE_OR_COPY< gsc::definition_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.YY_MOVE_OR_COPY< gsc::expr_arguments_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.YY_MOVE_OR_COPY< gsc::expr_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
        value.YY_MOVE_OR_COPY< gsc::expr_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.YY_MOVE_OR_COPY< gsc::expr_call_type_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_assign: // for_assign
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_cmp: // expr_cmp
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.YY_MOVE_OR_COPY< gsc::expr_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_false: // data_false
        value.YY_MOVE_OR_COPY< gsc::false_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_filepath: // filepath
        value.YY_MOVE_OR_COPY< gsc::filepath_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_float: // data_float
        value.YY_MOVE_OR_COPY< gsc::float_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< gsc::identifier_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.YY_MOVE_OR_COPY< gsc::include_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_integer: // data_integer
        value.YY_MOVE_OR_COPY< gsc::integer_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_localized_string: // data_localized_string
        value.YY_MOVE_OR_COPY< gsc::localized_string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_function_ref: // expr_function_ref
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
      case symbol_kind::S_number: // number
      case symbol_kind::S_empty_array: // empty_array
      case symbol_kind::S_undefined: // undefined
      case symbol_kind::S_size: // size
      case symbol_kind::S_game: // game
      case symbol_kind::S_self: // self
      case symbol_kind::S_anim: // anim
      case symbol_kind::S_level: // level
        value.YY_MOVE_OR_COPY< gsc::node_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.YY_MOVE_OR_COPY< gsc::parameters_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script: // script
        value.YY_MOVE_OR_COPY< gsc::script_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.YY_MOVE_OR_COPY< gsc::stmt_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.YY_MOVE_OR_COPY< gsc::stmt_break_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.YY_MOVE_OR_COPY< gsc::stmt_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.YY_MOVE_OR_COPY< gsc::stmt_case_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.YY_MOVE_OR_COPY< gsc::stmt_continue_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.YY_MOVE_OR_COPY< gsc::stmt_default_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.YY_MOVE_OR_COPY< gsc::stmt_endon_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.YY_MOVE_OR_COPY< gsc::stmt_for_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.YY_MOVE_OR_COPY< gsc::stmt_foreach_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.YY_MOVE_OR_COPY< gsc::stmt_if_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.YY_MOVE_OR_COPY< gsc::stmt_ifelse_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.YY_MOVE_OR_COPY< gsc::stmt_notify_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< gsc::stmt_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.YY_MOVE_OR_COPY< gsc::stmt_return_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.YY_MOVE_OR_COPY< gsc::stmt_switch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.YY_MOVE_OR_COPY< gsc::stmt_wait_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.YY_MOVE_OR_COPY< gsc::stmt_waittill_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.YY_MOVE_OR_COPY< gsc::stmt_waittillframeend_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.YY_MOVE_OR_COPY< gsc::stmt_waittillmatch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.YY_MOVE_OR_COPY< gsc::stmt_while_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_string: // data_string
        value.YY_MOVE_OR_COPY< gsc::string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.YY_MOVE_OR_COPY< gsc::thread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_true: // data_true
        value.YY_MOVE_OR_COPY< gsc::true_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_animtree: // using_animtree
        value.YY_MOVE_OR_COPY< gsc::using_animtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FILEPATH: // FILEPATH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_ANIMREF: // ANIMREF
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_STRING_LOC: // STRING_LOC
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_animref: // animref
        value.move< gsc::animref_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animtree: // animtree
        value.move< gsc::animtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.move< gsc::block_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< gsc::constant_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.move< gsc::definition_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.move< gsc::expr_arguments_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< gsc::expr_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
        value.move< gsc::expr_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< gsc::expr_call_type_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_assign: // for_assign
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_cmp: // expr_cmp
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< gsc::expr_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_false: // data_false
        value.move< gsc::false_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_filepath: // filepath
        value.move< gsc::filepath_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_float: // data_float
        value.move< gsc::float_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< gsc::identifier_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.move< gsc::include_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_integer: // data_integer
        value.move< gsc::integer_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_localized_string: // data_localized_string
        value.move< gsc::localized_string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_function_ref: // expr_function_ref
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
      case symbol_kind::S_number: // number
      case symbol_kind::S_empty_array: // empty_array
      case symbol_kind::S_undefined: // undefined
      case symbol_kind::S_size: // size
      case symbol_kind::S_game: // game
      case symbol_kind::S_self: // self
      case symbol_kind::S_anim: // anim
      case symbol_kind::S_level: // level
        value.move< gsc::node_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< gsc::parameters_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script: // script
        value.move< gsc::script_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< gsc::stmt_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< gsc::stmt_break_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< gsc::stmt_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< gsc::stmt_case_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< gsc::stmt_continue_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< gsc::stmt_default_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< gsc::stmt_endon_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< gsc::stmt_for_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< gsc::stmt_foreach_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< gsc::stmt_if_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< gsc::stmt_ifelse_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< gsc::stmt_notify_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< gsc::stmt_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< gsc::stmt_return_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< gsc::stmt_switch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< gsc::stmt_wait_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< gsc::stmt_waittill_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< gsc::stmt_waittillframeend_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< gsc::stmt_waittillmatch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< gsc::stmt_while_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_string: // data_string
        value.move< gsc::string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.move< gsc::thread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_true: // data_true
        value.move< gsc::true_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_animtree: // using_animtree
        value.move< gsc::using_animtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FILEPATH: // FILEPATH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_ANIMREF: // ANIMREF
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_STRING_LOC: // STRING_LOC
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_INTEGER: // INTEGER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_animref: // animref
        value.copy< gsc::animref_ptr > (that.value);
        break;

      case symbol_kind::S_animtree: // animtree
        value.copy< gsc::animtree_ptr > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.copy< gsc::block_ptr > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.copy< gsc::constant_ptr > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.copy< gsc::definition_ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.copy< gsc::expr_arguments_ptr > (that.value);
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.copy< gsc::expr_assign_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
        value.copy< gsc::expr_call_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.copy< gsc::expr_call_type_ptr > (that.value);
        break;

      case symbol_kind::S_for_assign: // for_assign
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_cmp: // expr_cmp
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.copy< gsc::expr_ptr > (that.value);
        break;

      case symbol_kind::S_data_false: // data_false
        value.copy< gsc::false_ptr > (that.value);
        break;

      case symbol_kind::S_filepath: // filepath
        value.copy< gsc::filepath_ptr > (that.value);
        break;

      case symbol_kind::S_data_float: // data_float
        value.copy< gsc::float_ptr > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< gsc::identifier_ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.copy< gsc::include_ptr > (that.value);
        break;

      case symbol_kind::S_data_integer: // data_integer
        value.copy< gsc::integer_ptr > (that.value);
        break;

      case symbol_kind::S_data_localized_string: // data_localized_string
        value.copy< gsc::localized_string_ptr > (that.value);
        break;

      case symbol_kind::S_expr_function_ref: // expr_function_ref
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
      case symbol_kind::S_number: // number
      case symbol_kind::S_empty_array: // empty_array
      case symbol_kind::S_undefined: // undefined
      case symbol_kind::S_size: // size
      case symbol_kind::S_game: // game
      case symbol_kind::S_self: // self
      case symbol_kind::S_anim: // anim
      case symbol_kind::S_level: // level
        value.copy< gsc::node_ptr > (that.value);
        break;

      case symbol_kind::S_parameters: // parameters
        value.copy< gsc::parameters_ptr > (that.value);
        break;

      case symbol_kind::S_script: // script
        value.copy< gsc::script_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.copy< gsc::stmt_assign_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.copy< gsc::stmt_break_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.copy< gsc::stmt_call_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.copy< gsc::stmt_case_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.copy< gsc::stmt_continue_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.copy< gsc::stmt_default_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.copy< gsc::stmt_endon_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.copy< gsc::stmt_for_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.copy< gsc::stmt_foreach_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.copy< gsc::stmt_if_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.copy< gsc::stmt_ifelse_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.copy< gsc::stmt_notify_ptr > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< gsc::stmt_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.copy< gsc::stmt_return_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.copy< gsc::stmt_switch_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.copy< gsc::stmt_wait_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.copy< gsc::stmt_waittill_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.copy< gsc::stmt_waittillframeend_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.copy< gsc::stmt_waittillmatch_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.copy< gsc::stmt_while_ptr > (that.value);
        break;

      case symbol_kind::S_data_string: // data_string
        value.copy< gsc::string_ptr > (that.value);
        break;

      case symbol_kind::S_thread: // thread
        value.copy< gsc::thread_ptr > (that.value);
        break;

      case symbol_kind::S_data_true: // data_true
        value.copy< gsc::true_ptr > (that.value);
        break;

      case symbol_kind::S_using_animtree: // using_animtree
        value.copy< gsc::using_animtree_ptr > (that.value);
        break;

      case symbol_kind::S_FILEPATH: // FILEPATH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_ANIMREF: // ANIMREF
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_STRING_LOC: // STRING_LOC
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_animref: // animref
        value.move< gsc::animref_ptr > (that.value);
        break;

      case symbol_kind::S_animtree: // animtree
        value.move< gsc::animtree_ptr > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.move< gsc::block_ptr > (that.value);
        break;

      case symbol_kind::S_constant: // constant
        value.move< gsc::constant_ptr > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.move< gsc::definition_ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.move< gsc::expr_arguments_ptr > (that.value);
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< gsc::expr_assign_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
        value.move< gsc::expr_call_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< gsc::expr_call_type_ptr > (that.value);
        break;

      case symbol_kind::S_for_assign: // for_assign
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_cmp: // expr_cmp
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< gsc::expr_ptr > (that.value);
        break;

      case symbol_kind::S_data_false: // data_false
        value.move< gsc::false_ptr > (that.value);
        break;

      case symbol_kind::S_filepath: // filepath
        value.move< gsc::filepath_ptr > (that.value);
        break;

      case symbol_kind::S_data_float: // data_float
        value.move< gsc::float_ptr > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< gsc::identifier_ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.move< gsc::include_ptr > (that.value);
        break;

      case symbol_kind::S_data_integer: // data_integer
        value.move< gsc::integer_ptr > (that.value);
        break;

      case symbol_kind::S_data_localized_string: // data_localized_string
        value.move< gsc::localized_string_ptr > (that.value);
        break;

      case symbol_kind::S_expr_function_ref: // expr_function_ref
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
      case symbol_kind::S_number: // number
      case symbol_kind::S_empty_array: // empty_array
      case symbol_kind::S_undefined: // undefined
      case symbol_kind::S_size: // size
      case symbol_kind::S_game: // game
      case symbol_kind::S_self: // self
      case symbol_kind::S_anim: // anim
      case symbol_kind::S_level: // level
        value.move< gsc::node_ptr > (that.value);
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< gsc::parameters_ptr > (that.value);
        break;

      case symbol_kind::S_script: // script
        value.move< gsc::script_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< gsc::stmt_assign_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< gsc::stmt_break_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< gsc::stmt_call_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< gsc::stmt_case_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< gsc::stmt_continue_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< gsc::stmt_default_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< gsc::stmt_endon_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< gsc::stmt_for_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< gsc::stmt_foreach_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< gsc::stmt_if_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< gsc::stmt_ifelse_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< gsc::stmt_notify_ptr > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< gsc::stmt_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< gsc::stmt_return_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< gsc::stmt_switch_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< gsc::stmt_wait_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< gsc::stmt_waittill_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< gsc::stmt_waittillframeend_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< gsc::stmt_waittillmatch_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< gsc::stmt_while_ptr > (that.value);
        break;

      case symbol_kind::S_data_string: // data_string
        value.move< gsc::string_ptr > (that.value);
        break;

      case symbol_kind::S_thread: // thread
        value.move< gsc::thread_ptr > (that.value);
        break;

      case symbol_kind::S_data_true: // data_true
        value.move< gsc::true_ptr > (that.value);
        break;

      case symbol_kind::S_using_animtree: // using_animtree
        value.move< gsc::using_animtree_ptr > (that.value);
        break;

      case symbol_kind::S_FILEPATH: // FILEPATH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_ANIMREF: // ANIMREF
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_STRING_LOC: // STRING_LOC
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_INTEGER: // INTEGER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if IW7DEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if IW7DEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // IW7DEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    /// Discard the LAC context in case there still is one left from a
    /// previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (yyscanner, location));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_animref: // animref
        yylhs.value.emplace< gsc::animref_ptr > ();
        break;

      case symbol_kind::S_animtree: // animtree
        yylhs.value.emplace< gsc::animtree_ptr > ();
        break;

      case symbol_kind::S_block: // block
        yylhs.value.emplace< gsc::block_ptr > ();
        break;

      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< gsc::constant_ptr > ();
        break;

      case symbol_kind::S_definition: // definition
        yylhs.value.emplace< gsc::definition_ptr > ();
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        yylhs.value.emplace< gsc::expr_arguments_ptr > ();
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        yylhs.value.emplace< gsc::expr_assign_ptr > ();
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
        yylhs.value.emplace< gsc::expr_call_ptr > ();
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        yylhs.value.emplace< gsc::expr_call_type_ptr > ();
        break;

      case symbol_kind::S_for_assign: // for_assign
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_cmp: // expr_cmp
      case symbol_kind::S_expr_ternary: // expr_ternary
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        yylhs.value.emplace< gsc::expr_ptr > ();
        break;

      case symbol_kind::S_data_false: // data_false
        yylhs.value.emplace< gsc::false_ptr > ();
        break;

      case symbol_kind::S_filepath: // filepath
        yylhs.value.emplace< gsc::filepath_ptr > ();
        break;

      case symbol_kind::S_data_float: // data_float
        yylhs.value.emplace< gsc::float_ptr > ();
        break;

      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< gsc::identifier_ptr > ();
        break;

      case symbol_kind::S_include: // include
        yylhs.value.emplace< gsc::include_ptr > ();
        break;

      case symbol_kind::S_data_integer: // data_integer
        yylhs.value.emplace< gsc::integer_ptr > ();
        break;

      case symbol_kind::S_data_localized_string: // data_localized_string
        yylhs.value.emplace< gsc::localized_string_ptr > ();
        break;

      case symbol_kind::S_expr_function_ref: // expr_function_ref
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
      case symbol_kind::S_number: // number
      case symbol_kind::S_empty_array: // empty_array
      case symbol_kind::S_undefined: // undefined
      case symbol_kind::S_size: // size
      case symbol_kind::S_game: // game
      case symbol_kind::S_self: // self
      case symbol_kind::S_anim: // anim
      case symbol_kind::S_level: // level
        yylhs.value.emplace< gsc::node_ptr > ();
        break;

      case symbol_kind::S_parameters: // parameters
        yylhs.value.emplace< gsc::parameters_ptr > ();
        break;

      case symbol_kind::S_script: // script
        yylhs.value.emplace< gsc::script_ptr > ();
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        yylhs.value.emplace< gsc::stmt_assign_ptr > ();
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        yylhs.value.emplace< gsc::stmt_break_ptr > ();
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        yylhs.value.emplace< gsc::stmt_call_ptr > ();
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        yylhs.value.emplace< gsc::stmt_case_ptr > ();
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        yylhs.value.emplace< gsc::stmt_continue_ptr > ();
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        yylhs.value.emplace< gsc::stmt_default_ptr > ();
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        yylhs.value.emplace< gsc::stmt_endon_ptr > ();
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        yylhs.value.emplace< gsc::stmt_for_ptr > ();
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        yylhs.value.emplace< gsc::stmt_foreach_ptr > ();
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        yylhs.value.emplace< gsc::stmt_if_ptr > ();
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        yylhs.value.emplace< gsc::stmt_ifelse_ptr > ();
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        yylhs.value.emplace< gsc::stmt_notify_ptr > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< gsc::stmt_ptr > ();
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        yylhs.value.emplace< gsc::stmt_return_ptr > ();
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        yylhs.value.emplace< gsc::stmt_switch_ptr > ();
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        yylhs.value.emplace< gsc::stmt_wait_ptr > ();
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        yylhs.value.emplace< gsc::stmt_waittill_ptr > ();
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        yylhs.value.emplace< gsc::stmt_waittillframeend_ptr > ();
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        yylhs.value.emplace< gsc::stmt_waittillmatch_ptr > ();
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        yylhs.value.emplace< gsc::stmt_while_ptr > ();
        break;

      case symbol_kind::S_data_string: // data_string
        yylhs.value.emplace< gsc::string_ptr > ();
        break;

      case symbol_kind::S_thread: // thread
        yylhs.value.emplace< gsc::thread_ptr > ();
        break;

      case symbol_kind::S_data_true: // data_true
        yylhs.value.emplace< gsc::true_ptr > ();
        break;

      case symbol_kind::S_using_animtree: // using_animtree
        yylhs.value.emplace< gsc::using_animtree_ptr > ();
        break;

      case symbol_kind::S_FILEPATH: // FILEPATH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_ANIMREF: // ANIMREF
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_STRING_LOC: // STRING_LOC
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: script
#line 121 "IW7.parser.ypp"
                 { astout = std::move(yystack_[0].value.as < gsc::script_ptr > ()); }
#line 1569 "./IW7/compiler_parser.cpp"
    break;

  case 3: // root: %empty
#line 122 "IW7.parser.ypp"
                 { astout = std::make_unique<gsc::node_script>(); }
#line 1575 "./IW7/compiler_parser.cpp"
    break;

  case 4: // script: script include
#line 127 "IW7.parser.ypp"
                { yylhs.value.as < gsc::script_ptr > () = std::move(yystack_[1].value.as < gsc::script_ptr > ()); yylhs.value.as < gsc::script_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1581 "./IW7/compiler_parser.cpp"
    break;

  case 5: // script: script definition
#line 129 "IW7.parser.ypp"
                { yylhs.value.as < gsc::script_ptr > () = std::move(yystack_[1].value.as < gsc::script_ptr > ()); yylhs.value.as < gsc::script_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::definition_ptr > ())); }
#line 1587 "./IW7/compiler_parser.cpp"
    break;

  case 6: // script: include
#line 131 "IW7.parser.ypp"
                { yylhs.value.as < gsc::script_ptr > () = std::make_unique<gsc::node_script>(std::to_string(*location)); yylhs.value.as < gsc::script_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ()));}
#line 1593 "./IW7/compiler_parser.cpp"
    break;

  case 7: // script: definition
#line 133 "IW7.parser.ypp"
                { yylhs.value.as < gsc::script_ptr > () = std::make_unique<gsc::node_script>(std::to_string(*location)); yylhs.value.as < gsc::script_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::definition_ptr > ()));}
#line 1599 "./IW7/compiler_parser.cpp"
    break;

  case 8: // include: INCLUDE filepath SEMICOLON
#line 138 "IW7.parser.ypp"
                { yylhs.value.as < gsc::include_ptr > () = std::make_unique<gsc::node_include>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::filepath_ptr > ())); }
#line 1605 "./IW7/compiler_parser.cpp"
    break;

  case 9: // definition: using_animtree
#line 142 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::definition_ptr > ().as_using_animtree = std::move(yystack_[0].value.as < gsc::using_animtree_ptr > ()); }
#line 1611 "./IW7/compiler_parser.cpp"
    break;

  case 10: // definition: constant
#line 143 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::definition_ptr > ().as_constant = std::move(yystack_[0].value.as < gsc::constant_ptr > ()); }
#line 1617 "./IW7/compiler_parser.cpp"
    break;

  case 11: // definition: thread
#line 144 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::definition_ptr > ().as_thread = std::move(yystack_[0].value.as < gsc::thread_ptr > ()); }
#line 1623 "./IW7/compiler_parser.cpp"
    break;

  case 12: // using_animtree: USING_ANIMTREE LPAREN data_string RPAREN SEMICOLON
#line 149 "IW7.parser.ypp"
                { yylhs.value.as < gsc::using_animtree_ptr > () = std::make_unique<gsc::node_using_animtree>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::string_ptr > ())); }
#line 1629 "./IW7/compiler_parser.cpp"
    break;

  case 13: // constant: identifier ASSIGN expr SEMICOLON
#line 154 "IW7.parser.ypp"
                { yylhs.value.as < gsc::constant_ptr > () = std::make_unique<gsc::node_constant>(std::to_string(*location), std::move(yystack_[3].value.as < gsc::identifier_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1635 "./IW7/compiler_parser.cpp"
    break;

  case 14: // thread: identifier LPAREN parameters RPAREN LBRACE block RBRACE
#line 159 "IW7.parser.ypp"
                { yylhs.value.as < gsc::thread_ptr > () = std::make_unique<gsc::node_thread>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::identifier_ptr > ()), std::move(yystack_[4].value.as < gsc::parameters_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1641 "./IW7/compiler_parser.cpp"
    break;

  case 15: // parameters: parameters COMMA identifier
#line 164 "IW7.parser.ypp"
                { yylhs.value.as < gsc::parameters_ptr > () = std::move(yystack_[2].value.as < gsc::parameters_ptr > ()); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::identifier_ptr > ())); }
#line 1647 "./IW7/compiler_parser.cpp"
    break;

  case 16: // parameters: identifier
#line 166 "IW7.parser.ypp"
                { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(std::to_string(*location)); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::identifier_ptr > ())); }
#line 1653 "./IW7/compiler_parser.cpp"
    break;

  case 17: // parameters: %empty
#line 168 "IW7.parser.ypp"
                { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(std::to_string(*location)); }
#line 1659 "./IW7/compiler_parser.cpp"
    break;

  case 18: // block: block stmt
#line 173 "IW7.parser.ypp"
                { yylhs.value.as < gsc::block_ptr > () = std::move(yystack_[1].value.as < gsc::block_ptr > ()); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1665 "./IW7/compiler_parser.cpp"
    break;

  case 19: // block: stmt
#line 175 "IW7.parser.ypp"
                { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(std::to_string(*location)); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1671 "./IW7/compiler_parser.cpp"
    break;

  case 20: // block: %empty
#line 177 "IW7.parser.ypp"
                { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(std::to_string(*location)); }
#line 1677 "./IW7/compiler_parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 181 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_call = std::move(yystack_[0].value.as < gsc::stmt_call_ptr > ()); }
#line 1683 "./IW7/compiler_parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 182 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_assign = std::move(yystack_[0].value.as < gsc::stmt_assign_ptr > ()); }
#line 1689 "./IW7/compiler_parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 183 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_endon = std::move(yystack_[0].value.as < gsc::stmt_endon_ptr > ()); }
#line 1695 "./IW7/compiler_parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 184 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_notify = std::move(yystack_[0].value.as < gsc::stmt_notify_ptr > ()); }
#line 1701 "./IW7/compiler_parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 185 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_wait = std::move(yystack_[0].value.as < gsc::stmt_wait_ptr > ()); }
#line 1707 "./IW7/compiler_parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 186 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_waittill = std::move(yystack_[0].value.as < gsc::stmt_waittill_ptr > ()); }
#line 1713 "./IW7/compiler_parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 187 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::stmt_ptr > ().as_waittillmatch = std::move(yystack_[0].value.as < gsc::stmt_waittillmatch_ptr > ()); }
#line 1719 "./IW7/compiler_parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 188 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::stmt_ptr > ().as_waittillframeend = std::move(yystack_[0].value.as < gsc::stmt_waittillframeend_ptr > ()); }
#line 1725 "./IW7/compiler_parser.cpp"
    break;

  case 29: // stmt: stmt_if
#line 189 "IW7.parser.ypp"
                                                                                        { yylhs.value.as < gsc::stmt_ptr > ().as_if = std::move(yystack_[0].value.as < gsc::stmt_if_ptr > ()); }
#line 1731 "./IW7/compiler_parser.cpp"
    break;

  case 30: // stmt: stmt_ifelse
#line 190 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_ifelse = std::move(yystack_[0].value.as < gsc::stmt_ifelse_ptr > ()); }
#line 1737 "./IW7/compiler_parser.cpp"
    break;

  case 31: // stmt: stmt_while
#line 191 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_while = std::move(yystack_[0].value.as < gsc::stmt_while_ptr > ()); }
#line 1743 "./IW7/compiler_parser.cpp"
    break;

  case 32: // stmt: stmt_for
#line 192 "IW7.parser.ypp"
                                                                                        { yylhs.value.as < gsc::stmt_ptr > ().as_for = std::move(yystack_[0].value.as < gsc::stmt_for_ptr > ()); }
#line 1749 "./IW7/compiler_parser.cpp"
    break;

  case 33: // stmt: stmt_foreach
#line 193 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_foreach = std::move(yystack_[0].value.as < gsc::stmt_foreach_ptr > ()); }
#line 1755 "./IW7/compiler_parser.cpp"
    break;

  case 34: // stmt: stmt_switch
#line 194 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_switch = std::move(yystack_[0].value.as < gsc::stmt_switch_ptr > ()); }
#line 1761 "./IW7/compiler_parser.cpp"
    break;

  case 35: // stmt: stmt_case
#line 195 "IW7.parser.ypp"
                                                                                        { yylhs.value.as < gsc::stmt_ptr > ().as_case = std::move(yystack_[0].value.as < gsc::stmt_case_ptr > ()); }
#line 1767 "./IW7/compiler_parser.cpp"
    break;

  case 36: // stmt: stmt_default
#line 196 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_default = std::move(yystack_[0].value.as < gsc::stmt_default_ptr > ()); }
#line 1773 "./IW7/compiler_parser.cpp"
    break;

  case 37: // stmt: stmt_break
#line 197 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_break = std::move(yystack_[0].value.as < gsc::stmt_break_ptr > ()); }
#line 1779 "./IW7/compiler_parser.cpp"
    break;

  case 38: // stmt: stmt_continue
#line 198 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_continue = std::move(yystack_[0].value.as < gsc::stmt_continue_ptr > ()); }
#line 1785 "./IW7/compiler_parser.cpp"
    break;

  case 39: // stmt: stmt_return
#line 199 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::stmt_ptr > ().as_return = std::move(yystack_[0].value.as < gsc::stmt_return_ptr > ()); }
#line 1791 "./IW7/compiler_parser.cpp"
    break;

  case 40: // stmt_call: expr_call SEMICOLON
#line 204 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1797 "./IW7/compiler_parser.cpp"
    break;

  case 41: // stmt_call: expr_call_thread SEMICOLON
#line 206 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1803 "./IW7/compiler_parser.cpp"
    break;

  case 42: // stmt_assign: expr_assign SEMICOLON
#line 211 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_assign_ptr > () = std::make_unique<gsc::node_stmt_assign>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::expr_assign_ptr > ())); }
#line 1809 "./IW7/compiler_parser.cpp"
    break;

  case 43: // stmt_endon: object ENDON LPAREN expr RPAREN SEMICOLON
#line 216 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_endon_ptr > () = std::make_unique<gsc::node_stmt_endon>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1815 "./IW7/compiler_parser.cpp"
    break;

  case 44: // stmt_notify: object NOTIFY LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 221 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(std::to_string(*location), std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1821 "./IW7/compiler_parser.cpp"
    break;

  case 45: // stmt_notify: object NOTIFY LPAREN expr RPAREN SEMICOLON
#line 223 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(std::to_string(*location))); }
#line 1827 "./IW7/compiler_parser.cpp"
    break;

  case 46: // stmt_wait: WAIT LPAREN expr RPAREN SEMICOLON
#line 228 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1833 "./IW7/compiler_parser.cpp"
    break;

  case 47: // stmt_wait: WAIT number SEMICOLON
#line 230 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 1839 "./IW7/compiler_parser.cpp"
    break;

  case 48: // stmt_waittill: object WAITTILL LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 235 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(std::to_string(*location), std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1845 "./IW7/compiler_parser.cpp"
    break;

  case 49: // stmt_waittill: object WAITTILL LPAREN expr RPAREN SEMICOLON
#line 237 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(std::to_string(*location))); }
#line 1851 "./IW7/compiler_parser.cpp"
    break;

  case 50: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr RPAREN SEMICOLON
#line 242 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(std::to_string(*location), std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1857 "./IW7/compiler_parser.cpp"
    break;

  case 51: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 247 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(std::to_string(*location)); }
#line 1863 "./IW7/compiler_parser.cpp"
    break;

  case 52: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 252 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1869 "./IW7/compiler_parser.cpp"
    break;

  case 53: // stmt_if: IF LPAREN expr RPAREN stmt
#line 254 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 1878 "./IW7/compiler_parser.cpp"
    break;

  case 54: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 262 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(std::to_string(*location), std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1884 "./IW7/compiler_parser.cpp"
    break;

  case 55: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 264 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1893 "./IW7/compiler_parser.cpp"
    break;

  case 56: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 269 "IW7.parser.ypp"
                { 
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk)); }
#line 1902 "./IW7/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 274 "IW7.parser.ypp"
                {
			auto blk1 = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
			auto blk2 = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2)); }
#line 1913 "./IW7/compiler_parser.cpp"
    break;

  case 58: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 284 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1919 "./IW7/compiler_parser.cpp"
    break;

  case 59: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 286 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 1928 "./IW7/compiler_parser.cpp"
    break;

  case 60: // stmt_for: FOR LPAREN for_assign SEMICOLON for_cond SEMICOLON for_assign RPAREN LBRACE block RBRACE
#line 294 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(std::to_string(*location), std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1934 "./IW7/compiler_parser.cpp"
    break;

  case 61: // stmt_for: FOR LPAREN for_assign SEMICOLON for_cond SEMICOLON for_assign RPAREN stmt
#line 296 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
		}
#line 1944 "./IW7/compiler_parser.cpp"
    break;

  case 62: // stmt_foreach: FOREACH LPAREN identifier IN expr RPAREN LBRACE block RBRACE
#line 305 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::identifier_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1950 "./IW7/compiler_parser.cpp"
    break;

  case 63: // stmt_foreach: FOREACH LPAREN identifier COMMA identifier IN expr RPAREN LBRACE block RBRACE
#line 307 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(std::to_string(*location), std::move(yystack_[8].value.as < gsc::identifier_ptr > ()), std::move(yystack_[6].value.as < gsc::identifier_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1956 "./IW7/compiler_parser.cpp"
    break;

  case 64: // stmt_foreach: FOREACH LPAREN identifier IN expr RPAREN stmt
#line 309 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::identifier_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
		}
#line 1966 "./IW7/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN identifier COMMA identifier IN expr RPAREN stmt
#line 315 "IW7.parser.ypp"
                {
			auto blk = std::make_unique<gsc::node_block>(std::to_string(*location));
			blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
			yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(std::to_string(*location), std::move(yystack_[6].value.as < gsc::identifier_ptr > ()), std::move(yystack_[4].value.as < gsc::identifier_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
		}
#line 1976 "./IW7/compiler_parser.cpp"
    break;

  case 66: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 324 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1982 "./IW7/compiler_parser.cpp"
    break;

  case 67: // stmt_case: CASE data_integer COLON
#line 329 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(std::to_string(*location), gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 1988 "./IW7/compiler_parser.cpp"
    break;

  case 68: // stmt_case: CASE data_string COLON
#line 331 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(std::to_string(*location), gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 1994 "./IW7/compiler_parser.cpp"
    break;

  case 69: // stmt_default: DEFAULT COLON
#line 336 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(std::to_string(*location)); }
#line 2000 "./IW7/compiler_parser.cpp"
    break;

  case 70: // stmt_break: BREAK SEMICOLON
#line 341 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(std::to_string(*location)); }
#line 2006 "./IW7/compiler_parser.cpp"
    break;

  case 71: // stmt_continue: CONTINUE SEMICOLON
#line 345 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(std::to_string(*location)); }
#line 2012 "./IW7/compiler_parser.cpp"
    break;

  case 72: // stmt_return: RETURN expr SEMICOLON
#line 350 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2018 "./IW7/compiler_parser.cpp"
    break;

  case 73: // stmt_return: RETURN SEMICOLON
#line 352 "IW7.parser.ypp"
                { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(std::to_string(*location), std::make_unique<gsc::node>()); }
#line 2024 "./IW7/compiler_parser.cpp"
    break;

  case 74: // for_assign: expr_assign
#line 356 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2030 "./IW7/compiler_parser.cpp"
    break;

  case 75: // for_assign: %empty
#line 357 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2036 "./IW7/compiler_parser.cpp"
    break;

  case 76: // for_cond: expr_cmp
#line 361 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2042 "./IW7/compiler_parser.cpp"
    break;

  case 77: // for_cond: %empty
#line 362 "IW7.parser.ypp"
                                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2048 "./IW7/compiler_parser.cpp"
    break;

  case 78: // expr: expr_cmp
#line 366 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2054 "./IW7/compiler_parser.cpp"
    break;

  case 79: // expr: expr_ternary
#line 367 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2060 "./IW7/compiler_parser.cpp"
    break;

  case 80: // expr: expr_binary
#line 368 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2066 "./IW7/compiler_parser.cpp"
    break;

  case 81: // expr: expr_primitive
#line 369 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2072 "./IW7/compiler_parser.cpp"
    break;

  case 82: // expr_assign: object INCREMENT
#line 373 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2078 "./IW7/compiler_parser.cpp"
    break;

  case 83: // expr_assign: object DECREMENT
#line 374 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2084 "./IW7/compiler_parser.cpp"
    break;

  case 84: // expr_assign: object ASSIGN expr
#line 375 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2090 "./IW7/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 376 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2096 "./IW7/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 377 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2102 "./IW7/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 378 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2108 "./IW7/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_LSHIFT expr
#line 379 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2114 "./IW7/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_RSHIFT expr
#line 380 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2120 "./IW7/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_ADD expr
#line 381 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2126 "./IW7/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_SUB expr
#line 382 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2132 "./IW7/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_MULT expr
#line 383 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2138 "./IW7/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_DIV expr
#line 384 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2144 "./IW7/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_MOD expr
#line 385 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2150 "./IW7/compiler_parser.cpp"
    break;

  case 95: // expr_cmp: expr OR expr
#line 389 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2156 "./IW7/compiler_parser.cpp"
    break;

  case 96: // expr_cmp: expr AND expr
#line 390 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2162 "./IW7/compiler_parser.cpp"
    break;

  case 97: // expr_cmp: expr EQUALITY expr
#line 391 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2168 "./IW7/compiler_parser.cpp"
    break;

  case 98: // expr_cmp: expr INEQUALITY expr
#line 392 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2174 "./IW7/compiler_parser.cpp"
    break;

  case 99: // expr_cmp: expr LESS_EQUAL expr
#line 393 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2180 "./IW7/compiler_parser.cpp"
    break;

  case 100: // expr_cmp: expr GREATER_EQUAL expr
#line 394 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2186 "./IW7/compiler_parser.cpp"
    break;

  case 101: // expr_cmp: expr LESS expr
#line 395 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2192 "./IW7/compiler_parser.cpp"
    break;

  case 102: // expr_cmp: expr GREATER expr
#line 396 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2198 "./IW7/compiler_parser.cpp"
    break;

  case 103: // expr_ternary: expr_cmp QMARK expr COLON expr
#line 400 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_ternary>(std::to_string(*location), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2204 "./IW7/compiler_parser.cpp"
    break;

  case 104: // expr_binary: expr BITWISE_OR expr
#line 404 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2210 "./IW7/compiler_parser.cpp"
    break;

  case 105: // expr_binary: expr BITWISE_AND expr
#line 405 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2216 "./IW7/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr BITWISE_EXOR expr
#line 406 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2222 "./IW7/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr LSHIFT expr
#line 407 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2228 "./IW7/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr RSHIFT expr
#line 408 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2234 "./IW7/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr ADD expr
#line 409 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2240 "./IW7/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr SUB expr
#line 410 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2246 "./IW7/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr MULT expr
#line 411 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2252 "./IW7/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr DIV expr
#line 412 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2258 "./IW7/compiler_parser.cpp"
    break;

  case 113: // expr_binary: expr MOD expr
#line 413 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2264 "./IW7/compiler_parser.cpp"
    break;

  case 114: // expr_primitive: LPAREN expr RPAREN
#line 417 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2270 "./IW7/compiler_parser.cpp"
    break;

  case 115: // expr_primitive: COMPLEMENT expr
#line 418 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(std::to_string(*location), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2276 "./IW7/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: NOT expr
#line 419 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(std::to_string(*location), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2282 "./IW7/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: expr_call
#line 420 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2288 "./IW7/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: expr_call_thread
#line 421 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2294 "./IW7/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_function_ref
#line 422 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2300 "./IW7/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_array
#line 423 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2306 "./IW7/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_field
#line 424 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2312 "./IW7/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_size
#line 425 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2318 "./IW7/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_vector
#line 426 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2324 "./IW7/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_add_array
#line 427 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2330 "./IW7/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: vector
#line 428 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2336 "./IW7/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: number
#line 429 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2342 "./IW7/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: data_localized_string
#line 430 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::localized_string_ptr > ()); }
#line 2348 "./IW7/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: data_string
#line 431 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2354 "./IW7/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: data_false
#line 432 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2360 "./IW7/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: data_true
#line 433 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2366 "./IW7/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: animref
#line 434 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animref_ptr > ()); }
#line 2372 "./IW7/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: animtree
#line 435 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2378 "./IW7/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: identifier
#line 436 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::identifier_ptr > ()); }
#line 2384 "./IW7/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: empty_array
#line 437 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2390 "./IW7/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: undefined
#line 438 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2396 "./IW7/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: game
#line 439 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2402 "./IW7/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: self
#line 440 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2408 "./IW7/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: anim
#line 441 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2414 "./IW7/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: level
#line 442 "IW7.parser.ypp"
                                                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2420 "./IW7/compiler_parser.cpp"
    break;

  case 140: // expr_call: expr_call_function
#line 446 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2426 "./IW7/compiler_parser.cpp"
    break;

  case 141: // expr_call: expr_call_pointer
#line 447 "IW7.parser.ypp"
                                                                { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2432 "./IW7/compiler_parser.cpp"
    break;

  case 142: // expr_call: object expr_call_function
#line 448 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2438 "./IW7/compiler_parser.cpp"
    break;

  case 143: // expr_call: object expr_call_pointer
#line 449 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2444 "./IW7/compiler_parser.cpp"
    break;

  case 144: // expr_call_thread: THREAD expr_call_function
#line 453 "IW7.parser.ypp"
                                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2450 "./IW7/compiler_parser.cpp"
    break;

  case 145: // expr_call_thread: THREAD expr_call_pointer
#line 454 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2456 "./IW7/compiler_parser.cpp"
    break;

  case 146: // expr_call_thread: object THREAD expr_call_function
#line 455 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2462 "./IW7/compiler_parser.cpp"
    break;

  case 147: // expr_call_thread: object THREAD expr_call_pointer
#line 456 "IW7.parser.ypp"
                                                { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(std::to_string(*location), true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2468 "./IW7/compiler_parser.cpp"
    break;

  case 148: // expr_call_function: identifier LPAREN expr_arguments RPAREN
#line 461 "IW7.parser.ypp"
                {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(std::to_string(*location), std::make_unique<gsc::node_filepath>(std::to_string(*location), ""), std::move(yystack_[3].value.as < gsc::identifier_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2474 "./IW7/compiler_parser.cpp"
    break;

  case 149: // expr_call_function: filepath DOUBLECOLON identifier LPAREN expr_arguments RPAREN
#line 463 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::filepath_ptr > ()), std::move(yystack_[3].value.as < gsc::identifier_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2480 "./IW7/compiler_parser.cpp"
    break;

  case 150: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 468 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(std::to_string(*location), false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2486 "./IW7/compiler_parser.cpp"
    break;

  case 151: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 470 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(std::to_string(*location), true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2492 "./IW7/compiler_parser.cpp"
    break;

  case 152: // expr_arguments: expr_arguments COMMA expr
#line 475 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2498 "./IW7/compiler_parser.cpp"
    break;

  case 153: // expr_arguments: expr
#line 477 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(std::to_string(*location)); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2504 "./IW7/compiler_parser.cpp"
    break;

  case 154: // expr_arguments: %empty
#line 479 "IW7.parser.ypp"
                { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(std::to_string(*location)); }
#line 2510 "./IW7/compiler_parser.cpp"
    break;

  case 155: // expr_function_ref: DOUBLECOLON identifier
#line 484 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function_ref>(std::to_string(*location), std::make_unique<gsc::node_filepath>(std::to_string(*location), ""), std::move(yystack_[0].value.as < gsc::identifier_ptr > ())); }
#line 2516 "./IW7/compiler_parser.cpp"
    break;

  case 156: // expr_function_ref: filepath DOUBLECOLON identifier
#line 486 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function_ref>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::filepath_ptr > ()), std::move(yystack_[0].value.as < gsc::identifier_ptr > ())); }
#line 2522 "./IW7/compiler_parser.cpp"
    break;

  case 157: // expr_array: object LBRACKET expr RBRACKET
#line 491 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(std::to_string(*location), std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2528 "./IW7/compiler_parser.cpp"
    break;

  case 158: // expr_field: object DOT identifier
#line 496 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::identifier_ptr > ())); }
#line 2534 "./IW7/compiler_parser.cpp"
    break;

  case 159: // expr_size: object DOT size
#line 501 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(std::to_string(*location), std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2540 "./IW7/compiler_parser.cpp"
    break;

  case 160: // expr_vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 506 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_vector>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2546 "./IW7/compiler_parser.cpp"
    break;

  case 161: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 511 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(std::to_string(*location), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2552 "./IW7/compiler_parser.cpp"
    break;

  case 162: // object: expr_call
#line 515 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2558 "./IW7/compiler_parser.cpp"
    break;

  case 163: // object: expr_array
#line 516 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2564 "./IW7/compiler_parser.cpp"
    break;

  case 164: // object: expr_field
#line 517 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2570 "./IW7/compiler_parser.cpp"
    break;

  case 165: // object: identifier
#line 518 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::identifier_ptr > ()); }
#line 2576 "./IW7/compiler_parser.cpp"
    break;

  case 166: // object: level
#line 519 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2582 "./IW7/compiler_parser.cpp"
    break;

  case 167: // object: anim
#line 520 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2588 "./IW7/compiler_parser.cpp"
    break;

  case 168: // object: self
#line 521 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2594 "./IW7/compiler_parser.cpp"
    break;

  case 169: // object: game
#line 522 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2600 "./IW7/compiler_parser.cpp"
    break;

  case 170: // vector: LPAREN number COMMA number COMMA number RPAREN
#line 527 "IW7.parser.ypp"
                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_vector>(std::to_string(*location), std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2606 "./IW7/compiler_parser.cpp"
    break;

  case 171: // number: data_float
#line 531 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2612 "./IW7/compiler_parser.cpp"
    break;

  case 172: // number: data_integer
#line 532 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2618 "./IW7/compiler_parser.cpp"
    break;

  case 173: // data_false: FALSE
#line 535 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(std::to_string(*location)); }
#line 2624 "./IW7/compiler_parser.cpp"
    break;

  case 174: // data_true: TRUE
#line 536 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(std::to_string(*location)); }
#line 2630 "./IW7/compiler_parser.cpp"
    break;

  case 175: // data_float: FLOAT
#line 537 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2636 "./IW7/compiler_parser.cpp"
    break;

  case 176: // data_integer: INTEGER
#line 538 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2642 "./IW7/compiler_parser.cpp"
    break;

  case 177: // data_localized_string: STRING_LOC
#line 539 "IW7.parser.ypp"
                                   { yylhs.value.as < gsc::localized_string_ptr > () = std::make_unique<gsc::node_localized_string>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2648 "./IW7/compiler_parser.cpp"
    break;

  case 178: // data_string: STRING
#line 540 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2654 "./IW7/compiler_parser.cpp"
    break;

  case 179: // animref: ANIMREF
#line 541 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::animref_ptr > () = std::make_unique<gsc::node_animref>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2660 "./IW7/compiler_parser.cpp"
    break;

  case 180: // animtree: ANIMTREE
#line 542 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(std::to_string(*location)); }
#line 2666 "./IW7/compiler_parser.cpp"
    break;

  case 181: // identifier: IDENTIFIER
#line 543 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::identifier_ptr > () = std::make_unique<gsc::node_identifier>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2672 "./IW7/compiler_parser.cpp"
    break;

  case 182: // filepath: FILEPATH
#line 544 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::filepath_ptr > () = std::make_unique<gsc::node_filepath>(std::to_string(*location), yystack_[0].value.as < std::string > ()); }
#line 2678 "./IW7/compiler_parser.cpp"
    break;

  case 183: // empty_array: EMPTY_ARRAY
#line 545 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_empty_array>(std::to_string(*location)); }
#line 2684 "./IW7/compiler_parser.cpp"
    break;

  case 184: // undefined: UNDEFINED
#line 546 "IW7.parser.ypp"
                                { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_undefined>(std::to_string(*location)); }
#line 2690 "./IW7/compiler_parser.cpp"
    break;

  case 185: // size: SIZE
#line 547 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_size>(std::to_string(*location)); }
#line 2696 "./IW7/compiler_parser.cpp"
    break;

  case 186: // game: GAME
#line 548 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_game>(std::to_string(*location)); }
#line 2702 "./IW7/compiler_parser.cpp"
    break;

  case 187: // self: SELF
#line 549 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_self>(std::to_string(*location)); }
#line 2708 "./IW7/compiler_parser.cpp"
    break;

  case 188: // anim: ANIM
#line 550 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_anim>(std::to_string(*location)); }
#line 2714 "./IW7/compiler_parser.cpp"
    break;

  case 189: // level: LEVEL
#line 551 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_level>(std::to_string(*location)); }
#line 2720 "./IW7/compiler_parser.cpp"
    break;


#line 2724 "./IW7/compiler_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "INCLUDE", "USING_ANIMTREE",
  "ANIMTREE", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "BREAK", "FOR",
  "FOREACH", "WHILE", "CONTINUE", "RETURN", "THREAD", "CALL", "WAIT",
  "WAITTILL", "WAITTILLMATCH", "WAITTILLFRAMEEND", "ENDON", "NOTIFY", "IN",
  "UNDEFINED", "TRUE", "FALSE", "SIZE", "GAME", "LEVEL", "ANIM", "SELF",
  "EMPTY_ARRAY", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "COMMA", "DOT", "DOUBLECOLON", "COLON", "SEMICOLON", "QMARK",
  "MOD", "INCREMENT", "DECREMENT", "LSHIFT", "RSHIFT", "OR", "AND",
  "EQUALITY", "INEQUALITY", "LESS_EQUAL", "GREATER_EQUAL", "LESS",
  "GREATER", "ASSIGN", "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_MULT",
  "ASSIGN_DIV", "ASSIGN_MOD", "ASSIGN_BITWISE_OR", "ASSIGN_BITWISE_AND",
  "ASSIGN_BITWISE_EXOR", "ASSIGN_LSHIFT", "ASSIGN_RSHIFT", "BITWISE_OR",
  "BITWISE_AND", "BITWISE_EXOR", "ADD", "SUB", "MULT", "DIV", "NOT",
  "COMPLEMENT", "FILEPATH", "IDENTIFIER", "ANIMREF", "STRING",
  "STRING_LOC", "FLOAT", "INTEGER", "IFX", "$accept", "root", "script",
  "include", "definition", "using_animtree", "constant", "thread",
  "parameters", "block", "stmt", "stmt_call", "stmt_assign", "stmt_endon",
  "stmt_notify", "stmt_wait", "stmt_waittill", "stmt_waittillmatch",
  "stmt_waittillframeend", "stmt_if", "stmt_ifelse", "stmt_while",
  "stmt_for", "stmt_foreach", "stmt_switch", "stmt_case", "stmt_default",
  "stmt_break", "stmt_continue", "stmt_return", "for_assign", "for_cond",
  "expr", "expr_assign", "expr_cmp", "expr_ternary", "expr_binary",
  "expr_primitive", "expr_call", "expr_call_thread", "expr_call_function",
  "expr_call_pointer", "expr_arguments", "expr_function_ref", "expr_array",
  "expr_field", "expr_size", "expr_vector", "expr_add_array", "object",
  "vector", "number", "data_false", "data_true", "data_float",
  "data_integer", "data_localized_string", "data_string", "animref",
  "animtree", "identifier", "filepath", "empty_array", "undefined", "size",
  "game", "self", "anim", "level", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if IW7DEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }


  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if IW7DEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (!yy_lac_established_)
      {
#if IW7DEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
    return true;
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* evt)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << evt << '\n';
        yy_lac_established_ = false;
      }
  }

  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -218;

  const short parser::yytable_ninf_ = -170;

  const short
  parser::yypact_[] =
  {
       4,   -70,     1,  -218,    25,     4,  -218,  -218,  -218,  -218,
    -218,   -21,  -218,    -3,   -49,  -218,  -218,  -218,   -34,  1159,
    -218,  -218,    13,   -20,  -218,  -218,    40,    18,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  1159,  1229,   -34,  1159,
    1159,  -218,  -218,  -218,  -218,  2466,    17,  -218,  -218,  -218,
       6,  -218,  -218,  -218,  -218,    12,    86,  -218,  -218,  -218,
     112,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,     2,    16,  -218,  -218,   118,   123,   220,   227,    20,
      47,   -34,    55,  -218,  -218,    63,    72,    68,  1886,    76,
    1229,  2530,    70,  -218,  2530,  2530,  -218,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,  1159,    40,  1229,   -25,  -218,
    -218,  1159,   -34,  -218,  1848,  -218,  1159,   -34,  1159,  -218,
    1159,    46,  1156,  -218,  1159,  2530,  2530,  2530,  2530,  2530,
    2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,
    2530,  2530,  2530,  2433,  -218,  -218,  2287,  -218,  -218,  -218,
     -19,    78,    84,    91,    23,    79,    97,   108,   109,   110,
     101,  1139,   -24,   102,  1265,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,   103,   104,   105,  -218,  -218,
    1851,    63,  -218,  -218,  -218,  -218,  1156,    78,  2325,  2362,
     111,   115,  2530,  1159,  -218,  -218,  1159,  1159,  1159,   114,
     117,  -218,  -218,   246,   -34,  1159,  -218,  -218,  2499,  1159,
     119,  -218,  -218,  -218,  -218,  -218,  -218,   121,   124,   128,
     134,   -34,  -218,  -218,  1159,  1159,  1159,  1159,  1159,  1159,
    1159,  1159,  1159,  1159,  1159,   130,  1159,    46,   136,  2530,
      -9,  2001,  2032,  -218,  -218,   133,  -218,  -218,   575,   -10,
    2063,  -218,  2094,  -218,  1159,  1159,  1159,  1159,  2530,  2530,
    2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,   138,
    2125,   139,  1159,  -218,    58,   142,  1159,  1159,   -34,  1310,
     135,  1928,  2399,  2156,  1970,  1159,  -218,  -218,    -8,  1848,
     174,  1848,   137,  2530,    88,  2187,   160,  1848,  -218,  -218,
     143,  1159,  1159,   145,   146,  1159,    -1,  -218,  1342,  1387,
    1419,   246,  1464,  1159,  1496,  -218,    14,  2218,  -218,  -218,
      64,  -218,   187,  1848,  -218,  -218,   165,  1848,  -218,  2249,
    -218,   151,   157,   166,  1541,  1573,  1618,  1650,  1695,  -218,
    -218,  -218,  1848,  -218,  -218,  1848,  -218,  -218,  1848,  -218,
    1727,  1771,  1805,  -218,  -218,  -218
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   181,     0,     2,     6,     7,     9,    10,
      11,     0,   182,     0,     0,     1,     4,     5,    17,     0,
       8,   178,     0,     0,    16,   180,     0,     0,   184,   174,
     173,   186,   189,   188,   187,   183,     0,   154,     0,     0,
       0,   179,   177,   175,   176,     0,    78,    79,    80,    81,
     117,   118,   140,   141,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   129,   130,   171,   172,   127,   128,   131,
     132,   133,     0,   134,   135,   136,   137,   138,   139,     0,
       0,     0,     0,   144,   145,     0,     0,     0,     0,   126,
     154,   153,     0,   155,   116,   115,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   154,     0,    12,    20,    15,     0,     0,     0,   114,
       0,     0,   153,   161,     0,   113,   107,   108,    95,    96,
      97,    98,    99,   100,   101,   102,   104,   105,   106,   109,
     110,   111,   112,     0,   146,   147,     0,   185,   158,   159,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,   162,     0,   163,   164,
       0,   165,   169,   168,   167,   166,     0,     0,     0,     0,
       0,     0,   152,     0,   157,   148,   154,     0,     0,     0,
       0,    69,    70,    75,     0,     0,    71,    73,     0,     0,
       0,    51,    14,    18,    42,    40,    41,     0,     0,     0,
       0,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,    67,    68,     0,    74,   162,     0,     0,
       0,    72,     0,    47,     0,     0,     0,     0,    84,    90,
      91,    92,    93,    94,    85,    86,    87,    88,    89,     0,
       0,     0,   154,   149,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,   154,   160,   170,     0,    20,
      53,    20,     0,     0,    78,     0,     0,    20,    59,    46,
       0,   154,     0,     0,     0,   154,     0,   150,     0,     0,
       0,    75,     0,     0,     0,    49,     0,     0,    43,    45,
       0,   151,    52,    20,    57,    66,     0,    20,    64,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      50,    44,    20,    56,    55,    20,    61,    62,    20,    65,
       0,     0,     0,    54,    60,    63
  };

  const short
  parser::yypgoto_[] =
  {
    -218,  -218,  -218,   200,   209,  -218,  -218,  -218,  -218,   -29,
     410,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -116,  -218,   354,  -217,   -80,  -218,  -218,  -218,  -122,   783,
     -17,   -14,  -108,  -218,   192,   363,  -218,  -218,  -218,   442,
    -218,   -35,  -218,  -218,  -218,    54,  -218,   -11,  -218,  -218,
       0,    52,  -218,  -218,  -218,   509,   588,   653,   718
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    23,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     265,   312,    91,   195,    46,    47,    48,    49,    50,    51,
      52,    53,    92,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   159,    75,    76,    77,    78
  };

  const short
  parser::yytable_[] =
  {
      11,    89,   196,    22,   157,    11,   266,     1,     2,    83,
      12,   229,    84,   160,    18,   297,    80,   215,    24,  -165,
    -165,    81,   134,  -162,  -162,    15,    85,   293,   327,  -163,
    -163,   298,   134,   134,    21,   341,    14,   121,    93,    19,
     134,  -165,    20,   119,  -165,  -162,   120,     3,  -162,    79,
     351,  -163,   196,    13,  -163,   134,     3,    87,    27,   122,
      85,    43,    44,   115,   162,   123,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    26,    27,   172,    86,    82,
     173,   125,  -165,  -165,   124,     3,  -162,  -162,    31,    32,
      33,    34,  -163,  -163,   126,   309,   210,    82,   121,   154,
     353,   267,   155,  -164,  -164,   134,    21,   128,   260,    44,
     133,   134,    86,   216,   266,   127,    85,   131,   158,   217,
      12,     3,   161,   221,   201,  -164,   218,   207,  -164,   116,
      27,    43,    44,   -76,   115,  -169,  -169,   230,    12,     3,
    -168,  -168,   222,   223,   224,   225,   226,   231,   234,   235,
     236,   117,   257,   220,   118,   258,   274,  -169,   263,   275,
    -169,   264,  -168,   276,   273,  -168,  -164,  -164,    86,   277,
     289,   292,   196,   305,   201,   307,    86,   196,   296,   311,
     319,   329,   331,   119,   308,   333,   120,   196,   335,   196,
     338,   339,    12,     3,   354,   196,   359,   326,  -169,  -169,
      85,   356,   360,  -168,  -168,    16,   196,   196,   196,   267,
     196,   361,   196,   336,    17,   346,   314,   340,   219,     0,
       0,   196,   291,   201,   269,   196,    86,     0,     0,     0,
       0,     0,   196,   196,   196,   196,   196,  -167,  -167,     0,
     196,   158,     0,   196,  -166,  -166,   196,     0,   196,   196,
     196,   119,    86,     0,   120,     0,     0,     0,     0,  -167,
       0,     0,  -167,     0,    27,     0,  -166,     0,    85,  -166,
       0,     0,     0,     0,     0,    86,    31,    32,    33,    34,
     328,     0,   330,     0,     0,    82,     0,     0,   334,     0,
       0,     0,     0,     0,   201,     0,     0,     0,   316,   201,
    -167,  -167,     0,     0,     0,     0,     0,  -166,  -166,   201,
       0,   201,     0,     0,   355,     0,   198,   201,   357,     0,
      86,     0,     0,     0,     0,     0,    12,     3,   201,   201,
     201,   201,   201,   370,   201,     0,   371,     0,     0,   372,
       0,     0,     0,   201,     0,     0,    86,   201,     0,     0,
       0,    86,     0,     0,   201,   201,   201,   201,   201,     0,
       0,    86,   201,    86,     0,   201,   198,     0,   201,    86,
     201,   201,   201,    45,     0,     0,     0,     0,     0,     0,
      86,    86,    86,    86,    86,     0,    86,     0,     0,     0,
      88,     0,     0,    94,    95,    86,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,    86,    86,    86,    86,
      86,     0,     0,     0,    86,   198,     0,    86,     0,     0,
      86,     0,    86,    86,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,   208,     0,   209,     0,   198,   199,   212,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,     0,   198,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   198,   198,   198,   198,   228,   198,     0,     0,     0,
       0,     0,     0,     0,     0,   198,     0,   199,     0,   198,
       0,     0,     0,     0,     0,     0,   198,   198,   198,   198,
     198,     0,     0,     0,   198,     0,     0,   198,     0,     0,
     198,     0,   198,   198,   198,     0,   200,   259,     0,     0,
       0,   261,   262,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   272,   233,     0,   199,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,     0,
     290,     0,     0,     0,   117,     0,   200,   241,     0,     0,
       0,     0,     0,   242,   243,     0,     0,     0,   301,   302,
     303,   304,     0,   202,     0,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     0,     0,     0,
     313,   315,     0,     0,     0,    12,     3,   199,     0,     0,
       0,     0,   199,     0,     0,   268,     0,     0,     0,     0,
       0,     0,   199,     0,   199,     0,   337,     0,     0,     0,
     199,     0,     0,   202,     0,     0,     0,   349,     0,     0,
       0,   199,   199,   199,   199,   199,     0,   199,     0,     0,
       0,     0,     0,     0,   310,     0,   199,     0,     0,   318,
     199,     0,   203,     0,     0,     0,     0,   199,   199,   199,
     199,   199,     0,     0,     0,   199,     0,     0,   199,     0,
       0,   199,   202,   199,   199,   199,   200,     0,   233,   344,
     233,   200,   348,     0,   233,     0,     0,     0,     0,     0,
       0,   200,     0,   200,     0,     0,     0,     0,     0,   200,
       0,     0,   203,     0,   363,   233,   366,   233,   369,     0,
     200,   200,   200,   268,   200,     0,   200,   204,     0,     0,
     233,   233,   233,     0,     0,   200,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,   200,   200,   200,   200,
     200,     0,     0,   202,   200,     0,     0,   200,   202,     0,
     200,   203,   200,   200,   200,     0,     0,     0,   202,     0,
     202,     0,     0,     0,     0,     0,   202,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   202,   202,
     202,   202,   205,   202,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     0,     0,     0,   202,     0,     0,     0,
       0,     0,     0,   202,   202,   202,   202,   202,     0,     0,
       0,   202,     0,     0,   202,     0,   204,   202,     0,   202,
     202,   202,   203,     0,     0,     0,     0,   203,     0,     0,
       0,     0,   205,     0,     0,     0,     0,   203,     0,   203,
       0,     0,     0,     0,     0,   203,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   203,   203,   203,
     203,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,     0,   203,     0,     0,     0,     0,
       0,   205,   203,   203,   203,   203,   203,   204,     0,     0,
     203,     0,   204,   203,     0,     0,   203,   197,   203,   203,
     203,     0,   204,     0,   204,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   204,   204,   204,   204,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,   204,   204,   204,
     204,   204,   205,     0,     0,   204,     0,   205,   204,     0,
       0,   204,     0,   204,   204,   204,     0,   205,     0,   205,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   205,   205,   205,
     205,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,   205,   205,   205,   205,   205,   197,     0,     0,
     205,     0,   197,   205,     0,     0,   205,     0,   205,   205,
     205,     0,   197,     0,   197,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   197,   197,     0,   197,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,   197,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,   197,   197,   197,
     197,   197,     0,     0,    25,   197,     0,     0,   197,     0,
       0,   197,     0,   197,   197,   197,    26,    27,     0,     0,
       0,     0,     0,     0,    25,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,     0,    26,    27,    37,     0,
       0,     0,    38,     0,   227,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,     0,   211,     0,    37,     0,
       0,     0,    38,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,    39,    40,    12,
       3,    41,    21,    42,    43,    44,     0,   108,   109,   110,
     111,   112,   113,   114,    25,     0,     0,    39,    40,    12,
       3,    41,    21,    42,    43,    44,    26,    27,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    90,     0,
       0,   162,    38,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    26,    27,   172,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,     0,   232,    82,     0,     0,    39,    40,    12,
       3,    41,    21,    42,    43,    44,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    26,    27,   172,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,     0,    12,     3,   317,   162,    82,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    26,
      27,   172,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,     0,     0,     0,     0,
     342,    82,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     3,     0,   162,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    26,    27,   172,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,     0,    12,     3,   343,   162,    82,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    26,    27,   172,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,     0,     0,     0,     0,   345,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     3,     0,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    26,    27,   172,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,     0,    12,
       3,   347,   162,    82,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    26,    27,   172,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
       0,     0,     0,     0,   350,    82,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     3,     0,   162,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    26,    27,
     172,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,     0,    12,     3,   362,   162,
      82,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      26,    27,   172,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
       0,   364,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     3,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    26,    27,   172,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,     0,    12,     3,   365,   162,    82,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    26,    27,   172,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,     0,     0,     0,     0,   367,    82,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     3,
       0,   162,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    26,    27,   172,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
      12,     3,   368,   162,    82,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    26,    27,   172,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,     0,     0,     0,     0,   373,    82,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     3,   162,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    26,    27,
     172,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,     0,     0,    12,     3,   374,
      82,   162,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    26,    27,   172,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,     0,   375,    82,     0,     0,     0,     0,     0,
       0,    12,     3,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    26,    27,   172,   116,    27,
     173,   237,   238,     0,   239,   240,     0,     0,    31,    32,
      33,    34,     0,     0,     0,    12,     3,    82,     0,     0,
     117,     0,     0,   241,     0,     0,     0,     0,     0,   242,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   129,     0,     0,     0,     0,   130,    12,     3,
       0,    12,     3,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   320,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,    97,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   324,     0,     0,     0,
       0,   325,     0,     0,     0,     0,     0,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,   294,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,    97,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,   358,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   214,     0,     0,
       0,     0,     0,     0,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   255,     0,     0,     0,     0,
       0,     0,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   256,     0,     0,     0,     0,     0,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     322,     0,     0,     0,     0,     0,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   213,     0,     0,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,    96,     0,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   271,     0,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114
  };

  const short
  parser::yycheck_[] =
  {
       0,    36,   124,    14,    29,     5,   223,     3,     4,    26,
      80,    35,    26,   121,    35,    25,    36,    36,    18,    17,
      18,    41,    41,    17,    18,     0,    26,    36,    36,    17,
      18,    41,    41,    41,    83,    36,    35,    35,    38,    60,
      41,    39,    45,    60,    42,    39,    60,    81,    42,    36,
      36,    39,   174,     1,    42,    41,    81,    39,    18,    43,
      60,    85,    86,    46,     6,    45,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    26,    39,
      22,    81,    80,    81,    37,    81,    80,    81,    30,    31,
      32,    33,    80,    81,    39,    37,   131,    39,    35,   116,
      36,   223,   116,    17,    18,    41,    83,    39,   216,    86,
      40,    41,    60,    35,   331,    43,   116,    41,   118,    35,
      80,    81,   122,    44,   124,    39,    35,   127,    42,    17,
      18,    85,    86,    45,    46,    17,    18,   172,    80,    81,
      17,    18,    45,    35,    35,    35,    45,    45,    45,    45,
      45,    39,    41,   164,    42,    40,    35,    39,    44,    35,
      42,    44,    39,    35,    45,    42,    80,    81,   116,    35,
      40,    35,   294,    35,   174,    36,   124,   299,    45,    37,
      45,     7,    45,   200,   292,    25,   200,   309,    45,   311,
      45,    45,    80,    81,     7,   317,    45,   305,    80,    81,
     200,    36,    45,    80,    81,     5,   328,   329,   330,   331,
     332,    45,   334,   321,     5,   331,   296,   325,   164,    -1,
      -1,   343,   257,   223,   224,   347,   174,    -1,    -1,    -1,
      -1,    -1,   354,   355,   356,   357,   358,    17,    18,    -1,
     362,   241,    -1,   365,    17,    18,   368,    -1,   370,   371,
     372,   268,   200,    -1,   268,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    18,    -1,    39,    -1,   268,    42,
      -1,    -1,    -1,    -1,    -1,   223,    30,    31,    32,    33,
     309,    -1,   311,    -1,    -1,    39,    -1,    -1,   317,    -1,
      -1,    -1,    -1,    -1,   294,    -1,    -1,    -1,   298,   299,
      80,    81,    -1,    -1,    -1,    -1,    -1,    80,    81,   309,
      -1,   311,    -1,    -1,   343,    -1,   124,   317,   347,    -1,
     268,    -1,    -1,    -1,    -1,    -1,    80,    81,   328,   329,
     330,   331,   332,   362,   334,    -1,   365,    -1,    -1,   368,
      -1,    -1,    -1,   343,    -1,    -1,   294,   347,    -1,    -1,
      -1,   299,    -1,    -1,   354,   355,   356,   357,   358,    -1,
      -1,   309,   362,   311,    -1,   365,   174,    -1,   368,   317,
     370,   371,   372,    19,    -1,    -1,    -1,    -1,    -1,    -1,
     328,   329,   330,   331,   332,    -1,   334,    -1,    -1,    -1,
      36,    -1,    -1,    39,    40,   343,    -1,    -1,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,   357,
     358,    -1,    -1,    -1,   362,   223,    -1,   365,    -1,    -1,
     368,    -1,   370,   371,   372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,   128,    -1,   130,    -1,   294,   124,   134,    -1,
      -1,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   309,    -1,   311,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     328,   329,   330,   331,   332,   171,   334,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   343,    -1,   174,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,   357,
     358,    -1,    -1,    -1,   362,    -1,    -1,   365,    -1,    -1,
     368,    -1,   370,   371,   372,    -1,   124,   213,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,   229,   174,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,    -1,    -1,    -1,    39,    -1,   174,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,   274,   275,
     276,   277,    -1,   124,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
     296,   297,    -1,    -1,    -1,    80,    81,   294,    -1,    -1,
      -1,    -1,   299,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   309,    -1,   311,    -1,   322,    -1,    -1,    -1,
     317,    -1,    -1,   174,    -1,    -1,    -1,   333,    -1,    -1,
      -1,   328,   329,   330,   331,   332,    -1,   334,    -1,    -1,
      -1,    -1,    -1,    -1,   294,    -1,   343,    -1,    -1,   299,
     347,    -1,   124,    -1,    -1,    -1,    -1,   354,   355,   356,
     357,   358,    -1,    -1,    -1,   362,    -1,    -1,   365,    -1,
      -1,   368,   223,   370,   371,   372,   294,    -1,   328,   329,
     330,   299,   332,    -1,   334,    -1,    -1,    -1,    -1,    -1,
      -1,   309,    -1,   311,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,   174,    -1,   354,   355,   356,   357,   358,    -1,
     328,   329,   330,   331,   332,    -1,   334,   124,    -1,    -1,
     370,   371,   372,    -1,    -1,   343,    -1,    -1,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,   357,
     358,    -1,    -1,   294,   362,    -1,    -1,   365,   299,    -1,
     368,   223,   370,   371,   372,    -1,    -1,    -1,   309,    -1,
     311,    -1,    -1,    -1,    -1,    -1,   317,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,   329,   330,
     331,   332,   124,   334,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,   354,   355,   356,   357,   358,    -1,    -1,
      -1,   362,    -1,    -1,   365,    -1,   223,   368,    -1,   370,
     371,   372,   294,    -1,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   309,    -1,   311,
      -1,    -1,    -1,    -1,    -1,   317,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   328,   329,   330,   331,
     332,    -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,   223,   354,   355,   356,   357,   358,   294,    -1,    -1,
     362,    -1,   299,   365,    -1,    -1,   368,   174,   370,   371,
     372,    -1,   309,    -1,   311,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   328,   329,   330,   331,   332,    -1,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,
     357,   358,   294,    -1,    -1,   362,    -1,   299,   365,    -1,
      -1,   368,    -1,   370,   371,   372,    -1,   309,    -1,   311,
      -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   328,   329,   330,   331,
     332,    -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   343,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,    -1,   354,   355,   356,   357,   358,   294,    -1,    -1,
     362,    -1,   299,   365,    -1,    -1,   368,    -1,   370,   371,
     372,    -1,   309,    -1,   311,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   328,   329,   330,    -1,   332,    -1,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,
     357,   358,    -1,    -1,     5,   362,    -1,    -1,   365,    -1,
      -1,   368,    -1,   370,   371,   372,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    17,    18,    39,    -1,
      -1,    -1,    43,    -1,    45,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    40,    -1,    39,    -1,
      -1,    -1,    43,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    71,    72,    73,
      74,    75,    76,    77,     5,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,     6,    43,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    80,    81,    37,     6,    39,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,     6,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    80,    81,    37,     6,    39,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
       6,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,    80,
      81,    37,     6,    39,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,     6,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    80,    81,    37,     6,
      39,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,     6,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    -1,    80,    81,    37,     6,    39,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,     6,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      80,    81,    37,     6,    39,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,     6,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    80,    81,    38,
      39,     6,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,     6,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    17,    18,
      22,    20,    21,    -1,    23,    24,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    80,    81,    39,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    36,    -1,    -1,    -1,    -1,    41,    80,    81,
      -1,    80,    81,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    47,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    44,    -1,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    45,    -1,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    45,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,    81,    89,    90,    91,    92,    93,    94,
      95,   148,    80,   149,    35,     0,    91,    92,    35,    60,
      45,    83,   145,    96,   148,     5,    17,    18,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    39,    43,    78,
      79,    82,    84,    85,    86,   120,   122,   123,   124,   125,
     126,   127,   128,   129,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   153,   154,   155,   156,    36,
      36,    41,    39,   128,   129,   148,   149,    39,   120,   139,
      39,   120,   130,   148,   120,   120,    45,    47,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    71,    72,
      73,    74,    75,    76,    77,    46,    17,    39,    42,   128,
     129,    35,    43,    45,    37,   148,    39,    43,    39,    36,
      41,    41,   120,    40,    41,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   128,   129,   120,    29,   148,   152,
     130,   148,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    19,    22,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   121,   126,   127,   132,   133,
     137,   148,   153,   154,   155,   156,   120,   148,   120,   120,
     139,    40,   120,    44,    40,    36,    35,    35,    35,   143,
     145,    44,    45,    35,    35,    35,    45,    45,   120,    35,
     139,    45,    38,    98,    45,    45,    45,    20,    21,    23,
      24,    42,    48,    49,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    40,    41,    41,    40,   120,
     130,   120,   120,    44,    44,   118,   121,   126,   137,   148,
     120,    45,   120,    45,    35,    35,    35,    35,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,    40,
     120,   139,    35,    36,    36,    36,    45,    25,    41,    36,
      36,   120,   120,   120,   120,    35,    36,    36,   130,    37,
      98,    37,   119,   120,   122,   120,   148,    37,    98,    45,
      36,    41,    41,    36,    36,    41,   130,    36,    97,     7,
      97,    45,    36,    25,    97,    45,   130,   120,    45,    45,
     130,    36,    38,    37,    98,    38,   118,    37,    98,   120,
      38,    36,    36,    36,     7,    97,    36,    97,    36,    45,
      45,    45,    37,    98,    38,    37,    98,    38,    37,    98,
      97,    97,    97,    38,    38,    38
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    88,    89,    89,    90,    90,    90,    90,    91,    92,
      92,    92,    93,    94,    95,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   101,   102,   102,   103,   103,   104,   104,
     105,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   112,   113,   113,   114,
     115,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   131,   131,   132,   133,   134,
     135,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     138,   139,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     1,
       1,     1,     5,     4,     7,     3,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     6,     8,     6,     5,     3,     8,     6,
       8,     2,     7,     5,    11,     9,     9,     7,     7,     5,
      11,     9,     9,    11,     7,     9,     7,     3,     3,     2,
       2,     2,     3,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     4,     6,
       8,     9,     3,     1,     0,     2,     3,     4,     3,     3,
       7,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };




#if IW7DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   121,   121,   122,   126,   128,   130,   132,   137,   142,
     143,   144,   148,   153,   158,   163,   165,   168,   172,   174,
     177,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     203,   205,   210,   215,   220,   222,   227,   229,   234,   236,
     241,   246,   251,   253,   261,   263,   268,   273,   283,   285,
     293,   295,   304,   306,   308,   314,   323,   328,   330,   335,
     340,   344,   349,   351,   356,   357,   361,   362,   366,   367,
     368,   369,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   389,   390,   391,   392,   393,
     394,   395,   396,   400,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     446,   447,   448,   449,   453,   454,   455,   456,   460,   462,
     467,   469,   474,   476,   479,   483,   485,   490,   495,   500,
     505,   510,   515,   516,   517,   518,   519,   520,   521,   522,
     526,   531,   532,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // IW7DEBUG


#line 14 "IW7.parser.ypp"
} // IW7
#line 3992 "./IW7/compiler_parser.cpp"

#line 553 "IW7.parser.ypp"


void IW7::parser::error(const std::string& msg)
{
    GSC_COMP_ERROR("%s", msg.data());
}
