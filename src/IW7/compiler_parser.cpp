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
    IW7::parser::symbol_type IW7lex(yyscan_t yyscanner, std::uint32_t *pos);

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
  parser::parser (yyscan_t yyscanner_yyarg, std::uint32_t *pos_yyarg, gsc::program_ptr& astout_yyarg)
#if IW7DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      yyscanner (yyscanner_yyarg),
      pos (pos_yyarg),
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
      case symbol_kind::S_anim: // anim
        value.YY_MOVE_OR_COPY< gsc::anim_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animation: // animation
        value.YY_MOVE_OR_COPY< gsc::animation_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_define: // define
        value.YY_MOVE_OR_COPY< gsc::define_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.YY_MOVE_OR_COPY< gsc::empty_array_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.YY_MOVE_OR_COPY< gsc::expr_arguments_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.YY_MOVE_OR_COPY< gsc::expr_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.YY_MOVE_OR_COPY< gsc::expr_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.YY_MOVE_OR_COPY< gsc::expr_call_type_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.YY_MOVE_OR_COPY< gsc::expr_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_false: // false
        value.YY_MOVE_OR_COPY< gsc::false_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_file: // file
        value.YY_MOVE_OR_COPY< gsc::file_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.YY_MOVE_OR_COPY< gsc::float_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_game: // game
        value.YY_MOVE_OR_COPY< gsc::game_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.YY_MOVE_OR_COPY< gsc::include_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.YY_MOVE_OR_COPY< gsc::integer_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_istring: // istring
        value.YY_MOVE_OR_COPY< gsc::istring_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_level: // level
        value.YY_MOVE_OR_COPY< gsc::level_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_name: // name
        value.YY_MOVE_OR_COPY< gsc::name_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_self: // expr_self
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
        value.YY_MOVE_OR_COPY< gsc::node_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< gsc::number_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.YY_MOVE_OR_COPY< gsc::parameters_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< gsc::program_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_self: // self
        value.YY_MOVE_OR_COPY< gsc::self_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_string: // string
        value.YY_MOVE_OR_COPY< gsc::string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.YY_MOVE_OR_COPY< gsc::thisthread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.YY_MOVE_OR_COPY< gsc::thread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_true: // true
        value.YY_MOVE_OR_COPY< gsc::true_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_undefined: // undefined
        value.YY_MOVE_OR_COPY< gsc::undefined_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.YY_MOVE_OR_COPY< gsc::usingtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ISTRING: // ISTRING
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
      case symbol_kind::S_anim: // anim
        value.move< gsc::anim_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animation: // animation
        value.move< gsc::animation_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_define: // define
        value.move< gsc::define_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.move< gsc::empty_array_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.move< gsc::expr_arguments_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< gsc::expr_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.move< gsc::expr_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< gsc::expr_call_type_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< gsc::expr_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_false: // false
        value.move< gsc::false_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_file: // file
        value.move< gsc::file_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.move< gsc::float_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_game: // game
        value.move< gsc::game_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.move< gsc::include_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.move< gsc::integer_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_istring: // istring
        value.move< gsc::istring_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_level: // level
        value.move< gsc::level_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_name: // name
        value.move< gsc::name_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_self: // expr_self
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
        value.move< gsc::node_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< gsc::number_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< gsc::parameters_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< gsc::program_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_self: // self
        value.move< gsc::self_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_string: // string
        value.move< gsc::string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.move< gsc::thisthread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.move< gsc::thread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_true: // true
        value.move< gsc::true_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_undefined: // undefined
        value.move< gsc::undefined_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.move< gsc::usingtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ISTRING: // ISTRING
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
      case symbol_kind::S_anim: // anim
        value.copy< gsc::anim_ptr > (that.value);
        break;

      case symbol_kind::S_animation: // animation
        value.copy< gsc::animation_ptr > (that.value);
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

      case symbol_kind::S_define: // define
        value.copy< gsc::define_ptr > (that.value);
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.copy< gsc::empty_array_ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.copy< gsc::expr_arguments_ptr > (that.value);
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.copy< gsc::expr_assign_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.copy< gsc::expr_call_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.copy< gsc::expr_call_type_ptr > (that.value);
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.copy< gsc::expr_ptr > (that.value);
        break;

      case symbol_kind::S_false: // false
        value.copy< gsc::false_ptr > (that.value);
        break;

      case symbol_kind::S_file: // file
        value.copy< gsc::file_ptr > (that.value);
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.copy< gsc::float_ptr > (that.value);
        break;

      case symbol_kind::S_game: // game
        value.copy< gsc::game_ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.copy< gsc::include_ptr > (that.value);
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.copy< gsc::integer_ptr > (that.value);
        break;

      case symbol_kind::S_istring: // istring
        value.copy< gsc::istring_ptr > (that.value);
        break;

      case symbol_kind::S_level: // level
        value.copy< gsc::level_ptr > (that.value);
        break;

      case symbol_kind::S_name: // name
        value.copy< gsc::name_ptr > (that.value);
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_self: // expr_self
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
        value.copy< gsc::node_ptr > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.copy< gsc::number_ptr > (that.value);
        break;

      case symbol_kind::S_parameters: // parameters
        value.copy< gsc::parameters_ptr > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< gsc::program_ptr > (that.value);
        break;

      case symbol_kind::S_self: // self
        value.copy< gsc::self_ptr > (that.value);
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

      case symbol_kind::S_string: // string
        value.copy< gsc::string_ptr > (that.value);
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.copy< gsc::thisthread_ptr > (that.value);
        break;

      case symbol_kind::S_thread: // thread
        value.copy< gsc::thread_ptr > (that.value);
        break;

      case symbol_kind::S_true: // true
        value.copy< gsc::true_ptr > (that.value);
        break;

      case symbol_kind::S_undefined: // undefined
        value.copy< gsc::undefined_ptr > (that.value);
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.copy< gsc::usingtree_ptr > (that.value);
        break;

      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ISTRING: // ISTRING
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
      case symbol_kind::S_anim: // anim
        value.move< gsc::anim_ptr > (that.value);
        break;

      case symbol_kind::S_animation: // animation
        value.move< gsc::animation_ptr > (that.value);
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

      case symbol_kind::S_define: // define
        value.move< gsc::define_ptr > (that.value);
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.move< gsc::empty_array_ptr > (that.value);
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        value.move< gsc::expr_arguments_ptr > (that.value);
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< gsc::expr_assign_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.move< gsc::expr_call_ptr > (that.value);
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< gsc::expr_call_type_ptr > (that.value);
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< gsc::expr_ptr > (that.value);
        break;

      case symbol_kind::S_false: // false
        value.move< gsc::false_ptr > (that.value);
        break;

      case symbol_kind::S_file: // file
        value.move< gsc::file_ptr > (that.value);
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.move< gsc::float_ptr > (that.value);
        break;

      case symbol_kind::S_game: // game
        value.move< gsc::game_ptr > (that.value);
        break;

      case symbol_kind::S_include: // include
        value.move< gsc::include_ptr > (that.value);
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.move< gsc::integer_ptr > (that.value);
        break;

      case symbol_kind::S_istring: // istring
        value.move< gsc::istring_ptr > (that.value);
        break;

      case symbol_kind::S_level: // level
        value.move< gsc::level_ptr > (that.value);
        break;

      case symbol_kind::S_name: // name
        value.move< gsc::name_ptr > (that.value);
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_self: // expr_self
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
        value.move< gsc::node_ptr > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.move< gsc::number_ptr > (that.value);
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< gsc::parameters_ptr > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< gsc::program_ptr > (that.value);
        break;

      case symbol_kind::S_self: // self
        value.move< gsc::self_ptr > (that.value);
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

      case symbol_kind::S_string: // string
        value.move< gsc::string_ptr > (that.value);
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.move< gsc::thisthread_ptr > (that.value);
        break;

      case symbol_kind::S_thread: // thread
        value.move< gsc::thread_ptr > (that.value);
        break;

      case symbol_kind::S_true: // true
        value.move< gsc::true_ptr > (that.value);
        break;

      case symbol_kind::S_undefined: // undefined
        value.move< gsc::undefined_ptr > (that.value);
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.move< gsc::usingtree_ptr > (that.value);
        break;

      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ISTRING: // ISTRING
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
            symbol_type yylookahead (yylex (yyscanner, pos));
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
      case symbol_kind::S_anim: // anim
        yylhs.value.emplace< gsc::anim_ptr > ();
        break;

      case symbol_kind::S_animation: // animation
        yylhs.value.emplace< gsc::animation_ptr > ();
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

      case symbol_kind::S_define: // define
        yylhs.value.emplace< gsc::define_ptr > ();
        break;

      case symbol_kind::S_empty_array: // empty_array
        yylhs.value.emplace< gsc::empty_array_ptr > ();
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
        yylhs.value.emplace< gsc::expr_arguments_ptr > ();
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        yylhs.value.emplace< gsc::expr_assign_ptr > ();
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        yylhs.value.emplace< gsc::expr_call_ptr > ();
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        yylhs.value.emplace< gsc::expr_call_type_ptr > ();
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        yylhs.value.emplace< gsc::expr_ptr > ();
        break;

      case symbol_kind::S_false: // false
        yylhs.value.emplace< gsc::false_ptr > ();
        break;

      case symbol_kind::S_file: // file
        yylhs.value.emplace< gsc::file_ptr > ();
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        yylhs.value.emplace< gsc::float_ptr > ();
        break;

      case symbol_kind::S_game: // game
        yylhs.value.emplace< gsc::game_ptr > ();
        break;

      case symbol_kind::S_include: // include
        yylhs.value.emplace< gsc::include_ptr > ();
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        yylhs.value.emplace< gsc::integer_ptr > ();
        break;

      case symbol_kind::S_istring: // istring
        yylhs.value.emplace< gsc::istring_ptr > ();
        break;

      case symbol_kind::S_level: // level
        yylhs.value.emplace< gsc::level_ptr > ();
        break;

      case symbol_kind::S_name: // name
        yylhs.value.emplace< gsc::name_ptr > ();
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_vector: // expr_vector
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_self: // expr_self
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
      case symbol_kind::S_vector: // vector
        yylhs.value.emplace< gsc::node_ptr > ();
        break;

      case symbol_kind::S_number: // number
        yylhs.value.emplace< gsc::number_ptr > ();
        break;

      case symbol_kind::S_parameters: // parameters
        yylhs.value.emplace< gsc::parameters_ptr > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< gsc::program_ptr > ();
        break;

      case symbol_kind::S_self: // self
        yylhs.value.emplace< gsc::self_ptr > ();
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

      case symbol_kind::S_string: // string
        yylhs.value.emplace< gsc::string_ptr > ();
        break;

      case symbol_kind::S_thisthread: // thisthread
        yylhs.value.emplace< gsc::thisthread_ptr > ();
        break;

      case symbol_kind::S_thread: // thread
        yylhs.value.emplace< gsc::thread_ptr > ();
        break;

      case symbol_kind::S_true: // true
        yylhs.value.emplace< gsc::true_ptr > ();
        break;

      case symbol_kind::S_undefined: // undefined
        yylhs.value.emplace< gsc::undefined_ptr > ();
        break;

      case symbol_kind::S_usingtree: // usingtree
        yylhs.value.emplace< gsc::usingtree_ptr > ();
        break;

      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ISTRING: // ISTRING
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
  case 2: // root: program
