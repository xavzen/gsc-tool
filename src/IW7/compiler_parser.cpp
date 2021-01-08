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
#line 40 "IW7.parser.ypp"

    #include "IW7.hpp"
    #include "compiler_parser.hpp"
    #include "compiler_lexer.hpp"
    IW7::parser::symbol_type IW7lex(yyscan_t yyscanner, gsc::location& loc);

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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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

#line 13 "IW7.parser.ypp"
namespace IW7 {
#line 148 "./IW7/compiler_parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, gsc::location& loc_yyarg, gsc::program_ptr& ast_yyarg)
#if IW7DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      yyscanner (yyscanner_yyarg),
      loc (loc_yyarg),
      ast (ast_yyarg)
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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
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
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
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

      case symbol_kind::S_vector: // vector
        value.YY_MOVE_OR_COPY< gsc::vector_ptr > (YY_MOVE (that.value));
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
    : super_type (s, YY_MOVE (that.location))
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
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
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

      case symbol_kind::S_vector: // vector
        value.move< gsc::vector_ptr > (YY_MOVE (that.value));
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
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
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

      case symbol_kind::S_vector: // vector
        value.copy< gsc::vector_ptr > (that.value);
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

    location = that.location;
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
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
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

      case symbol_kind::S_vector: // vector
        value.move< gsc::vector_ptr > (that.value);
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

    location = that.location;
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
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
            symbol_type yylookahead (yylex (yyscanner, loc));
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
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
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

      case symbol_kind::S_vector: // vector
        yylhs.value.emplace< gsc::vector_ptr > ();
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


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
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
#line 155 "IW7.parser.ypp"
              { ast = std::move(yystack_[0].value.as < gsc::program_ptr > ()); }
#line 1735 "./IW7/compiler_parser.cpp"
    break;

  case 3: // root: %empty
#line 156 "IW7.parser.ypp"
              { ast = std::make_unique<gsc::node_program>(yylhs.location); }
#line 1741 "./IW7/compiler_parser.cpp"
    break;

  case 4: // program: program include
#line 161 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1747 "./IW7/compiler_parser.cpp"
    break;

  case 5: // program: program define
#line 163 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1753 "./IW7/compiler_parser.cpp"
    break;

  case 6: // program: include
#line 165 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(yylhs.location); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1759 "./IW7/compiler_parser.cpp"
    break;

  case 7: // program: define
#line 167 "IW7.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(yylhs.location); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1765 "./IW7/compiler_parser.cpp"
    break;

  case 8: // include: INCLUDE file SEMICOLON
#line 172 "IW7.parser.ypp"
        { yylhs.value.as < gsc::include_ptr > () = std::make_unique<gsc::node_include>(yylhs.location, std::move(yystack_[1].value.as < gsc::file_ptr > ())); }
#line 1771 "./IW7/compiler_parser.cpp"
    break;

  case 9: // define: usingtree
#line 176 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_usingtree = std::move(yystack_[0].value.as < gsc::usingtree_ptr > ()); }
#line 1777 "./IW7/compiler_parser.cpp"
    break;

  case 10: // define: constant
#line 177 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_constant = std::move(yystack_[0].value.as < gsc::constant_ptr > ()); }
#line 1783 "./IW7/compiler_parser.cpp"
    break;

  case 11: // define: thread
#line 178 "IW7.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_thread = std::move(yystack_[0].value.as < gsc::thread_ptr > ()); }
#line 1789 "./IW7/compiler_parser.cpp"
    break;

  case 12: // usingtree: USINGTREE LPAREN string RPAREN SEMICOLON
#line 183 "IW7.parser.ypp"
        { yylhs.value.as < gsc::usingtree_ptr > () = std::make_unique<gsc::node_usingtree>(yylhs.location, std::move(yystack_[2].value.as < gsc::string_ptr > ())); }
#line 1795 "./IW7/compiler_parser.cpp"
    break;

  case 13: // constant: name ASSIGN expr SEMICOLON
#line 188 "IW7.parser.ypp"
        { yylhs.value.as < gsc::constant_ptr > () = std::make_unique<gsc::node_constant>(yylhs.location, std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1801 "./IW7/compiler_parser.cpp"
    break;

  case 14: // thread: name LPAREN parameters RPAREN LBRACE block RBRACE
#line 193 "IW7.parser.ypp"
        { yylhs.value.as < gsc::thread_ptr > () = std::make_unique<gsc::node_thread>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::parameters_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1807 "./IW7/compiler_parser.cpp"
    break;

  case 15: // parameters: parameters COMMA name
#line 198 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::move(yystack_[2].value.as < gsc::parameters_ptr > ()); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1813 "./IW7/compiler_parser.cpp"
    break;

  case 16: // parameters: name
#line 200 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(yylhs.location); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1819 "./IW7/compiler_parser.cpp"
    break;

  case 17: // parameters: %empty
#line 202 "IW7.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(yylhs.location); }
#line 1825 "./IW7/compiler_parser.cpp"
    break;

  case 18: // block: block stmt
#line 207 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::move(yystack_[1].value.as < gsc::block_ptr > ()); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1831 "./IW7/compiler_parser.cpp"
    break;

  case 19: // block: stmt
#line 209 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(yylhs.location); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1837 "./IW7/compiler_parser.cpp"
    break;

  case 20: // block: %empty
#line 211 "IW7.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(yylhs.location); }
#line 1843 "./IW7/compiler_parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 215 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_call = std::move(yystack_[0].value.as < gsc::stmt_call_ptr > ()); }
#line 1849 "./IW7/compiler_parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 216 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_assign = std::move(yystack_[0].value.as < gsc::stmt_assign_ptr > ()); }
#line 1855 "./IW7/compiler_parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 217 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_endon = std::move(yystack_[0].value.as < gsc::stmt_endon_ptr > ()); }
#line 1861 "./IW7/compiler_parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 218 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_notify = std::move(yystack_[0].value.as < gsc::stmt_notify_ptr > ()); }
#line 1867 "./IW7/compiler_parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 219 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_wait = std::move(yystack_[0].value.as < gsc::stmt_wait_ptr > ()); }
#line 1873 "./IW7/compiler_parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 220 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittill = std::move(yystack_[0].value.as < gsc::stmt_waittill_ptr > ()); }
#line 1879 "./IW7/compiler_parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 221 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillmatch = std::move(yystack_[0].value.as < gsc::stmt_waittillmatch_ptr > ()); }
#line 1885 "./IW7/compiler_parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 222 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillframeend = std::move(yystack_[0].value.as < gsc::stmt_waittillframeend_ptr > ()); }
#line 1891 "./IW7/compiler_parser.cpp"
    break;

  case 29: // stmt: stmt_if
#line 223 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_if = std::move(yystack_[0].value.as < gsc::stmt_if_ptr > ()); }
#line 1897 "./IW7/compiler_parser.cpp"
    break;

  case 30: // stmt: stmt_ifelse
#line 224 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_ifelse = std::move(yystack_[0].value.as < gsc::stmt_ifelse_ptr > ()); }
#line 1903 "./IW7/compiler_parser.cpp"
    break;

  case 31: // stmt: stmt_while
#line 225 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_while = std::move(yystack_[0].value.as < gsc::stmt_while_ptr > ()); }
#line 1909 "./IW7/compiler_parser.cpp"
    break;

  case 32: // stmt: stmt_for
#line 226 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_for = std::move(yystack_[0].value.as < gsc::stmt_for_ptr > ()); }
#line 1915 "./IW7/compiler_parser.cpp"
    break;

  case 33: // stmt: stmt_foreach
#line 227 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_foreach = std::move(yystack_[0].value.as < gsc::stmt_foreach_ptr > ()); }
#line 1921 "./IW7/compiler_parser.cpp"
    break;

  case 34: // stmt: stmt_switch
#line 228 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_switch = std::move(yystack_[0].value.as < gsc::stmt_switch_ptr > ()); }
#line 1927 "./IW7/compiler_parser.cpp"
    break;

  case 35: // stmt: stmt_case
#line 229 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_case = std::move(yystack_[0].value.as < gsc::stmt_case_ptr > ()); }
#line 1933 "./IW7/compiler_parser.cpp"
    break;

  case 36: // stmt: stmt_default
#line 230 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_default = std::move(yystack_[0].value.as < gsc::stmt_default_ptr > ()); }
#line 1939 "./IW7/compiler_parser.cpp"
    break;

  case 37: // stmt: stmt_break
#line 231 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_break = std::move(yystack_[0].value.as < gsc::stmt_break_ptr > ()); }
#line 1945 "./IW7/compiler_parser.cpp"
    break;

  case 38: // stmt: stmt_continue
#line 232 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_continue = std::move(yystack_[0].value.as < gsc::stmt_continue_ptr > ()); }
#line 1951 "./IW7/compiler_parser.cpp"
    break;

  case 39: // stmt: stmt_return
#line 233 "IW7.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_return = std::move(yystack_[0].value.as < gsc::stmt_return_ptr > ()); }
#line 1957 "./IW7/compiler_parser.cpp"
    break;

  case 40: // stmt_call: expr_call SEMICOLON
#line 238 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1963 "./IW7/compiler_parser.cpp"
    break;

  case 41: // stmt_call: expr_call_thread SEMICOLON
#line 240 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1969 "./IW7/compiler_parser.cpp"
    break;

  case 42: // stmt_assign: expr_assign SEMICOLON
#line 245 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_assign_ptr > () = std::make_unique<gsc::node_stmt_assign>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_assign_ptr > ())); }
#line 1975 "./IW7/compiler_parser.cpp"
    break;

  case 43: // stmt_endon: object ENDON LPAREN expr RPAREN SEMICOLON
#line 250 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_endon_ptr > () = std::make_unique<gsc::node_stmt_endon>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1981 "./IW7/compiler_parser.cpp"
    break;

  case 44: // stmt_notify: object NOTIFY LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 255 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1987 "./IW7/compiler_parser.cpp"
    break;

  case 45: // stmt_notify: object NOTIFY LPAREN expr RPAREN SEMICOLON
#line 257 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 1993 "./IW7/compiler_parser.cpp"
    break;

  case 46: // stmt_wait: WAIT LPAREN expr RPAREN SEMICOLON
#line 262 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1999 "./IW7/compiler_parser.cpp"
    break;

  case 47: // stmt_wait: WAIT number SEMICOLON
#line 264 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::number_ptr > ().as_node))); }
#line 2005 "./IW7/compiler_parser.cpp"
    break;

  case 48: // stmt_waittill: object WAITTILL LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 269 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 2011 "./IW7/compiler_parser.cpp"
    break;

  case 49: // stmt_waittill: object WAITTILL LPAREN expr RPAREN SEMICOLON
#line 271 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 2017 "./IW7/compiler_parser.cpp"
    break;

  case 50: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 276 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 2023 "./IW7/compiler_parser.cpp"
    break;

  case 51: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr RPAREN SEMICOLON
#line 278 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 2029 "./IW7/compiler_parser.cpp"
    break;

  case 52: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 283 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(yylhs.location); }
#line 2035 "./IW7/compiler_parser.cpp"
    break;

  case 53: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 288 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2041 "./IW7/compiler_parser.cpp"
    break;

  case 54: // stmt_if: IF LPAREN expr RPAREN stmt
#line 290 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2051 "./IW7/compiler_parser.cpp"
    break;

  case 55: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 299 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2057 "./IW7/compiler_parser.cpp"
    break;

  case 56: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 301 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[4].location);
            blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ()));
        }
