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

  case 51: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr RPAREN SEMICOLON
#line 256 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(*pos, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 2013 "./S2/compiler_parser.cpp"
    break;

  case 52: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 261 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(*pos); }
#line 2019 "./S2/compiler_parser.cpp"
    break;

  case 53: // stmt_waitframe: WAITFRAME SEMICOLON
#line 266 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waitframe_ptr > () = std::make_unique<gsc::node_stmt_waitframe>(*pos); }
#line 2025 "./S2/compiler_parser.cpp"
    break;

  case 54: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 271 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2031 "./S2/compiler_parser.cpp"
    break;

  case 55: // stmt_if: IF LPAREN expr RPAREN stmt
#line 273 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2041 "./S2/compiler_parser.cpp"
    break;

  case 56: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 282 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2047 "./S2/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 284 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ()));
        }
#line 2057 "./S2/compiler_parser.cpp"
    break;

  case 58: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 290 "S2.parser.ypp"
        { 
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk));
        }
#line 2067 "./S2/compiler_parser.cpp"
    break;

  case 59: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 296 "S2.parser.ypp"
        {
            auto blk1 = std::make_unique<gsc::node_block>(*pos);
            blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
            auto blk2 = std::make_unique<gsc::node_block>(*pos);
            blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2));
        }
#line 2079 "./S2/compiler_parser.cpp"
    break;

  case 60: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 307 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2085 "./S2/compiler_parser.cpp"
    break;

  case 61: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 309 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 2094 "./S2/compiler_parser.cpp"
    break;

  case 62: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN LBRACE block RBRACE
#line 317 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2100 "./S2/compiler_parser.cpp"
    break;

  case 63: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN stmt
#line 319 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(*pos, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2110 "./S2/compiler_parser.cpp"
    break;

  case 64: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN LBRACE block RBRACE
#line 328 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2116 "./S2/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN LBRACE block RBRACE
#line 330 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[8].value.as < gsc::name_ptr > ()), std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2122 "./S2/compiler_parser.cpp"
    break;

  case 66: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN stmt