#line 133 "IW7.parser.ypp"
              { astout = std::move(yystack_[0].value.as < gsc::program_ptr > ()); }
#line 1699 "./IW7/compiler_parser.cpp"
    break;

  case 3: // root: %empty
#line 134 "IW7.parser.ypp"
              { astout = std::make_unique<gsc::node_program>(); }
#line 1705 "./IW7/compiler_parser.cpp"
    break;

  case 4: // program: program include
#line 139 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1711 "./IW7/compiler_parser.cpp"
    break;

  case 5: // program: program define
#line 141 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1717 "./IW7/compiler_parser.cpp"
    break;

  case 6: // program: include
#line 143 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(*pos); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1723 "./IW7/compiler_parser.cpp"
    break;

  case 7: // program: define
#line 145 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(*pos); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1729 "./IW7/compiler_parser.cpp"
    break;

  case 8: // include: INCLUDE file SEMICOLON
#line 150 "IW7.parser.ypp"
        { yylhs.value.as < gsc::include_ptr > () = std::make_unique<gsc::node_include>(*pos, std::move(yystack_[1].value.as < gsc::file_ptr > ())); }
#line 1735 "./IW7/compiler_parser.cpp"
    break;

  case 9: // define: usingtree
#line 154 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_usingtree = std::move(yystack_[0].value.as < gsc::usingtree_ptr > ()); }
#line 1741 "./IW7/compiler_parser.cpp"
    break;

  case 10: // define: constant
#line 155 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_constant = std::move(yystack_[0].value.as < gsc::constant_ptr > ()); }
#line 1747 "./IW7/compiler_parser.cpp"
    break;

  case 11: // define: thread
#line 156 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_thread = std::move(yystack_[0].value.as < gsc::thread_ptr > ()); }
#line 1753 "./IW7/compiler_parser.cpp"
    break;

  case 12: // usingtree: USINGTREE LPAREN string RPAREN SEMICOLON
#line 161 "IW7.parser.ypp"
        { yylhs.value.as < gsc::usingtree_ptr > () = std::make_unique<gsc::node_usingtree>(*pos, std::move(yystack_[2].value.as < gsc::string_ptr > ())); }
#line 1759 "./IW7/compiler_parser.cpp"
    break;

  case 13: // constant: name ASSIGN expr SEMICOLON
