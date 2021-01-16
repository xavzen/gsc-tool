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
#line 37 "S2.parser.ypp"

    #include "S2.hpp"
    #include "compiler_parser.hpp"
    #include "compiler_lexer.hpp"
    S2::parser::symbol_type S2lex(yyscan_t yyscanner, std::uint32_t *pos);

#line 46 "./S2/compiler_parser.cpp"

// Take the name prefix into account.
#define yylex   S2lex



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
#if S2DEBUG

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

#else // !S2DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !S2DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "S2.parser.ypp"
namespace S2 {
#line 129 "./S2/compiler_parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, std::uint32_t *pos_yyarg, gsc::program_ptr& astout_yyarg)
#if S2DEBUG
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

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.YY_MOVE_OR_COPY< gsc::stmt_waitframe_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.move< gsc::stmt_waitframe_ptr > (YY_MOVE (that.value));
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

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.copy< gsc::stmt_waitframe_ptr > (that.value);
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

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        value.move< gsc::stmt_waitframe_ptr > (that.value);
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

#if S2DEBUG
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

#if S2DEBUG
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
#endif // S2DEBUG

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

      case symbol_kind::S_stmt_waitframe: // stmt_waitframe
        yylhs.value.emplace< gsc::stmt_waitframe_ptr > ();
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
#line 134 "S2.parser.ypp"
              { astout = std::move(yystack_[0].value.as < gsc::program_ptr > ()); }
#line 1719 "./S2/compiler_parser.cpp"
    break;

  case 3: // root: %empty
#line 135 "S2.parser.ypp"
              { astout = std::make_unique<gsc::node_program>(); }
#line 1725 "./S2/compiler_parser.cpp"
    break;

  case 4: // program: program include
#line 140 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1731 "./S2/compiler_parser.cpp"
    break;

  case 5: // program: program define
#line 142 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1737 "./S2/compiler_parser.cpp"
    break;

  case 6: // program: include
#line 144 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(*pos); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1743 "./S2/compiler_parser.cpp"
    break;

  case 7: // program: define
#line 146 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(*pos); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1749 "./S2/compiler_parser.cpp"
    break;

  case 8: // include: INCLUDE file SEMICOLON
#line 151 "S2.parser.ypp"
        { yylhs.value.as < gsc::include_ptr > () = std::make_unique<gsc::node_include>(*pos, std::move(yystack_[1].value.as < gsc::file_ptr > ())); }
#line 1755 "./S2/compiler_parser.cpp"
    break;

  case 9: // define: usingtree
#line 155 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_usingtree = std::move(yystack_[0].value.as < gsc::usingtree_ptr > ()); }
#line 1761 "./S2/compiler_parser.cpp"
    break;

  case 10: // define: constant
#line 156 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_constant = std::move(yystack_[0].value.as < gsc::constant_ptr > ()); }
#line 1767 "./S2/compiler_parser.cpp"
    break;

  case 11: // define: thread
#line 157 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_thread = std::move(yystack_[0].value.as < gsc::thread_ptr > ()); }
#line 1773 "./S2/compiler_parser.cpp"
    break;

  case 12: // usingtree: USINGTREE LPAREN string RPAREN SEMICOLON
#line 162 "S2.parser.ypp"
        { yylhs.value.as < gsc::usingtree_ptr > () = std::make_unique<gsc::node_usingtree>(*pos, std::move(yystack_[2].value.as < gsc::string_ptr > ())); }
#line 1779 "./S2/compiler_parser.cpp"
    break;

  case 13: // constant: name ASSIGN expr SEMICOLON
#line 167 "S2.parser.ypp"
        { yylhs.value.as < gsc::constant_ptr > () = std::make_unique<gsc::node_constant>(*pos, std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1785 "./S2/compiler_parser.cpp"
    break;

  case 14: // thread: name LPAREN parameters RPAREN LBRACE block RBRACE
#line 172 "S2.parser.ypp"
        { yylhs.value.as < gsc::thread_ptr > () = std::make_unique<gsc::node_thread>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::parameters_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1791 "./S2/compiler_parser.cpp"
    break;

  case 15: // parameters: parameters COMMA name
#line 177 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::move(yystack_[2].value.as < gsc::parameters_ptr > ()); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1797 "./S2/compiler_parser.cpp"
    break;

  case 16: // parameters: name
#line 179 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(*pos); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1803 "./S2/compiler_parser.cpp"
    break;

  case 17: // parameters: %empty
#line 181 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(*pos); }
#line 1809 "./S2/compiler_parser.cpp"
    break;

  case 18: // block: block stmt
#line 186 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::move(yystack_[1].value.as < gsc::block_ptr > ()); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1815 "./S2/compiler_parser.cpp"
    break;

  case 19: // block: stmt
#line 188 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(*pos); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1821 "./S2/compiler_parser.cpp"
    break;

  case 20: // block: %empty
#line 190 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(*pos); }
#line 1827 "./S2/compiler_parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 194 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_call = std::move(yystack_[0].value.as < gsc::stmt_call_ptr > ()); }
#line 1833 "./S2/compiler_parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 195 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_assign = std::move(yystack_[0].value.as < gsc::stmt_assign_ptr > ()); }
#line 1839 "./S2/compiler_parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 196 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_endon = std::move(yystack_[0].value.as < gsc::stmt_endon_ptr > ()); }
#line 1845 "./S2/compiler_parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 197 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_notify = std::move(yystack_[0].value.as < gsc::stmt_notify_ptr > ()); }
#line 1851 "./S2/compiler_parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 198 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_wait = std::move(yystack_[0].value.as < gsc::stmt_wait_ptr > ()); }
#line 1857 "./S2/compiler_parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 199 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittill = std::move(yystack_[0].value.as < gsc::stmt_waittill_ptr > ()); }
#line 1863 "./S2/compiler_parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 200 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillmatch = std::move(yystack_[0].value.as < gsc::stmt_waittillmatch_ptr > ()); }
#line 1869 "./S2/compiler_parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 201 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillframeend = std::move(yystack_[0].value.as < gsc::stmt_waittillframeend_ptr > ()); }
#line 1875 "./S2/compiler_parser.cpp"
    break;

  case 29: // stmt: stmt_waitframe
#line 202 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waitframe = std::move(yystack_[0].value.as < gsc::stmt_waitframe_ptr > ()); }
#line 1881 "./S2/compiler_parser.cpp"
    break;

  case 30: // stmt: stmt_if
#line 203 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_if = std::move(yystack_[0].value.as < gsc::stmt_if_ptr > ()); }
#line 1887 "./S2/compiler_parser.cpp"
    break;

  case 31: // stmt: stmt_ifelse
#line 204 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_ifelse = std::move(yystack_[0].value.as < gsc::stmt_ifelse_ptr > ()); }
#line 1893 "./S2/compiler_parser.cpp"
    break;

  case 32: // stmt: stmt_while
#line 205 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_while = std::move(yystack_[0].value.as < gsc::stmt_while_ptr > ()); }
#line 1899 "./S2/compiler_parser.cpp"
    break;

  case 33: // stmt: stmt_for
#line 206 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_for = std::move(yystack_[0].value.as < gsc::stmt_for_ptr > ()); }
#line 1905 "./S2/compiler_parser.cpp"
    break;

  case 34: // stmt: stmt_foreach
#line 207 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_foreach = std::move(yystack_[0].value.as < gsc::stmt_foreach_ptr > ()); }
#line 1911 "./S2/compiler_parser.cpp"
    break;

  case 35: // stmt: stmt_switch
#line 208 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_switch = std::move(yystack_[0].value.as < gsc::stmt_switch_ptr > ()); }
#line 1917 "./S2/compiler_parser.cpp"
    break;

  case 36: // stmt: stmt_case
#line 209 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_case = std::move(yystack_[0].value.as < gsc::stmt_case_ptr > ()); }
#line 1923 "./S2/compiler_parser.cpp"
    break;

  case 37: // stmt: stmt_default
#line 210 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_default = std::move(yystack_[0].value.as < gsc::stmt_default_ptr > ()); }
#line 1929 "./S2/compiler_parser.cpp"
    break;

  case 38: // stmt: stmt_break
#line 211 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_break = std::move(yystack_[0].value.as < gsc::stmt_break_ptr > ()); }
#line 1935 "./S2/compiler_parser.cpp"
    break;

  case 39: // stmt: stmt_continue
#line 212 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_continue = std::move(yystack_[0].value.as < gsc::stmt_continue_ptr > ()); }
#line 1941 "./S2/compiler_parser.cpp"
    break;

  case 40: // stmt: stmt_return
#line 213 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_return = std::move(yystack_[0].value.as < gsc::stmt_return_ptr > ()); }
#line 1947 "./S2/compiler_parser.cpp"
    break;

  case 41: // stmt_call: expr_call SEMICOLON
#line 218 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(*pos, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1953 "./S2/compiler_parser.cpp"
    break;

  case 42: // stmt_call: expr_call_thread SEMICOLON
#line 220 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(*pos, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1959 "./S2/compiler_parser.cpp"
    break;

  case 43: // stmt_assign: expr_assign SEMICOLON
#line 225 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_assign_ptr > () = std::make_unique<gsc::node_stmt_assign>(*pos, std::move(yystack_[1].value.as < gsc::expr_assign_ptr > ())); }
#line 1965 "./S2/compiler_parser.cpp"
    break;

  case 44: // stmt_endon: object ENDON LPAREN expr RPAREN SEMICOLON
#line 230 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_endon_ptr > () = std::make_unique<gsc::node_stmt_endon>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1971 "./S2/compiler_parser.cpp"
    break;

  case 45: // stmt_notify: object NOTIFY LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 235 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1977 "./S2/compiler_parser.cpp"
    break;

  case 46: // stmt_notify: object NOTIFY LPAREN expr RPAREN SEMICOLON
#line 237 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(*pos)); }
#line 1983 "./S2/compiler_parser.cpp"
    break;

  case 47: // stmt_wait: WAIT LPAREN expr RPAREN SEMICOLON
#line 242 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1989 "./S2/compiler_parser.cpp"
    break;

  case 48: // stmt_wait: WAIT number SEMICOLON
#line 244 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::number_ptr > ().as_node))); }
#line 1995 "./S2/compiler_parser.cpp"
    break;

  case 49: // stmt_waittill: object WAITTILL LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 249 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 2001 "./S2/compiler_parser.cpp"
    break;

  case 50: // stmt_waittill: object WAITTILL LPAREN expr RPAREN SEMICOLON
#line 251 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(*pos)); }
#line 2007 "./S2/compiler_parser.cpp"
    break;

  case 51: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 256 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 2013 "./S2/compiler_parser.cpp"
    break;

  case 52: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr RPAREN SEMICOLON
#line 258 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(*pos, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(*pos)); }
#line 2019 "./S2/compiler_parser.cpp"
    break;

  case 53: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 263 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(*pos); }
#line 2025 "./S2/compiler_parser.cpp"
    break;

  case 54: // stmt_waitframe: WAITFRAME SEMICOLON
#line 268 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waitframe_ptr > () = std::make_unique<gsc::node_stmt_waitframe>(*pos); }
#line 2031 "./S2/compiler_parser.cpp"
    break;

  case 55: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 273 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2037 "./S2/compiler_parser.cpp"
    break;

  case 56: // stmt_if: IF LPAREN expr RPAREN stmt
#line 275 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2047 "./S2/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 284 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2053 "./S2/compiler_parser.cpp"
    break;

  case 58: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 286 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ()));
        }