#line 2067 "./IW7/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 307 "IW7.parser.ypp"
        { 
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk));
        }
#line 2077 "./IW7/compiler_parser.cpp"
    break;

  case 58: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 313 "IW7.parser.ypp"
        {
            auto blk1 = std::make_unique<gsc::node_block>(yystack_[2].location);
            blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
            auto blk2 = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2));
        }
#line 2089 "./IW7/compiler_parser.cpp"
    break;

  case 59: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 324 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2095 "./IW7/compiler_parser.cpp"
    break;

  case 60: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 326 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 2104 "./IW7/compiler_parser.cpp"
    break;

  case 61: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN LBRACE block RBRACE
#line 334 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(yylhs.location, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2110 "./IW7/compiler_parser.cpp"
    break;

  case 62: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN stmt
#line 336 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2120 "./IW7/compiler_parser.cpp"
    break;

  case 63: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN LBRACE block RBRACE
#line 345 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2126 "./IW7/compiler_parser.cpp"
    break;

  case 64: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN LBRACE block RBRACE
#line 347 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[8].value.as < gsc::name_ptr > ()), std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2132 "./IW7/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN stmt
#line 349 "IW7.parser.ypp"
        {
        auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2142 "./IW7/compiler_parser.cpp"
    break;

  case 66: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN stmt
#line 355 "IW7.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2152 "./IW7/compiler_parser.cpp"
    break;

  case 67: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 364 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2158 "./IW7/compiler_parser.cpp"
    break;

  case 68: // stmt_case: CASE integer COLON
#line 369 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2164 "./IW7/compiler_parser.cpp"
    break;

  case 69: // stmt_case: CASE neg_integer COLON
#line 371 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2170 "./IW7/compiler_parser.cpp"
    break;

  case 70: // stmt_case: CASE string COLON
#line 373 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 2176 "./IW7/compiler_parser.cpp"
    break;

  case 71: // stmt_default: DEFAULT COLON
#line 378 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(yylhs.location); }
#line 2182 "./IW7/compiler_parser.cpp"
    break;

  case 72: // stmt_break: BREAK SEMICOLON
#line 383 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(yylhs.location); }
#line 2188 "./IW7/compiler_parser.cpp"
    break;

  case 73: // stmt_continue: CONTINUE SEMICOLON
#line 388 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(yylhs.location); }
#line 2194 "./IW7/compiler_parser.cpp"
    break;

  case 74: // stmt_return: RETURN expr SEMICOLON
#line 393 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2200 "./IW7/compiler_parser.cpp"
    break;

  case 75: // stmt_return: RETURN SEMICOLON
#line 395 "IW7.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(yylhs.location, std::make_unique<gsc::node>()); }
#line 2206 "./IW7/compiler_parser.cpp"
    break;

  case 76: // for_stmt: expr_assign
#line 399 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2212 "./IW7/compiler_parser.cpp"
    break;

  case 77: // for_stmt: %empty
#line 400 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2218 "./IW7/compiler_parser.cpp"
    break;

  case 78: // for_expr: expr
#line 404 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2224 "./IW7/compiler_parser.cpp"
    break;

  case 79: // for_expr: %empty
#line 405 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2230 "./IW7/compiler_parser.cpp"
    break;

  case 80: // expr: expr_compare
#line 409 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2236 "./IW7/compiler_parser.cpp"
    break;

  case 81: // expr: expr_binary
#line 410 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2242 "./IW7/compiler_parser.cpp"
    break;

  case 82: // expr: expr_primitive
#line 411 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2248 "./IW7/compiler_parser.cpp"
    break;

  case 83: // expr_assign: INCREMENT object
#line 415 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(yylhs.location, std::move(yystack_[0].value.as < gsc::node_ptr > ())); }
#line 2254 "./IW7/compiler_parser.cpp"
    break;

  case 84: // expr_assign: DECREMENT object
#line 416 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(yylhs.location, std::move(yystack_[0].value.as < gsc::node_ptr > ())); }
#line 2260 "./IW7/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object INCREMENT
#line 417 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(yylhs.location, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2266 "./IW7/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object DECREMENT
#line 418 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(yylhs.location, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2272 "./IW7/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN expr
#line 419 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2278 "./IW7/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 420 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2284 "./IW7/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 421 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2290 "./IW7/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 422 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2296 "./IW7/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_LSHIFT expr
#line 423 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2302 "./IW7/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_RSHIFT expr
#line 424 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2308 "./IW7/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_ADD expr
#line 425 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2314 "./IW7/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_SUB expr
#line 426 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2320 "./IW7/compiler_parser.cpp"
    break;

  case 95: // expr_assign: object ASSIGN_MULT expr
#line 427 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2326 "./IW7/compiler_parser.cpp"
    break;

  case 96: // expr_assign: object ASSIGN_DIV expr
#line 428 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2332 "./IW7/compiler_parser.cpp"
    break;

  case 97: // expr_assign: object ASSIGN_MOD expr
#line 429 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2338 "./IW7/compiler_parser.cpp"
    break;

  case 98: // expr_compare: expr OR expr
#line 433 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2344 "./IW7/compiler_parser.cpp"
    break;

  case 99: // expr_compare: expr AND expr
#line 434 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2350 "./IW7/compiler_parser.cpp"
    break;

  case 100: // expr_compare: expr EQUALITY expr
#line 435 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2356 "./IW7/compiler_parser.cpp"
    break;

  case 101: // expr_compare: expr INEQUALITY expr
#line 436 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2362 "./IW7/compiler_parser.cpp"
    break;

  case 102: // expr_compare: expr LESS_EQUAL expr
#line 437 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2368 "./IW7/compiler_parser.cpp"
    break;

  case 103: // expr_compare: expr GREATER_EQUAL expr
#line 438 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2374 "./IW7/compiler_parser.cpp"
    break;

  case 104: // expr_compare: expr LESS expr
#line 439 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2380 "./IW7/compiler_parser.cpp"
    break;

  case 105: // expr_compare: expr GREATER expr
#line 440 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2386 "./IW7/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr BITWISE_OR expr
#line 444 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2392 "./IW7/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr BITWISE_AND expr
#line 445 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2398 "./IW7/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr BITWISE_EXOR expr
#line 446 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2404 "./IW7/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr LSHIFT expr
#line 447 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2410 "./IW7/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr RSHIFT expr
#line 448 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2416 "./IW7/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr ADD expr
#line 449 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2422 "./IW7/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr SUB expr
#line 450 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2428 "./IW7/compiler_parser.cpp"
    break;

  case 113: // expr_binary: expr MULT expr
#line 451 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2434 "./IW7/compiler_parser.cpp"
    break;

  case 114: // expr_binary: expr DIV expr
#line 452 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2440 "./IW7/compiler_parser.cpp"
    break;

  case 115: // expr_binary: expr MOD expr
#line 453 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2446 "./IW7/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: LPAREN expr RPAREN
#line 457 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2452 "./IW7/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: COMPLEMENT expr
#line 458 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(yylhs.location, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2458 "./IW7/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: NOT expr
#line 459 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(yylhs.location, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2464 "./IW7/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_call
#line 460 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2470 "./IW7/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_call_thread
#line 461 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2476 "./IW7/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_call_childthread
#line 462 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2482 "./IW7/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_function
#line 463 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2488 "./IW7/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_add_array
#line 464 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2494 "./IW7/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_array
#line 465 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2500 "./IW7/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: expr_field
#line 466 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2506 "./IW7/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: expr_size
#line 467 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2512 "./IW7/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: thisthread
#line 468 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::thisthread_ptr > ()); }
#line 2518 "./IW7/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: empty_array
#line 469 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::empty_array_ptr > ()); }
#line 2524 "./IW7/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: undefined
#line 470 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::undefined_ptr > ()); }
#line 2530 "./IW7/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: game
#line 471 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2536 "./IW7/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: self
#line 472 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2542 "./IW7/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: anim
#line 473 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2548 "./IW7/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: level
#line 474 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2554 "./IW7/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: animation
#line 475 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animation_ptr > ()); }
#line 2560 "./IW7/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: animtree
#line 476 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2566 "./IW7/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: name
#line 477 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2572 "./IW7/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: istring
#line 478 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::istring_ptr > ()); }
#line 2578 "./IW7/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: string
#line 479 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2584 "./IW7/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: vector
#line 480 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::vector_ptr > ()); }
#line 2590 "./IW7/compiler_parser.cpp"
    break;

  case 140: // expr_primitive: number
#line 481 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::number_ptr > ().as_node); }
#line 2596 "./IW7/compiler_parser.cpp"
    break;

  case 141: // expr_primitive: false
#line 482 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2602 "./IW7/compiler_parser.cpp"
    break;

  case 142: // expr_primitive: true
#line 483 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2608 "./IW7/compiler_parser.cpp"
    break;

  case 143: // expr_call: expr_call_function
#line 487 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2614 "./IW7/compiler_parser.cpp"
    break;

  case 144: // expr_call: expr_call_pointer
#line 488 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2620 "./IW7/compiler_parser.cpp"
    break;

  case 145: // expr_call: object expr_call_function
#line 489 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2626 "./IW7/compiler_parser.cpp"
    break;

  case 146: // expr_call: object expr_call_pointer
#line 490 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2632 "./IW7/compiler_parser.cpp"
    break;

  case 147: // expr_call_thread: THREAD expr_call_function
#line 494 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2638 "./IW7/compiler_parser.cpp"
    break;

  case 148: // expr_call_thread: THREAD expr_call_pointer
#line 495 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2644 "./IW7/compiler_parser.cpp"
    break;

  case 149: // expr_call_thread: object THREAD expr_call_function
#line 496 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2650 "./IW7/compiler_parser.cpp"
    break;

  case 150: // expr_call_thread: object THREAD expr_call_pointer
#line 497 "IW7.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2656 "./IW7/compiler_parser.cpp"
    break;

  case 151: // expr_call_childthread: CHILDTHREAD expr_call_function
#line 501 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2662 "./IW7/compiler_parser.cpp"
    break;

  case 152: // expr_call_childthread: CHILDTHREAD expr_call_pointer
#line 502 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2668 "./IW7/compiler_parser.cpp"
    break;

  case 153: // expr_call_childthread: object CHILDTHREAD expr_call_function
#line 503 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2674 "./IW7/compiler_parser.cpp"
    break;

  case 154: // expr_call_childthread: object CHILDTHREAD expr_call_pointer
#line 504 "IW7.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2680 "./IW7/compiler_parser.cpp"
    break;

  case 155: // expr_call_function: name LPAREN expr_arguments RPAREN
#line 509 "IW7.parser.ypp"
        {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(yylhs.location, std::make_unique<gsc::node_file>(), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2686 "./IW7/compiler_parser.cpp"
    break;

  case 156: // expr_call_function: file DOUBLECOLON name LPAREN expr_arguments RPAREN
#line 511 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(yylhs.location, std::move(yystack_[5].value.as < gsc::file_ptr > ()), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2692 "./IW7/compiler_parser.cpp"
    break;

  case 157: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 516 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(yylhs.location, false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2698 "./IW7/compiler_parser.cpp"
    break;

  case 158: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 518 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(yylhs.location, true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2704 "./IW7/compiler_parser.cpp"
    break;

  case 159: // expr_arguments: expr_arguments COMMA expr
#line 523 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2710 "./IW7/compiler_parser.cpp"
    break;

  case 160: // expr_arguments: expr
#line 525 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(yylhs.location); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2716 "./IW7/compiler_parser.cpp"
    break;

  case 161: // expr_arguments: %empty
#line 527 "IW7.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(yylhs.location); }
#line 2722 "./IW7/compiler_parser.cpp"
    break;

  case 162: // expr_function: DOUBLECOLON name
#line 532 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(yylhs.location, std::make_unique<gsc::node_file>(yylhs.location), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2728 "./IW7/compiler_parser.cpp"
    break;

  case 163: // expr_function: file DOUBLECOLON name
#line 534 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(yylhs.location, std::move(yystack_[2].value.as < gsc::file_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2734 "./IW7/compiler_parser.cpp"
    break;

  case 164: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 539 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2740 "./IW7/compiler_parser.cpp"
    break;

  case 165: // expr_array: object LBRACKET expr RBRACKET
#line 544 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(yylhs.location, std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2746 "./IW7/compiler_parser.cpp"
    break;

  case 166: // expr_field: object DOT name
#line 549 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2752 "./IW7/compiler_parser.cpp"
    break;

  case 167: // expr_size: object DOT SIZE
#line 554 "IW7.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2758 "./IW7/compiler_parser.cpp"
    break;

  case 168: // object: expr_call
#line 558 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2764 "./IW7/compiler_parser.cpp"
    break;

  case 169: // object: expr_array
#line 559 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2770 "./IW7/compiler_parser.cpp"
    break;

  case 170: // object: expr_field
#line 560 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2776 "./IW7/compiler_parser.cpp"
    break;

  case 171: // object: game
#line 561 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2782 "./IW7/compiler_parser.cpp"
    break;

  case 172: // object: self
#line 562 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2788 "./IW7/compiler_parser.cpp"
    break;

  case 173: // object: anim
#line 563 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2794 "./IW7/compiler_parser.cpp"
    break;

  case 174: // object: level
#line 564 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2800 "./IW7/compiler_parser.cpp"
    break;

  case 175: // object: name
#line 565 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2806 "./IW7/compiler_parser.cpp"
    break;

  case 176: // thisthread: THISTHREAD
#line 568 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::thisthread_ptr > () = std::make_unique<gsc::node_thisthread>(yylhs.location); }
#line 2812 "./IW7/compiler_parser.cpp"
    break;

  case 177: // empty_array: EMPTY_ARRAY
#line 569 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::empty_array_ptr > () = std::make_unique<gsc::node_empty_array>(yylhs.location); }
#line 2818 "./IW7/compiler_parser.cpp"
    break;

  case 178: // undefined: UNDEFINED
#line 570 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::undefined_ptr > () = std::make_unique<gsc::node_undefined>(yylhs.location); }
#line 2824 "./IW7/compiler_parser.cpp"
    break;

  case 179: // game: GAME
#line 571 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::game_ptr > () = std::make_unique<gsc::node_game>(yylhs.location); }
#line 2830 "./IW7/compiler_parser.cpp"
    break;

  case 180: // self: SELF
#line 572 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::self_ptr > () = std::make_unique<gsc::node_self>(yylhs.location); }
#line 2836 "./IW7/compiler_parser.cpp"
    break;

  case 181: // anim: ANIM
#line 573 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::anim_ptr > () = std::make_unique<gsc::node_anim>(yylhs.location); }
#line 2842 "./IW7/compiler_parser.cpp"
    break;

  case 182: // level: LEVEL
#line 574 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::level_ptr > () = std::make_unique<gsc::node_level>(yylhs.location); }
#line 2848 "./IW7/compiler_parser.cpp"
    break;

  case 183: // animation: MOD NAME
#line 575 "IW7.parser.ypp"
                                     { yylhs.value.as < gsc::animation_ptr > () = std::make_unique<gsc::node_animation>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2854 "./IW7/compiler_parser.cpp"
    break;

  case 184: // animtree: ANIMTREE
#line 576 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(yylhs.location); }
#line 2860 "./IW7/compiler_parser.cpp"
    break;

  case 185: // name: NAME
#line 577 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::name_ptr > () = std::make_unique<gsc::node_name>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2866 "./IW7/compiler_parser.cpp"
    break;

  case 186: // file: FILE
#line 578 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::file_ptr > () = std::make_unique<gsc::node_file>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2872 "./IW7/compiler_parser.cpp"
    break;

  case 187: // istring: ISTRING
#line 579 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::istring_ptr > () = std::make_unique<gsc::node_istring>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2878 "./IW7/compiler_parser.cpp"
    break;

  case 188: // string: STRING
#line 580 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2884 "./IW7/compiler_parser.cpp"
    break;

  case 189: // vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 584 "IW7.parser.ypp"
        { yylhs.value.as < gsc::vector_ptr > () = std::make_unique<gsc::node_vector>(yylhs.location, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2890 "./IW7/compiler_parser.cpp"
    break;

  case 190: // number: neg_float
#line 588 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2896 "./IW7/compiler_parser.cpp"
    break;

  case 191: // number: neg_integer
#line 589 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2902 "./IW7/compiler_parser.cpp"
    break;

  case 192: // number: float
#line 590 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_float   = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2908 "./IW7/compiler_parser.cpp"
    break;

  case 193: // number: integer
#line 591 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::number_ptr > ().as_integer  = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2914 "./IW7/compiler_parser.cpp"
    break;

  case 194: // neg_float: SUB FLOAT
#line 594 "IW7.parser.ypp"
                                     { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 2920 "./IW7/compiler_parser.cpp"
    break;

  case 195: // neg_integer: SUB INTEGER
#line 595 "IW7.parser.ypp"
                                     { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 2926 "./IW7/compiler_parser.cpp"
    break;

  case 196: // float: FLOAT
#line 596 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2932 "./IW7/compiler_parser.cpp"
    break;

  case 197: // integer: INTEGER
#line 597 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2938 "./IW7/compiler_parser.cpp"
    break;

  case 198: // false: FALSE
#line 598 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(yylhs.location); }
#line 2944 "./IW7/compiler_parser.cpp"
    break;

  case 199: // true: TRUE
#line 599 "IW7.parser.ypp"
                          { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(yylhs.location); }
#line 2950 "./IW7/compiler_parser.cpp"
    break;


#line 2954 "./IW7/compiler_parser.cpp"

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
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
    error (yyexc.location, yyexc.what ());
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
  "ISTRING", "FLOAT", "INTEGER", "NEG", "ANIMREF", "PREINC", "PREDEC",
  "POSTINC", "POSTDEC", "$accept", "root", "program", "include", "define",
  "usingtree", "constant", "thread", "parameters", "block", "stmt",
  "stmt_call", "stmt_assign", "stmt_endon", "stmt_notify", "stmt_wait",
  "stmt_waittill", "stmt_waittillmatch", "stmt_waittillframeend",
  "stmt_if", "stmt_ifelse", "stmt_while", "stmt_for", "stmt_foreach",
  "stmt_switch", "stmt_case", "stmt_default", "stmt_break",
  "stmt_continue", "stmt_return", "for_stmt", "for_expr", "expr",
  "expr_assign", "expr_compare", "expr_binary", "expr_primitive",
  "expr_call", "expr_call_thread", "expr_call_childthread",
  "expr_call_function", "expr_call_pointer", "expr_arguments",
  "expr_function", "expr_add_array", "expr_array", "expr_field",
  "expr_size", "object", "thisthread", "empty_array", "undefined", "game",
  "self", "anim", "level", "animation", "animtree", "name", "file",
  "istring", "string", "vector", "number", "neg_float", "neg_integer",
  "float", "integer", "false", "true", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -261;

  const short parser::yytable_ninf_ = -176;

  const short
  parser::yypact_[] =
  {
       7,   -49,     1,  -261,    42,     7,  -261,  -261,  -261,  -261,
    -261,   -16,  -261,    -2,    11,  -261,  -261,  -261,   -22,  1244,
    -261,  -261,    58,   -15,  -261,  -261,    57,    57,  -261,    54,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  1244,  1307,
     -22,    22,  1244,  1244,   -51,  -261,  -261,  -261,  2477,  -261,
    -261,  -261,    39,  -261,  -261,  -261,  -261,  -261,  -261,   274,
     307,  -261,   372,  -261,  -261,  -261,   399,   485,   524,   545,
    -261,  -261,   110,    60,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,    59,    68,   -22,    72,  -261,  -261,
      79,    83,  -261,  -261,    88,  2011,  1307,  2522,     9,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,    57,    57,  1307,    10,  -261,  -261,
    1244,   -22,  -261,  1971,  -261,  1244,   -22,  1244,  -261,  1244,
    2343,  -261,  1244,  -261,    31,    31,  1241,  1303,   742,   742,
     156,   156,   156,   156,  2023,  2065,  2108,   -36,   -36,  -261,
    -261,  -261,  -261,  -261,  -261,  2374,  -261,  -261,   -14,    93,
     -29,    85,   108,   109,   115,   116,   124,   -61,    96,   112,
     119,  1181,   123,   123,   248,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,   120,   121,   128,  -261,  -261,
       6,  -261,  -261,  -261,  -261,    79,  2343,    93,  2405,  2443,
     129,  2522,  -261,  -261,  1244,  1244,   130,  -261,  1244,  1244,
     601,   -22,  1244,    77,   133,   134,   140,  -261,  -261,  -261,
    -261,  2511,  -261,    41,    41,  -261,  -261,  -261,  -261,  -261,
     125,   153,   158,   159,   -22,  -261,  -261,  1244,  1244,  1244,
    1244,  1244,  1244,  1244,  1244,  1244,  1244,  1244,   151,  1244,
     161,    -7,  2151,  -261,  2183,  2194,   165,  -261,  1974,     3,
    2226,  -261,  -261,  -261,  -261,  1244,  1244,  1244,  1244,  2522,
    2522,  2522,  2522,  2522,  2522,  2522,  2522,  2522,  2522,  2522,
     177,  2237,  1244,  -261,   175,  1386,  1425,  1244,  1244,   -22,
     131,  2269,  2054,  2097,  2140,  1244,  -261,    15,  -261,  1971,
     210,  1971,  -261,   179,  2522,  2280,   207,  1971,   180,   181,
    1244,   182,  1244,   185,  1244,    76,  -261,  1464,  1503,  1542,
     601,  1581,  1244,  1620,  -261,  -261,   105,  -261,   106,  -261,
     122,  -261,   212,  1971,  -261,  -261,   199,  1971,  -261,  2312,
    -261,   191,   192,   193,  1659,  1698,  1737,  1776,  1815,  -261,
    -261,  -261,  1971,  -261,  -261,  1971,  -261,  -261,  1971,  -261,
    1854,  1893,  1932,  -261,  -261,  -261
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   185,     0,     2,     6,     7,     9,    10,
      11,     0,   186,     0,     0,     1,     4,     5,    17,     0,
       8,   188,     0,     0,    16,   184,     0,     0,   176,     0,
     199,   198,   178,   179,   180,   181,   182,   177,     0,   161,
       0,     0,     0,     0,     0,   187,   196,   197,     0,    80,
      81,    82,   119,   120,   121,   143,   144,   122,   123,   124,
     125,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     0,   137,   138,   139,   140,   190,   191,
     192,   193,   141,   142,     0,     0,     0,     0,   147,   148,
       0,     0,   151,   152,     0,     0,   161,   160,     0,   162,
     183,   118,   117,   194,   195,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     161,     0,    12,    20,    15,     0,     0,     0,   116,     0,
     160,   164,     0,   115,   109,   110,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   111,   112,   113,
     114,   149,   150,   153,   154,     0,   167,   166,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,   168,     0,   169,   170,
       0,   171,   172,   173,   174,   175,     0,     0,     0,     0,
       0,   159,   165,   155,   161,     0,     0,    52,     0,     0,
      77,     0,     0,     0,     0,     0,     0,    71,    72,    73,
      75,     0,   168,    83,    84,    14,    18,    42,    40,    41,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,    76,     0,     0,
       0,    70,    69,    68,    74,     0,     0,     0,     0,    92,
      87,    93,    94,    95,    96,    97,    88,    89,    90,    91,
       0,     0,   161,   156,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,   161,   189,     0,    46,    20,
      54,    20,    60,     0,    78,     0,     0,    20,     0,     0,
     161,     0,   161,     0,   161,     0,   157,     0,     0,     0,
      77,     0,     0,     0,    43,    45,     0,    49,     0,    51,
       0,   158,    53,    20,    58,    59,     0,    20,    65,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      48,    50,    20,    57,    56,    20,    62,    63,    20,    66,
       0,     0,     0,    55,    61,    64
  };

  const short
  parser::yypgoto_[] =
  {
    -261,  -261,  -261,   236,   237,  -261,  -261,  -261,  -261,  -260,
    -165,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
     -95,  -261,   352,  -223,  -261,  -261,  -261,   178,   817,  -261,
     -25,   -23,  -121,  -261,  -261,   324,   392,  -261,   470,  -261,
    -261,  -261,   538,   603,   671,   749,  -261,  -261,     0,    64,
    -261,    -8,  -261,    80,  -261,    74,  -261,    75,  -261,  -261
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    23,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     276,   323,    97,   205,    49,    50,    51,    52,    53,    54,
      55,    56,    98,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83
  };

  const short
  parser::yytable_[] =
  {
      11,    88,    92,    89,    93,    11,    22,   277,   225,   168,
       1,     2,   250,   251,   106,   252,   253,   233,    24,   246,
     308,    18,    21,    85,   223,    47,    90,    90,    86,   142,
     124,   303,    12,    29,   103,   104,   142,   128,    14,   129,
      99,   166,    15,   122,   123,    20,   309,   126,    19,    44,
     254,   141,   142,   336,   255,   256,    46,    47,   142,   337,
       3,   339,    90,  -168,  -168,    13,  -168,   343,    29,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
    -168,   106,   126,  -168,    29,   254,   134,    12,     3,     3,
      91,    91,     3,   365,    21,    94,    84,   367,    87,   161,
     163,   162,   164,   271,   100,   131,   132,   133,   120,   121,
     122,   123,   380,   135,   351,   381,   130,   277,   382,   142,
    -168,  -168,    12,     3,    90,    90,    91,   167,   136,   137,
     224,   169,   227,   215,  -175,  -175,   217,  -175,    12,     3,
     320,   322,   237,   361,   362,   228,   229,   130,   142,   142,
      29,  -175,   230,   231,  -175,    33,    34,    35,    36,   238,
     363,   232,   285,   104,    87,   142,   239,   247,   248,   234,
     327,   270,   246,   354,   246,   249,   358,   273,   246,   281,
     282,   317,   215,   215,   215,   128,   283,   129,    91,    91,
     286,  -175,  -175,   300,   335,   287,   288,    91,   302,   373,
     246,   376,   246,   379,    12,     3,   106,   107,   108,   346,
      90,   348,   307,   350,   315,   246,   246,   246,   128,   128,
     129,   129,   318,   338,   342,   364,   340,   344,   345,   347,
     215,   279,   349,   120,   121,   122,   123,   366,   369,   370,
     371,    16,    17,    90,    90,   356,    91,    91,    91,     0,
     226,   235,   236,   128,   167,   129,   170,     0,     0,   171,
     172,     0,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,    26,     0,    91,    29,     0,     0,    90,     0,
      33,    34,    35,    36,     0,     0,     0,     0,   245,    87,
       0,     0,     0,     0,    91,     0,   182,   183,  -169,  -169,
       0,  -169,     0,     0,     0,   215,   215,    91,    91,   326,
       0,   206,     0,     0,     0,  -169,     0,     0,  -169,   215,
       0,   215,     0,     0,     0,     0,     0,   215,     0,    12,
       3,  -170,  -170,     0,  -170,     0,     0,   215,   215,   215,
     215,   215,    91,   215,     0,     0,     0,     0,  -170,     0,
       0,  -170,     0,   215,     0,  -169,  -169,   215,     0,     0,
     242,   242,   206,     0,   215,   215,   215,   215,   215,    91,
      91,    48,   215,     0,     0,   215,     0,     0,   215,     0,
     215,   215,   215,    91,     0,    91,     0,     0,  -170,  -170,
      95,    91,     0,     0,   101,   102,   124,   125,     0,    29,
       0,    91,    91,    91,    91,    91,     0,    91,   242,     0,
       0,     0,     0,   126,     0,     0,   127,    91,     0,     0,
       0,    91,     0,  -171,  -171,     0,  -171,     0,    91,    91,
      91,    91,    91,     0,     0,     0,    91,     0,     0,    91,
    -171,     0,    91,  -171,    91,    91,    91,     0,   140,     0,
       0,     0,     0,    12,     3,     0,     0,   208,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   165,     0,
    -171,  -171,     0,   206,   206,     0,     0,   216,     0,   218,
       0,   219,     0,     0,   221,     0,     0,   206,     0,   206,
       0,     0,     0,     0,     0,   206,   208,   208,   208,  -172,
    -172,     0,  -172,     0,     0,   206,   206,   206,   242,   206,
       0,   206,     0,     0,     0,   209,  -172,     0,     0,  -172,
       0,   206,     0,   241,     0,   206,     0,     0,     0,     0,
       0,     0,   206,   206,   206,   206,   206,     0,  -173,  -173,
     206,  -173,     0,   206,   208,     0,   206,     0,   206,   206,
     206,     0,     0,     0,     0,  -173,  -172,  -172,  -173,  -174,
    -174,     0,  -174,     0,   209,   209,   209,   272,     0,     0,
     274,   275,     0,     0,   280,     0,  -174,     0,     0,  -174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,  -173,  -173,     0,     0,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
       0,   301,   209,     0,     0,     0,  -174,  -174,    29,   208,
     208,     0,     0,    33,    34,    35,    36,   311,   312,   313,
     314,     0,    87,   208,     0,   208,     0,     0,     0,   182,
     183,   208,   243,   244,   210,     0,     0,     0,     0,   324,
     325,   208,   208,   208,   208,   208,     0,   208,     0,     0,
       0,   211,     0,     0,     0,     0,     0,   208,     0,     0,
       0,   208,    12,     3,     0,     0,     0,     0,   208,   208,
     208,   208,   208,     0,   359,     0,   208,   209,   209,   208,
     278,     0,   208,     0,   208,   208,   208,     0,     0,     0,
       0,   209,     0,   209,     0,     0,     0,     0,     0,   209,
     211,   211,   211,     0,     0,     0,     0,     0,     0,   209,
     209,   209,   209,   209,     0,   209,   212,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,   209,   209,   209,   209,
     209,     0,     0,     0,   209,     0,     0,   209,   211,     0,
     209,     0,   209,   209,   209,   210,   210,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   212,   212,     0,   210,
       0,   210,   106,   107,   108,     0,     0,   210,     0,   113,
     114,   115,   116,     0,   213,     0,     0,   210,   210,   210,
     278,   210,     0,   210,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   210,     0,     0,     0,   210,     0,     0,
       0,     0,     0,   212,   210,   210,   210,   210,   210,     0,
       0,     0,   210,   211,   211,   210,     0,     0,   210,     0,
     210,   210,   210,   213,   213,   213,     0,   211,     0,   211,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,   211,   211,   211,   211,
       0,   211,   214,     0,     0,     0,     0,     0,     0,     0,
       0,   211,     0,     0,     0,   211,     0,     0,     0,     0,
       0,   213,   211,   211,   211,   211,   211,     0,   212,   212,
     211,     0,     0,   211,     0,     0,   211,     0,   211,   211,
     211,     0,   212,     0,   212,     0,     0,     0,     0,     0,
     212,   214,   214,   214,     0,     0,     0,     0,     0,     0,
     212,   212,   212,   212,   212,     0,   212,     0,     0,     0,
     207,     0,     0,     0,     0,     0,   212,     0,     0,     0,
     212,     0,     0,     0,     0,     0,     0,   212,   212,   212,
     212,   212,     0,     0,     0,   212,   213,   213,   212,   214,
       0,   212,     0,   212,   212,   212,     0,     0,     0,     0,
     213,     0,   213,     0,     0,     0,     0,     0,   213,     0,
       0,   207,     0,     0,     0,     0,     0,     0,   213,   213,
     213,   213,   213,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,   213,   213,   213,   213,   213,
       0,     0,     0,   213,     0,     0,   213,     0,     0,   213,
       0,   213,   213,   213,   214,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
     214,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   214,   214,   214,
     214,     0,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,   214,   214,   214,   214,   214,     0,     0,
       0,   214,   207,   207,   214,     0,     0,   214,     0,   214,
     214,   214,     0,     0,     0,     0,   207,     0,   207,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   207,   207,   207,     0,   207,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,   207,   207,   207,   207,   207,    25,     0,     0,   207,
       0,     0,   207,     0,     0,   207,     0,   207,   207,   207,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
       0,     0,    39,     0,     0,     0,    40,     0,   240,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    12,     3,    21,    45,    46,    47,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,    39,     0,     0,     0,    40,
       0,   106,   107,   108,    41,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,    42,    43,     0,     0,     0,
       0,     0,    25,     0,     0,   117,   118,   119,   120,   121,
     122,   123,    44,     0,     0,    12,     3,    21,    45,    46,
      47,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,    96,     0,
       0,     0,    40,   106,   107,   108,     0,    41,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,    42,    43,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,    44,     0,     0,    12,     3,
      21,    45,    46,    47,   170,     0,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
      26,     0,     0,    29,     0,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,   319,     0,    87,     0,     0,
       0,     0,     0,   170,   182,   183,   171,   172,     0,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,   321,     0,    87,    12,     3,     0,
       0,     0,   170,   182,   183,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,     0,   352,    87,    12,     3,     0,     0,
       0,   170,   182,   183,   171,   172,     0,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,   353,     0,    87,    12,     3,     0,     0,     0,
     170,   182,   183,   171,   172,     0,   173,   174,   175,     0,
     176,   177,   178,   179,   180,   181,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,     0,   355,    87,    12,     3,     0,     0,     0,   170,
     182,   183,   171,   172,     0,   173,   174,   175,     0,   176,
     177,   178,   179,   180,   181,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
     357,     0,    87,    12,     3,     0,     0,     0,   170,   182,
     183,   171,   172,     0,   173,   174,   175,     0,   176,   177,
     178,   179,   180,   181,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
     360,    87,    12,     3,     0,     0,     0,   170,   182,   183,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,    26,     0,     0,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,     0,   372,     0,
      87,    12,     3,     0,     0,     0,   170,   182,   183,   171,
     172,     0,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,     0,   374,    87,
      12,     3,     0,     0,     0,   170,   182,   183,   171,   172,
       0,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,   375,     0,    87,    12,
       3,     0,     0,     0,   170,   182,   183,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
      26,     0,     0,    29,     0,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,     0,   377,    87,    12,     3,
       0,     0,     0,   170,   182,   183,   171,   172,     0,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,   378,     0,    87,    12,     3,     0,
       0,     0,   170,   182,   183,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,     0,   383,    87,    12,     3,     0,     0,
       0,   170,   182,   183,   171,   172,     0,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,     0,   384,    87,    12,     3,     0,     0,     0,
     170,   182,   183,   171,   172,     0,   173,   174,   175,     0,
     176,   177,   178,   179,   180,   181,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,     0,   385,    87,    12,     3,     0,     0,     0,   170,
     182,   183,   171,   172,     0,   173,   174,   175,     0,   176,
     177,   178,   179,   180,   181,    26,     0,     0,    29,     0,
       0,    29,     0,    33,    34,    35,    36,     0,     0,     0,
       0,     0,    87,    12,     3,   126,     0,     0,   254,   182,
     183,     0,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   138,
       0,     0,    12,     3,   139,    12,     3,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   106,   107,   108,     0,     0,   111,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,   121,
     122,   123,   329,     0,     0,     0,     0,   330,   118,   119,
     120,   121,   122,   123,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   106,   107,   108,     0,     0,
     111,   112,   113,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   331,     0,     0,     0,     0,
     332,   119,   120,   121,   122,   123,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   106,   107,
     108,     0,     0,   111,   112,   113,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   333,     0,
       0,     0,     0,   334,     0,   120,   121,   122,   123,   304,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   305,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   306,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   310,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   316,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   328,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   341,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     368,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   117,   118,   119,   120,
     121,   122,   123,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   117,   118,   119,
     120,   121,   122,   123,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   117,   118,
     119,   120,   121,   122,   123,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   269,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   284,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123
  };

  const short
  parser::yycheck_[] =
  {
       0,    26,    27,    26,    27,     5,    14,   230,    37,   130,
       3,     4,     6,     7,    50,     9,    10,    78,    18,   184,
      17,    37,    83,    38,    38,    86,    26,    27,    43,    43,
      24,    38,    81,    27,    85,    86,    43,    62,    37,    62,
      40,    31,     0,    79,    80,    47,    43,    41,    64,    78,
      44,    42,    43,    38,    48,    49,    85,    86,    43,   319,
      82,   321,    62,    24,    25,     1,    27,   327,    27,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      41,    50,    41,    44,    27,    44,    86,    81,    82,    82,
      26,    27,    82,   353,    83,    41,    38,   357,    41,   124,
     125,   124,   125,   224,    82,    45,    47,    39,    77,    78,
      79,    80,   372,    41,    38,   375,    37,   340,   378,    43,
      81,    82,    81,    82,   124,   125,    62,   127,    45,    41,
      37,   131,    47,   133,    24,    25,   136,    27,    81,    82,
     305,   306,    46,    38,    38,    37,    37,    37,    43,    43,
      27,    41,    37,    37,    44,    32,    33,    34,    35,    47,
      38,    37,    37,    86,    41,    43,    47,    47,    47,   177,
      39,    42,   337,   338,   339,    47,   341,    47,   343,    46,
      46,   302,   182,   183,   184,   210,    46,   210,   124,   125,
      37,    81,    82,    42,   315,    37,    37,   133,    37,   364,
     365,   366,   367,   368,    81,    82,    50,    51,    52,   330,
     210,   332,    47,   334,    37,   380,   381,   382,   243,   244,
     243,   244,    47,    13,    17,    13,    47,    47,    47,    47,
     230,   231,    47,    77,    78,    79,    80,    38,    47,    47,
      47,     5,     5,   243,   244,   340,   182,   183,   184,    -1,
     170,   177,   177,   278,   254,   278,     8,    -1,    -1,    11,
      12,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,   210,    27,    -1,    -1,   278,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,   230,    -1,    48,    49,    24,    25,
      -1,    27,    -1,    -1,    -1,   305,   306,   243,   244,   309,
      -1,   133,    -1,    -1,    -1,    41,    -1,    -1,    44,   319,
      -1,   321,    -1,    -1,    -1,    -1,    -1,   327,    -1,    81,
      82,    24,    25,    -1,    27,    -1,    -1,   337,   338,   339,
     340,   341,   278,   343,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,   353,    -1,    81,    82,   357,    -1,    -1,
     182,   183,   184,    -1,   364,   365,   366,   367,   368,   305,
     306,    19,   372,    -1,    -1,   375,    -1,    -1,   378,    -1,
     380,   381,   382,   319,    -1,   321,    -1,    -1,    81,    82,
      38,   327,    -1,    -1,    42,    43,    24,    25,    -1,    27,
      -1,   337,   338,   339,   340,   341,    -1,   343,   230,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    44,   353,    -1,    -1,
      -1,   357,    -1,    24,    25,    -1,    27,    -1,   364,   365,
     366,   367,   368,    -1,    -1,    -1,   372,    -1,    -1,   375,
      41,    -1,   378,    44,   380,   381,   382,    -1,    96,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,   133,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,   126,    -1,
      81,    82,    -1,   305,   306,    -1,    -1,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,   319,    -1,   321,
      -1,    -1,    -1,    -1,    -1,   327,   182,   183,   184,    24,
      25,    -1,    27,    -1,    -1,   337,   338,   339,   340,   341,
      -1,   343,    -1,    -1,    -1,   133,    41,    -1,    -1,    44,
      -1,   353,    -1,   181,    -1,   357,    -1,    -1,    -1,    -1,
      -1,    -1,   364,   365,   366,   367,   368,    -1,    24,    25,
     372,    27,    -1,   375,   230,    -1,   378,    -1,   380,   381,
     382,    -1,    -1,    -1,    -1,    41,    81,    82,    44,    24,
      25,    -1,    27,    -1,   182,   183,   184,   225,    -1,    -1,
     228,   229,    -1,    -1,   232,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    81,    82,    -1,    -1,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
      -1,   269,   230,    -1,    -1,    -1,    81,    82,    27,   305,
     306,    -1,    -1,    32,    33,    34,    35,   285,   286,   287,
     288,    -1,    41,   319,    -1,   321,    -1,    -1,    -1,    48,
      49,   327,   182,   183,   184,    -1,    -1,    -1,    -1,   307,
     308,   337,   338,   339,   340,   341,    -1,   343,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
      -1,   357,    81,    82,    -1,    -1,    -1,    -1,   364,   365,
     366,   367,   368,    -1,   342,    -1,   372,   305,   306,   375,
     230,    -1,   378,    -1,   380,   381,   382,    -1,    -1,    -1,
      -1,   319,    -1,   321,    -1,    -1,    -1,    -1,    -1,   327,
     182,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,   337,
     338,   339,   340,   341,    -1,   343,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,   357,
      -1,    -1,    -1,    -1,    -1,    -1,   364,   365,   366,   367,
     368,    -1,    -1,    -1,   372,    -1,    -1,   375,   230,    -1,
     378,    -1,   380,   381,   382,   305,   306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,   319,
      -1,   321,    50,    51,    52,    -1,    -1,   327,    -1,    57,
      58,    59,    60,    -1,   133,    -1,    -1,   337,   338,   339,
     340,   341,    -1,   343,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,   353,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    -1,    -1,   230,   364,   365,   366,   367,   368,    -1,
      -1,    -1,   372,   305,   306,   375,    -1,    -1,   378,    -1,
     380,   381,   382,   182,   183,   184,    -1,   319,    -1,   321,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,   339,   340,   341,
      -1,   343,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,
      -1,   230,   364,   365,   366,   367,   368,    -1,   305,   306,
     372,    -1,    -1,   375,    -1,    -1,   378,    -1,   380,   381,
     382,    -1,   319,    -1,   321,    -1,    -1,    -1,    -1,    -1,
     327,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
     337,   338,   339,   340,   341,    -1,   343,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
     357,    -1,    -1,    -1,    -1,    -1,    -1,   364,   365,   366,
     367,   368,    -1,    -1,    -1,   372,   305,   306,   375,   230,
      -1,   378,    -1,   380,   381,   382,    -1,    -1,    -1,    -1,
     319,    -1,   321,    -1,    -1,    -1,    -1,    -1,   327,    -1,
      -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,   337,   338,
     339,   340,   341,    -1,   343,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,   357,    -1,
      -1,    -1,    -1,    -1,    -1,   364,   365,   366,   367,   368,
      -1,    -1,    -1,   372,    -1,    -1,   375,    -1,    -1,   378,
      -1,   380,   381,   382,   305,   306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,
     321,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,   338,   339,   340,
     341,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,   357,    -1,    -1,    -1,
      -1,    -1,    -1,   364,   365,   366,   367,   368,    -1,    -1,
      -1,   372,   305,   306,   375,    -1,    -1,   378,    -1,   380,
     381,   382,    -1,    -1,    -1,    -1,   319,    -1,   321,    -1,
      -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   337,   338,   339,    -1,   341,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
      -1,   364,   365,   366,   367,   368,     5,    -1,    -1,   372,
      -1,    -1,   375,    -1,    -1,   378,    -1,   380,   381,   382,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    81,    82,    83,    84,    85,    86,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,
      -1,    50,    51,    52,    50,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    50,    51,    52,    -1,    50,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    -1,    78,    -1,    -1,    81,    82,
      83,    84,    85,    86,     8,    -1,    -1,    11,    12,    -1,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,     8,    48,    49,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    81,    82,    -1,
      -1,    -1,     8,    48,    49,    11,    12,    -1,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    41,    81,    82,    -1,    -1,
      -1,     8,    48,    49,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    41,    81,    82,    -1,    -1,    -1,
       8,    48,    49,    11,    12,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    81,    82,    -1,    -1,    -1,     8,
      48,    49,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    81,    82,    -1,    -1,    -1,     8,    48,
      49,    11,    12,    -1,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    81,    82,    -1,    -1,    -1,     8,    48,    49,
      11,    12,    -1,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      41,    81,    82,    -1,    -1,    -1,     8,    48,    49,    11,
      12,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    41,
      81,    82,    -1,    -1,    -1,     8,    48,    49,    11,    12,
      -1,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,    81,
      82,    -1,    -1,    -1,     8,    48,    49,    11,    12,    -1,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    41,    81,    82,
      -1,    -1,    -1,     8,    48,    49,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    81,    82,    -1,
      -1,    -1,     8,    48,    49,    11,    12,    -1,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    41,    81,    82,    -1,    -1,
      -1,     8,    48,    49,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,    81,    82,    -1,    -1,    -1,
       8,    48,    49,    11,    12,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    81,    82,    -1,    -1,    -1,     8,
      48,    49,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    27,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,    81,    82,    41,    -1,    -1,    44,    48,
      49,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    38,
      -1,    -1,    81,    82,    43,    81,    82,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    50,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    -1,    74,    75,    76,    77,    78,
      79,    80,    38,    -1,    -1,    -1,    -1,    43,    75,    76,
      77,    78,    79,    80,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    50,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    38,    -1,    -1,    -1,    -1,
      43,    76,    77,    78,    79,    80,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    50,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    38,    -1,
      -1,    -1,    -1,    43,    -1,    77,    78,    79,    80,    38,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    38,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    38,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    38,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    38,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    38,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    38,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      38,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    74,    75,    76,    77,
      78,    79,    80,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    74,    75,    76,
      77,    78,    79,    80,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    74,    75,
      76,    77,    78,    79,    80,    50,    51,    52,    53,    54,
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
       0,     3,     4,    82,    94,    95,    96,    97,    98,    99,
     100,   151,    81,   152,    37,     0,    96,    97,    37,    64,
      47,    83,   154,   101,   151,     5,    24,    25,    26,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    37,    41,
      45,    50,    61,    62,    78,    84,    85,    86,   125,   127,
     128,   129,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    38,    38,    43,    41,   133,   134,
     151,   152,   133,   134,    41,   125,    41,   125,   135,   151,
      82,   125,   125,    85,    86,    47,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    74,    75,    76,
      77,    78,    79,    80,    24,    25,    41,    44,   133,   134,
      37,    45,    47,    39,   151,    41,    45,    41,    38,    43,
     125,    42,    43,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   133,   134,   133,   134,   125,    31,   151,   135,   151,
       8,    11,    12,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    48,    49,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   126,   130,   131,   138,   139,
     141,   145,   146,   147,   148,   151,   125,   151,   125,   125,
      42,   125,    42,    38,    37,    37,   156,    47,    37,    37,
      37,    37,    37,    78,   154,   158,   160,    46,    47,    47,
      47,   125,   130,   141,   141,    40,   103,    47,    47,    47,
       6,     7,     9,    10,    44,    48,    49,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    42,    43,
      42,   135,   125,    47,   125,   125,   123,   126,   141,   151,
     125,    46,    46,    46,    47,    37,    37,    37,    37,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
      42,   125,    37,    38,    38,    38,    38,    47,    17,    43,
      38,   125,   125,   125,   125,    37,    38,   135,    47,    39,
     103,    39,   103,   124,   125,   125,   151,    39,    38,    38,
      43,    38,    43,    38,    43,   135,    38,   102,    13,   102,
      47,    38,    17,   102,    47,    47,   135,    47,   135,    47,
     135,    38,    40,    39,   103,    40,   123,    39,   103,   125,
      40,    38,    38,    38,    13,   102,    38,   102,    38,    47,
      47,    47,    39,   103,    40,    39,   103,    40,    39,   103,
     102,   102,   102,    40,    40,    40
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    93,    94,    94,    95,    95,    95,    95,    96,    97,
      97,    97,    98,    99,   100,   101,   101,   101,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   117,   118,   118,
     118,   119,   120,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   130,   130,   130,   130,   131,   131,   131,
     131,   132,   132,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   136,   136,   137,   138,   139,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   156,   156,   156,   157,   158,   159,   160,   161,   162
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     1,
       1,     1,     5,     4,     7,     3,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     6,     8,     6,     5,     3,     8,     6,
       8,     6,     2,     7,     5,    11,     9,     9,     7,     7,
       5,    11,     9,     9,    11,     7,     9,     7,     3,     3,
       3,     2,     2,     2,     3,     2,     1,     0,     1,     0,
       1,     1,     1,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       3,     2,     2,     3,     3,     4,     6,     8,     9,     3,
       1,     0,     2,     3,     3,     4,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     7,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1
  };




#if IW7DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   155,   155,   156,   160,   162,   164,   166,   171,   176,
     177,   178,   182,   187,   192,   197,   199,   202,   206,   208,
     211,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     237,   239,   244,   249,   254,   256,   261,   263,   268,   270,
     275,   277,   282,   287,   289,   298,   300,   306,   312,   323,
     325,   333,   335,   344,   346,   348,   354,   363,   368,   370,
     372,   377,   382,   387,   392,   394,   399,   400,   404,   405,
     409,   410,   411,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   433,   434,
     435,   436,   437,   438,   439,   440,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   487,   488,   489,   490,   494,   495,   496,
     497,   501,   502,   503,   504,   508,   510,   515,   517,   522,
     524,   527,   531,   533,   538,   543,   548,   553,   558,   559,
     560,   561,   562,   563,   564,   565,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   583,
     588,   589,   590,   591,   594,   595,   596,   597,   598,   599
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


#line 13 "IW7.parser.ypp"
} // IW7
#line 4233 "./IW7/compiler_parser.cpp"

#line 601 "IW7.parser.ypp"


void IW7::parser::error(const gsc::location& loc, const std::string& msg)
{
    throw gsc::error("[compiler] " + std::to_string(loc.begin.line) + ":" + std::to_string(loc.begin.column) + ": " + msg);
}