#line 332 "S2.parser.ypp"
        {
        auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2132 "./S2/compiler_parser.cpp"
    break;

  case 67: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN stmt
#line 338 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(*pos);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(*pos, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2142 "./S2/compiler_parser.cpp"
    break;

  case 68: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 347 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(*pos, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2148 "./S2/compiler_parser.cpp"
    break;

  case 69: // stmt_case: CASE integer COLON
#line 352 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2154 "./S2/compiler_parser.cpp"
    break;

  case 70: // stmt_case: CASE neg_integer COLON
#line 354 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2160 "./S2/compiler_parser.cpp"
    break;

  case 71: // stmt_case: CASE string COLON
#line 356 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(*pos, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 2166 "./S2/compiler_parser.cpp"
    break;

  case 72: // stmt_default: DEFAULT COLON
#line 361 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(*pos); }
#line 2172 "./S2/compiler_parser.cpp"
    break;

  case 73: // stmt_break: BREAK SEMICOLON
#line 366 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(*pos); }
#line 2178 "./S2/compiler_parser.cpp"
    break;

  case 74: // stmt_continue: CONTINUE SEMICOLON
#line 371 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(*pos); }
#line 2184 "./S2/compiler_parser.cpp"
    break;

  case 75: // stmt_return: RETURN expr SEMICOLON
#line 376 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2190 "./S2/compiler_parser.cpp"
    break;

  case 76: // stmt_return: RETURN SEMICOLON
#line 378 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(*pos, std::make_unique<gsc::node>()); }
#line 2196 "./S2/compiler_parser.cpp"
    break;

  case 77: // for_stmt: expr_assign
#line 382 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2202 "./S2/compiler_parser.cpp"
    break;

  case 78: // for_stmt: %empty
#line 383 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2208 "./S2/compiler_parser.cpp"
    break;

  case 79: // for_expr: expr_compare
#line 387 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2214 "./S2/compiler_parser.cpp"
    break;

  case 80: // for_expr: %empty
#line 388 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2220 "./S2/compiler_parser.cpp"
    break;

  case 81: // expr: expr_compare
#line 392 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2226 "./S2/compiler_parser.cpp"
    break;

  case 82: // expr: expr_binary
#line 393 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2232 "./S2/compiler_parser.cpp"
    break;

  case 83: // expr: expr_primitive
#line 394 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2238 "./S2/compiler_parser.cpp"
    break;

  case 84: // expr_assign: object INCREMENT
#line 398 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2244 "./S2/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object DECREMENT
#line 399 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(*pos, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2250 "./S2/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object ASSIGN expr
#line 400 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2256 "./S2/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 401 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2262 "./S2/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 402 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2268 "./S2/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 403 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2274 "./S2/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_LSHIFT expr
#line 404 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2280 "./S2/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_RSHIFT expr
#line 405 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2286 "./S2/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_ADD expr
#line 406 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2292 "./S2/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_SUB expr
#line 407 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2298 "./S2/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_MULT expr
#line 408 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2304 "./S2/compiler_parser.cpp"
    break;

  case 95: // expr_assign: object ASSIGN_DIV expr
#line 409 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2310 "./S2/compiler_parser.cpp"
    break;

  case 96: // expr_assign: object ASSIGN_MOD expr
#line 410 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2316 "./S2/compiler_parser.cpp"
    break;

  case 97: // expr_compare: expr OR expr
#line 414 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2322 "./S2/compiler_parser.cpp"
    break;

  case 98: // expr_compare: expr AND expr
#line 415 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2328 "./S2/compiler_parser.cpp"
    break;

  case 99: // expr_compare: expr EQUALITY expr
#line 416 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2334 "./S2/compiler_parser.cpp"
    break;

  case 100: // expr_compare: expr INEQUALITY expr
#line 417 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2340 "./S2/compiler_parser.cpp"
    break;

  case 101: // expr_compare: expr LESS_EQUAL expr
#line 418 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2346 "./S2/compiler_parser.cpp"
    break;

  case 102: // expr_compare: expr GREATER_EQUAL expr
#line 419 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2352 "./S2/compiler_parser.cpp"
    break;

  case 103: // expr_compare: expr LESS expr
#line 420 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2358 "./S2/compiler_parser.cpp"
    break;

  case 104: // expr_compare: expr GREATER expr
#line 421 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2364 "./S2/compiler_parser.cpp"
    break;

  case 105: // expr_binary: expr BITWISE_OR expr
#line 425 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2370 "./S2/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr BITWISE_AND expr
#line 426 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2376 "./S2/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr BITWISE_EXOR expr
#line 427 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2382 "./S2/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr LSHIFT expr
#line 428 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2388 "./S2/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr RSHIFT expr
#line 429 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2394 "./S2/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr ADD expr
#line 430 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2400 "./S2/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr SUB expr
#line 431 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2406 "./S2/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr MULT expr
#line 432 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2412 "./S2/compiler_parser.cpp"
    break;

  case 113: // expr_binary: expr DIV expr
#line 433 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2418 "./S2/compiler_parser.cpp"
    break;

  case 114: // expr_binary: expr MOD expr
#line 434 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(*pos, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2424 "./S2/compiler_parser.cpp"
    break;

  case 115: // expr_primitive: LPAREN expr RPAREN
#line 438 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2430 "./S2/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: COMPLEMENT expr
#line 439 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2436 "./S2/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: NOT expr
#line 440 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(*pos, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2442 "./S2/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: expr_call
#line 441 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2448 "./S2/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_call_thread
#line 442 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2454 "./S2/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_call_childthread
#line 443 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2460 "./S2/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_function
#line 444 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2466 "./S2/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_add_array
#line 445 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2472 "./S2/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_vector
#line 446 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2478 "./S2/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_array
#line 447 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2484 "./S2/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: expr_field
#line 448 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2490 "./S2/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: expr_self
#line 449 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2496 "./S2/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: expr_size
#line 450 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2502 "./S2/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: thisthread
#line 451 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::thisthread_ptr > ()); }
#line 2508 "./S2/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: empty_array
#line 452 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::empty_array_ptr > ()); }
#line 2514 "./S2/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: undefined
#line 453 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::undefined_ptr > ()); }
#line 2520 "./S2/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: game
#line 454 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2526 "./S2/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: self
#line 455 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2532 "./S2/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: anim
#line 456 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2538 "./S2/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: level
#line 457 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2544 "./S2/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: animation
#line 458 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animation_ptr > ()); }
#line 2550 "./S2/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: animtree
#line 459 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2556 "./S2/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: name
#line 460 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2562 "./S2/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: istring
#line 461 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::istring_ptr > ()); }
#line 2568 "./S2/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: string
#line 462 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2574 "./S2/compiler_parser.cpp"
    break;

  case 140: // expr_primitive: vector
#line 463 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2580 "./S2/compiler_parser.cpp"
    break;

  case 141: // expr_primitive: number
#line 464 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::number_ptr > ().as_node); }
#line 2586 "./S2/compiler_parser.cpp"
    break;

  case 142: // expr_primitive: false
#line 465 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2592 "./S2/compiler_parser.cpp"
    break;

  case 143: // expr_primitive: true
#line 466 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2598 "./S2/compiler_parser.cpp"
    break;

  case 144: // expr_call: expr_call_function
#line 470 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2604 "./S2/compiler_parser.cpp"
    break;

  case 145: // expr_call: expr_call_pointer
#line 471 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2610 "./S2/compiler_parser.cpp"
    break;

  case 146: // expr_call: object expr_call_function
#line 472 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2616 "./S2/compiler_parser.cpp"
    break;

  case 147: // expr_call: object expr_call_pointer
#line 473 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2622 "./S2/compiler_parser.cpp"
    break;

  case 148: // expr_call_thread: THREAD expr_call_function
#line 477 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2628 "./S2/compiler_parser.cpp"
    break;

  case 149: // expr_call_thread: THREAD expr_call_pointer
#line 478 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2634 "./S2/compiler_parser.cpp"
    break;

  case 150: // expr_call_thread: object THREAD expr_call_function
#line 479 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2640 "./S2/compiler_parser.cpp"
    break;

  case 151: // expr_call_thread: object THREAD expr_call_pointer
#line 480 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2646 "./S2/compiler_parser.cpp"
    break;

  case 152: // expr_call_childthread: CHILDTHREAD expr_call_function
#line 484 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2652 "./S2/compiler_parser.cpp"
    break;

  case 153: // expr_call_childthread: CHILDTHREAD expr_call_pointer
#line 485 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2658 "./S2/compiler_parser.cpp"
    break;

  case 154: // expr_call_childthread: object CHILDTHREAD expr_call_function
#line 486 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2664 "./S2/compiler_parser.cpp"
    break;

  case 155: // expr_call_childthread: object CHILDTHREAD expr_call_pointer
#line 487 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(*pos, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2670 "./S2/compiler_parser.cpp"
    break;

  case 156: // expr_call_function: name LPAREN expr_arguments RPAREN
#line 492 "S2.parser.ypp"
        {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2676 "./S2/compiler_parser.cpp"
    break;

  case 157: // expr_call_function: file DOUBLECOLON name LPAREN expr_arguments RPAREN
#line 494 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(*pos, std::move(yystack_[5].value.as < gsc::file_ptr > ()), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2682 "./S2/compiler_parser.cpp"
    break;

  case 158: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 499 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2688 "./S2/compiler_parser.cpp"
    break;

  case 159: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 501 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(*pos, true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2694 "./S2/compiler_parser.cpp"
    break;

  case 160: // expr_arguments: expr_arguments COMMA expr
#line 506 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2700 "./S2/compiler_parser.cpp"
    break;

  case 161: // expr_arguments: expr
#line 508 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2706 "./S2/compiler_parser.cpp"
    break;

  case 162: // expr_arguments: %empty
#line 510 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(*pos); }
#line 2712 "./S2/compiler_parser.cpp"
    break;

  case 163: // expr_function: DOUBLECOLON name
#line 515 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::make_unique<gsc::node_file>(), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2718 "./S2/compiler_parser.cpp"
    break;

  case 164: // expr_function: file DOUBLECOLON name
#line 517 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(*pos, std::move(yystack_[2].value.as < gsc::file_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2724 "./S2/compiler_parser.cpp"
    break;

  case 165: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 522 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(*pos, std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2730 "./S2/compiler_parser.cpp"
    break;

  case 166: // expr_vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 527 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_vector>(*pos, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2736 "./S2/compiler_parser.cpp"
    break;

  case 167: // expr_array: object LBRACKET expr RBRACKET
#line 532 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(*pos, std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2742 "./S2/compiler_parser.cpp"
    break;

  case 168: // expr_field: object DOT name
#line 537 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2748 "./S2/compiler_parser.cpp"
    break;

  case 169: // expr_self: object DOT SELF
#line 542 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_self>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2754 "./S2/compiler_parser.cpp"
    break;

  case 170: // expr_size: object DOT SIZE
#line 547 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(*pos, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2760 "./S2/compiler_parser.cpp"
    break;

  case 171: // object: expr_call
#line 551 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2766 "./S2/compiler_parser.cpp"
    break;

  case 172: // object: expr_array
#line 552 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2772 "./S2/compiler_parser.cpp"
    break;

  case 173: // object: expr_field
#line 553 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2778 "./S2/compiler_parser.cpp"
    break;

  case 174: // object: game
#line 554 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2784 "./S2/compiler_parser.cpp"
    break;

  case 175: // object: self
#line 555 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2790 "./S2/compiler_parser.cpp"
    break;

  case 176: // object: anim
#line 556 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2796 "./S2/compiler_parser.cpp"
    break;

  case 177: // object: level
#line 557 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2802 "./S2/compiler_parser.cpp"
    break;

  case 178: // object: name
#line 558 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2808 "./S2/compiler_parser.cpp"
    break;

  case 179: // thisthread: THISTHREAD
#line 561 "S2.parser.ypp"
                          { yylhs.value.as < gsc::thisthread_ptr > () = std::make_unique<gsc::node_thisthread>(*pos); }
#line 2814 "./S2/compiler_parser.cpp"
    break;

  case 180: // empty_array: EMPTY_ARRAY
#line 562 "S2.parser.ypp"
                          { yylhs.value.as < gsc::empty_array_ptr > () = std::make_unique<gsc::node_empty_array>(*pos); }
#line 2820 "./S2/compiler_parser.cpp"
    break;

  case 181: // undefined: UNDEFINED
#line 563 "S2.parser.ypp"
                          { yylhs.value.as < gsc::undefined_ptr > () = std::make_unique<gsc::node_undefined>(*pos); }
#line 2826 "./S2/compiler_parser.cpp"
    break;

  case 182: // game: GAME
#line 564 "S2.parser.ypp"
                          { yylhs.value.as < gsc::game_ptr > () = std::make_unique<gsc::node_game>(*pos); }
#line 2832 "./S2/compiler_parser.cpp"
    break;

  case 183: // self: SELF
#line 565 "S2.parser.ypp"
                          { yylhs.value.as < gsc::self_ptr > () = std::make_unique<gsc::node_self>(*pos); }
#line 2838 "./S2/compiler_parser.cpp"
    break;

  case 184: // anim: ANIM
#line 566 "S2.parser.ypp"
                          { yylhs.value.as < gsc::anim_ptr > () = std::make_unique<gsc::node_anim>(*pos); }
#line 2844 "./S2/compiler_parser.cpp"
    break;

  case 185: // level: LEVEL
#line 567 "S2.parser.ypp"
                          { yylhs.value.as < gsc::level_ptr > () = std::make_unique<gsc::node_level>(*pos); }
#line 2850 "./S2/compiler_parser.cpp"
    break;

  case 186: // animation: MOD NAME
#line 568 "S2.parser.ypp"
                          { yylhs.value.as < gsc::animation_ptr > () = std::make_unique<gsc::node_animation>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2856 "./S2/compiler_parser.cpp"
    break;

  case 187: // animtree: ANIMTREE
#line 569 "S2.parser.ypp"
                          { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(*pos); }
#line 2862 "./S2/compiler_parser.cpp"
    break;

  case 188: // name: NAME
#line 570 "S2.parser.ypp"
                          { yylhs.value.as < gsc::name_ptr > () = std::make_unique<gsc::node_name>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2868 "./S2/compiler_parser.cpp"
    break;

  case 189: // file: FILE
#line 571 "S2.parser.ypp"
                          { yylhs.value.as < gsc::file_ptr > () = std::make_unique<gsc::node_file>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2874 "./S2/compiler_parser.cpp"
    break;

  case 190: // istring: ISTRING
#line 572 "S2.parser.ypp"
                          { yylhs.value.as < gsc::istring_ptr > () = std::make_unique<gsc::node_istring>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2880 "./S2/compiler_parser.cpp"
    break;

  case 191: // string: STRING
#line 573 "S2.parser.ypp"
                          { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2886 "./S2/compiler_parser.cpp"
    break;

  case 192: // vector: LPAREN number COMMA number COMMA number RPAREN
#line 577 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_vector>(*pos, std::move(yystack_[5].value.as < gsc::number_ptr > ()), std::move(yystack_[3].value.as < gsc::number_ptr > ()), std::move(yystack_[1].value.as < gsc::number_ptr > ())); }
#line 2892 "./S2/compiler_parser.cpp"
    break;

  case 193: // number: neg_float
#line 581 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2898 "./S2/compiler_parser.cpp"
    break;

  case 194: // number: neg_integer
#line 582 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2904 "./S2/compiler_parser.cpp"
    break;

  case 195: // number: float
#line 583 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2910 "./S2/compiler_parser.cpp"
    break;

  case 196: // number: integer
#line 584 "S2.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer  = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2916 "./S2/compiler_parser.cpp"
    break;

  case 197: // neg_float: SUB FLOAT
#line 587 "S2.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2922 "./S2/compiler_parser.cpp"
    break;

  case 198: // neg_integer: SUB INTEGER
#line 588 "S2.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, "-" + yystack_[0].value.as < std::string > ()); }
#line 2928 "./S2/compiler_parser.cpp"
    break;

  case 199: // float: FLOAT
#line 589 "S2.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2934 "./S2/compiler_parser.cpp"
    break;

  case 200: // integer: INTEGER
#line 590 "S2.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(*pos, yystack_[0].value.as < std::string > ()); }
#line 2940 "./S2/compiler_parser.cpp"
    break;

  case 201: // false: FALSE
#line 591 "S2.parser.ypp"
                          { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(*pos); }
#line 2946 "./S2/compiler_parser.cpp"
    break;

  case 202: // true: TRUE
#line 592 "S2.parser.ypp"
                          { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(*pos); }
#line 2952 "./S2/compiler_parser.cpp"
    break;


#line 2956 "./S2/compiler_parser.cpp"

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


  const short parser::yypact_ninf_ = -237;

  const short parser::yytable_ninf_ = -179;

  const short
  parser::yypact_[] =
  {
       8,   -61,    -8,  -237,    33,     8,  -237,  -237,  -237,  -237,
    -237,   -22,  -237,     2,   -46,  -237,  -237,  -237,   -31,  1201,
    -237,  -237,    20,   -10,  -237,  -237,    40,    40,  -237,    37,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  1201,  1264,
     -31,     4,  1201,  1201,   -72,  -237,  -237,  -237,  2437,  -237,
    -237,  -237,    69,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
      75,   121,  -237,  -237,   204,  -237,  -237,  -237,   237,   273,
     279,   352,  -237,  -237,    -6,    43,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,    45,    58,   -31,    60,
    -237,  -237,    68,    70,  -237,  -237,    79,  2007,    80,  1264,
    2482,    82,  -237,  -237,  2482,  2482,  -237,  -237,  -237,  1201,
    1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,
    1201,  1201,  1201,  1201,  1201,  1201,  1201,    40,    40,  1264,
      13,  -237,  -237,  1201,   -31,  -237,  1967,  -237,  1201,   -31,
    1201,  -237,  1201,   -62,   602,  -237,  1201,  2482,  2482,  2482,
    2482,  2482,  2482,  2482,  2482,  2482,  2482,  2482,  2482,  2482,
    2482,  2482,  2482,  2482,  2482,  -237,  -237,  -237,  -237,  2296,
    -237,  -237,  -237,    -2,    91,    81,    83,    87,   102,   103,
     104,   105,   106,   -56,   101,   107,   108,  1138,  1386,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
     111,   113,   114,  -237,  -237,  1310,  -237,  -237,  -237,  -237,
      68,   602,    91,  2327,  2365,   109,   122,  2482,  -237,  -237,
    1201,  1201,   116,  -237,  -237,  1201,  1201,   418,   -31,  1201,
      63,   126,   128,   130,  -237,  -237,  -237,  -237,  2471,  -237,
    -237,  -237,  -237,  -237,   131,   142,   145,   146,   -31,  -237,
    -237,  1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,
    1201,  1201,   143,  1201,   -62,   147,     7,   471,  -237,  2104,
    2136,   139,  -237,  -237,  1971,    -9,  2147,  -237,  -237,  -237,
    -237,  1201,  1201,  1201,  1201,  2482,  2482,  2482,  2482,  2482,
    2482,  2482,  2482,  2482,  2482,  2482,   151,  2179,   115,  1201,
    -237,   153,    50,  1421,  1201,  1201,   -31,   154,  2190,  2050,
    2093,  2403,  1201,  -237,  -237,     9,  -237,  1967,   179,  1967,
    -237,   157,  2482,   158,  2222,   184,  1967,   159,   161,  1201,
     163,  1201,  1201,    10,  -237,  1464,  1499,  1542,   418,  1577,
    1201,  1620,  -237,  -237,    17,  -237,    71,  2233,  -237,   202,
    1967,  -237,  -237,   178,  1967,  -237,  2265,  -237,   170,   172,
     174,  1655,  1698,  1733,  1776,  1811,  -237,  -237,  -237,  1967,
    -237,  -237,  1967,  -237,  -237,  1967,  -237,  1854,  1889,  1932,
    -237,  -237,  -237
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   188,     0,     2,     6,     7,     9,    10,
      11,     0,   189,     0,     0,     1,     4,     5,    17,     0,
       8,   191,     0,     0,    16,   187,     0,     0,   179,     0,
     202,   201,   181,   182,   183,   184,   185,   180,     0,   162,
       0,     0,     0,     0,     0,   190,   199,   200,     0,    81,
      82,    83,   118,   119,   120,   144,   145,   121,   122,   123,
     124,   125,   126,   127,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,   138,   139,   140,   141,
     193,   194,   195,   196,   142,   143,     0,     0,     0,     0,
     148,   149,     0,     0,   152,   153,     0,     0,   141,   162,
     161,     0,   163,   186,   117,   116,   197,   198,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   162,     0,    12,    20,    15,     0,     0,
       0,   115,     0,     0,   161,   165,     0,   114,   108,   109,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   110,   111,   112,   113,   150,   151,   154,   155,     0,
     170,   169,   168,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,   171,     0,   172,   173,     0,   174,   175,   176,   177,
     178,     0,     0,     0,     0,     0,     0,   160,   167,   156,
     162,     0,     0,    53,    52,     0,     0,    78,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    76,     0,    14,
      18,    43,    41,    42,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    77,   171,     0,     0,     0,    71,    70,    69,
      75,     0,     0,     0,     0,    91,    86,    92,    93,    94,
      95,    96,    87,    88,    89,    90,     0,     0,     0,   162,
     157,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,   162,   166,   192,     0,    47,    20,    55,    20,
      61,     0,     0,    81,     0,     0,    20,     0,     0,   162,
       0,   162,     0,     0,   158,     0,     0,     0,    78,     0,
       0,     0,    44,    46,     0,    50,     0,     0,   159,    54,
      20,    59,    60,     0,    20,    66,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    49,    51,    20,
      58,    57,    20,    63,    64,    20,    67,     0,     0,     0,
      56,    62,    65
  };

  const short
  parser::yypgoto_[] =
  {
    -237,  -237,  -237,   218,   219,  -237,  -237,  -237,  -237,  -108,
    -175,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -123,  -237,   373,  -236,   -88,  -237,  -237,   208,   -79,
    -237,   -23,   -20,  -131,  -237,  -237,  -237,   381,   435,  -237,
    -237,   513,  -237,  -237,  -237,   584,   641,   705,   773,  -237,
    -237,     0,    54,  -237,    -4,  -237,   -30,  -237,    44,  -237,
      48,  -237,  -237
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
      11,   282,   173,    90,    94,    11,    91,    95,    98,   315,
      22,     1,     2,   250,   106,   107,    18,    44,    24,  -178,
    -178,    12,  -178,   240,    46,    47,    92,    92,    21,    87,
      14,    47,   133,    15,    88,   316,  -178,   229,    21,  -178,
     102,   131,   146,    19,   132,   170,   310,   171,   344,   358,
      20,   146,     3,   146,   146,    13,   368,   212,   175,    86,
     176,   146,   177,   178,    92,   179,   180,   181,    29,   182,
     183,   184,   185,   186,   187,    26,  -178,  -178,    29,    96,
      93,    93,    89,    33,    34,    35,    36,   103,   137,   134,
     327,     3,    89,   135,  -171,  -171,     3,  -171,   136,   276,
    -172,  -172,   138,  -172,   165,   167,   133,   166,   168,   212,
     369,  -171,   282,   225,  -171,   146,   139,  -172,    93,   231,
    -172,   140,    12,     3,   143,   145,   146,    92,    92,   230,
     172,   233,    12,     3,   174,   234,   220,   328,   330,   222,
     235,   236,   237,   238,   239,   232,  -173,  -173,   244,  -173,
     107,  -171,  -171,   274,   324,   245,   246,  -172,  -172,   251,
      44,   252,   253,  -173,   278,   275,  -173,    46,    47,   291,
     250,   361,   250,   287,   365,   288,   250,   289,   325,   241,
     292,    93,    93,   293,   294,   309,   306,   314,   220,   322,
      93,   343,   131,   346,   336,   132,   380,   250,   383,   250,
     386,   326,   350,  -173,  -173,   348,   -79,   352,   354,   353,
     356,   355,   250,   250,   250,    92,   371,   373,   376,   345,
     377,   347,   378,    16,    17,   363,   333,   242,   351,   127,
     128,   243,    29,   212,   212,     0,     0,   220,   285,     0,
       0,     0,    93,     0,   308,     0,   129,     0,   212,   130,
     212,     0,   372,     0,     0,     0,   374,   212,   172,     0,
       0,   131,  -174,  -174,   132,  -174,   212,   212,   212,    93,
     212,   387,   212,     0,   388,     0,     0,   389,     0,  -174,
       0,   212,  -174,     0,    92,   212,    12,     3,     0,     0,
       0,    93,   212,   212,   212,   212,   212,     0,  -175,  -175,
     212,  -175,     0,   212,  -176,  -176,   212,  -176,   212,   212,
     212,     0,   220,   220,     0,  -175,   335,     0,  -175,  -174,
    -174,  -176,     0,     0,  -176,     0,     0,   220,     0,   220,
       0,     0,     0,     0,     0,     0,   220,     0,    93,     0,
       0,     0,     0,     0,   211,   220,   220,   220,   220,   220,
       0,   220,     0,     0,     0,  -175,  -175,     0,     0,     0,
     220,  -176,  -176,     0,   220,     0,    93,    93,     0,     0,
       0,   220,   220,   220,   220,   220,     0,  -177,  -177,   220,
    -177,    93,   220,    93,     0,   220,     0,   220,   220,   220,
      93,     0,    48,     0,  -177,     0,   211,  -177,     0,    93,
      93,    93,    93,    93,     0,    93,     0,     0,     0,     0,
       0,    97,     0,     0,    93,   104,   105,     0,    93,     0,
       0,     0,     0,     0,     0,    93,    93,    93,    93,    93,
       0,     0,     0,    93,  -177,  -177,    93,     0,     0,    93,
       0,    93,    93,    93,     0,   283,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      12,     3,   169,     0,     0,     0,     0,     0,     0,     0,
     311,   221,     0,   223,     0,   224,     0,   213,     0,   227,
     211,   211,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,   211,     0,   211,     0,     0,
       0,     0,     0,     0,   211,     0,   120,   121,   122,   123,
     124,   125,   126,   211,   211,   211,   283,   211,     0,   211,
     248,     0,     0,     0,     0,     0,     0,     0,   211,   213,
       0,   214,   211,     0,     0,     0,     0,     0,     0,   211,
     211,   211,   211,   211,     0,     0,     0,   211,     0,     0,
     211,     0,     0,   211,     0,   211,   211,   211,     0,     0,
       0,     0,     0,     0,   277,     0,     0,     0,   279,   280,
       0,     0,   286,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   226,   307,     0,     0,   215,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   318,   319,   320,   321,     0,     0,
       0,     0,   214,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,     0,     0,     0,   332,   334,     0,
       0,     0,     0,   213,   213,     0,     0,     0,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,   213,     0,
     213,     0,     0,     0,     0,   357,     0,   213,     0,     0,
     216,     0,     0,   366,     0,     0,   213,   213,   213,   213,
     213,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,   213,     0,   214,   214,     0,
     284,     0,   213,   213,   213,   213,   213,     0,     0,     0,
     213,     0,   214,   213,   214,     0,   213,     0,   213,   213,
     213,   214,   216,     0,     0,     0,     0,   217,     0,     0,
     214,   214,   214,   214,   214,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,   214,
       0,     0,     0,     0,     0,     0,   214,   214,   214,   214,
     214,     0,     0,     0,   214,     0,     0,   214,     0,     0,
     214,   216,   214,   214,   214,   215,   215,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   218,   215,     0,     0,     0,     0,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,   215,   215,
     215,   284,   215,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,   215,     0,     0,     0,   215,   217,     0,
       0,     0,     0,     0,   215,   215,   215,   215,   215,     0,
       0,     0,   215,   218,     0,   215,   216,   216,   215,     0,
     215,   215,   215,     0,     0,     0,     0,     0,     0,   219,
       0,   216,     0,   216,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,   216,
     216,   216,   216,   216,     0,   216,     0,     0,     0,     0,
       0,     0,   218,     0,   216,     0,     0,     0,   216,     0,
       0,     0,     0,   217,   217,   216,   216,   216,   216,   216,
       0,   219,     0,   216,     0,     0,   216,     0,   217,   216,
     217,   216,   216,   216,     0,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   217,   217,   217,
     217,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,   217,     0,     0,     0,     0,
     219,     0,   217,   217,   217,   217,   217,   218,   218,     0,
     217,     0,     0,   217,     0,     0,   217,     0,   217,   217,
     217,     0,   218,     0,   218,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   218,   218,   218,   218,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,   218,   218,   218,   218,
     218,     0,     0,     0,   218,   219,   219,   218,     0,     0,
     218,     0,   218,   218,   218,     0,     0,     0,     0,     0,
     219,     0,   219,     0,     0,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   219,
     219,   219,   219,     0,   219,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,   219,     0,     0,
       0,     0,     0,    25,   219,   219,   219,   219,   219,     0,
       0,     0,   219,     0,     0,   219,     0,     0,   219,     0,
     219,   219,   219,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
      39,     0,     0,     0,    40,     0,   247,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
      12,     3,    21,    45,    46,    47,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,    39,     0,     0,     0,    40,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,    12,     3,    21,    45,    46,    47,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,    99,     0,     0,     0,
      40,     0,     0,     0,     0,    41,   254,   255,     0,   256,
       0,   257,     0,     0,     0,     0,    42,    43,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,    29,     0,
       0,     0,     0,    44,     0,     0,    12,     3,    21,    45,
      46,    47,   129,     0,     0,   258,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,     0,     0,     0,     0,     0,
       0,     0,    12,     3,   175,     0,   176,     0,   177,   178,
       0,   179,   180,   181,     0,   182,   183,   184,   185,   186,
     187,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,     0,   249,    89,   175,
       0,   176,     0,   177,   178,     0,   179,   180,   181,     0,
     182,   183,   184,   185,   186,   187,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,   329,     0,    89,     0,     0,     0,     0,    12,     3,
       0,     0,   175,     0,   176,     0,   177,   178,     0,   179,
     180,   181,     0,   182,   183,   184,   185,   186,   187,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,    12,     3,   359,    89,   175,     0,   176,
       0,   177,   178,     0,   179,   180,   181,     0,   182,   183,
     184,   185,   186,   187,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,   360,
       0,    89,     0,     0,     0,     0,    12,     3,     0,     0,
     175,     0,   176,     0,   177,   178,     0,   179,   180,   181,
       0,   182,   183,   184,   185,   186,   187,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,    12,     3,   362,    89,   175,     0,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,   364,     0,    89,
       0,     0,     0,     0,    12,     3,     0,     0,   175,     0,
     176,     0,   177,   178,     0,   179,   180,   181,     0,   182,
     183,   184,   185,   186,   187,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,    12,
       3,   367,    89,   175,     0,   176,     0,   177,   178,     0,
     179,   180,   181,     0,   182,   183,   184,   185,   186,   187,
      26,     0,     0,    29,     0,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,   379,     0,    89,     0,     0,
       0,     0,    12,     3,     0,     0,   175,     0,   176,     0,
     177,   178,     0,   179,   180,   181,     0,   182,   183,   184,
     185,   186,   187,    26,     0,     0,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,    12,     3,   381,
      89,   175,     0,   176,     0,   177,   178,     0,   179,   180,
     181,     0,   182,   183,   184,   185,   186,   187,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,   382,     0,    89,     0,     0,     0,     0,
      12,     3,     0,     0,   175,     0,   176,     0,   177,   178,
       0,   179,   180,   181,     0,   182,   183,   184,   185,   186,
     187,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,    12,     3,   384,    89,   175,
       0,   176,     0,   177,   178,     0,   179,   180,   181,     0,
     182,   183,   184,   185,   186,   187,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,   385,     0,    89,     0,     0,     0,     0,    12,     3,
       0,     0,   175,     0,   176,     0,   177,   178,     0,   179,
     180,   181,     0,   182,   183,   184,   185,   186,   187,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,    12,     3,   390,    89,   175,     0,   176,
       0,   177,   178,     0,   179,   180,   181,     0,   182,   183,
     184,   185,   186,   187,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
     391,    89,     0,     0,     0,     0,    12,     3,     0,     0,
     175,     0,   176,     0,   177,   178,     0,   179,   180,   181,
       0,   182,   183,   184,   185,   186,   187,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,    12,     3,   392,    89,   175,     0,   176,     0,   177,
     178,     0,   179,   180,   181,     0,   182,   183,   184,   185,
     186,   187,    26,     0,     0,    29,     0,     0,     0,    29,
      33,    34,    35,    36,     0,     0,     0,     0,     0,    89,
       0,     0,     0,   129,    12,     3,   258,     0,     0,     0,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   141,     0,     0,    12,
       3,   142,     0,    12,     3,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   338,
       0,     0,     0,     0,   339,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   340,     0,     0,     0,     0,   341,     0,     0,
       0,     0,     0,   312,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   313,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   317,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   323,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   337,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,   123,   124,   125,
     126,   349,     0,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   370,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   375,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     120,   121,   122,   123,   124,   125,   126,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,   120,   121,   122,   123,   124,   125,   126,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   273,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   342,     0,     0,
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
       0,   237,   133,    26,    27,     5,    26,    27,    38,    18,
      14,     3,     4,   188,    86,    87,    38,    79,    18,    25,
      26,    82,    28,    79,    86,    87,    26,    27,    84,    39,
      38,    87,    38,     0,    44,    44,    42,    39,    84,    45,
      40,    64,    44,    65,    64,    32,    39,    34,    39,    39,
      48,    44,    83,    44,    44,     1,    39,   136,     8,    39,
      10,    44,    12,    13,    64,    15,    16,    17,    28,    19,
      20,    21,    22,    23,    24,    25,    82,    83,    28,    42,
      26,    27,    42,    33,    34,    35,    36,    83,    88,    46,
      40,    83,    42,    48,    25,    26,    83,    28,    40,   230,
      25,    26,    42,    28,   127,   128,    38,   127,   128,   188,
      39,    42,   348,   143,    45,    44,    46,    42,    64,    38,
      45,    42,    82,    83,    44,    43,    44,   127,   128,    38,
     130,    48,    82,    83,   134,    48,   136,   312,   313,   139,
      38,    38,    38,    38,    38,   175,    25,    26,    47,    28,
      87,    82,    83,    44,    39,    48,    48,    82,    83,    48,
      79,    48,    48,    42,    48,    43,    45,    86,    87,    38,
     345,   346,   347,    47,   349,    47,   351,    47,   309,   183,
      38,   127,   128,    38,    38,    38,    43,    48,   188,    38,
     136,   322,   215,    14,    40,   215,   371,   372,   373,   374,
     375,    48,    18,    82,    83,    48,    48,    48,   339,    48,
     341,    48,   387,   388,   389,   215,    14,    39,    48,   327,
      48,   329,    48,     5,     5,   348,   314,   183,   336,    25,
      26,   183,    28,   312,   313,    -1,    -1,   237,   238,    -1,
      -1,    -1,   188,    -1,   274,    -1,    42,    -1,   327,    45,
     329,    -1,   360,    -1,    -1,    -1,   364,   336,   258,    -1,
      -1,   284,    25,    26,   284,    28,   345,   346,   347,   215,
     349,   379,   351,    -1,   382,    -1,    -1,   385,    -1,    42,
      -1,   360,    45,    -1,   284,   364,    82,    83,    -1,    -1,
      -1,   237,   371,   372,   373,   374,   375,    -1,    25,    26,
     379,    28,    -1,   382,    25,    26,   385,    28,   387,   388,
     389,    -1,   312,   313,    -1,    42,   316,    -1,    45,    82,
      83,    42,    -1,    -1,    45,    -1,    -1,   327,    -1,   329,
      -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,   284,    -1,
      -1,    -1,    -1,    -1,   136,   345,   346,   347,   348,   349,
      -1,   351,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
     360,    82,    83,    -1,   364,    -1,   312,   313,    -1,    -1,
      -1,   371,   372,   373,   374,   375,    -1,    25,    26,   379,
      28,   327,   382,   329,    -1,   385,    -1,   387,   388,   389,
     336,    -1,    19,    -1,    42,    -1,   188,    45,    -1,   345,
     346,   347,   348,   349,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,   360,    42,    43,    -1,   364,    -1,
      -1,    -1,    -1,    -1,    -1,   371,   372,   373,   374,   375,
      -1,    -1,    -1,   379,    82,    83,   382,    -1,    -1,   385,
      -1,   387,   388,   389,    -1,   237,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      82,    83,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,   138,    -1,   140,    -1,   142,    -1,   136,    -1,   146,
     312,   313,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,   327,    -1,   329,    -1,    -1,
      -1,    -1,    -1,    -1,   336,    -1,    75,    76,    77,    78,
      79,    80,    81,   345,   346,   347,   348,   349,    -1,   351,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   188,
      -1,   136,   364,    -1,    -1,    -1,    -1,    -1,    -1,   371,
     372,   373,   374,   375,    -1,    -1,    -1,   379,    -1,    -1,
     382,    -1,    -1,   385,    -1,   387,   388,   389,    -1,    -1,
      -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,   235,   236,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,    43,   273,    -1,    -1,   136,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   291,   292,   293,   294,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,   314,   315,    -1,
      -1,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,
     329,    -1,    -1,    -1,    -1,   342,    -1,   336,    -1,    -1,
     136,    -1,    -1,   350,    -1,    -1,   345,   346,   347,   348,
     349,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,   364,    -1,   312,   313,    -1,
     237,    -1,   371,   372,   373,   374,   375,    -1,    -1,    -1,
     379,    -1,   327,   382,   329,    -1,   385,    -1,   387,   388,
     389,   336,   188,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     345,   346,   347,   348,   349,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,   364,
      -1,    -1,    -1,    -1,    -1,    -1,   371,   372,   373,   374,
     375,    -1,    -1,    -1,   379,    -1,    -1,   382,    -1,    -1,
     385,   237,   387,   388,   389,   312,   313,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,   136,   329,    -1,    -1,    -1,    -1,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,   346,
     347,   348,   349,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,    -1,    -1,    -1,   364,   237,    -1,
      -1,    -1,    -1,    -1,   371,   372,   373,   374,   375,    -1,
      -1,    -1,   379,   188,    -1,   382,   312,   313,   385,    -1,
     387,   388,   389,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   327,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
     346,   347,   348,   349,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    -1,   237,    -1,   360,    -1,    -1,    -1,   364,    -1,
      -1,    -1,    -1,   312,   313,   371,   372,   373,   374,   375,
      -1,   188,    -1,   379,    -1,    -1,   382,    -1,   327,   385,
     329,   387,   388,   389,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,   347,   348,
     349,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,   364,    -1,    -1,    -1,    -1,
     237,    -1,   371,   372,   373,   374,   375,   312,   313,    -1,
     379,    -1,    -1,   382,    -1,    -1,   385,    -1,   387,   388,
     389,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,    -1,
      -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   346,   347,   348,   349,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,   364,
      -1,    -1,    -1,    -1,    -1,    -1,   371,   372,   373,   374,
     375,    -1,    -1,    -1,   379,   312,   313,   382,    -1,    -1,
     385,    -1,   387,   388,   389,    -1,    -1,    -1,    -1,    -1,
     327,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,   346,
     347,   348,   349,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,    -1,    -1,    -1,   364,    -1,    -1,
      -1,    -1,    -1,     5,   371,   372,   373,   374,   375,    -1,
      -1,    -1,   379,    -1,    -1,   382,    -1,    -1,   385,    -1,
     387,   388,   389,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,     6,     7,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,     8,    -1,    10,    -1,    12,    13,
      -1,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,     8,
      -1,    10,    -1,    12,    13,    -1,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,     8,    -1,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    82,    83,    41,    42,     8,    -1,    10,
      -1,    12,    13,    -1,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
       8,    -1,    10,    -1,    12,    13,    -1,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    82,    83,    41,    42,     8,    -1,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,     8,    -1,
      10,    -1,    12,    13,    -1,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    82,
      83,    41,    42,     8,    -1,    10,    -1,    12,    13,    -1,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,     8,    -1,    10,    -1,
      12,    13,    -1,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    82,    83,    41,
      42,     8,    -1,    10,    -1,    12,    13,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,     8,    -1,    10,    -1,    12,    13,
      -1,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    82,    83,    41,    42,     8,
      -1,    10,    -1,    12,    13,    -1,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,     8,    -1,    10,    -1,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    82,    83,    41,    42,     8,    -1,    10,
      -1,    12,    13,    -1,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
       8,    -1,    10,    -1,    12,    13,    -1,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    82,    83,    41,    42,     8,    -1,    10,    -1,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    28,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    42,    82,    83,    45,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    39,    -1,    -1,    82,
      83,    44,    -1,    82,    83,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    39,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    39,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    39,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    39,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    39,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    39,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    39,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    39,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      75,    76,    77,    78,    79,    80,    81,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    75,    76,    77,    78,    79,    80,    81,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
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
      39,    44,    44,   131,    39,    97,    14,    97,    48,    39,
      18,    97,    48,    48,   131,    48,   131,   121,    39,    41,
      40,    98,    41,   119,    40,    98,   121,    41,    39,    39,
      39,    14,    97,    39,    97,    39,    48,    48,    48,    40,
      98,    41,    40,    98,    41,    40,    98,    97,    97,    97,
      41,    41,    41
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    88,    89,    89,    90,    90,    90,    90,    91,    92,
      92,    92,    93,    94,    95,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   106,   107,   108,   108,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   114,
     114,   114,   115,   116,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   133,   134,   135,   136,   137,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   154,   154,   154,   155,   156,   157,
     158,   159,   160
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     1,
       1,     1,     5,     4,     7,     3,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     6,     8,     6,     5,     3,     8,
       6,     8,     2,     2,     7,     5,    11,     9,     9,     7,
       7,     5,    11,     9,     9,    11,     7,     9,     7,     3,
       3,     3,     2,     2,     2,     3,     2,     1,     0,     1,
       0,     1,     1,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     2,     2,     3,     3,     4,     6,     8,     9,
       3,     1,     0,     2,     3,     3,     7,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     7,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1
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
     250,   255,   260,   265,   270,   272,   281,   283,   289,   295,
     306,   308,   316,   318,   327,   329,   331,   337,   346,   351,
     353,   355,   360,   365,   370,   375,   377,   382,   383,   387,
     388,   392,   393,   394,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   414,   415,   416,
     417,   418,   419,   420,   421,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   470,   471,   472,   473,   477,   478,
     479,   480,   484,   485,   486,   487,   491,   493,   498,   500,
     505,   507,   510,   514,   516,   521,   526,   531,   536,   541,
     546,   551,   552,   553,   554,   555,   556,   557,   558,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   576,   581,   582,   583,   584,   587,   588,   589,
     590,   591,   592
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
#line 4231 "./S2/compiler_parser.cpp"

#line 594 "S2.parser.ypp"


void S2::parser::error(const std::string& msg)
{
    throw gsc::comp_error(0, msg);
}