#line 2063 "./S2/compiler_parser.cpp"
    break;

  case 59: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 292 "S2.parser.ypp"
        { 
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk));
        }
#line 2073 "./S2/compiler_parser.cpp"
    break;

  case 60: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 298 "S2.parser.ypp"
        {
            auto blk1 = std::make_unique<gsc::node_block>(*pos);
            blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
            auto blk2 = std::make_unique<gsc::node_block>(*pos);
            blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2));
        }
#line 2085 "./S2/compiler_parser.cpp"
    break;

  case 61: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 309 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2091 "./S2/compiler_parser.cpp"
    break;

  case 62: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 311 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 2100 "./S2/compiler_parser.cpp"
    break;

  case 63: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN LBRACE block RBRACE
#line 319 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2106 "./S2/compiler_parser.cpp"
    break;

  case 64: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN stmt
#line 321 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2116 "./S2/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN LBRACE block RBRACE
#line 330 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2122 "./S2/compiler_parser.cpp"
    break;

  case 66: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN LBRACE block RBRACE
#line 332 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[8].value.as < gsc::name_ptr > ()), std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2128 "./S2/compiler_parser.cpp"
    break;

  case 67: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN stmt
#line 334 "S2.parser.ypp"
        {
        auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2138 "./S2/compiler_parser.cpp"
    break;

  case 68: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN stmt
#line 340 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2148 "./S2/compiler_parser.cpp"
    break;

  case 69: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 349 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2154 "./S2/compiler_parser.cpp"
    break;

  case 70: // stmt_case: CASE integer COLON
#line 354 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2160 "./S2/compiler_parser.cpp"
    break;

  case 71: // stmt_case: CASE neg_integer COLON
#line 356 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2166 "./S2/compiler_parser.cpp"
    break;

  case 72: // stmt_case: CASE string COLON
#line 358 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 2172 "./S2/compiler_parser.cpp"
    break;

  case 73: // stmt_default: DEFAULT COLON
#line 363 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(*pos); }
#line 2178 "./S2/compiler_parser.cpp"
    break;

  case 74: // stmt_break: BREAK SEMICOLON
#line 368 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(*pos); }
#line 2184 "./S2/compiler_parser.cpp"
    break;

  case 75: // stmt_continue: CONTINUE SEMICOLON
#line 373 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(*pos); }
#line 2190 "./S2/compiler_parser.cpp"
    break;

  case 76: // stmt_return: RETURN expr SEMICOLON
#line 378 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2196 "./S2/compiler_parser.cpp"
    break;

  case 77: // stmt_return: RETURN SEMICOLON
#line 380 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::make_unique<gsc::node>()); }
#line 2202 "./S2/compiler_parser.cpp"
    break;

  case 78: // for_stmt: expr_assign
#line 384 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2208 "./S2/compiler_parser.cpp"
    break;

  case 79: // for_stmt: %empty
#line 385 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2214 "./S2/compiler_parser.cpp"
    break;

  case 80: // for_expr: expr_compare
#line 389 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2220 "./S2/compiler_parser.cpp"
    break;

  case 81: // for_expr: %empty
#line 390 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2226 "./S2/compiler_parser.cpp"
    break;

  case 82: // expr: expr_compare
#line 394 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2232 "./S2/compiler_parser.cpp"
    break;

  case 83: // expr: expr_binary
#line 395 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2238 "./S2/compiler_parser.cpp"
    break;

  case 84: // expr: expr_primitive
#line 396 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2244 "./S2/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object INCREMENT
#line 400 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2250 "./S2/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object DECREMENT
#line 401 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2256 "./S2/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN expr
#line 402 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2262 "./S2/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 403 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2268 "./S2/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 404 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2274 "./S2/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 405 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2280 "./S2/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_LSHIFT expr
#line 406 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2286 "./S2/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_RSHIFT expr
#line 407 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2292 "./S2/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_ADD expr
#line 408 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2298 "./S2/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_SUB expr
#line 409 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2304 "./S2/compiler_parser.cpp"
    break;

  case 95: // expr_assign: object ASSIGN_MULT expr
#line 410 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2310 "./S2/compiler_parser.cpp"
    break;

  case 96: // expr_assign: object ASSIGN_DIV expr
#line 411 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2316 "./S2/compiler_parser.cpp"
    break;

  case 97: // expr_assign: object ASSIGN_MOD expr
#line 412 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2322 "./S2/compiler_parser.cpp"
    break;

  case 98: // expr_compare: expr OR expr
#line 416 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2328 "./S2/compiler_parser.cpp"
    break;

  case 99: // expr_compare: expr AND expr
#line 417 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2334 "./S2/compiler_parser.cpp"
    break;

  case 100: // expr_compare: expr EQUALITY expr
#line 418 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2340 "./S2/compiler_parser.cpp"
    break;

  case 101: // expr_compare: expr INEQUALITY expr
#line 419 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2346 "./S2/compiler_parser.cpp"
    break;

  case 102: // expr_compare: expr LESS_EQUAL expr
#line 420 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2352 "./S2/compiler_parser.cpp"
    break;

  case 103: // expr_compare: expr GREATER_EQUAL expr
#line 421 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2358 "./S2/compiler_parser.cpp"
    break;

  case 104: // expr_compare: expr LESS expr
#line 422 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2364 "./S2/compiler_parser.cpp"
    break;

  case 105: // expr_compare: expr GREATER expr
#line 423 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2370 "./S2/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr BITWISE_OR expr
#line 427 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2376 "./S2/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr BITWISE_AND expr
#line 428 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2382 "./S2/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr BITWISE_EXOR expr
#line 429 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2388 "./S2/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr LSHIFT expr
#line 430 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2394 "./S2/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr RSHIFT expr
#line 431 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2400 "./S2/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr ADD expr
#line 432 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2406 "./S2/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr SUB expr
#line 433 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2412 "./S2/compiler_parser.cpp"
    break;

  case 113: // expr_binary: expr MULT expr
#line 434 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2418 "./S2/compiler_parser.cpp"
    break;

  case 114: // expr_binary: expr DIV expr
#line 435 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2424 "./S2/compiler_parser.cpp"
    break;

  case 115: // expr_binary: expr MOD expr
#line 436 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2430 "./S2/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: LPAREN expr RPAREN
#line 440 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2436 "./S2/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: COMPLEMENT expr
#line 441 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2442 "./S2/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: NOT expr
#line 442 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2448 "./S2/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_call
#line 443 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2454 "./S2/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_call_thread
#line 444 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2460 "./S2/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_call_childthread
#line 445 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2466 "./S2/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_function
#line 446 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2472 "./S2/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_add_array
#line 447 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2478 "./S2/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_vector
#line 448 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2484 "./S2/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: expr_array
#line 449 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2490 "./S2/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: expr_field
#line 450 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2496 "./S2/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: expr_self
#line 451 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2502 "./S2/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: expr_size
#line 452 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2508 "./S2/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: thisthread
#line 453 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::thisthread_ptr > ()); }
#line 2514 "./S2/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: empty_array
#line 454 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::empty_array_ptr > ()); }
#line 2520 "./S2/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: undefined
#line 455 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::undefined_ptr > ()); }
#line 2526 "./S2/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: game
#line 456 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2532 "./S2/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: self
#line 457 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2538 "./S2/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: anim
#line 458 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2544 "./S2/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: level
#line 459 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2550 "./S2/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: animation
#line 460 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animation_ptr > ()); }
#line 2556 "./S2/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: animtree
#line 461 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2562 "./S2/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: name
#line 462 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2568 "./S2/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: istring
#line 463 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::istring_ptr > ()); }
#line 2574 "./S2/compiler_parser.cpp"
    break;

  case 140: // expr_primitive: string
#line 464 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2580 "./S2/compiler_parser.cpp"
    break;

  case 141: // expr_primitive: vector
#line 465 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2586 "./S2/compiler_parser.cpp"
    break;

  case 142: // expr_primitive: number
#line 466 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::number_ptr > ().as_node); }
#line 2592 "./S2/compiler_parser.cpp"
    break;

  case 143: // expr_primitive: false
#line 467 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2598 "./S2/compiler_parser.cpp"
    break;

  case 144: // expr_primitive: true
#line 468 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2604 "./S2/compiler_parser.cpp"
    break;

  case 145: // expr_call: expr_call_function
#line 472 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2610 "./S2/compiler_parser.cpp"
    break;

  case 146: // expr_call: expr_call_pointer
#line 473 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2616 "./S2/compiler_parser.cpp"
    break;

  case 147: // expr_call: object expr_call_function
#line 474 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2622 "./S2/compiler_parser.cpp"
    break;

  case 148: // expr_call: object expr_call_pointer
#line 475 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2628 "./S2/compiler_parser.cpp"
    break;

  case 149: // expr_call_thread: THREAD expr_call_function
#line 479 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2634 "./S2/compiler_parser.cpp"
    break;

  case 150: // expr_call_thread: THREAD expr_call_pointer
#line 480 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2640 "./S2/compiler_parser.cpp"
    break;

  case 151: // expr_call_thread: object THREAD expr_call_function
#line 481 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2646 "./S2/compiler_parser.cpp"
    break;

  case 152: // expr_call_thread: object THREAD expr_call_pointer
#line 482 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2652 "./S2/compiler_parser.cpp"
    break;

  case 153: // expr_call_childthread: CHILDTHREAD expr_call_function
#line 486 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2658 "./S2/compiler_parser.cpp"
    break;

  case 154: // expr_call_childthread: CHILDTHREAD expr_call_pointer
#line 487 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2664 "./S2/compiler_parser.cpp"
    break;

  case 155: // expr_call_childthread: object CHILDTHREAD expr_call_function
#line 488 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2670 "./S2/compiler_parser.cpp"
    break;

  case 156: // expr_call_childthread: object CHILDTHREAD expr_call_pointer
#line 489 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2676 "./S2/compiler_parser.cpp"
    break;

  case 157: // expr_call_function: name LPAREN expr_arguments RPAREN
#line 494 "S2.parser.ypp"
        {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2682 "./S2/compiler_parser.cpp"
    break;

  case 158: // expr_call_function: file DOUBLECOLON name LPAREN expr_arguments RPAREN
#line 496 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::move(yystack_[5].value.as < gsc::file_ptr > ()), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2688 "./S2/compiler_parser.cpp"
    break;

  case 159: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 501 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2694 "./S2/compiler_parser.cpp"
    break;

  case 160: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 503 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2700 "./S2/compiler_parser.cpp"
    break;

  case 161: // expr_arguments: expr_arguments COMMA expr
#line 508 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2706 "./S2/compiler_parser.cpp"
    break;

  case 162: // expr_arguments: expr
#line 510 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2712 "./S2/compiler_parser.cpp"
    break;

  case 163: // expr_arguments: %empty
#line 512 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); }
#line 2718 "./S2/compiler_parser.cpp"
    break;

  case 164: // expr_function: DOUBLECOLON name
#line 517 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2724 "./S2/compiler_parser.cpp"
    break;

  case 165: // expr_function: file DOUBLECOLON name
#line 519 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::move(yystack_[2].value.as < gsc::file_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2730 "./S2/compiler_parser.cpp"
    break;

  case 166: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 524 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(*pos, std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2736 "./S2/compiler_parser.cpp"
    break;

  case 167: // expr_vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 529 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_vector>(*pos, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2742 "./S2/compiler_parser.cpp"
    break;

  case 168: // expr_array: object LBRACKET expr RBRACKET
#line 534 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(*pos, std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2748 "./S2/compiler_parser.cpp"
    break;

  case 169: // expr_field: object DOT name
#line 539 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2754 "./S2/compiler_parser.cpp"
    break;

  case 170: // expr_self: object DOT SELF
#line 544 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_self>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2760 "./S2/compiler_parser.cpp"
    break;

  case 171: // expr_size: object DOT SIZE
#line 549 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2766 "./S2/compiler_parser.cpp"
    break;

  case 172: // object: expr_call
#line 553 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2772 "./S2/compiler_parser.cpp"
    break;

  case 173: // object: expr_array
#line 554 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2778 "./S2/compiler_parser.cpp"
    break;

  case 174: // object: expr_field
#line 555 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2784 "./S2/compiler_parser.cpp"
    break;

  case 175: // object: game
#line 556 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2790 "./S2/compiler_parser.cpp"
    break;

  case 176: // object: self
#line 557 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2796 "./S2/compiler_parser.cpp"
    break;

  case 177: // object: anim
#line 558 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2802 "./S2/compiler_parser.cpp"
    break;

  case 178: // object: level
#line 559 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2808 "./S2/compiler_parser.cpp"
    break;

  case 179: // object: name
#line 560 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2814 "./S2/compiler_parser.cpp"
    break;

  case 180: // thisthread: THISTHREAD
#line 563 "S2.parser.ypp"
                          { yylhs.value.as < gsc::thisthread_ptr > () = std::make_unique<gsc::node_thisthread>(*pos); }
#line 2820 "./S2/compiler_parser.cpp"
    break;

  case 181: // empty_array: EMPTY_ARRAY
#line 564 "S2.parser.ypp"
                          { yylhs.value.as < gsc::empty_array_ptr > () = std::make_unique<gsc::node_empty_array>(*pos); }
#line 2826 "./S2/compiler_parser.cpp"
    break;

  case 182: // undefined: UNDEFINED
#line 565 "S2.parser.ypp"
                          { yylhs.value.as < gsc::undefined_ptr > () = std::make_unique<gsc::node_undefined>(*pos); }
#line 2832 "./S2/compiler_parser.cpp"
    break;

  case 183: // game: GAME
#line 566 "S2.parser.ypp"
                          { yylhs.value.as < gsc::game_ptr > () = std::make_unique<gsc::node_game>(*pos); }
#line 2838 "./S2/compiler_parser.cpp"
    break;

  case 184: // self: SELF
#line 567 "S2.parser.ypp"
                          { yylhs.value.as < gsc::self_ptr > () = std::make_unique<gsc::node_self>(*pos); }
#line 2844 "./S2/compiler_parser.cpp"
    break;

  case 185: // anim: ANIM
#line 568 "S2.parser.ypp"
                          { yylhs.value.as < gsc::anim_ptr > () = std::make_unique<gsc::node_anim>(*pos); }
#line 2850 "./S2/compiler_parser.cpp"
    break;

  case 186: // level: LEVEL
#line 569 "S2.parser.ypp"
                          { yylhs.value.as < gsc::level_ptr > () = std::make_unique<gsc::node_level>(*pos); }
#line 2856 "./S2/compiler_parser.cpp"
    break;

  case 187: // animation: MOD NAME
#line 570 "S2.parser.ypp"
                          { yylhs.value.as < gsc::animation_ptr > () = std::make_unique<gsc::node_animation>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2862 "./S2/compiler_parser.cpp"
    break;

  case 188: // animtree: ANIMTREE
#line 571 "S2.parser.ypp"
                          { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(*pos); }
#line 2868 "./S2/compiler_parser.cpp"
    break;

  case 189: // name: NAME
#line 572 "S2.parser.ypp"
                          { yylhs.value.as < gsc::name_ptr > () = std::make_unique<gsc::node_name>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2874 "./S2/compiler_parser.cpp"
    break;

  case 190: // file: FILE
#line 573 "S2.parser.ypp"
                          { yylhs.value.as < gsc::file_ptr > () = std::make_unique<gsc::node_file>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2880 "./S2/compiler_parser.cpp"
    break;

  case 191: // istring: ISTRING
#line 574 "S2.parser.ypp"
                          { yylhs.value.as < gsc::istring_ptr > () = std::make_unique<gsc::node_istring>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2886 "./S2/compiler_parser.cpp"
    break;

  case 192: // string: STRING
#line 575 "S2.parser.ypp"
                          { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2892 "./S2/compiler_parser.cpp"
    break;

  case 193: // vector: LPAREN number COMMA number COMMA number RPAREN
#line 579 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_vector>(*pos, std::move(yystack_[5].value.as < gsc::number_ptr > ()), std::move(yystack_[3].value.as < gsc::number_ptr > ()), std::move(yystack_[1].value.as < gsc::number_ptr > ())); }
#line 2898 "./S2/compiler_parser.cpp"
    break;

  case 194: // number: neg_float
#line 583 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2904 "./S2/compiler_parser.cpp"
    break;

  case 195: // number: neg_integer
#line 584 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2910 "./S2/compiler_parser.cpp"
    break;

  case 196: // number: float
#line 585 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2916 "./S2/compiler_parser.cpp"
    break;

  case 197: // number: integer
#line 586 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer  = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2922 "./S2/compiler_parser.cpp"
    break;

  case 198: // neg_float: SUB FLOAT
#line 589 "S2.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2928 "./S2/compiler_parser.cpp"
    break;

  case 199: // neg_integer: SUB INTEGER
#line 590 "S2.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2934 "./S2/compiler_parser.cpp"
    break;

  case 200: // float: FLOAT
#line 591 "S2.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2940 "./S2/compiler_parser.cpp"
    break;

  case 201: // integer: INTEGER
#line 592 "S2.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2946 "./S2/compiler_parser.cpp"
    break;

  case 202: // false: FALSE
#line 593 "S2.parser.ypp"
                          { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(*pos); }
#line 2952 "./S2/compiler_parser.cpp"
    break;

  case 203: // true: TRUE
#line 594 "S2.parser.ypp"
                          { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(*pos); }
#line 2958 "./S2/compiler_parser.cpp"
    break;


#line 2962 "./S2/compiler_parser.cpp"

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
  "ANIMTREE", "ENDON", "NOTIFY", "WAIT", "WAITTILL", "WAITFRAME",
  "WAITTILLMATCH", "WAITTILLFRAMEEND", "IF", "ELSE", "WHILE", "FOR",
  "FOREACH", "IN", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE",
  "RETURN", "THREAD", "CHILDTHREAD", "THISTHREAD", "CALL", "TRUE", "FALSE",
  "UNDEFINED", "SIZE", "GAME", "SELF", "ANIM", "LEVEL", "EMPTY_ARRAY",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA",
  "DOT", "DOUBLECOLON", "COLON", "SEMICOLON", "INCREMENT", "DECREMENT",
  "MOD", "LSHIFT", "RSHIFT", "OR", "AND", "EQUALITY", "INEQUALITY",
  "LESS_EQUAL", "GREATER_EQUAL", "LESS", "GREATER", "NOT", "COMPLEMENT",
  "ASSIGN_RSHIFT", "ASSIGN", "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_MULT",
  "ASSIGN_DIV", "ASSIGN_MOD", "ASSIGN_BITWISE_OR", "ASSIGN_BITWISE_AND",
  "ASSIGN_BITWISE_EXOR", "ASSIGN_LSHIFT", "BITWISE_OR", "BITWISE_AND",
  "BITWISE_EXOR", "ADD", "SUB", "MULT", "DIV", "FILE", "NAME", "STRING",
  "ISTRING", "FLOAT", "INTEGER", "$accept", "root", "program", "include",
  "define", "usingtree", "constant", "thread", "parameters", "block",
  "stmt", "stmt_call", "stmt_assign", "stmt_endon", "stmt_notify",
  "stmt_wait", "stmt_waittill", "stmt_waittillmatch",
  "stmt_waittillframeend", "stmt_waitframe", "stmt_if", "stmt_ifelse",
  "stmt_while", "stmt_for", "stmt_foreach", "stmt_switch", "stmt_case",
  "stmt_default", "stmt_break", "stmt_continue", "stmt_return", "for_stmt",
  "for_expr", "expr", "expr_assign", "expr_compare", "expr_binary",
  "expr_primitive", "expr_call", "expr_call_thread",
  "expr_call_childthread", "expr_call_function", "expr_call_pointer",
  "expr_arguments", "expr_function", "expr_add_array", "expr_vector",
  "expr_array", "expr_field", "expr_self", "expr_size", "object",
  "thisthread", "empty_array", "undefined", "game", "self", "anim",
  "level", "animation", "animtree", "name", "file", "istring", "string",
  "vector", "number", "neg_float", "neg_integer", "float", "integer",
  "false", "true", YY_NULLPTR
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

#if S2DEBUG
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
#if S2DEBUG
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
#if S2DEBUG
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


  const short parser::yypact_ninf_ = -314;

  const short parser::yytable_ninf_ = -180;

  const short
  parser::yypact_[] =
  {
       6,   -63,    -5,  -314,    37,     6,  -314,  -314,  -314,  -314,
    -314,   -23,  -314,     4,   -14,  -314,  -314,  -314,   -10,  1212,
    -314,  -314,    48,   -27,  -314,  -314,   -17,   -17,  -314,    34,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  1212,  1275,
     -10,    13,  1212,  1212,   -51,  -314,  -314,  -314,  2447,  -314,
    -314,  -314,     3,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
      30,    35,  -314,  -314,    69,  -314,  -314,  -314,    98,   121,
     131,   249,  -314,  -314,    -4,    44,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,    50,    65,   -10,    64,
    -314,  -314,    78,    73,  -314,  -314,    80,  1045,    81,  1275,
    2492,     7,  -314,  -314,  2492,  2492,  -314,  -314,  -314,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  1212,   -17,   -17,  1275,
      -2,  -314,  -314,  1212,   -10,  -314,  2014,  -314,  1212,   -10,
    1212,  -314,  1212,    14,  2313,  -314,  1212,  2492,  2492,  2492,
    2492,  2492,  2492,  2492,  2492,  2492,  2492,  2492,  2492,  2492,
    2492,  2492,  2492,  2492,  2492,  -314,  -314,  -314,  -314,  2344,
    -314,  -314,  -314,    15,    91,     5,    83,    84,    97,   106,
     116,   120,   122,    58,   114,   117,   126,  1149,  1397,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
     127,   130,   134,  -314,  -314,  1321,  -314,  -314,  -314,  -314,
      78,  2313,    91,  2375,  2413,   124,   136,  2492,  -314,  -314,
    1212,  1212,   137,  -314,  -314,  1212,  1212,   219,   -10,  1212,
      77,   139,   140,   144,  -314,  -314,  -314,  -314,  2481,  -314,
    -314,  -314,  -314,  -314,   155,   156,   158,   159,   -10,  -314,
    -314,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,   157,  1212,    14,   160,    23,   898,  -314,  2153,
    2185,   151,  -314,  -314,  2016,     2,  2196,  -314,  -314,  -314,
    -314,  1212,  1212,  1212,  1212,  2492,  2492,  2492,  2492,  2492,
    2492,  2492,  2492,  2492,  2492,  2492,   163,  2228,   169,  1212,
    -314,   162,  1432,  1476,  1212,  1212,   -10,   129,  2239,  2056,
    2099,  2142,  1212,  -314,  -314,    60,  -314,  2014,   198,  2014,
    -314,   168,  2492,   170,  2271,   199,  2014,   172,   174,  1212,
     176,  1212,   177,  1212,    94,  -314,  1509,  1553,  1586,   219,
    1630,  1212,  1663,  -314,  -314,   109,  -314,   111,  -314,   123,
    -314,   212,  2014,  -314,  -314,   188,  2014,  -314,  2282,  -314,
     180,   181,   182,  1707,  1740,  1784,  1817,  1861,  -314,  -314,
    -314,  2014,  -314,  -314,  2014,  -314,  -314,  2014,  -314,  1894,
    1937,  1972,  -314,  -314,  -314
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   189,     0,     2,     6,     7,     9,    10,
      11,     0,   190,     0,     0,     1,     4,     5,    17,     0,
       8,   192,     0,     0,    16,   188,     0,     0,   180,     0,
     203,   202,   182,   183,   184,   185,   186,   181,     0,   163,
       0,     0,     0,     0,     0,   191,   200,   201,     0,    82,
      83,    84,   119,   120,   121,   145,   146,   122,   123,   124,
     125,   126,   127,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   139,   140,   141,   142,
     194,   195,   196,   197,   143,   144,     0,     0,     0,     0,
     149,   150,     0,     0,   153,   154,     0,     0,   142,   163,
     162,     0,   164,   187,   118,   117,   198,   199,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   163,     0,    12,    20,    15,     0,     0,
       0,   116,     0,     0,   162,   166,     0,   115,   109,   110,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   111,   112,   113,   114,   151,   152,   155,   156,     0,
     171,   170,   169,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,   172,     0,   173,   174,     0,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,   161,   168,   157,
     163,     0,     0,    54,    53,     0,     0,    79,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    77,     0,    14,
      18,    43,    41,    42,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    78,   172,     0,     0,     0,    72,    71,    70,
      76,     0,     0,     0,     0,    92,    87,    93,    94,    95,
      96,    97,    88,    89,    90,    91,     0,     0,     0,   163,
     158,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,   163,   167,   193,     0,    47,    20,    56,    20,
      62,     0,     0,    82,     0,     0,    20,     0,     0,   163,
       0,   163,     0,   163,     0,   159,     0,     0,     0,    79,
       0,     0,     0,    44,    46,     0,    50,     0,    52,     0,
     160,    55,    20,    60,    61,     0,    20,    67,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    49,
      51,    20,    59,    58,    20,    64,    65,    20,    68,     0,
       0,     0,    57,    63,    66
  };

  const short
  parser::yypgoto_[] =
  {
    -314,  -314,  -314,   226,   234,  -314,  -314,  -314,  -314,  -313,
    -141,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -108,  -314,   369,  -234,   -72,  -314,  -314,   -67,   782,
    -314,   -25,   -20,  -120,  -314,  -314,  -314,   205,   340,  -314,
    -314,   410,  -314,  -314,  -314,   466,   555,   635,   701,  -314,
    -314,     0,    56,  -314,    -6,  -314,   -34,  -314,    68,  -314,
      74,  -314,  -314
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    23,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   281,   331,   100,   210,    49,    50,    51,    52,    53,
      54,    55,    56,   101,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85
  };

  const short
  parser::yytable_[] =
  {
      11,    90,    94,   282,    98,    11,    91,    95,    22,     1,
       2,    29,    87,   173,   346,    18,   348,    88,    24,    12,
     315,  -179,  -179,   352,  -179,    89,    92,    92,  -172,  -172,
     170,  -172,   171,    14,   133,   106,   107,    15,  -179,   131,
     102,  -179,    19,   231,   132,  -172,   316,   250,  -172,   374,
     145,   146,    20,   376,   229,  -173,  -173,    13,  -173,   146,
    -174,  -174,   310,  -174,    92,    12,     3,   146,   389,   211,
      21,   390,  -173,     3,   391,  -173,    96,  -174,  -179,  -179,
    -174,     3,    93,    93,    44,  -172,  -172,    86,   137,     3,
     134,    46,    47,    44,   127,   128,   103,    29,   135,   345,
      46,    47,   165,   167,   146,   136,   138,   166,   168,   225,
     276,   129,  -173,  -173,   130,   282,   133,  -174,  -174,   139,
      93,   211,   140,  -175,  -175,   143,  -175,    92,    92,   230,
     172,   233,   234,   360,   174,   235,   220,   240,   146,   222,
    -175,   232,    21,  -175,   236,    47,  -176,  -176,   370,  -176,
     371,    12,     3,   146,   237,   146,  -177,  -177,   238,  -177,
     239,   244,   372,  -176,   107,   245,  -176,   146,   274,   336,
     283,   328,   330,  -177,   246,   251,  -177,   241,   252,   275,
    -175,  -175,   253,    93,    93,   278,   287,   288,   220,   325,
     131,   289,    93,   291,   292,   132,   293,   294,   309,   314,
     306,   322,   344,  -176,  -176,   250,   363,   250,   324,   367,
     326,   250,   347,  -177,  -177,    92,   349,   351,   -80,   355,
     353,   357,   354,   359,   356,   358,   373,   375,   378,   379,
     380,    16,   382,   250,   385,   250,   388,   220,   285,    17,
     308,   365,   333,     0,    93,   211,   211,    29,   250,   250,
     250,   242,    33,    34,    35,    36,     0,   243,   172,   131,
     211,    89,   211,     0,   132,     0,     0,     0,     0,   211,
       0,    93,     0,     0,  -178,  -178,     0,  -178,     0,   211,
     211,   211,   283,   211,    92,   211,     0,     0,     0,     0,
       0,  -178,     0,    93,  -178,   211,     0,     0,     0,   211,
       0,    12,     3,     0,     0,     0,   211,   211,   211,   211,
     211,     0,   220,   220,   211,     0,   335,   211,     0,     0,
     211,     0,   211,   211,   211,     0,     0,   220,     0,   220,
       0,  -178,  -178,     0,     0,     0,   220,     0,     0,     0,
      93,   213,     0,     0,     0,     0,   220,   220,   220,   220,
     220,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,     0,     0,     0,   220,     0,    93,    93,
       0,     0,     0,   220,   220,   220,   220,   220,     0,     0,
       0,   220,     0,    93,   220,    93,     0,   220,    48,   220,
     220,   220,    93,   213,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    93,    93,    93,    93,    97,    93,     0,
       0,   104,   105,     0,     0,     0,     0,     0,    93,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,    93,
      93,    93,    93,    93,     0,     0,     0,    93,     0,     0,
      93,     0,   213,    93,     0,    93,    93,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   214,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,   169,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,   223,
       0,   224,     0,     0,     0,   227,     0,   213,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
       0,     0,   213,     0,   213,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,     0,   215,     0,     0,     0,
       0,   213,   213,   213,   213,   213,   248,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,   213,     0,     0,     0,     0,     0,   214,   213,   213,
     213,   213,   213,     0,     0,     0,   213,     0,     0,   213,
       0,     0,   213,     0,   213,   213,   213,     0,   215,     0,
     277,     0,   216,     0,   279,   280,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,     0,   307,     0,     0,     0,     0,   284,     0,     0,
       0,     0,   214,   214,   216,     0,     0,     0,     0,     0,
     318,   319,   320,   321,     0,     0,     0,   214,     0,   214,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,   332,   334,     0,   214,   214,   214,   214,
     214,   217,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,   216,     0,     0,   214,     0,     0,     0,
       0,     0,     0,   214,   214,   214,   214,   214,     0,     0,
     368,   214,   215,   215,   214,     0,     0,   214,     0,   214,
     214,   214,     0,     0,     0,     0,     0,   215,     0,   215,
       0,     0,     0,   217,     0,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,   215,   215,   284,
     215,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,   218,   215,     0,     0,     0,   215,     0,   216,   216,
       0,     0,     0,   215,   215,   215,   215,   215,     0,     0,
       0,   215,   217,   216,   215,   216,     0,   215,     0,   215,
     215,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   216,   216,   216,   216,     0,   216,     0,
       0,     0,     0,   218,     0,     0,     0,     0,   216,     0,
       0,     0,   216,     0,     0,     0,     0,   219,     0,   216,
     216,   216,   216,   216,     0,     0,     0,   216,     0,     0,
     216,     0,     0,   216,     0,   216,   216,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   217,     0,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,   217,     0,     0,     0,     0,   219,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   217,   217,   217,   217,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   212,     0,
       0,   217,     0,     0,     0,     0,     0,     0,   217,   217,
     217,   217,   217,     0,     0,     0,   217,   311,   219,   217,
       0,     0,   217,     0,   217,   217,   217,   218,   218,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,   218,     0,   218,     0,     0,     0,     0,     0,
     212,   218,     0,   120,   121,   122,   123,   124,   125,   126,
       0,   218,   218,   218,   218,   218,     0,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,   218,   218,
     218,   218,   218,   219,   219,     0,   218,     0,     0,   218,
       0,     0,   218,     0,   218,   218,   218,     0,   219,     0,
     219,     0,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   219,   219,
     219,   219,     0,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,   219,   219,   219,   219,   219,     0,
       0,     0,   219,     0,   141,   219,     0,     0,   219,   142,
     219,   219,   219,     0,   212,   212,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,   212,
       0,   212,     0,     0,     0,     0,     0,     0,   212,     0,
     120,   121,   122,   123,   124,   125,   126,     0,   212,   212,
     212,     0,   212,     0,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   212,     0,     0,     0,   212,     0,
       0,     0,     0,     0,    25,   212,   212,   212,   212,   212,
       0,     0,     0,   212,     0,     0,   212,     0,     0,   212,
       0,   212,   212,   212,    26,    27,    28,    29,    30,    31,
      32,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,    39,     0,     0,     0,    40,     0,   247,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    43,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
       0,    12,     3,    21,    45,    46,    47,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,    39,     0,     0,     0,    40,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     0,    12,     3,    21,    45,    46,    47,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,    99,     0,     0,
       0,    40,     0,     0,     0,     0,    41,   254,   255,     0,
     256,     0,   257,     0,     0,     0,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,    29,
       0,     0,     0,     0,    44,     0,     0,    12,     3,    21,
      45,    46,    47,   129,     0,     0,   258,     0,     0,     0,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,     0,     0,     0,     0,
       0,     0,     0,    12,     3,   175,     0,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,     0,   249,    89,
     175,     0,   176,     0,   177,   178,     0,   179,   180,   181,
       0,   182,   183,   184,   185,   186,   187,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,   327,     0,    89,     0,     0,     0,     0,    12,
       3,     0,     0,     0,   175,     0,   176,     0,   177,   178,
       0,   179,   180,   181,     0,   182,   183,   184,   185,   186,
     187,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,    12,     3,   329,   175,    89,   176,
       0,   177,   178,     0,   179,   180,   181,     0,   182,   183,
     184,   185,   186,   187,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
     361,    89,     0,     0,     0,     0,     0,     0,    12,     3,
       0,   175,     0,   176,     0,   177,   178,     0,   179,   180,
     181,     0,   182,   183,   184,   185,   186,   187,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,    12,     3,   362,   175,    89,   176,     0,   177,   178,
       0,   179,   180,   181,     0,   182,   183,   184,   185,   186,
     187,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,     0,   364,    89,     0,
       0,     0,     0,     0,     0,    12,     3,     0,   175,     0,
     176,     0,   177,   178,     0,   179,   180,   181,     0,   182,
     183,   184,   185,   186,   187,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,    12,     3,
     366,   175,    89,   176,     0,   177,   178,     0,   179,   180,
     181,     0,   182,   183,   184,   185,   186,   187,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,     0,   369,    89,     0,     0,     0,     0,
       0,     0,    12,     3,     0,   175,     0,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,    12,     3,   381,   175,    89,
     176,     0,   177,   178,     0,   179,   180,   181,     0,   182,
     183,   184,   185,   186,   187,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
       0,   383,    89,     0,     0,     0,     0,     0,     0,    12,
       3,     0,   175,     0,   176,     0,   177,   178,     0,   179,
     180,   181,     0,   182,   183,   184,   185,   186,   187,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,    12,     3,   384,   175,    89,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,     0,   386,    89,
       0,     0,     0,     0,     0,     0,    12,     3,     0,   175,
       0,   176,     0,   177,   178,     0,   179,   180,   181,     0,
     182,   183,   184,   185,   186,   187,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,    12,
       3,   387,   175,    89,   176,     0,   177,   178,     0,   179,
     180,   181,     0,   182,   183,   184,   185,   186,   187,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,     0,   392,    89,     0,     0,     0,
       0,     0,     0,    12,     3,   175,     0,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,    12,     3,   393,    89,
     175,     0,   176,     0,   177,   178,     0,   179,   180,   181,
       0,   182,   183,   184,   185,   186,   187,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,     0,   394,    89,     0,     0,     0,     0,    12,
       3,     0,   175,     0,   176,     0,   177,   178,     0,   179,
     180,   181,     0,   182,   183,   184,   185,   186,   187,    26,
       0,     0,    29,     0,    29,     0,     0,    33,    34,    35,
      36,     0,     0,     0,    12,     3,    89,     0,   129,     0,
       0,   258,     0,     0,     0,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,     0,     0,     0,     0,   338,    12,     3,    12,     3,
     339,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   340,     0,
       0,     0,     0,   341,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   121,   122,   123,   124,   125,
     126,   342,     0,     0,     0,     0,   343,     0,     0,     0,
       0,     0,   312,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   313,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   317,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   323,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   337,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     350,     0,     0,     0,   120,   121,   122,   123,   124,   125,
     126,   377,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,   226,   120,   121,   122,
     123,   124,   125,   126,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   120,   121,
     122,   123,   124,   125,   126,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,   120,
     121,   122,   123,   124,   125,   126,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   273,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   290,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126
  };

  const short
  parser::yycheck_[] =
  {
       0,    26,    27,   237,    38,     5,    26,    27,    14,     3,
       4,    28,    39,   133,   327,    38,   329,    44,    18,    82,
      18,    25,    26,   336,    28,    42,    26,    27,    25,    26,
      32,    28,    34,    38,    38,    86,    87,     0,    42,    64,
      40,    45,    65,    38,    64,    42,    44,   188,    45,   362,
      43,    44,    48,   366,    39,    25,    26,     1,    28,    44,
      25,    26,    39,    28,    64,    82,    83,    44,   381,   136,
      84,   384,    42,    83,   387,    45,    42,    42,    82,    83,
      45,    83,    26,    27,    79,    82,    83,    39,    88,    83,
      46,    86,    87,    79,    25,    26,    83,    28,    48,    39,
      86,    87,   127,   128,    44,    40,    42,   127,   128,   143,
     230,    42,    82,    83,    45,   349,    38,    82,    83,    46,
      64,   188,    42,    25,    26,    44,    28,   127,   128,    38,
     130,    48,    48,    39,   134,    38,   136,    79,    44,   139,
      42,   175,    84,    45,    38,    87,    25,    26,    39,    28,
      39,    82,    83,    44,    38,    44,    25,    26,    38,    28,
      38,    47,    39,    42,    87,    48,    45,    44,    44,    40,
     237,   312,   313,    42,    48,    48,    45,   183,    48,    43,
      82,    83,    48,   127,   128,    48,    47,    47,   188,   309,
     215,    47,   136,    38,    38,   215,    38,    38,    38,    48,
      43,    38,   322,    82,    83,   346,   347,   348,    39,   350,
      48,   352,    14,    82,    83,   215,    48,    18,    48,   339,
      48,   341,    48,   343,    48,    48,    14,    39,    48,    48,
      48,     5,   373,   374,   375,   376,   377,   237,   238,     5,
     274,   349,   314,    -1,   188,   312,   313,    28,   389,   390,
     391,   183,    33,    34,    35,    36,    -1,   183,   258,   284,
     327,    42,   329,    -1,   284,    -1,    -1,    -1,    -1,   336,
      -1,   215,    -1,    -1,    25,    26,    -1,    28,    -1,   346,
     347,   348,   349,   350,   284,   352,    -1,    -1,    -1,    -1,
      -1,    42,    -1,   237,    45,   362,    -1,    -1,    -1,   366,
      -1,    82,    83,    -1,    -1,    -1,   373,   374,   375,   376,
     377,    -1,   312,   313,   381,    -1,   316,   384,    -1,    -1,
     387,    -1,   389,   390,   391,    -1,    -1,   327,    -1,   329,
      -1,    82,    83,    -1,    -1,    -1,   336,    -1,    -1,    -1,
     284,   136,    -1,    -1,    -1,    -1,   346,   347,   348,   349,
     350,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   362,    -1,    -1,    -1,   366,    -1,   312,   313,
      -1,    -1,    -1,   373,   374,   375,   376,   377,    -1,    -1,
      -1,   381,    -1,   327,   384,   329,    -1,   387,    19,   389,
     390,   391,   336,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   346,   347,   348,   349,   350,    38,   352,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,   362,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,
     374,   375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,
     384,    -1,   237,   387,    -1,   389,   390,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
      -1,   142,    -1,    -1,    -1,   146,    -1,   312,   313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,    -1,
      -1,   336,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,   346,   347,   348,   349,   350,   187,   352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,   237,   373,   374,
     375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,   384,
      -1,    -1,   387,    -1,   389,   390,   391,    -1,   188,    -1,
     231,    -1,   136,    -1,   235,   236,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,    -1,   273,    -1,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,   312,   313,   188,    -1,    -1,    -1,    -1,    -1,
     291,   292,   293,   294,    -1,    -1,    -1,   327,    -1,   329,
      -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,    -1,    -1,
      -1,    -1,    -1,   314,   315,    -1,   346,   347,   348,   349,
     350,   136,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   362,   237,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,    -1,   373,   374,   375,   376,   377,    -1,    -1,
     351,   381,   312,   313,   384,    -1,    -1,   387,    -1,   389,
     390,   391,    -1,    -1,    -1,    -1,    -1,   327,    -1,   329,
      -1,    -1,    -1,   188,    -1,    -1,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,   347,   348,   349,
     350,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   362,    -1,    -1,    -1,   366,    -1,   312,   313,
      -1,    -1,    -1,   373,   374,   375,   376,   377,    -1,    -1,
      -1,   381,   237,   327,   384,   329,    -1,   387,    -1,   389,
     390,   391,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   346,   347,   348,   349,   350,    -1,   352,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,   362,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,   136,    -1,   373,
     374,   375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,
     384,    -1,    -1,   387,    -1,   389,   390,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,   188,
      -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,   347,   348,   349,   350,    -1,   352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,   136,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,
     375,   376,   377,    -1,    -1,    -1,   381,    39,   237,   384,
      -1,    -1,   387,    -1,   389,   390,   391,   312,   313,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,    -1,
     188,   336,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,   346,   347,   348,   349,   350,    -1,   352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,   373,   374,
     375,   376,   377,   312,   313,    -1,   381,    -1,    -1,   384,
      -1,    -1,   387,    -1,   389,   390,   391,    -1,   327,    -1,
     329,    -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   347,   348,
     349,   350,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   362,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,    -1,   373,   374,   375,   376,   377,    -1,
      -1,    -1,   381,    -1,    39,   384,    -1,    -1,   387,    44,
     389,   390,   391,    -1,   312,   313,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,   327,
      -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,
      75,    76,    77,    78,    79,    80,    81,    -1,   346,   347,
     348,    -1,   350,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,     5,   373,   374,   375,   376,   377,
      -1,    -1,    -1,   381,    -1,    -1,   384,    -1,    -1,   387,
      -1,   389,   390,   391,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    82,    83,    84,    85,    86,    87,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,     6,     7,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    42,    -1,    -1,    45,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,     8,    -1,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
       8,    -1,    10,    -1,    12,    13,    -1,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,     8,    -1,    10,    -1,    12,    13,
      -1,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    82,    83,    40,     8,    42,    10,
      -1,    12,    13,    -1,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,     8,    -1,    10,    -1,    12,    13,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    82,    83,    40,     8,    42,    10,    -1,    12,    13,
      -1,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,     8,    -1,
      10,    -1,    12,    13,    -1,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    -1,    82,    83,
      40,     8,    42,    10,    -1,    12,    13,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,     8,    -1,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    82,    83,    40,     8,    42,
      10,    -1,    12,    13,    -1,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,     8,    -1,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    82,    83,    40,     8,    42,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,     8,
      -1,    10,    -1,    12,    13,    -1,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,    82,
      83,    40,     8,    42,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,     8,    -1,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    82,    83,    41,    42,
       8,    -1,    10,    -1,    12,    13,    -1,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    82,
      83,    -1,     8,    -1,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    -1,    28,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    82,    83,    42,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    39,    82,    83,    82,    83,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    39,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    39,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    39,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    39,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    39,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      39,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    39,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    43,    75,    76,    77,
      78,    79,    80,    81,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    75,    76,
      77,    78,    79,    80,    81,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    75,
      76,    77,    78,    79,    80,    81,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,    83,    89,    90,    91,    92,    93,    94,
      95,   149,    82,   150,    38,     0,    91,    92,    38,    65,
      48,    84,   152,    96,   149,     5,    25,    26,    27,    28,
      29,    30,    31,    33,    34,    35,    36,    37,    38,    42,
      46,    51,    62,    63,    79,    85,    86,    87,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    39,    39,    44,    42,
     129,   130,   149,   150,   129,   130,    42,   121,   154,    42,
     121,   131,   149,    83,   121,   121,    86,    87,    48,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      75,    76,    77,    78,    79,    80,    81,    25,    26,    42,
      45,   129,   130,    38,    46,    48,    40,   149,    42,    46,
      42,    39,    44,    44,   121,    43,    44,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   129,   130,   129,   130,   121,
      32,    34,   149,   131,   149,     8,    10,    12,    13,    15,
      16,    17,    19,    20,    21,    22,    23,    24,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     122,   126,   127,   135,   136,   139,   143,   144,   145,   146,
     149,   121,   149,   121,   121,   154,    43,   121,    43,    39,
      38,    38,   154,    48,    48,    38,    38,    38,    38,    38,
      79,   152,   156,   158,    47,    48,    48,    48,   121,    41,
      98,    48,    48,    48,     6,     7,     9,    11,    45,    49,
      50,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    43,    44,    44,    43,   131,   121,    48,   121,
     121,   119,   122,   126,   139,   149,   121,    47,    47,    47,
      48,    38,    38,    38,    38,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,    43,   121,   154,    38,
      39,    39,    39,    39,    48,    18,    44,    39,   121,   121,
     121,   121,    38,    39,    39,   131,    48,    40,    98,    40,
      98,   120,   121,   123,   121,   149,    40,    39,    39,    44,
      39,    44,    39,    44,   131,    39,    97,    14,    97,    48,
      39,    18,    97,    48,    48,   131,    48,   131,    48,   131,
      39,    41,    40,    98,    41,   119,    40,    98,   121,    41,
      39,    39,    39,    14,    97,    39,    97,    39,    48,    48,
      48,    40,    98,    41,    40,    98,    41,    40,    98,    97,
      97,    97,    41,    41,    41
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    88,    89,    89,    90,    90,    90,    90,    91,    92,
      92,    92,    93,    94,    95,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   107,   108,   108,   109,   109,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   112,   113,
     114,   114,   114,   115,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   127,
     127,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   132,   132,   133,   134,   135,   136,
     137,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   154,   154,   154,   155,   156,
     157,   158,   159,   160
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     1,
       1,     1,     5,     4,     7,     3,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     6,     8,     6,     5,     3,     8,
       6,     8,     6,     2,     2,     7,     5,    11,     9,     9,
       7,     7,     5,    11,     9,     9,    11,     7,     9,     7,
       3,     3,     3,     2,     2,     2,     3,     2,     1,     0,
       1,     0,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     2,     2,     3,     3,     4,     6,     8,
       9,     3,     1,     0,     2,     3,     3,     7,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     7,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1
  };




#if S2DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   134,   134,   135,   139,   141,   143,   145,   150,   155,
     156,   157,   161,   166,   171,   176,   178,   181,   185,   187,
     190,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   217,   219,   224,   229,   234,   236,   241,   243,   248,
     250,   255,   257,   262,   267,   272,   274,   283,   285,   291,
     297,   308,   310,   318,   320,   329,   331,   333,   339,   348,
     353,   355,   357,   362,   367,   372,   377,   379,   384,   385,
     389,   390,   394,   395,   396,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   416,   417,
     418,   419,   420,   421,   422,   423,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   472,   473,   474,   475,   479,
     480,   481,   482,   486,   487,   488,   489,   493,   495,   500,
     502,   507,   509,   512,   516,   518,   523,   528,   533,   538,
     543,   548,   553,   554,   555,   556,   557,   558,   559,   560,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   578,   583,   584,   585,   586,   589,   590,
     591,   592,   593,   594
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
#endif // S2DEBUG


#line 14 "S2.parser.ypp"
} // S2
#line 4239 "./S2/compiler_parser.cpp"

#line 596 "S2.parser.ypp"


void S2::parser::error(const std::string& msg)
{
    throw gsc::comp_error(0, msg);
}