#line 166 "IW7.parser.ypp"
        { yylhs.value.as < gsc::constant_ptr > () = std::make_unique<gsc::node_constant>(*pos, std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1765 "./IW7/compiler_parser.cpp"
    break;

  case 14: // thread: name LPAREN parameters RPAREN LBRACE block RBRACE
#line 171 "IW7.parser.ypp"
        { yylhs.value.as < gsc::thread_ptr > () = std::make_unique<gsc::node_thread>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::parameters_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1771 "./IW7/compiler_parser.cpp"
    break;

  case 15: // parameters: parameters COMMA name
#line 176 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::move(yystack_[2].value.as < gsc::parameters_ptr > ()); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1777 "./IW7/compiler_parser.cpp"
    break;

  case 16: // parameters: name
#line 178 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(*pos); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1783 "./IW7/compiler_parser.cpp"
    break;

  case 17: // parameters: %empty
#line 180 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(*pos); }
#line 1789 "./IW7/compiler_parser.cpp"
    break;

  case 18: // block: block stmt
#line 185 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::move(yystack_[1].value.as < gsc::block_ptr > ()); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1795 "./IW7/compiler_parser.cpp"
    break;

  case 19: // block: stmt
#line 187 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(*pos); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1801 "./IW7/compiler_parser.cpp"
    break;

  case 20: // block: %empty
#line 189 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(*pos); }
#line 1807 "./IW7/compiler_parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 193 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_call = std::move(yystack_[0].value.as < gsc::stmt_call_ptr > ()); }
#line 1813 "./IW7/compiler_parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 194 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_assign = std::move(yystack_[0].value.as < gsc::stmt_assign_ptr > ()); }
#line 1819 "./IW7/compiler_parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 195 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_endon = std::move(yystack_[0].value.as < gsc::stmt_endon_ptr > ()); }
#line 1825 "./IW7/compiler_parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 196 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_notify = std::move(yystack_[0].value.as < gsc::stmt_notify_ptr > ()); }
#line 1831 "./IW7/compiler_parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 197 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_wait = std::move(yystack_[0].value.as < gsc::stmt_wait_ptr > ()); }
#line 1837 "./IW7/compiler_parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 198 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittill = std::move(yystack_[0].value.as < gsc::stmt_waittill_ptr > ()); }
#line 1843 "./IW7/compiler_parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 199 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillmatch = std::move(yystack_[0].value.as < gsc::stmt_waittillmatch_ptr > ()); }
#line 1849 "./IW7/compiler_parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 200 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillframeend = std::move(yystack_[0].value.as < gsc::stmt_waittillframeend_ptr > ()); }
#line 1855 "./IW7/compiler_parser.cpp"
    break;

  case 29: // stmt: stmt_if
#line 201 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_if = std::move(yystack_[0].value.as < gsc::stmt_if_ptr > ()); }
#line 1861 "./IW7/compiler_parser.cpp"
    break;

  case 30: // stmt: stmt_ifelse
#line 202 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_ifelse = std::move(yystack_[0].value.as < gsc::stmt_ifelse_ptr > ()); }
#line 1867 "./IW7/compiler_parser.cpp"
    break;

  case 31: // stmt: stmt_while
#line 203 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_while = std::move(yystack_[0].value.as < gsc::stmt_while_ptr > ()); }
#line 1873 "./IW7/compiler_parser.cpp"
    break;

  case 32: // stmt: stmt_for
#line 204 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_for = std::move(yystack_[0].value.as < gsc::stmt_for_ptr > ()); }
#line 1879 "./IW7/compiler_parser.cpp"
    break;

  case 33: // stmt: stmt_foreach
#line 205 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_foreach = std::move(yystack_[0].value.as < gsc::stmt_foreach_ptr > ()); }
#line 1885 "./IW7/compiler_parser.cpp"
    break;

  case 34: // stmt: stmt_switch
#line 206 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_switch = std::move(yystack_[0].value.as < gsc::stmt_switch_ptr > ()); }
#line 1891 "./IW7/compiler_parser.cpp"
    break;

  case 35: // stmt: stmt_case
#line 207 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_case = std::move(yystack_[0].value.as < gsc::stmt_case_ptr > ()); }
#line 1897 "./IW7/compiler_parser.cpp"
    break;

  case 36: // stmt: stmt_default
#line 208 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_default = std::move(yystack_[0].value.as < gsc::stmt_default_ptr > ()); }
#line 1903 "./IW7/compiler_parser.cpp"
    break;

  case 37: // stmt: stmt_break
#line 209 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_break = std::move(yystack_[0].value.as < gsc::stmt_break_ptr > ()); }
#line 1909 "./IW7/compiler_parser.cpp"
    break;

  case 38: // stmt: stmt_continue
#line 210 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_continue = std::move(yystack_[0].value.as < gsc::stmt_continue_ptr > ()); }
#line 1915 "./IW7/compiler_parser.cpp"
    break;

  case 39: // stmt: stmt_return
#line 211 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_return = std::move(yystack_[0].value.as < gsc::stmt_return_ptr > ()); }
#line 1921 "./IW7/compiler_parser.cpp"
    break;

  case 40: // stmt_call: expr_call SEMICOLON
#line 216 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(*pos, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1927 "./IW7/compiler_parser.cpp"
    break;

  case 41: // stmt_call: expr_call_thread SEMICOLON
#line 218 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(*pos, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1933 "./IW7/compiler_parser.cpp"
    break;

  case 42: // stmt_assign: expr_assign SEMICOLON
#line 223 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_assign_ptr > () = std::make_unique<gsc::node_stmt_assign>(*pos, std::move(yystack_[1].value.as < gsc::expr_assign_ptr > ())); }
#line 1939 "./IW7/compiler_parser.cpp"
    break;

  case 43: // stmt_endon: object ENDON LPAREN expr RPAREN SEMICOLON
#line 228 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_endon_ptr > () = std::make_unique<gsc::node_stmt_endon>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1945 "./IW7/compiler_parser.cpp"
    break;

  case 44: // stmt_notify: object NOTIFY LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 233 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1951 "./IW7/compiler_parser.cpp"
    break;

  case 45: // stmt_notify: object NOTIFY LPAREN expr RPAREN SEMICOLON
#line 235 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(*pos)); }
#line 1957 "./IW7/compiler_parser.cpp"
    break;

  case 46: // stmt_wait: WAIT LPAREN expr RPAREN SEMICOLON
#line 240 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1963 "./IW7/compiler_parser.cpp"
    break;

  case 47: // stmt_wait: WAIT number SEMICOLON
#line 242 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::number_ptr > ().as_node))); }
#line 1969 "./IW7/compiler_parser.cpp"
    break;

  case 48: // stmt_waittill: object WAITTILL LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 247 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1975 "./IW7/compiler_parser.cpp"
    break;

  case 49: // stmt_waittill: object WAITTILL LPAREN expr RPAREN SEMICOLON
#line 249 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(*pos)); }
#line 1981 "./IW7/compiler_parser.cpp"
    break;

  case 50: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr RPAREN SEMICOLON
#line 254 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1987 "./IW7/compiler_parser.cpp"
    break;

  case 51: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 259 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(*pos); }
#line 1993 "./IW7/compiler_parser.cpp"
    break;

  case 52: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 264 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1999 "./IW7/compiler_parser.cpp"
    break;

  case 53: // stmt_if: IF LPAREN expr RPAREN stmt
#line 266 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2009 "./IW7/compiler_parser.cpp"
    break;

  case 54: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 275 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2015 "./IW7/compiler_parser.cpp"
    break;

  case 55: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 277 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ()));
        }
#line 2025 "./IW7/compiler_parser.cpp"
    break;

  case 56: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 283 "IW7.parser.ypp"
        { 
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk));
        }
#line 2035 "./IW7/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 289 "IW7.parser.ypp"
        {
            auto blk1 = std::make_unique<gsc::node_block>(*pos);
            blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
            auto blk2 = std::make_unique<gsc::node_block>(*pos);
            blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2));
        }
#line 2047 "./IW7/compiler_parser.cpp"
    break;

  case 58: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 300 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2053 "./IW7/compiler_parser.cpp"
    break;

  case 59: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 302 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 2062 "./IW7/compiler_parser.cpp"
    break;

  case 60: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN LBRACE block RBRACE
#line 310 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2068 "./IW7/compiler_parser.cpp"
    break;

  case 61: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN stmt
#line 312 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2078 "./IW7/compiler_parser.cpp"
    break;

  case 62: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN LBRACE block RBRACE
#line 321 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2084 "./IW7/compiler_parser.cpp"
    break;

  case 63: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN LBRACE block RBRACE
#line 323 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[8].value.as < gsc::name_ptr > ()), std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2090 "./IW7/compiler_parser.cpp"
    break;

  case 64: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN stmt
#line 325 "IW7.parser.ypp"
        {
        auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2100 "./IW7/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN stmt
#line 331 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2110 "./IW7/compiler_parser.cpp"
    break;

  case 66: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 340 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2116 "./IW7/compiler_parser.cpp"
    break;

  case 67: // stmt_case: CASE integer COLON
#line 345 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2122 "./IW7/compiler_parser.cpp"
    break;

  case 68: // stmt_case: CASE neg_integer COLON
#line 347 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2128 "./IW7/compiler_parser.cpp"
    break;

  case 69: // stmt_case: CASE string COLON
#line 349 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 2134 "./IW7/compiler_parser.cpp"
    break;

  case 70: // stmt_default: DEFAULT COLON
#line 354 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(*pos); }
#line 2140 "./IW7/compiler_parser.cpp"
    break;

  case 71: // stmt_break: BREAK SEMICOLON
#line 359 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(*pos); }
#line 2146 "./IW7/compiler_parser.cpp"
    break;

  case 72: // stmt_continue: CONTINUE SEMICOLON
#line 364 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(*pos); }
#line 2152 "./IW7/compiler_parser.cpp"
    break;

  case 73: // stmt_return: RETURN expr SEMICOLON
#line 369 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2158 "./IW7/compiler_parser.cpp"
    break;

  case 74: // stmt_return: RETURN SEMICOLON
#line 371 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::make_unique<gsc::node>()); }
#line 2164 "./IW7/compiler_parser.cpp"
    break;

  case 75: // for_stmt: expr_assign
#line 375 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2170 "./IW7/compiler_parser.cpp"
    break;

  case 76: // for_stmt: %empty
#line 376 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2176 "./IW7/compiler_parser.cpp"
    break;

  case 77: // for_expr: expr_compare
#line 380 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2182 "./IW7/compiler_parser.cpp"
    break;

  case 78: // for_expr: %empty
#line 381 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2188 "./IW7/compiler_parser.cpp"
    break;

  case 79: // expr: expr_compare
#line 385 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2194 "./IW7/compiler_parser.cpp"
    break;

  case 80: // expr: expr_binary
#line 386 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2200 "./IW7/compiler_parser.cpp"
    break;

  case 81: // expr: expr_primitive
#line 387 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2206 "./IW7/compiler_parser.cpp"
    break;

  case 82: // expr_assign: object INCREMENT
#line 391 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2212 "./IW7/compiler_parser.cpp"
    break;

  case 83: // expr_assign: object DECREMENT
#line 392 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2218 "./IW7/compiler_parser.cpp"
    break;

  case 84: // expr_assign: object ASSIGN expr
#line 393 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2224 "./IW7/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 394 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2230 "./IW7/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 395 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2236 "./IW7/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 396 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2242 "./IW7/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_LSHIFT expr
#line 397 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2248 "./IW7/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_RSHIFT expr
#line 398 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2254 "./IW7/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_ADD expr
#line 399 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2260 "./IW7/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_SUB expr
#line 400 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2266 "./IW7/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_MULT expr
#line 401 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2272 "./IW7/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_DIV expr
#line 402 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2278 "./IW7/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_MOD expr
#line 403 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2284 "./IW7/compiler_parser.cpp"
    break;

  case 95: // expr_compare: expr OR expr
#line 407 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2290 "./IW7/compiler_parser.cpp"
    break;

  case 96: // expr_compare: expr AND expr
#line 408 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2296 "./IW7/compiler_parser.cpp"
    break;

  case 97: // expr_compare: expr EQUALITY expr
#line 409 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2302 "./IW7/compiler_parser.cpp"
    break;

  case 98: // expr_compare: expr INEQUALITY expr
#line 410 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2308 "./IW7/compiler_parser.cpp"
    break;

  case 99: // expr_compare: expr LESS_EQUAL expr
#line 411 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2314 "./IW7/compiler_parser.cpp"
    break;

  case 100: // expr_compare: expr GREATER_EQUAL expr
#line 412 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2320 "./IW7/compiler_parser.cpp"
    break;

  case 101: // expr_compare: expr LESS expr
#line 413 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2326 "./IW7/compiler_parser.cpp"
    break;

  case 102: // expr_compare: expr GREATER expr
#line 414 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2332 "./IW7/compiler_parser.cpp"
    break;

  case 103: // expr_binary: expr BITWISE_OR expr
#line 418 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2338 "./IW7/compiler_parser.cpp"
    break;

  case 104: // expr_binary: expr BITWISE_AND expr
#line 419 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2344 "./IW7/compiler_parser.cpp"
    break;

  case 105: // expr_binary: expr BITWISE_EXOR expr
#line 420 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2350 "./IW7/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr LSHIFT expr
#line 421 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2356 "./IW7/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr RSHIFT expr
#line 422 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2362 "./IW7/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr ADD expr
#line 423 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2368 "./IW7/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr SUB expr
#line 424 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2374 "./IW7/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr MULT expr
#line 425 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2380 "./IW7/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr DIV expr
#line 426 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2386 "./IW7/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr MOD expr
#line 427 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2392 "./IW7/compiler_parser.cpp"
    break;

  case 113: // expr_primitive: LPAREN expr RPAREN
#line 431 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2398 "./IW7/compiler_parser.cpp"
    break;

  case 114: // expr_primitive: COMPLEMENT expr
#line 432 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2404 "./IW7/compiler_parser.cpp"
    break;

  case 115: // expr_primitive: NOT expr
#line 433 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2410 "./IW7/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: expr_call
#line 434 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2416 "./IW7/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: expr_call_thread
#line 435 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2422 "./IW7/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: expr_call_childthread
#line 436 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2428 "./IW7/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_function
#line 437 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2434 "./IW7/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_add_array
#line 438 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2440 "./IW7/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_vector
#line 439 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2446 "./IW7/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_array
#line 440 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2452 "./IW7/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_field
#line 441 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2458 "./IW7/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_self
#line 442 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2464 "./IW7/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: expr_size
#line 443 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2470 "./IW7/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: thisthread
#line 444 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::thisthread_ptr > ()); }
#line 2476 "./IW7/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: empty_array
#line 445 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::empty_array_ptr > ()); }
#line 2482 "./IW7/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: undefined
#line 446 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::undefined_ptr > ()); }
#line 2488 "./IW7/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: game
#line 447 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2494 "./IW7/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: self
#line 448 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2500 "./IW7/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: anim
#line 449 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2506 "./IW7/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: level
#line 450 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2512 "./IW7/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: animation
#line 451 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animation_ptr > ()); }
#line 2518 "./IW7/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: animtree
#line 452 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2524 "./IW7/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: name
#line 453 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2530 "./IW7/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: istring
#line 454 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::istring_ptr > ()); }
#line 2536 "./IW7/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: string
#line 455 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2542 "./IW7/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: vector
#line 456 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2548 "./IW7/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: number
#line 457 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::number_ptr > ().as_node); }
#line 2554 "./IW7/compiler_parser.cpp"
    break;

  case 140: // expr_primitive: false
#line 458 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2560 "./IW7/compiler_parser.cpp"
    break;

  case 141: // expr_primitive: true
#line 459 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2566 "./IW7/compiler_parser.cpp"
    break;

  case 142: // expr_call: expr_call_function
#line 463 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2572 "./IW7/compiler_parser.cpp"
    break;

  case 143: // expr_call: expr_call_pointer
#line 464 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2578 "./IW7/compiler_parser.cpp"
    break;

  case 144: // expr_call: object expr_call_function
#line 465 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2584 "./IW7/compiler_parser.cpp"
    break;

  case 145: // expr_call: object expr_call_pointer
#line 466 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2590 "./IW7/compiler_parser.cpp"
    break;

  case 146: // expr_call_thread: THREAD expr_call_function
#line 470 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2596 "./IW7/compiler_parser.cpp"
    break;

  case 147: // expr_call_thread: THREAD expr_call_pointer
#line 471 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2602 "./IW7/compiler_parser.cpp"
    break;

  case 148: // expr_call_thread: object THREAD expr_call_function
#line 472 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2608 "./IW7/compiler_parser.cpp"
    break;

  case 149: // expr_call_thread: object THREAD expr_call_pointer
#line 473 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2614 "./IW7/compiler_parser.cpp"
    break;

  case 150: // expr_call_childthread: CHILDTHREAD expr_call_function
#line 477 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2620 "./IW7/compiler_parser.cpp"
    break;

  case 151: // expr_call_childthread: CHILDTHREAD expr_call_pointer
#line 478 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2626 "./IW7/compiler_parser.cpp"
    break;

  case 152: // expr_call_childthread: object CHILDTHREAD expr_call_function
#line 479 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2632 "./IW7/compiler_parser.cpp"
    break;

  case 153: // expr_call_childthread: object CHILDTHREAD expr_call_pointer
#line 480 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2638 "./IW7/compiler_parser.cpp"
    break;

  case 154: // expr_call_function: name LPAREN expr_arguments RPAREN
#line 485 "IW7.parser.ypp"
        {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2644 "./IW7/compiler_parser.cpp"
    break;

  case 155: // expr_call_function: file DOUBLECOLON name LPAREN expr_arguments RPAREN
#line 487 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::move(yystack_[5].value.as < gsc::file_ptr > ()), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2650 "./IW7/compiler_parser.cpp"
    break;

  case 156: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 492 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2656 "./IW7/compiler_parser.cpp"
    break;

  case 157: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 494 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2662 "./IW7/compiler_parser.cpp"
    break;

  case 158: // expr_arguments: expr_arguments COMMA expr
#line 499 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2668 "./IW7/compiler_parser.cpp"
    break;

  case 159: // expr_arguments: expr
#line 501 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2674 "./IW7/compiler_parser.cpp"
    break;

  case 160: // expr_arguments: %empty
#line 503 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); }
#line 2680 "./IW7/compiler_parser.cpp"
    break;

  case 161: // expr_function: DOUBLECOLON name
#line 508 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2686 "./IW7/compiler_parser.cpp"
    break;

  case 162: // expr_function: file DOUBLECOLON name
#line 510 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::move(yystack_[2].value.as < gsc::file_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2692 "./IW7/compiler_parser.cpp"
    break;

  case 163: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 515 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(*pos, std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2698 "./IW7/compiler_parser.cpp"
    break;

  case 164: // expr_vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 520 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_vector>(*pos, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2704 "./IW7/compiler_parser.cpp"
    break;

  case 165: // expr_array: object LBRACKET expr RBRACKET
#line 525 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(*pos, std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2710 "./IW7/compiler_parser.cpp"
    break;

  case 166: // expr_field: object DOT name
#line 530 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2716 "./IW7/compiler_parser.cpp"
    break;

  case 167: // expr_self: object DOT SELF
#line 535 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_self>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2722 "./IW7/compiler_parser.cpp"
    break;

  case 168: // expr_size: object DOT SIZE
#line 540 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2728 "./IW7/compiler_parser.cpp"
    break;

  case 169: // object: expr_call
#line 544 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2734 "./IW7/compiler_parser.cpp"
    break;

  case 170: // object: expr_array
#line 545 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2740 "./IW7/compiler_parser.cpp"
    break;

  case 171: // object: expr_field
#line 546 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2746 "./IW7/compiler_parser.cpp"
    break;

  case 172: // object: game
#line 547 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2752 "./IW7/compiler_parser.cpp"
    break;

  case 173: // object: self
#line 548 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2758 "./IW7/compiler_parser.cpp"
    break;

  case 174: // object: anim
#line 549 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2764 "./IW7/compiler_parser.cpp"
    break;

  case 175: // object: level
#line 550 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2770 "./IW7/compiler_parser.cpp"
    break;

  case 176: // object: name
#line 551 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2776 "./IW7/compiler_parser.cpp"
    break;

  case 177: // thisthread: THISTHREAD
#line 554 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::thisthread_ptr > () = std::make_unique<gsc::node_thisthread>(*pos); }
#line 2782 "./IW7/compiler_parser.cpp"
    break;

  case 178: // empty_array: EMPTY_ARRAY
#line 555 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::empty_array_ptr > () = std::make_unique<gsc::node_empty_array>(*pos); }
#line 2788 "./IW7/compiler_parser.cpp"
    break;

  case 179: // undefined: UNDEFINED
#line 556 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::undefined_ptr > () = std::make_unique<gsc::node_undefined>(*pos); }
#line 2794 "./IW7/compiler_parser.cpp"
    break;

  case 180: // game: GAME
#line 557 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::game_ptr > () = std::make_unique<gsc::node_game>(*pos); }
#line 2800 "./IW7/compiler_parser.cpp"
    break;

  case 181: // self: SELF
#line 558 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::self_ptr > () = std::make_unique<gsc::node_self>(*pos); }
#line 2806 "./IW7/compiler_parser.cpp"
    break;

  case 182: // anim: ANIM
#line 559 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::anim_ptr > () = std::make_unique<gsc::node_anim>(*pos); }
#line 2812 "./IW7/compiler_parser.cpp"
    break;

  case 183: // level: LEVEL
#line 560 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::level_ptr > () = std::make_unique<gsc::node_level>(*pos); }
#line 2818 "./IW7/compiler_parser.cpp"
    break;

  case 184: // animation: MOD NAME
#line 561 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::animation_ptr > () = std::make_unique<gsc::node_animation>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2824 "./IW7/compiler_parser.cpp"
    break;

  case 185: // animtree: ANIMTREE
#line 562 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(*pos); }
#line 2830 "./IW7/compiler_parser.cpp"
    break;

  case 186: // name: NAME
#line 563 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::name_ptr > () = std::make_unique<gsc::node_name>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2836 "./IW7/compiler_parser.cpp"
    break;

  case 187: // file: FILE
#line 564 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::file_ptr > () = std::make_unique<gsc::node_file>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2842 "./IW7/compiler_parser.cpp"
    break;

  case 188: // istring: ISTRING
#line 565 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::istring_ptr > () = std::make_unique<gsc::node_istring>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2848 "./IW7/compiler_parser.cpp"
    break;

  case 189: // string: STRING
#line 566 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2854 "./IW7/compiler_parser.cpp"
    break;

  case 190: // vector: LPAREN number COMMA number COMMA number RPAREN
#line 570 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_vector>(*pos, std::move(yystack_[5].value.as < gsc::number_ptr > ()), std::move(yystack_[3].value.as < gsc::number_ptr > ()), std::move(yystack_[1].value.as < gsc::number_ptr > ())); }
#line 2860 "./IW7/compiler_parser.cpp"
    break;

  case 191: // number: neg_float
#line 574 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2866 "./IW7/compiler_parser.cpp"
    break;

  case 192: // number: neg_integer
#line 575 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2872 "./IW7/compiler_parser.cpp"
    break;

  case 193: // number: float
#line 576 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2878 "./IW7/compiler_parser.cpp"
    break;

  case 194: // number: integer
#line 577 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer  = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2884 "./IW7/compiler_parser.cpp"
    break;

  case 195: // neg_float: SUB FLOAT
#line 580 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2890 "./IW7/compiler_parser.cpp"
    break;

  case 196: // neg_integer: SUB INTEGER
#line 581 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2896 "./IW7/compiler_parser.cpp"
    break;

  case 197: // float: FLOAT
#line 582 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2902 "./IW7/compiler_parser.cpp"
    break;

  case 198: // integer: INTEGER
#line 583 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2908 "./IW7/compiler_parser.cpp"
    break;

  case 199: // false: FALSE
#line 584 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(*pos); }
#line 2914 "./IW7/compiler_parser.cpp"
    break;

  case 200: // true: TRUE
#line 585 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(*pos); }
#line 2920 "./IW7/compiler_parser.cpp"
    break;


#line 2924 "./IW7/compiler_parser.cpp"

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
    "end of file", "error", "invalid token", "INCLUDE", "USINGTREE",
  "ANIMTREE", "ENDON", "NOTIFY", "WAIT", "WAITTILL", "WAITTILLMATCH",
  "WAITTILLFRAMEEND", "IF", "ELSE", "WHILE", "FOR", "FOREACH", "IN",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "THREAD",
  "CHILDTHREAD", "THISTHREAD", "CALL", "TRUE", "FALSE", "UNDEFINED",
  "SIZE", "GAME", "SELF", "ANIM", "LEVEL", "EMPTY_ARRAY", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA", "DOT",
  "DOUBLECOLON", "COLON", "SEMICOLON", "INCREMENT", "DECREMENT", "MOD",
  "LSHIFT", "RSHIFT", "OR", "AND", "EQUALITY", "INEQUALITY", "LESS_EQUAL",
  "GREATER_EQUAL", "LESS", "GREATER", "NOT", "COMPLEMENT", "ASSIGN_RSHIFT",
  "ASSIGN", "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_MULT", "ASSIGN_DIV",
  "ASSIGN_MOD", "ASSIGN_BITWISE_OR", "ASSIGN_BITWISE_AND",
  "ASSIGN_BITWISE_EXOR", "ASSIGN_LSHIFT", "BITWISE_OR", "BITWISE_AND",
  "BITWISE_EXOR", "ADD", "SUB", "MULT", "DIV", "FILE", "NAME", "STRING",
  "ISTRING", "FLOAT", "INTEGER", "$accept", "root", "program", "include",
  "define", "usingtree", "constant", "thread", "parameters", "block",
  "stmt", "stmt_call", "stmt_assign", "stmt_endon", "stmt_notify",
  "stmt_wait", "stmt_waittill", "stmt_waittillmatch",
  "stmt_waittillframeend", "stmt_if", "stmt_ifelse", "stmt_while",
  "stmt_for", "stmt_foreach", "stmt_switch", "stmt_case", "stmt_default",
  "stmt_break", "stmt_continue", "stmt_return", "for_stmt", "for_expr",
  "expr", "expr_assign", "expr_compare", "expr_binary", "expr_primitive",
  "expr_call", "expr_call_thread", "expr_call_childthread",
  "expr_call_function", "expr_call_pointer", "expr_arguments",
  "expr_function", "expr_add_array", "expr_vector", "expr_array",
  "expr_field", "expr_self", "expr_size", "object", "thisthread",
  "empty_array", "undefined", "game", "self", "anim", "level", "animation",
  "animtree", "name", "file", "istring", "string", "vector", "number",
  "neg_float", "neg_integer", "float", "integer", "false", "true", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -306;

  const short parser::yytable_ninf_ = -177;

  const short
  parser::yypact_[] =
  {
       7,   -67,   -14,  -306,    37,     7,  -306,  -306,  -306,  -306,
    -306,   -17,  -306,    -1,   -29,  -306,  -306,  -306,   -22,  1185,
    -306,  -306,    29,    -8,  -306,  -306,    56,    56,  -306,    41,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  1185,  1248,
     -22,    11,  1185,  1185,   -69,  -306,  -306,  -306,  2367,  -306,
    -306,  -306,     9,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
      18,    24,  -306,  -306,    51,  -306,  -306,  -306,   246,   250,
     312,   393,  -306,  -306,   -12,    49,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,    66,    75,   -22,    85,
    -306,  -306,    92,    86,  -306,  -306,    94,  1906,    97,  1248,
    2412,    42,  -306,  -306,  2412,  2412,  -306,  -306,  -306,  1185,
    1185,  1185,  1185,  1185,  1185,  1185,  1185,  1185,  1185,  1185,
    1185,  1185,  1185,  1185,  1185,  1185,  1185,    56,    56,  1248,
      -9,  -306,  -306,  1185,   -22,  -306,  1907,  -306,  1185,   -22,
    1185,  -306,  1185,    26,  2195,  -306,  1185,  2412,  2412,  2412,
    2412,  2412,  2412,  2412,  2412,  2412,  2412,  2412,  2412,  2412,
    2412,  2412,  2412,  2412,  2412,  -306,  -306,  -306,  -306,  2226,
    -306,  -306,  -306,    20,   106,     1,   100,   107,   114,   122,
     123,   125,    38,   132,   133,   136,  1122,   134,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,   137,   139,
     144,  -306,  -306,  1294,  -306,  -306,  -306,  -306,    92,  2195,
     106,  2257,  2295,   142,   150,  2412,  -306,  -306,  1185,  1185,
     147,  -306,  1185,  1185,   138,   -22,  1185,   109,   153,   155,
     157,  -306,  -306,  -306,  -306,  2401,  -306,  -306,  -306,  -306,
    -306,   167,   168,   170,   172,   -22,  -306,  -306,  1185,  1185,
    1185,  1185,  1185,  1185,  1185,  1185,  1185,  1185,  1185,   169,
    1185,    26,   173,    23,   897,  -306,  2003,  2035,   165,  -306,
    -306,   544,    14,  2046,  -306,  -306,  -306,  -306,  1185,  1185,
    1185,  1185,  2412,  2412,  2412,  2412,  2412,  2412,  2412,  2412,
    2412,  2412,  2412,   177,  2078,   179,  1185,  -306,   171,  1366,
    1398,  1185,  1185,   -22,   182,  2089,  1949,  1992,  2333,  1185,
    -306,  -306,    58,  -306,  1907,   214,  1907,  -306,   181,  2412,
     183,  2121,   212,  1907,   184,   185,  1185,   186,  1185,  1185,
      72,  -306,  1441,  1475,  1513,   138,  1547,  1185,  1585,  -306,
    -306,    79,  -306,    82,  2132,  -306,   223,  1907,  -306,  -306,
     204,  1907,  -306,  2164,  -306,   196,   197,   200,  1619,  1657,
    1691,  1729,  1763,  -306,  -306,  -306,  1907,  -306,  -306,  1907,
    -306,  -306,  1907,  -306,  1801,  1835,  1873,  -306,  -306,  -306
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   186,     0,     2,     6,     7,     9,    10,
      11,     0,   187,     0,     0,     1,     4,     5,    17,     0,
       8,   189,     0,     0,    16,   185,     0,     0,   177,     0,
     200,   199,   179,   180,   181,   182,   183,   178,     0,   160,
       0,     0,     0,     0,     0,   188,   197,   198,     0,    79,
      80,    81,   116,   117,   118,   142,   143,   119,   120,   121,
     122,   123,   124,   125,     0,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,   136,   137,   138,   139,
     191,   192,   193,   194,   140,   141,     0,     0,     0,     0,
     146,   147,     0,     0,   150,   151,     0,     0,   139,   160,
     159,     0,   161,   184,   115,   114,   195,   196,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,   160,     0,    12,    20,    15,     0,     0,
       0,   113,     0,     0,   159,   163,     0,   112,   106,   107,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   108,   109,   110,   111,   148,   149,   152,   153,     0,
     168,   167,   166,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,   169,
       0,   170,   171,     0,   172,   173,   174,   175,   176,     0,
       0,     0,     0,     0,     0,   158,   165,   154,   160,     0,
       0,    51,     0,     0,    76,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    74,     0,    14,    18,    42,    40,
      41,     0,     0,     0,     0,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,    75,
     169,     0,     0,     0,    69,    68,    67,    73,     0,     0,
       0,     0,    89,    84,    90,    91,    92,    93,    94,    85,
      86,    87,    88,     0,     0,     0,   160,   155,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,   160,
     164,   190,     0,    46,    20,    53,    20,    59,     0,     0,
      79,     0,     0,    20,     0,     0,   160,     0,   160,     0,
       0,   156,     0,     0,     0,    76,     0,     0,     0,    43,
      45,     0,    49,     0,     0,   157,    52,    20,    57,    58,
       0,    20,    64,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    48,    50,    20,    56,    55,    20,
      61,    62,    20,    65,     0,     0,     0,    54,    60,    63
  };

  const short
  parser::yypgoto_[] =
  {
    -306,  -306,  -306,   243,   244,  -306,  -306,  -306,  -306,  -305,
    -146,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
     -95,  -306,   370,  -226,   -60,  -306,  -306,   194,   -64,  -306,
     -25,   -20,  -130,  -306,  -306,  -306,   362,   433,  -306,  -306,
     487,  -306,  -306,  -306,   558,   636,   690,   754,  -306,  -306,
       0,    54,  -306,    -5,  -306,   -34,  -306,    70,  -306,    71,
    -306,  -306
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    23,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     278,   328,   100,   208,    49,    50,    51,    52,    53,    54,
      55,    56,   101,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85
  };

  const short
  parser::yytable_[] =
  {
      11,    90,    94,   173,    98,    11,    91,    95,   279,    22,
       1,     2,  -176,  -176,    12,  -176,   106,   107,    24,   342,
      18,   344,   170,    14,   171,   133,    92,    92,   348,  -176,
      87,   312,  -176,  -169,  -169,    88,  -169,    15,   229,   131,
     102,   247,  -170,  -170,   132,  -170,    20,    19,  -171,  -171,
    -169,  -171,   369,  -169,    21,    13,   371,   313,   227,  -170,
       3,   307,  -170,   146,    92,  -171,   146,    86,  -171,  -176,
    -176,   384,   210,     3,   385,   127,   128,   386,    29,    44,
      93,    93,    96,    29,   145,   146,    46,    47,   137,     3,
    -169,  -169,   129,   103,   134,   130,   341,    89,   273,  -170,
    -170,   146,   165,   167,    44,  -171,  -171,   166,   168,   223,
     355,    46,    47,   135,   136,   146,   237,   365,    93,   279,
     366,    21,   146,   210,    47,   146,   138,    92,    92,   133,
     172,   139,    12,     3,   174,   140,   218,    12,     3,   220,
     143,   230,   175,   228,   232,   176,   177,   231,   178,   179,
     180,   233,   181,   182,   183,   184,   185,   186,    26,   234,
     235,    29,   236,   325,   327,    29,    33,    34,    35,    36,
      33,    34,    35,    36,   246,    89,   322,   238,   241,    89,
     242,    93,    93,   243,   248,   271,   249,   218,   131,   340,
      93,   250,   272,   132,   275,   107,   247,   358,   247,   284,
     362,   285,   247,   286,   288,   289,   351,   290,   353,   291,
     306,   303,   311,    92,   319,    12,     3,   321,   323,    12,
       3,   333,   377,   247,   380,   247,   383,   343,   345,   347,
     -77,   349,   350,   352,   218,   282,   368,   305,   247,   247,
     247,    93,   370,   373,   374,   210,   210,   375,    16,    17,
     360,   330,   239,   240,     0,   172,   131,     0,     0,     0,
     210,   132,   210,     0,     0,     0,     0,    93,     0,   210,
    -172,  -172,     0,  -172,  -173,  -173,     0,  -173,   210,   210,
     210,    92,   210,     0,   210,     0,     0,  -172,    93,     0,
    -172,  -173,     0,   210,  -173,     0,     0,   210,     0,     0,
       0,     0,     0,     0,   210,   210,   210,   210,   210,   218,
     218,     0,   210,   332,     0,   210,     0,     0,   210,     0,
     210,   210,   210,     0,   218,     0,   218,  -172,  -172,     0,
     209,  -173,  -173,   218,     0,    93,  -174,  -174,     0,  -174,
       0,     0,   218,   218,   218,   218,   218,     0,   218,     0,
       0,     0,     0,  -174,     0,     0,  -174,   218,     0,     0,
       0,   218,     0,    93,    93,     0,     0,     0,   218,   218,
     218,   218,   218,     0,     0,     0,   218,     0,    93,   218,
      93,   209,   218,     0,   218,   218,   218,    93,     0,    48,
       0,     0,     0,  -174,  -174,     0,    93,    93,    93,    93,
      93,     0,    93,     0,     0,     0,     0,     0,    97,     0,
       0,    93,   104,   105,     0,    93,     0,  -175,  -175,     0,
    -175,     0,    93,    93,    93,    93,    93,     0,   280,     0,
      93,     0,     0,    93,  -175,     0,    93,  -175,    93,    93,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,  -175,  -175,     0,     0,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   211,   169,
       0,     0,     0,   209,   209,     0,     0,     0,   219,     0,
     221,     0,   222,     0,     0,     0,   225,     0,   209,     0,
     209,     0,     0,     0,     0,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   209,   209,   280,
     209,     0,   209,     0,     0,     0,     0,     0,     0,   211,
       0,   209,     0,     0,     0,   209,   245,     0,     0,     0,
       0,     0,   209,   209,   209,   209,   209,     0,     0,   212,
     209,    29,     0,   209,     0,     0,   209,     0,   209,   209,
     209,     0,     0,     0,     0,   129,     0,     0,   255,     0,
       0,     0,   256,   257,     0,     0,   211,     0,     0,   274,
       0,     0,   276,   277,     0,     0,   283,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,     0,     0,
     212,     0,     0,   213,     0,    12,     3,     0,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,     0,
     304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,   316,
     317,   318,     0,     0,     0,     0,     0,   212,     0,     0,
       0,   211,   211,     0,   213,     0,     0,     0,     0,     0,
       0,   329,   331,     0,     0,     0,   211,     0,   211,     0,
       0,     0,     0,     0,   214,   211,     0,     0,     0,     0,
       0,     0,     0,     0,   211,   211,   211,   211,   211,   354,
     211,     0,     0,     0,     0,     0,     0,   363,     0,   211,
       0,   281,     0,   211,     0,     0,     0,     0,     0,     0,
     211,   211,   211,   211,   211,     0,     0,     0,   211,     0,
       0,   211,   212,   212,   211,   214,   211,   211,   211,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,   212,
       0,     0,     0,     0,     0,     0,   212,     0,     0,     0,
       0,     0,   215,     0,     0,   212,   212,   212,   212,   212,
       0,   212,     0,     0,     0,     0,     0,     0,     0,     0,
     212,     0,   214,     0,   212,     0,   213,   213,     0,     0,
       0,   212,   212,   212,   212,   212,     0,     0,     0,   212,
       0,   213,   212,   213,     0,   212,     0,   212,   212,   212,
     213,     0,     0,   215,     0,     0,   216,     0,     0,   213,
     213,   213,   281,   213,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,   213,   213,   213,   213,   213,
       0,     0,     0,   213,     0,     0,   213,   214,   214,   213,
     215,   213,   213,   213,     0,     0,     0,   216,     0,     0,
       0,     0,   214,     0,   214,     0,     0,     0,     0,     0,
     217,   214,     0,     0,     0,     0,     0,     0,     0,     0,
     214,   214,   214,   214,   214,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,   214,
       0,     0,     0,     0,   216,     0,   214,   214,   214,   214,
     214,     0,     0,     0,   214,   308,     0,   214,     0,     0,
     214,   217,   214,   214,   214,   215,   215,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     215,     0,   215,     0,     0,     0,     0,     0,     0,   215,
       0,   120,   121,   122,   123,   124,   125,   126,   215,   215,
     215,   215,   215,     0,   215,     0,     0,     0,   217,     0,
       0,     0,     0,   215,     0,     0,     0,   215,     0,   216,
     216,     0,     0,     0,   215,   215,   215,   215,   215,     0,
       0,     0,   215,     0,   216,   215,   216,     0,   215,     0,
     215,   215,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   216,   216,   216,   216,     0,   216,     0,
       0,     0,     0,     0,     0,     0,     0,   216,     0,     0,
       0,   216,     0,     0,     0,     0,     0,     0,   216,   216,
     216,   216,   216,   217,   217,     0,   216,     0,     0,   216,
       0,     0,   216,     0,   216,   216,   216,     0,   217,     0,
     217,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   217,   217,   217,
     217,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,   217,   217,   217,   217,   217,    25,     0,     0,
     217,     0,     0,   217,     0,     0,   217,     0,   217,   217,
     217,     0,     0,     0,     0,     0,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,    39,     0,     0,     0,    40,     0,   244,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,    12,     3,    21,    45,    46,    47,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     0,     0,
      40,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,    12,     3,    21,    45,
      46,    47,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,    99,
       0,     0,     0,    40,     0,     0,     0,     0,    41,     0,
     251,   252,     0,   253,   254,     0,     0,     0,     0,    42,
      43,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,    29,     0,     0,     0,     0,    44,     0,     0,    12,
       3,    21,    45,    46,    47,   129,     0,     0,   255,     0,
       0,     0,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,     0,     0,
       0,     0,     0,     0,   175,    12,     3,   176,   177,     0,
     178,   179,   180,     0,   181,   182,   183,   184,   185,   186,
      26,     0,     0,    29,     0,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,   324,   175,    89,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,   326,     0,    89,
       0,     0,     0,     0,     0,     0,     0,    12,     3,   175,
       0,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,    12,
       3,   356,    89,   175,     0,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,   357,     0,    89,     0,     0,     0,
       0,   175,    12,     3,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,     0,   359,    89,   175,    12,     3,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,   361,     0,    89,     0,
       0,     0,     0,   175,    12,     3,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,     0,   364,    89,   175,    12,     3,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,    26,     0,     0,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,     0,   376,     0,
      89,     0,     0,     0,     0,   175,    12,     3,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,     0,   378,    89,   175,
      12,     3,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
     379,     0,    89,     0,     0,     0,     0,   175,    12,     3,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,    26,     0,     0,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,     0,     0,   381,
      89,   175,    12,     3,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,   382,     0,    89,     0,     0,     0,     0,   175,
      12,     3,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
       0,   387,    89,   175,    12,     3,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,     0,   388,    89,     0,     0,     0,
       0,   175,    12,     3,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,     0,   389,    89,   175,    12,     3,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,   141,     0,     0,     0,    89,   142,
       0,     0,     0,     0,    12,     3,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   335,    12,     3,
       0,     0,   336,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     337,     0,     0,     0,     0,   338,     0,     0,     0,     0,
       0,   309,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,   123,
     124,   125,   126,   310,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   314,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   320,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   334,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   346,
       0,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     367,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   372,     0,     0,     0,   120,   121,   122,   123,
     124,   125,   126,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,   120,   121,
     122,   123,   124,   125,   126,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   120,
     121,   122,   123,   124,   125,   126,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
     120,   121,   122,   123,   124,   125,   126,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   270,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   339,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   287,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,   120,   121,   122,   123,
     124,   125,   126
  };

  const short
  parser::yycheck_[] =
  {
       0,    26,    27,   133,    38,     5,    26,    27,   234,    14,
       3,     4,    24,    25,    81,    27,    85,    86,    18,   324,
      37,   326,    31,    37,    33,    37,    26,    27,   333,    41,
      38,    17,    44,    24,    25,    43,    27,     0,    37,    64,
      40,   187,    24,    25,    64,    27,    47,    64,    24,    25,
      41,    27,   357,    44,    83,     1,   361,    43,    38,    41,
      82,    38,    44,    43,    64,    41,    43,    38,    44,    81,
      82,   376,   136,    82,   379,    24,    25,   382,    27,    78,
      26,    27,    41,    27,    42,    43,    85,    86,    88,    82,
      81,    82,    41,    82,    45,    44,    38,    41,   228,    81,
      82,    43,   127,   128,    78,    81,    82,   127,   128,   143,
      38,    85,    86,    47,    39,    43,    78,    38,    64,   345,
      38,    83,    43,   187,    86,    43,    41,   127,   128,    37,
     130,    45,    81,    82,   134,    41,   136,    81,    82,   139,
      43,   175,     8,    37,    37,    11,    12,    47,    14,    15,
      16,    37,    18,    19,    20,    21,    22,    23,    24,    37,
      37,    27,    37,   309,   310,    27,    32,    33,    34,    35,
      32,    33,    34,    35,    40,    41,   306,   182,    46,    41,
      47,   127,   128,    47,    47,    43,    47,   187,   213,   319,
     136,    47,    42,   213,    47,    86,   342,   343,   344,    46,
     346,    46,   348,    46,    37,    37,   336,    37,   338,    37,
      37,    42,    47,   213,    37,    81,    82,    38,    47,    81,
      82,    39,   368,   369,   370,   371,   372,    13,    47,    17,
      47,    47,    47,    47,   234,   235,    13,   271,   384,   385,
     386,   187,    38,    47,    47,   309,   310,    47,     5,     5,
     345,   311,   182,   182,    -1,   255,   281,    -1,    -1,    -1,
     324,   281,   326,    -1,    -1,    -1,    -1,   213,    -1,   333,
      24,    25,    -1,    27,    24,    25,    -1,    27,   342,   343,
     344,   281,   346,    -1,   348,    -1,    -1,    41,   234,    -1,
      44,    41,    -1,   357,    44,    -1,    -1,   361,    -1,    -1,
      -1,    -1,    -1,    -1,   368,   369,   370,   371,   372,   309,
     310,    -1,   376,   313,    -1,   379,    -1,    -1,   382,    -1,
     384,   385,   386,    -1,   324,    -1,   326,    81,    82,    -1,
     136,    81,    82,   333,    -1,   281,    24,    25,    -1,    27,
      -1,    -1,   342,   343,   344,   345,   346,    -1,   348,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    44,   357,    -1,    -1,
      -1,   361,    -1,   309,   310,    -1,    -1,    -1,   368,   369,
     370,   371,   372,    -1,    -1,    -1,   376,    -1,   324,   379,
     326,   187,   382,    -1,   384,   385,   386,   333,    -1,    19,
      -1,    -1,    -1,    81,    82,    -1,   342,   343,   344,   345,
     346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,   357,    42,    43,    -1,   361,    -1,    24,    25,    -1,
      27,    -1,   368,   369,   370,   371,   372,    -1,   234,    -1,
     376,    -1,    -1,   379,    41,    -1,   382,    44,   384,   385,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   136,   129,
      -1,    -1,    -1,   309,   310,    -1,    -1,    -1,   138,    -1,
     140,    -1,   142,    -1,    -1,    -1,   146,    -1,   324,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   342,   343,   344,   345,
     346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   357,    -1,    -1,    -1,   361,   186,    -1,    -1,    -1,
      -1,    -1,   368,   369,   370,   371,   372,    -1,    -1,   136,
     376,    27,    -1,   379,    -1,    -1,   382,    -1,   384,   385,
     386,    -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    -1,    -1,   234,    -1,    -1,   229,
      -1,    -1,   232,   233,    -1,    -1,   236,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
     187,    -1,    -1,   136,    -1,    81,    82,    -1,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,
     290,   291,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,   309,   310,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,   311,   312,    -1,    -1,    -1,   324,    -1,   326,    -1,
      -1,    -1,    -1,    -1,   136,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   342,   343,   344,   345,   346,   339,
     348,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,   357,
      -1,   234,    -1,   361,    -1,    -1,    -1,    -1,    -1,    -1,
     368,   369,   370,   371,   372,    -1,    -1,    -1,   376,    -1,
      -1,   379,   309,   310,   382,   187,   384,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,   326,
      -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,   342,   343,   344,   345,   346,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,   234,    -1,   361,    -1,   309,   310,    -1,    -1,
      -1,   368,   369,   370,   371,   372,    -1,    -1,    -1,   376,
      -1,   324,   379,   326,    -1,   382,    -1,   384,   385,   386,
     333,    -1,    -1,   187,    -1,    -1,   136,    -1,    -1,   342,
     343,   344,   345,   346,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,
      -1,    -1,    -1,    -1,    -1,   368,   369,   370,   371,   372,
      -1,    -1,    -1,   376,    -1,    -1,   379,   309,   310,   382,
     234,   384,   385,   386,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,   324,    -1,   326,    -1,    -1,    -1,    -1,    -1,
     136,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     342,   343,   344,   345,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,    -1,    -1,    -1,   234,    -1,   368,   369,   370,   371,
     372,    -1,    -1,    -1,   376,    38,    -1,   379,    -1,    -1,
     382,   187,   384,   385,   386,   309,   310,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
     324,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,   333,
      -1,    74,    75,    76,    77,    78,    79,    80,   342,   343,
     344,   345,   346,    -1,   348,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   309,
     310,    -1,    -1,    -1,   368,   369,   370,   371,   372,    -1,
      -1,    -1,   376,    -1,   324,   379,   326,    -1,   382,    -1,
     384,   385,   386,   333,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   342,   343,   344,   345,   346,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,   361,    -1,    -1,    -1,    -1,    -1,    -1,   368,   369,
     370,   371,   372,   309,   310,    -1,   376,    -1,    -1,   379,
      -1,    -1,   382,    -1,   384,   385,   386,    -1,   324,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   342,   343,   344,   345,
     346,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,
      -1,    -1,   368,   369,   370,   371,   372,     5,    -1,    -1,
     376,    -1,    -1,   379,    -1,    -1,   382,    -1,   384,   385,
     386,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    47,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    81,    82,    83,    84,    85,    86,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    81,    82,    83,    84,
      85,    86,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    41,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    81,    82,    11,    12,    -1,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,     8,    41,    -1,    11,
      12,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,     8,
      -1,    -1,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    81,
      82,    40,    41,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,     8,    81,    82,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,     8,    81,    82,    11,    12,
      -1,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,     8,    81,    82,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,     8,    81,    82,
      11,    12,    -1,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,     8,    81,    82,    11,    12,
      -1,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    41,     8,
      81,    82,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,     8,    81,    82,
      11,    12,    -1,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      41,     8,    81,    82,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,     8,
      81,    82,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    41,     8,    81,    82,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,     8,    81,    82,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,     8,    81,    82,    11,    12,
      -1,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    38,    -1,    -1,    -1,    41,    43,
      -1,    -1,    -1,    -1,    81,    82,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    38,    81,    82,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    38,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    38,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    38,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    38,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    38,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    38,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      38,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    38,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    74,    75,
      76,    77,    78,    79,    80,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    74,
      75,    76,    77,    78,    79,    80,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      74,    75,    76,    77,    78,    79,    80,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    47,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,    82,    88,    89,    90,    91,    92,    93,
      94,   147,    81,   148,    37,     0,    90,    91,    37,    64,
      47,    83,   150,    95,   147,     5,    24,    25,    26,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    37,    41,
      45,    50,    61,    62,    78,    84,    85,    86,   119,   121,
     122,   123,   124,   125,   126,   127,   128,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    38,    38,    43,    41,
     127,   128,   147,   148,   127,   128,    41,   119,   152,    41,
     119,   129,   147,    82,   119,   119,    85,    86,    47,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      74,    75,    76,    77,    78,    79,    80,    24,    25,    41,
      44,   127,   128,    37,    45,    47,    39,   147,    41,    45,
      41,    38,    43,    43,   119,    42,    43,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   127,   128,   127,   128,   119,
      31,    33,   147,   129,   147,     8,    11,    12,    14,    15,
      16,    18,    19,    20,    21,    22,    23,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   120,   124,
     125,   133,   134,   137,   141,   142,   143,   144,   147,   119,
     147,   119,   119,   152,    42,   119,    42,    38,    37,    37,
     152,    47,    37,    37,    37,    37,    37,    78,   150,   154,
     156,    46,    47,    47,    47,   119,    40,    97,    47,    47,
      47,     6,     7,     9,    10,    44,    48,    49,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    42,
      43,    43,    42,   129,   119,    47,   119,   119,   117,   120,
     124,   137,   147,   119,    46,    46,    46,    47,    37,    37,
      37,    37,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,    42,   119,   152,    37,    38,    38,    38,
      38,    47,    17,    43,    38,   119,   119,   119,   119,    37,
      38,    38,   129,    47,    39,    97,    39,    97,   118,   119,
     121,   119,   147,    39,    38,    38,    43,    38,    43,    43,
     129,    38,    96,    13,    96,    47,    38,    17,    96,    47,
      47,   129,    47,   129,   119,    38,    40,    39,    97,    40,
     117,    39,    97,   119,    40,    38,    38,    38,    13,    96,
      38,    96,    38,    47,    47,    47,    39,    97,    40,    39,
      97,    40,    39,    97,    96,    96,    96,    40,    40,    40
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    87,    88,    88,    89,    89,    89,    89,    90,    91,
      91,    91,    92,    93,    94,    95,    95,    95,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,   100,   101,   101,   102,   102,   103,   103,
     104,   105,   106,   106,   107,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   110,   110,   111,   112,   112,   112,
     113,   114,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   130,   130,   131,   132,   133,   134,   135,   136,   137,
     137,   137,   137,   137,   137,   137,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   152,   152,   152,   153,   154,   155,   156,   157,
     158
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
      11,     9,     9,    11,     7,     9,     7,     3,     3,     3,
       2,     2,     2,     3,     2,     1,     0,     1,     0,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     3,
       2,     2,     3,     3,     4,     6,     8,     9,     3,     1,
       0,     2,     3,     3,     7,     4,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       7,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1
  };




#if IW7DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   133,   133,   134,   138,   140,   142,   144,   149,   154,
     155,   156,   160,   165,   170,   175,   177,   180,   184,   186,
     189,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     215,   217,   222,   227,   232,   234,   239,   241,   246,   248,
     253,   258,   263,   265,   274,   276,   282,   288,   299,   301,
     309,   311,   320,   322,   324,   330,   339,   344,   346,   348,
     353,   358,   363,   368,   370,   375,   376,   380,   381,   385,
     386,   387,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   407,   408,   409,   410,   411,
     412,   413,   414,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   463,   464,   465,   466,   470,   471,   472,   473,
     477,   478,   479,   480,   484,   486,   491,   493,   498,   500,
     503,   507,   509,   514,   519,   524,   529,   534,   539,   544,
     545,   546,   547,   548,   549,   550,   551,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     569,   574,   575,   576,   577,   580,   581,   582,   583,   584,
     585
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
#line 4181 "./IW7/compiler_parser.cpp"

#line 587 "IW7.parser.ypp"


void IW7::parser::error(const std::string& msg)
{
    throw gsc::comp_error(0, msg);
}
