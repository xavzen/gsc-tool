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
#line 40 "S2.parser.ypp"

    #include "S2.hpp"
    #include "compiler_parser.hpp"
    #include "compiler_lexer.hpp"
    S2::parser::symbol_type S2lex(yyscan_t yyscanner, gsc::location& loc);

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

#line 13 "S2.parser.ypp"
namespace S2 {
#line 148 "./S2/compiler_parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, gsc::location& loc_yyarg, gsc::program_ptr& ast_yyarg)
#if S2DEBUG
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
#line 154 "S2.parser.ypp"
              { ast = std::move(yystack_[0].value.as < gsc::program_ptr > ()); }
#line 1715 "./S2/compiler_parser.cpp"
    break;

  case 3: // root: %empty
#line 155 "S2.parser.ypp"
              { ast = std::make_unique<gsc::node_program>(yylhs.location); }
#line 1721 "./S2/compiler_parser.cpp"
    break;

  case 4: // program: program include
#line 160 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1727 "./S2/compiler_parser.cpp"
    break;

  case 5: // program: program define
#line 162 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::move(yystack_[1].value.as < gsc::program_ptr > ()); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1733 "./S2/compiler_parser.cpp"
    break;

  case 6: // program: include
#line 164 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(yylhs.location); yylhs.value.as < gsc::program_ptr > ()->includes.push_back(std::move(yystack_[0].value.as < gsc::include_ptr > ())); }
#line 1739 "./S2/compiler_parser.cpp"
    break;

  case 7: // program: define
#line 166 "S2.parser.ypp"
        { yylhs.value.as < gsc::program_ptr > () = std::make_unique<gsc::node_program>(yylhs.location); yylhs.value.as < gsc::program_ptr > ()->definitions.push_back(std::move(yystack_[0].value.as < gsc::define_ptr > ())); }
#line 1745 "./S2/compiler_parser.cpp"
    break;

  case 8: // include: INCLUDE file SEMICOLON
#line 171 "S2.parser.ypp"
        { yylhs.value.as < gsc::include_ptr > () = std::make_unique<gsc::node_include>(yylhs.location, std::move(yystack_[1].value.as < gsc::file_ptr > ())); }
#line 1751 "./S2/compiler_parser.cpp"
    break;

  case 9: // define: usingtree
#line 175 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_usingtree = std::move(yystack_[0].value.as < gsc::usingtree_ptr > ()); }
#line 1757 "./S2/compiler_parser.cpp"
    break;

  case 10: // define: constant
#line 176 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_constant = std::move(yystack_[0].value.as < gsc::constant_ptr > ()); }
#line 1763 "./S2/compiler_parser.cpp"
    break;

  case 11: // define: thread
#line 177 "S2.parser.ypp"
                   { yylhs.value.as < gsc::define_ptr > ().as_thread = std::move(yystack_[0].value.as < gsc::thread_ptr > ()); }
#line 1769 "./S2/compiler_parser.cpp"
    break;

  case 12: // usingtree: USINGTREE LPAREN string RPAREN SEMICOLON
#line 182 "S2.parser.ypp"
        { yylhs.value.as < gsc::usingtree_ptr > () = std::make_unique<gsc::node_usingtree>(yylhs.location, std::move(yystack_[2].value.as < gsc::string_ptr > ())); }
#line 1775 "./S2/compiler_parser.cpp"
    break;

  case 13: // constant: name ASSIGN expr SEMICOLON
#line 187 "S2.parser.ypp"
        { yylhs.value.as < gsc::constant_ptr > () = std::make_unique<gsc::node_constant>(yylhs.location, std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1781 "./S2/compiler_parser.cpp"
    break;

  case 14: // thread: name LPAREN parameters RPAREN LBRACE block RBRACE
#line 192 "S2.parser.ypp"
        { yylhs.value.as < gsc::thread_ptr > () = std::make_unique<gsc::node_thread>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::parameters_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 1787 "./S2/compiler_parser.cpp"
    break;

  case 15: // parameters: parameters COMMA name
#line 197 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::move(yystack_[2].value.as < gsc::parameters_ptr > ()); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1793 "./S2/compiler_parser.cpp"
    break;

  case 16: // parameters: name
#line 199 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(yylhs.location); yylhs.value.as < gsc::parameters_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 1799 "./S2/compiler_parser.cpp"
    break;

  case 17: // parameters: %empty
#line 201 "S2.parser.ypp"
        { yylhs.value.as < gsc::parameters_ptr > () = std::make_unique<gsc::node_parameters>(yylhs.location); }
#line 1805 "./S2/compiler_parser.cpp"
    break;

  case 18: // block: block stmt
#line 206 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::move(yystack_[1].value.as < gsc::block_ptr > ()); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1811 "./S2/compiler_parser.cpp"
    break;

  case 19: // block: stmt
#line 208 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(yylhs.location); yylhs.value.as < gsc::block_ptr > ()->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ())); }
#line 1817 "./S2/compiler_parser.cpp"
    break;

  case 20: // block: %empty
#line 210 "S2.parser.ypp"
        { yylhs.value.as < gsc::block_ptr > () = std::make_unique<gsc::node_block>(yylhs.location); }
#line 1823 "./S2/compiler_parser.cpp"
    break;

  case 21: // stmt: stmt_call
#line 214 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_call = std::move(yystack_[0].value.as < gsc::stmt_call_ptr > ()); }
#line 1829 "./S2/compiler_parser.cpp"
    break;

  case 22: // stmt: stmt_assign
#line 215 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_assign = std::move(yystack_[0].value.as < gsc::stmt_assign_ptr > ()); }
#line 1835 "./S2/compiler_parser.cpp"
    break;

  case 23: // stmt: stmt_endon
#line 216 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_endon = std::move(yystack_[0].value.as < gsc::stmt_endon_ptr > ()); }
#line 1841 "./S2/compiler_parser.cpp"
    break;

  case 24: // stmt: stmt_notify
#line 217 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_notify = std::move(yystack_[0].value.as < gsc::stmt_notify_ptr > ()); }
#line 1847 "./S2/compiler_parser.cpp"
    break;

  case 25: // stmt: stmt_wait
#line 218 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_wait = std::move(yystack_[0].value.as < gsc::stmt_wait_ptr > ()); }
#line 1853 "./S2/compiler_parser.cpp"
    break;

  case 26: // stmt: stmt_waittill
#line 219 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittill = std::move(yystack_[0].value.as < gsc::stmt_waittill_ptr > ()); }
#line 1859 "./S2/compiler_parser.cpp"
    break;

  case 27: // stmt: stmt_waittillmatch
#line 220 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillmatch = std::move(yystack_[0].value.as < gsc::stmt_waittillmatch_ptr > ()); }
#line 1865 "./S2/compiler_parser.cpp"
    break;

  case 28: // stmt: stmt_waittillframeend
#line 221 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_waittillframeend = std::move(yystack_[0].value.as < gsc::stmt_waittillframeend_ptr > ()); }
#line 1871 "./S2/compiler_parser.cpp"
    break;

  case 29: // stmt: stmt_if
#line 222 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_if = std::move(yystack_[0].value.as < gsc::stmt_if_ptr > ()); }
#line 1877 "./S2/compiler_parser.cpp"
    break;

  case 30: // stmt: stmt_ifelse
#line 223 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_ifelse = std::move(yystack_[0].value.as < gsc::stmt_ifelse_ptr > ()); }
#line 1883 "./S2/compiler_parser.cpp"
    break;

  case 31: // stmt: stmt_while
#line 224 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_while = std::move(yystack_[0].value.as < gsc::stmt_while_ptr > ()); }
#line 1889 "./S2/compiler_parser.cpp"
    break;

  case 32: // stmt: stmt_for
#line 225 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_for = std::move(yystack_[0].value.as < gsc::stmt_for_ptr > ()); }
#line 1895 "./S2/compiler_parser.cpp"
    break;

  case 33: // stmt: stmt_foreach
#line 226 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_foreach = std::move(yystack_[0].value.as < gsc::stmt_foreach_ptr > ()); }
#line 1901 "./S2/compiler_parser.cpp"
    break;

  case 34: // stmt: stmt_switch
#line 227 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_switch = std::move(yystack_[0].value.as < gsc::stmt_switch_ptr > ()); }
#line 1907 "./S2/compiler_parser.cpp"
    break;

  case 35: // stmt: stmt_case
#line 228 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_case = std::move(yystack_[0].value.as < gsc::stmt_case_ptr > ()); }
#line 1913 "./S2/compiler_parser.cpp"
    break;

  case 36: // stmt: stmt_default
#line 229 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_default = std::move(yystack_[0].value.as < gsc::stmt_default_ptr > ()); }
#line 1919 "./S2/compiler_parser.cpp"
    break;

  case 37: // stmt: stmt_break
#line 230 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_break = std::move(yystack_[0].value.as < gsc::stmt_break_ptr > ()); }
#line 1925 "./S2/compiler_parser.cpp"
    break;

  case 38: // stmt: stmt_continue
#line 231 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_continue = std::move(yystack_[0].value.as < gsc::stmt_continue_ptr > ()); }
#line 1931 "./S2/compiler_parser.cpp"
    break;

  case 39: // stmt: stmt_return
#line 232 "S2.parser.ypp"
                             { yylhs.value.as < gsc::stmt_ptr > ().as_return = std::move(yystack_[0].value.as < gsc::stmt_return_ptr > ()); }
#line 1937 "./S2/compiler_parser.cpp"
    break;

  case 40: // stmt_call: expr_call SEMICOLON
#line 237 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1943 "./S2/compiler_parser.cpp"
    break;

  case 41: // stmt_call: expr_call_thread SEMICOLON
#line 239 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_call_ptr > () = std::make_unique<gsc::node_stmt_call>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_call_ptr > ())); }
#line 1949 "./S2/compiler_parser.cpp"
    break;

  case 42: // stmt_assign: expr_assign SEMICOLON
#line 244 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_assign_ptr > () = std::make_unique<gsc::node_stmt_assign>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_assign_ptr > ())); }
#line 1955 "./S2/compiler_parser.cpp"
    break;

  case 43: // stmt_endon: object ENDON LPAREN expr RPAREN SEMICOLON
#line 249 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_endon_ptr > () = std::make_unique<gsc::node_stmt_endon>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ())); }
#line 1961 "./S2/compiler_parser.cpp"
    break;

  case 44: // stmt_notify: object NOTIFY LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 254 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1967 "./S2/compiler_parser.cpp"
    break;

  case 45: // stmt_notify: object NOTIFY LPAREN expr RPAREN SEMICOLON
#line 256 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_notify_ptr > () = std::make_unique<gsc::node_stmt_notify>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 1973 "./S2/compiler_parser.cpp"
    break;

  case 46: // stmt_wait: WAIT expr SEMICOLON
#line 261 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_wait_ptr > () = std::make_unique<gsc::node_stmt_wait>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 1979 "./S2/compiler_parser.cpp"
    break;

  case 47: // stmt_waittill: object WAITTILL LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 266 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1985 "./S2/compiler_parser.cpp"
    break;

  case 48: // stmt_waittill: object WAITTILL LPAREN expr RPAREN SEMICOLON
#line 268 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittill_ptr > () = std::make_unique<gsc::node_stmt_waittill>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 1991 "./S2/compiler_parser.cpp"
    break;

  case 49: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr COMMA expr_arguments RPAREN SEMICOLON
#line 273 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(yylhs.location, std::move(yystack_[7].value.as < gsc::node_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ())); }
#line 1997 "./S2/compiler_parser.cpp"
    break;

  case 50: // stmt_waittillmatch: object WAITTILLMATCH LPAREN expr RPAREN SEMICOLON
#line 275 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillmatch_ptr > () = std::make_unique<gsc::node_stmt_waittillmatch>(yylhs.location, std::move(yystack_[5].value.as < gsc::node_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::make_unique<gsc::node_expr_arguments>(yylhs.location)); }
#line 2003 "./S2/compiler_parser.cpp"
    break;

  case 51: // stmt_waittillframeend: WAITTILLFRAMEEND SEMICOLON
#line 280 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_waittillframeend_ptr > () = std::make_unique<gsc::node_stmt_waittillframeend>(yylhs.location); }
#line 2009 "./S2/compiler_parser.cpp"
    break;

  case 52: // stmt_if: IF LPAREN expr RPAREN LBRACE block RBRACE
#line 285 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2015 "./S2/compiler_parser.cpp"
    break;

  case 53: // stmt_if: IF LPAREN expr RPAREN stmt
#line 287 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_if_ptr > () = std::make_unique<gsc::node_stmt_if>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2025 "./S2/compiler_parser.cpp"
    break;

  case 54: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE LBRACE block RBRACE
#line 296 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[5].value.as < gsc::block_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2031 "./S2/compiler_parser.cpp"
    break;

  case 55: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE LBRACE block RBRACE
#line 298 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[4].location);
            blk->stmts.push_back(std::move(yystack_[4].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(blk), std::move(yystack_[1].value.as < gsc::block_ptr > ()));
        }
#line 2041 "./S2/compiler_parser.cpp"
    break;

  case 56: // stmt_ifelse: IF LPAREN expr RPAREN LBRACE block RBRACE ELSE stmt
#line 304 "S2.parser.ypp"
        { 
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::block_ptr > ()), std::move(blk));
        }
#line 2051 "./S2/compiler_parser.cpp"
    break;

  case 57: // stmt_ifelse: IF LPAREN expr RPAREN stmt ELSE stmt
#line 310 "S2.parser.ypp"
        {
            auto blk1 = std::make_unique<gsc::node_block>(yystack_[2].location);
            blk1->stmts.push_back(std::move(yystack_[2].value.as < gsc::stmt_ptr > ()));
            auto blk2 = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk2->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_ifelse_ptr > () = std::make_unique<gsc::node_stmt_ifelse>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(blk1), std::move(blk2));
        }
#line 2063 "./S2/compiler_parser.cpp"
    break;

  case 58: // stmt_while: WHILE LPAREN expr RPAREN LBRACE block RBRACE
#line 321 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2069 "./S2/compiler_parser.cpp"
    break;

  case 59: // stmt_while: WHILE LPAREN expr RPAREN stmt
#line 323 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_while_ptr > () = std::make_unique<gsc::node_stmt_while>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk)); }
#line 2078 "./S2/compiler_parser.cpp"
    break;

  case 60: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN LBRACE block RBRACE
#line 331 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(yylhs.location, std::move(yystack_[8].value.as < gsc::expr_ptr > ()), std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2084 "./S2/compiler_parser.cpp"
    break;

  case 61: // stmt_for: FOR LPAREN for_stmt SEMICOLON for_expr SEMICOLON for_stmt RPAREN stmt
#line 333 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_for_ptr > () = std::make_unique<gsc::node_stmt_for>(yylhs.location, std::move(yystack_[6].value.as < gsc::expr_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2094 "./S2/compiler_parser.cpp"
    break;

  case 62: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN LBRACE block RBRACE
#line 342 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2100 "./S2/compiler_parser.cpp"
    break;

  case 63: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN LBRACE block RBRACE
#line 344 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[8].value.as < gsc::name_ptr > ()), std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2106 "./S2/compiler_parser.cpp"
    break;

  case 64: // stmt_foreach: FOREACH LPAREN name IN expr RPAREN stmt
#line 346 "S2.parser.ypp"
        {
        auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2116 "./S2/compiler_parser.cpp"
    break;

  case 65: // stmt_foreach: FOREACH LPAREN name COMMA name IN expr RPAREN stmt
#line 352 "S2.parser.ypp"
        {
            auto blk = std::make_unique<gsc::node_block>(yystack_[0].location);
            blk->stmts.push_back(std::move(yystack_[0].value.as < gsc::stmt_ptr > ()));
            yylhs.value.as < gsc::stmt_foreach_ptr > () = std::make_unique<gsc::node_stmt_foreach>(yylhs.location, std::move(yystack_[6].value.as < gsc::name_ptr > ()), std::move(yystack_[4].value.as < gsc::name_ptr > ()), std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(blk));
        }
#line 2126 "./S2/compiler_parser.cpp"
    break;

  case 66: // stmt_switch: SWITCH LPAREN expr RPAREN LBRACE block RBRACE
#line 361 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_switch_ptr > () = std::make_unique<gsc::node_stmt_switch>(yylhs.location, std::move(yystack_[4].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::block_ptr > ())); }
#line 2132 "./S2/compiler_parser.cpp"
    break;

  case 67: // stmt_case: CASE integer COLON
#line 366 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2138 "./S2/compiler_parser.cpp"
    break;

  case 68: // stmt_case: CASE neg_integer COLON
#line 368 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::integer_ptr > ()))); }
#line 2144 "./S2/compiler_parser.cpp"
    break;

  case 69: // stmt_case: CASE string COLON
#line 370 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_case_ptr > () = std::make_unique<gsc::node_stmt_case>(yylhs.location, gsc::expr_ptr(std::move(yystack_[1].value.as < gsc::string_ptr > ()))); }
#line 2150 "./S2/compiler_parser.cpp"
    break;

  case 70: // stmt_default: DEFAULT COLON
#line 375 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_default_ptr > () = std::make_unique<gsc::node_stmt_default>(yylhs.location); }
#line 2156 "./S2/compiler_parser.cpp"
    break;

  case 71: // stmt_break: BREAK SEMICOLON
#line 380 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_break_ptr > () = std::make_unique<gsc::node_stmt_break>(yylhs.location); }
#line 2162 "./S2/compiler_parser.cpp"
    break;

  case 72: // stmt_continue: CONTINUE SEMICOLON
#line 385 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_continue_ptr > () = std::make_unique<gsc::node_stmt_continue>(yylhs.location); }
#line 2168 "./S2/compiler_parser.cpp"
    break;

  case 73: // stmt_return: RETURN expr SEMICOLON
#line 390 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2174 "./S2/compiler_parser.cpp"
    break;

  case 74: // stmt_return: RETURN SEMICOLON
#line 392 "S2.parser.ypp"
        { yylhs.value.as < gsc::stmt_return_ptr > () = std::make_unique<gsc::node_stmt_return>(yylhs.location, std::make_unique<gsc::node>()); }
#line 2180 "./S2/compiler_parser.cpp"
    break;

  case 75: // for_stmt: expr_assign
#line 396 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_assign_ptr > ()); }
#line 2186 "./S2/compiler_parser.cpp"
    break;

  case 76: // for_stmt: %empty
#line 397 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2192 "./S2/compiler_parser.cpp"
    break;

  case 77: // for_expr: expr
#line 401 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2198 "./S2/compiler_parser.cpp"
    break;

  case 78: // for_expr: %empty
#line 402 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node>(); }
#line 2204 "./S2/compiler_parser.cpp"
    break;

  case 79: // expr: expr_compare
#line 406 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2210 "./S2/compiler_parser.cpp"
    break;

  case 80: // expr: expr_binary
#line 407 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2216 "./S2/compiler_parser.cpp"
    break;

  case 81: // expr: expr_primitive
#line 408 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[0].value.as < gsc::expr_ptr > ()); }
#line 2222 "./S2/compiler_parser.cpp"
    break;

  case 82: // expr_assign: INCREMENT object
#line 412 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(yylhs.location, std::move(yystack_[0].value.as < gsc::node_ptr > ())); }
#line 2228 "./S2/compiler_parser.cpp"
    break;

  case 83: // expr_assign: DECREMENT object
#line 413 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(yylhs.location, std::move(yystack_[0].value.as < gsc::node_ptr > ())); }
#line 2234 "./S2/compiler_parser.cpp"
    break;

  case 84: // expr_assign: object INCREMENT
#line 414 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_increment>(yylhs.location, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2240 "./S2/compiler_parser.cpp"
    break;

  case 85: // expr_assign: object DECREMENT
#line 415 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_decrement>(yylhs.location, std::move(yystack_[1].value.as < gsc::node_ptr > ())); }
#line 2246 "./S2/compiler_parser.cpp"
    break;

  case 86: // expr_assign: object ASSIGN expr
#line 416 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2252 "./S2/compiler_parser.cpp"
    break;

  case 87: // expr_assign: object ASSIGN_BITWISE_OR expr
#line 417 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2258 "./S2/compiler_parser.cpp"
    break;

  case 88: // expr_assign: object ASSIGN_BITWISE_AND expr
#line 418 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2264 "./S2/compiler_parser.cpp"
    break;

  case 89: // expr_assign: object ASSIGN_BITWISE_EXOR expr
#line 419 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2270 "./S2/compiler_parser.cpp"
    break;

  case 90: // expr_assign: object ASSIGN_LSHIFT expr
#line 420 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_left>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()),std::move( yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2276 "./S2/compiler_parser.cpp"
    break;

  case 91: // expr_assign: object ASSIGN_RSHIFT expr
#line 421 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_shift_right>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2282 "./S2/compiler_parser.cpp"
    break;

  case 92: // expr_assign: object ASSIGN_ADD expr
#line 422 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_add>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2288 "./S2/compiler_parser.cpp"
    break;

  case 93: // expr_assign: object ASSIGN_SUB expr
#line 423 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_sub>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2294 "./S2/compiler_parser.cpp"
    break;

  case 94: // expr_assign: object ASSIGN_MULT expr
#line 424 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mult>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2300 "./S2/compiler_parser.cpp"
    break;

  case 95: // expr_assign: object ASSIGN_DIV expr
#line 425 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_div>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2306 "./S2/compiler_parser.cpp"
    break;

  case 96: // expr_assign: object ASSIGN_MOD expr
#line 426 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_assign_ptr > () = std::make_unique<gsc::node_expr_assign_mod>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2312 "./S2/compiler_parser.cpp"
    break;

  case 97: // expr_compare: expr OR expr
#line 430 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2318 "./S2/compiler_parser.cpp"
    break;

  case 98: // expr_compare: expr AND expr
#line 431 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2324 "./S2/compiler_parser.cpp"
    break;

  case 99: // expr_compare: expr EQUALITY expr
#line 432 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_equality>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2330 "./S2/compiler_parser.cpp"
    break;

  case 100: // expr_compare: expr INEQUALITY expr
#line 433 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_inequality>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2336 "./S2/compiler_parser.cpp"
    break;

  case 101: // expr_compare: expr LESS_EQUAL expr
#line 434 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2342 "./S2/compiler_parser.cpp"
    break;

  case 102: // expr_compare: expr GREATER_EQUAL expr
#line 435 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater_equal>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2348 "./S2/compiler_parser.cpp"
    break;

  case 103: // expr_compare: expr LESS expr
#line 436 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_less>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2354 "./S2/compiler_parser.cpp"
    break;

  case 104: // expr_compare: expr GREATER expr
#line 437 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_greater>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2360 "./S2/compiler_parser.cpp"
    break;

  case 105: // expr_binary: expr BITWISE_OR expr
#line 441 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_or>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2366 "./S2/compiler_parser.cpp"
    break;

  case 106: // expr_binary: expr BITWISE_AND expr
#line 442 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_and>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2372 "./S2/compiler_parser.cpp"
    break;

  case 107: // expr_binary: expr BITWISE_EXOR expr
#line 443 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_bitwise_exor>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2378 "./S2/compiler_parser.cpp"
    break;

  case 108: // expr_binary: expr LSHIFT expr
#line 444 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_left>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2384 "./S2/compiler_parser.cpp"
    break;

  case 109: // expr_binary: expr RSHIFT expr
#line 445 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_shift_right>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2390 "./S2/compiler_parser.cpp"
    break;

  case 110: // expr_binary: expr ADD expr
#line 446 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_add>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2396 "./S2/compiler_parser.cpp"
    break;

  case 111: // expr_binary: expr SUB expr
#line 447 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_sub>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2402 "./S2/compiler_parser.cpp"
    break;

  case 112: // expr_binary: expr MULT expr
#line 448 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mult>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2408 "./S2/compiler_parser.cpp"
    break;

  case 113: // expr_binary: expr DIV expr
#line 449 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_div>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2414 "./S2/compiler_parser.cpp"
    break;

  case 114: // expr_binary: expr MOD expr
#line 450 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_mod>(yylhs.location, std::move(yystack_[2].value.as < gsc::expr_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2420 "./S2/compiler_parser.cpp"
    break;

  case 115: // expr_primitive: LPAREN expr RPAREN
#line 454 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > () = std::move(yystack_[1].value.as < gsc::expr_ptr > ()); }
#line 2426 "./S2/compiler_parser.cpp"
    break;

  case 116: // expr_primitive: COMPLEMENT expr
#line 455 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_complement>(yylhs.location, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2432 "./S2/compiler_parser.cpp"
    break;

  case 117: // expr_primitive: NOT expr
#line 456 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::make_unique<gsc::node_expr_not>(yylhs.location, std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2438 "./S2/compiler_parser.cpp"
    break;

  case 118: // expr_primitive: expr_call
#line 457 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2444 "./S2/compiler_parser.cpp"
    break;

  case 119: // expr_primitive: expr_call_thread
#line 458 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2450 "./S2/compiler_parser.cpp"
    break;

  case 120: // expr_primitive: expr_call_childthread
#line 459 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2456 "./S2/compiler_parser.cpp"
    break;

  case 121: // expr_primitive: expr_function
#line 460 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2462 "./S2/compiler_parser.cpp"
    break;

  case 122: // expr_primitive: expr_add_array
#line 461 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2468 "./S2/compiler_parser.cpp"
    break;

  case 123: // expr_primitive: expr_array
#line 462 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2474 "./S2/compiler_parser.cpp"
    break;

  case 124: // expr_primitive: expr_field
#line 463 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2480 "./S2/compiler_parser.cpp"
    break;

  case 125: // expr_primitive: expr_size
#line 464 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2486 "./S2/compiler_parser.cpp"
    break;

  case 126: // expr_primitive: thisthread
#line 465 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::thisthread_ptr > ()); }
#line 2492 "./S2/compiler_parser.cpp"
    break;

  case 127: // expr_primitive: empty_array
#line 466 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::empty_array_ptr > ()); }
#line 2498 "./S2/compiler_parser.cpp"
    break;

  case 128: // expr_primitive: undefined
#line 467 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::undefined_ptr > ()); }
#line 2504 "./S2/compiler_parser.cpp"
    break;

  case 129: // expr_primitive: game
#line 468 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2510 "./S2/compiler_parser.cpp"
    break;

  case 130: // expr_primitive: self
#line 469 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2516 "./S2/compiler_parser.cpp"
    break;

  case 131: // expr_primitive: anim
#line 470 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2522 "./S2/compiler_parser.cpp"
    break;

  case 132: // expr_primitive: level
#line 471 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2528 "./S2/compiler_parser.cpp"
    break;

  case 133: // expr_primitive: animation
#line 472 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animation_ptr > ()); }
#line 2534 "./S2/compiler_parser.cpp"
    break;

  case 134: // expr_primitive: animtree
#line 473 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::animtree_ptr > ()); }
#line 2540 "./S2/compiler_parser.cpp"
    break;

  case 135: // expr_primitive: name
#line 474 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2546 "./S2/compiler_parser.cpp"
    break;

  case 136: // expr_primitive: istring
#line 475 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::istring_ptr > ()); }
#line 2552 "./S2/compiler_parser.cpp"
    break;

  case 137: // expr_primitive: string
#line 476 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::string_ptr > ()); }
#line 2558 "./S2/compiler_parser.cpp"
    break;

  case 138: // expr_primitive: vector
#line 477 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::vector_ptr > ()); }
#line 2564 "./S2/compiler_parser.cpp"
    break;

  case 139: // expr_primitive: neg_float
#line 478 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2570 "./S2/compiler_parser.cpp"
    break;

  case 140: // expr_primitive: neg_integer
#line 479 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2576 "./S2/compiler_parser.cpp"
    break;

  case 141: // expr_primitive: float
#line 480 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::float_ptr > ()); }
#line 2582 "./S2/compiler_parser.cpp"
    break;

  case 142: // expr_primitive: integer
#line 481 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::integer_ptr > ()); }
#line 2588 "./S2/compiler_parser.cpp"
    break;

  case 143: // expr_primitive: false
#line 482 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::false_ptr > ()); }
#line 2594 "./S2/compiler_parser.cpp"
    break;

  case 144: // expr_primitive: true
#line 483 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_ptr > ().as_node = std::move(yystack_[0].value.as < gsc::true_ptr > ()); }
#line 2600 "./S2/compiler_parser.cpp"
    break;

  case 145: // expr_call: expr_call_function
#line 487 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2606 "./S2/compiler_parser.cpp"
    break;

  case 146: // expr_call: expr_call_pointer
#line 488 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2612 "./S2/compiler_parser.cpp"
    break;

  case 147: // expr_call: object expr_call_function
#line 489 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2618 "./S2/compiler_parser.cpp"
    break;

  case 148: // expr_call: object expr_call_pointer
#line 490 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, false, std::move(yystack_[1].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2624 "./S2/compiler_parser.cpp"
    break;

  case 149: // expr_call_thread: THREAD expr_call_function
#line 494 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2630 "./S2/compiler_parser.cpp"
    break;

  case 150: // expr_call_thread: THREAD expr_call_pointer
#line 495 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2636 "./S2/compiler_parser.cpp"
    break;

  case 151: // expr_call_thread: object THREAD expr_call_function
#line 496 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2642 "./S2/compiler_parser.cpp"
    break;

  case 152: // expr_call_thread: object THREAD expr_call_pointer
#line 497 "S2.parser.ypp"
                                        { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, true, false, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2648 "./S2/compiler_parser.cpp"
    break;

  case 153: // expr_call_childthread: CHILDTHREAD expr_call_function
#line 501 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2654 "./S2/compiler_parser.cpp"
    break;

  case 154: // expr_call_childthread: CHILDTHREAD expr_call_pointer
#line 502 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::make_unique<gsc::node>(), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2660 "./S2/compiler_parser.cpp"
    break;

  case 155: // expr_call_childthread: object CHILDTHREAD expr_call_function
#line 503 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2666 "./S2/compiler_parser.cpp"
    break;

  case 156: // expr_call_childthread: object CHILDTHREAD expr_call_pointer
#line 504 "S2.parser.ypp"
                                            { yylhs.value.as < gsc::expr_call_ptr > () = std::make_unique<gsc::node_expr_call>(yylhs.location, false, true, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::expr_call_type_ptr > ())); }
#line 2672 "./S2/compiler_parser.cpp"
    break;

  case 157: // expr_call_function: name LPAREN expr_arguments RPAREN
#line 509 "S2.parser.ypp"
        {yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(yylhs.location, std::make_unique<gsc::node_file>(), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2678 "./S2/compiler_parser.cpp"
    break;

  case 158: // expr_call_function: file DOUBLECOLON name LPAREN expr_arguments RPAREN
#line 511 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_func = std::make_unique<gsc::node_expr_call_function>(yylhs.location, std::move(yystack_[5].value.as < gsc::file_ptr > ()), std::move(yystack_[3].value.as < gsc::name_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2684 "./S2/compiler_parser.cpp"
    break;

  case 159: // expr_call_pointer: LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 516 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(yylhs.location, false, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2690 "./S2/compiler_parser.cpp"
    break;

  case 160: // expr_call_pointer: CALL LBRACKET LBRACKET expr RBRACKET RBRACKET LPAREN expr_arguments RPAREN
#line 518 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_call_type_ptr > ().as_pointer = std::make_unique<gsc::node_expr_call_pointer>(yylhs.location, true, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2696 "./S2/compiler_parser.cpp"
    break;

  case 161: // expr_arguments: expr_arguments COMMA expr
#line 523 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::move(yystack_[2].value.as < gsc::expr_arguments_ptr > ()); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2702 "./S2/compiler_parser.cpp"
    break;

  case 162: // expr_arguments: expr
#line 525 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(yylhs.location); yylhs.value.as < gsc::expr_arguments_ptr > ()->list.push_back(std::move(yystack_[0].value.as < gsc::expr_ptr > ())); }
#line 2708 "./S2/compiler_parser.cpp"
    break;

  case 163: // expr_arguments: %empty
#line 527 "S2.parser.ypp"
        { yylhs.value.as < gsc::expr_arguments_ptr > () = std::make_unique<gsc::node_expr_arguments>(yylhs.location); }
#line 2714 "./S2/compiler_parser.cpp"
    break;

  case 164: // expr_function: DOUBLECOLON name
#line 532 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(yylhs.location, std::make_unique<gsc::node_file>(yylhs.location), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2720 "./S2/compiler_parser.cpp"
    break;

  case 165: // expr_function: file DOUBLECOLON name
#line 534 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_function>(yylhs.location, std::move(yystack_[2].value.as < gsc::file_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2726 "./S2/compiler_parser.cpp"
    break;

  case 166: // expr_add_array: LBRACKET expr_arguments RBRACKET
#line 539 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_add_array>(yylhs.location, std::move(yystack_[1].value.as < gsc::expr_arguments_ptr > ())); }
#line 2732 "./S2/compiler_parser.cpp"
    break;

  case 167: // expr_array: object LBRACKET expr RBRACKET
#line 544 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_array>(yylhs.location, std::move(yystack_[3].value.as < gsc::node_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2738 "./S2/compiler_parser.cpp"
    break;

  case 168: // expr_field: object DOT name
#line 549 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_field>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ()), std::move(yystack_[0].value.as < gsc::name_ptr > ())); }
#line 2744 "./S2/compiler_parser.cpp"
    break;

  case 169: // expr_size: object DOT SIZE
#line 554 "S2.parser.ypp"
        { yylhs.value.as < gsc::node_ptr > () = std::make_unique<gsc::node_expr_size>(yylhs.location, std::move(yystack_[2].value.as < gsc::node_ptr > ())); }
#line 2750 "./S2/compiler_parser.cpp"
    break;

  case 170: // object: expr_call
#line 558 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::expr_call_ptr > ()); }
#line 2756 "./S2/compiler_parser.cpp"
    break;

  case 171: // object: expr_array
#line 559 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2762 "./S2/compiler_parser.cpp"
    break;

  case 172: // object: expr_field
#line 560 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::node_ptr > ()); }
#line 2768 "./S2/compiler_parser.cpp"
    break;

  case 173: // object: game
#line 561 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::game_ptr > ()); }
#line 2774 "./S2/compiler_parser.cpp"
    break;

  case 174: // object: self
#line 562 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::self_ptr > ()); }
#line 2780 "./S2/compiler_parser.cpp"
    break;

  case 175: // object: anim
#line 563 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::anim_ptr > ()); }
#line 2786 "./S2/compiler_parser.cpp"
    break;

  case 176: // object: level
#line 564 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::level_ptr > ()); }
#line 2792 "./S2/compiler_parser.cpp"
    break;

  case 177: // object: name
#line 565 "S2.parser.ypp"
                          { yylhs.value.as < gsc::node_ptr > () = std::move(yystack_[0].value.as < gsc::name_ptr > ()); }
#line 2798 "./S2/compiler_parser.cpp"
    break;

  case 178: // thisthread: THISTHREAD
#line 568 "S2.parser.ypp"
                          { yylhs.value.as < gsc::thisthread_ptr > () = std::make_unique<gsc::node_thisthread>(yylhs.location); }
#line 2804 "./S2/compiler_parser.cpp"
    break;

  case 179: // empty_array: EMPTY_ARRAY
#line 569 "S2.parser.ypp"
                          { yylhs.value.as < gsc::empty_array_ptr > () = std::make_unique<gsc::node_empty_array>(yylhs.location); }
#line 2810 "./S2/compiler_parser.cpp"
    break;

  case 180: // undefined: UNDEFINED
#line 570 "S2.parser.ypp"
                          { yylhs.value.as < gsc::undefined_ptr > () = std::make_unique<gsc::node_undefined>(yylhs.location); }
#line 2816 "./S2/compiler_parser.cpp"
    break;

  case 181: // game: GAME
#line 571 "S2.parser.ypp"
                          { yylhs.value.as < gsc::game_ptr > () = std::make_unique<gsc::node_game>(yylhs.location); }
#line 2822 "./S2/compiler_parser.cpp"
    break;

  case 182: // self: SELF
#line 572 "S2.parser.ypp"
                          { yylhs.value.as < gsc::self_ptr > () = std::make_unique<gsc::node_self>(yylhs.location); }
#line 2828 "./S2/compiler_parser.cpp"
    break;

  case 183: // anim: ANIM
#line 573 "S2.parser.ypp"
                          { yylhs.value.as < gsc::anim_ptr > () = std::make_unique<gsc::node_anim>(yylhs.location); }
#line 2834 "./S2/compiler_parser.cpp"
    break;

  case 184: // level: LEVEL
#line 574 "S2.parser.ypp"
                          { yylhs.value.as < gsc::level_ptr > () = std::make_unique<gsc::node_level>(yylhs.location); }
#line 2840 "./S2/compiler_parser.cpp"
    break;

  case 185: // animation: MOD NAME
#line 575 "S2.parser.ypp"
                                     { yylhs.value.as < gsc::animation_ptr > () = std::make_unique<gsc::node_animation>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2846 "./S2/compiler_parser.cpp"
    break;

  case 186: // animtree: ANIMTREE
#line 576 "S2.parser.ypp"
                          { yylhs.value.as < gsc::animtree_ptr > () = std::make_unique<gsc::node_animtree>(yylhs.location); }
#line 2852 "./S2/compiler_parser.cpp"
    break;

  case 187: // name: NAME
#line 577 "S2.parser.ypp"
                          { yylhs.value.as < gsc::name_ptr > () = std::make_unique<gsc::node_name>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2858 "./S2/compiler_parser.cpp"
    break;

  case 188: // file: FILE
#line 578 "S2.parser.ypp"
                          { yylhs.value.as < gsc::file_ptr > () = std::make_unique<gsc::node_file>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2864 "./S2/compiler_parser.cpp"
    break;

  case 189: // istring: ISTRING
#line 579 "S2.parser.ypp"
                          { yylhs.value.as < gsc::istring_ptr > () = std::make_unique<gsc::node_istring>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2870 "./S2/compiler_parser.cpp"
    break;

  case 190: // string: STRING
#line 580 "S2.parser.ypp"
                          { yylhs.value.as < gsc::string_ptr > () = std::make_unique<gsc::node_string>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2876 "./S2/compiler_parser.cpp"
    break;

  case 191: // vector: LPAREN expr COMMA expr COMMA expr RPAREN
#line 581 "S2.parser.ypp"
                                                       { yylhs.value.as < gsc::vector_ptr > () = std::make_unique<gsc::node_vector>(yylhs.location, std::move(yystack_[5].value.as < gsc::expr_ptr > ()), std::move(yystack_[3].value.as < gsc::expr_ptr > ()), std::move(yystack_[1].value.as < gsc::expr_ptr > ())); }
#line 2882 "./S2/compiler_parser.cpp"
    break;

  case 192: // neg_float: SUB FLOAT
#line 582 "S2.parser.ypp"
                                     { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 2888 "./S2/compiler_parser.cpp"
    break;

  case 193: // neg_integer: SUB INTEGER
#line 583 "S2.parser.ypp"
                                     { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(yylhs.location, "-" + yystack_[0].value.as < std::string > ()); }
#line 2894 "./S2/compiler_parser.cpp"
    break;

  case 194: // float: FLOAT
#line 584 "S2.parser.ypp"
                          { yylhs.value.as < gsc::float_ptr > () = std::make_unique<gsc::node_float>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2900 "./S2/compiler_parser.cpp"
    break;

  case 195: // integer: INTEGER
#line 585 "S2.parser.ypp"
                          { yylhs.value.as < gsc::integer_ptr > () = std::make_unique<gsc::node_integer>(yylhs.location, yystack_[0].value.as < std::string > ()); }
#line 2906 "./S2/compiler_parser.cpp"
    break;

  case 196: // false: FALSE
#line 586 "S2.parser.ypp"
                          { yylhs.value.as < gsc::false_ptr > () = std::make_unique<gsc::node_false>(yylhs.location); }
#line 2912 "./S2/compiler_parser.cpp"
    break;

  case 197: // true: TRUE
#line 587 "S2.parser.ypp"
                          { yylhs.value.as < gsc::true_ptr > () = std::make_unique<gsc::node_true>(yylhs.location); }
#line 2918 "./S2/compiler_parser.cpp"
    break;


#line 2922 "./S2/compiler_parser.cpp"

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
  "istring", "string", "vector", "neg_float", "neg_integer", "float",
  "integer", "false", "true", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -304;

  const short parser::yytable_ninf_ = -178;

  const short
  parser::yypact_[] =
  {
       6,   -65,     7,  -304,    22,     6,  -304,  -304,  -304,  -304,
    -304,   -16,  -304,     3,   -53,  -304,  -304,  -304,   -25,  1284,
    -304,  -304,    21,   -15,  -304,  -304,    25,    25,  -304,    32,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  1284,  1347,
     -25,    -8,  1284,  1284,   -61,  -304,  -304,  -304,  2563,  -304,
    -304,  -304,    31,  -304,  -304,  -304,  -304,  -304,  -304,    36,
      84,  -304,   109,  -304,  -304,  -304,   113,   117,   183,   265,
    -304,  -304,    10,    45,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,    42,    54,   -25,    75,  -304,  -304,    85,
      50,  -304,  -304,    86,  2129,  1347,  2642,   -10,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,    25,    25,  1347,   -17,  -304,  -304,  1284,
     -25,  -304,  2089,  -304,  1284,   -25,  1284,  -304,  1284,  2429,
    -304,  1284,  -304,    93,    93,  1281,  2161,   180,   180,    69,
      69,    69,    69,   898,   458,  2204,   -11,   -11,  -304,  -304,
    -304,  -304,  -304,  -304,  2460,  -304,  -304,    -7,    92,  1284,
      98,    94,   102,   114,   115,   118,   -66,   110,   112,   120,
    1221,   399,   399,  1465,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,   121,   122,   130,  -304,  -304,  1393,
    -304,  -304,  -304,  -304,    85,  2429,    92,  2491,  2529,   136,
    2642,  -304,  -304,  1284,  2597,  -304,  1284,  1284,   403,   -25,
    1284,    74,   116,   133,   134,  -304,  -304,  -304,  -304,  2631,
    -304,     2,     2,  -304,  -304,  -304,  -304,  -304,   127,   150,
     151,   155,   -25,  -304,  -304,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1284,  1284,  1284,   154,  1284,   156,    33,
    -304,  2269,  2301,   158,  -304,  2092,    -2,  2312,  -304,  -304,
    -304,  -304,  1284,  1284,  1284,  1284,  2642,  2642,  2642,  2642,
    2642,  2642,  2642,  2642,  2642,  2642,  2642,   160,  2344,  1284,
    -304,  1504,  1543,  1284,  1284,   -25,   162,  2355,  2172,  2215,
    2258,  1284,  -304,    43,  2089,   190,  2089,  -304,   159,  2642,
    2387,   194,  2089,   167,   168,  1284,   169,  1284,   172,  1284,
      44,  -304,  1582,  1621,  1660,   403,  1699,  1284,  1738,  -304,
    -304,    58,  -304,    59,  -304,    67,  -304,   207,  2089,  -304,
    -304,   185,  2089,  -304,  2398,  -304,   178,   179,   189,  1777,
    1816,  1855,  1894,  1933,  -304,  -304,  -304,  2089,  -304,  -304,
    2089,  -304,  -304,  2089,  -304,  1972,  2011,  2050,  -304,  -304,
    -304
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,   187,     0,     2,     6,     7,     9,    10,
      11,     0,   188,     0,     0,     1,     4,     5,    17,     0,
       8,   190,     0,     0,    16,   186,     0,     0,   178,     0,
     197,   196,   180,   181,   182,   183,   184,   179,     0,   163,
       0,     0,     0,     0,     0,   189,   194,   195,     0,    79,
      80,    81,   118,   119,   120,   145,   146,   121,   122,   123,
     124,   125,     0,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,   149,   150,     0,
       0,   153,   154,     0,     0,   163,   162,     0,   164,   185,
     117,   116,   192,   193,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   163,
       0,    12,    20,    15,     0,     0,     0,   115,     0,   162,
     166,     0,   114,   108,   109,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   110,   111,   112,   113,
     151,   152,   155,   156,     0,   169,   168,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,   170,     0,   171,   172,     0,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
     161,   167,   157,   163,     0,    51,     0,     0,    76,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    74,     0,
     170,    82,    83,    14,    18,    42,    40,    41,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,    75,     0,     0,     0,    69,    68,
      67,    73,     0,     0,     0,     0,    91,    86,    92,    93,
      94,    95,    96,    87,    88,    89,    90,     0,     0,   163,
     158,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,   163,   191,     0,    20,    53,    20,    59,     0,    77,
       0,     0,    20,     0,     0,   163,     0,   163,     0,   163,
       0,   159,     0,     0,     0,    76,     0,     0,     0,    43,
      45,     0,    48,     0,    50,     0,   160,    52,    20,    57,
      58,     0,    20,    64,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    47,    49,    20,    56,    55,
      20,    61,    62,    20,    65,     0,     0,     0,    54,    60,
      63
  };

  const short
  parser::yypgoto_[] =
  {
    -304,  -304,  -304,   241,   243,  -304,  -304,  -304,  -304,  -303,
     -89,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
     -85,  -304,   353,  -220,  -304,  -304,  -304,   225,   862,  -304,
     -24,   -20,  -125,  -304,  -304,   347,   424,  -304,   491,  -304,
    -304,  -304,   561,   650,   733,   810,  -304,  -304,     0,    52,
    -304,   -13,  -304,  -304,    77,  -304,    78,  -304,  -304
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    23,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     273,   318,    96,   204,    49,    50,    51,    52,    53,    54,
      55,    56,    97,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82
  };

  const short
  parser::yytable_[] =
  {
      11,    22,    87,    91,   167,    11,    88,    92,   274,     1,
       2,   332,   231,   334,   165,   304,    12,    21,    24,   338,
      47,    18,    15,    84,   102,   103,    89,    89,    85,    29,
      21,   222,   140,   141,  -177,  -177,   141,  -177,   127,   105,
      98,   305,   128,   125,    14,   360,   252,   129,    19,   362,
      20,  -177,    29,    13,  -177,  -170,  -170,     3,  -170,    83,
    -171,  -171,    89,  -171,   375,     3,    86,   376,   121,   122,
     377,   300,  -170,    93,    99,  -170,   141,  -171,    90,    90,
    -171,   331,   346,    12,     3,   133,   141,   141,     3,   131,
     130,  -177,  -177,   132,   244,   135,   356,   357,   269,   160,
     162,   141,   141,   161,   163,   358,    12,     3,  -172,  -172,
     141,  -172,  -170,  -170,    90,   274,   134,  -171,  -171,   105,
     106,   107,   129,    89,    89,  -172,   166,   136,  -172,   223,
     168,   226,   214,   123,   124,   216,    29,  -173,  -173,   227,
    -173,  -174,  -174,   105,  -174,   225,   119,   120,   121,   122,
     125,   228,   229,   126,  -173,   230,   235,  -173,  -174,   236,
     103,  -174,   278,   232,   282,  -172,  -172,   237,   245,   246,
     119,   120,   121,   122,   313,    90,    90,   247,   268,   279,
     280,   214,   214,   214,    90,   127,   330,   283,   284,   128,
      12,     3,   285,   299,  -173,  -173,   297,   311,  -174,  -174,
     341,   322,   343,   333,   345,   303,   335,  -175,  -175,    89,
    -175,   337,   315,   317,   339,   340,   342,   127,   127,   344,
     359,   128,   128,   361,  -175,   364,   365,  -175,   214,   276,
     105,   106,   107,    90,    90,    90,   366,   112,   113,   114,
     115,    89,    89,   244,   349,   244,    16,   353,    17,   244,
     351,   127,   166,   233,   234,   128,     0,   119,   120,   121,
     122,    90,     0,     0,  -175,  -175,     0,     0,     0,     0,
     368,   244,   371,   244,   374,    89,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,   244,   244,   244,  -176,
    -176,     0,  -176,    90,    90,     0,     0,     0,     0,     0,
       0,   214,   214,     0,     0,   321,  -176,     0,     0,  -176,
       0,     0,     0,     0,   214,     0,   214,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,    90,     0,     0,
       0,     0,   214,   214,   214,   214,   214,     0,   214,     0,
       0,     0,     0,     0,     0,     0,  -176,  -176,   214,     0,
       0,     0,   214,    90,    90,     0,     0,   205,     0,   214,
     214,   214,   214,   214,     0,     0,    90,   214,    90,     0,
     214,     0,    48,   214,    90,   214,   214,   214,     0,     0,
       0,     0,     0,     0,    90,    90,    90,    90,    90,     0,
      90,    94,     0,     0,     0,   100,   101,     0,     0,     0,
      90,     0,     0,     0,    90,     0,   240,   240,   205,     0,
       0,    90,    90,    90,    90,    90,     0,     0,     0,    90,
       0,     0,    90,     0,     0,    90,    29,    90,    90,    90,
      29,    33,    34,    35,    36,    33,    34,    35,    36,     0,
      86,     0,     0,     0,    86,     0,     0,     0,   139,     0,
       0,   181,   182,   240,     0,     0,     0,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,   164,   207,
      12,     3,     0,     0,    12,     3,     0,   215,     0,   217,
       0,   218,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   224,     0,     0,     0,   205,   205,   207,   207,
     207,     0,     0,   239,   118,   119,   120,   121,   122,   205,
       0,   205,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   205,   205,   205,
     240,   205,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,   207,     0,   205,     0,   271,
     272,     0,     0,   277,   205,   205,   205,   205,   205,     0,
       0,     0,   205,     0,     0,   205,     0,     0,   205,     0,
     205,   205,   205,     0,     0,   208,   208,   208,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,     0,
     298,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,   308,   309,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   207,   207,
       0,     0,   208,     0,     0,     0,   319,   320,     0,     0,
       0,   207,     0,   207,     0,     0,     0,     0,     0,   207,
       0,     0,   241,   242,   209,     0,     0,     0,     0,   207,
     207,   207,   207,   207,     0,   207,     0,     0,     0,     0,
     354,     0,     0,   210,     0,   207,     0,     0,     0,   207,
       0,     0,     0,     0,     0,     0,   207,   207,   207,   207,
     207,     0,     0,     0,   207,     0,     0,   207,     0,   275,
     207,     0,   207,   207,   207,   208,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
     208,     0,   210,   210,   210,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   208,   208,   208,
     208,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,   208,     0,     0,     0,
       0,     0,   211,   208,   208,   208,   208,   208,     0,   210,
       0,   208,   209,   209,   208,     0,     0,   208,     0,   208,
     208,   208,     0,     0,     0,   209,     0,   209,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   209,   209,   275,   209,     0,   209,
       0,   211,   211,   211,     0,     0,     0,     0,     0,   209,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
     209,   209,   209,   209,   209,     0,     0,     0,   209,     0,
       0,   209,   210,   210,   209,   212,   209,   209,   209,     0,
       0,     0,     0,     0,     0,   210,     0,   210,   211,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,   210,   210,   210,   210,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,   210,   212,   212,   212,     0,     0,     0,
     210,   210,   210,   210,   210,     0,     0,     0,   210,     0,
       0,   210,     0,     0,   210,     0,   210,   210,   210,     0,
       0,     0,   213,     0,     0,     0,     0,     0,   105,   106,
     107,   211,   211,   110,   111,   112,   113,   114,   115,     0,
       0,   212,     0,     0,   211,     0,   211,     0,     0,     0,
       0,     0,   211,   117,   118,   119,   120,   121,   122,     0,
       0,     0,   211,   211,   211,   211,   211,     0,   211,     0,
       0,   213,   213,   213,   206,     0,     0,     0,   211,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,   211,
     211,   211,   211,   211,     0,     0,     0,   211,     0,     0,
     211,     0,     0,   211,     0,   211,   211,   211,     0,     0,
       0,     0,     0,     0,   212,   212,     0,     0,   213,     0,
       0,     0,     0,     0,     0,   206,     0,   212,     0,   212,
       0,     0,     0,     0,     0,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   212,   212,   212,   212,
       0,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,     0,     0,   212,     0,     0,     0,     0,
       0,     0,   212,   212,   212,   212,   212,     0,     0,     0,
     212,     0,     0,   212,     0,     0,   212,     0,   212,   212,
     212,   213,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,   213,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   213,   213,   213,   213,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,     0,
       0,     0,   213,   206,   206,     0,     0,     0,     0,   213,
     213,   213,   213,   213,     0,     0,   206,   213,   206,     0,
     213,     0,     0,   213,   206,   213,   213,   213,     0,     0,
       0,     0,     0,     0,   206,   206,   206,     0,   206,     0,
     206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,     0,   206,     0,     0,     0,     0,     0,
       0,   206,   206,   206,   206,   206,    25,     0,     0,   206,
       0,     0,   206,     0,     0,   206,     0,   206,   206,   206,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
       0,     0,    39,     0,     0,     0,    40,     0,   238,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    12,     3,    21,    45,    46,    47,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,    39,     0,     0,     0,    40,
       0,   105,   106,   107,    41,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,    42,    43,     0,     0,     0,
       0,     0,    25,     0,     0,   116,   117,   118,   119,   120,
     121,   122,    44,     0,     0,    12,     3,    21,    45,    46,
      47,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,    95,     0,
       0,     0,    40,     0,     0,     0,     0,    41,     0,   248,
     249,     0,   250,   251,     0,     0,     0,     0,    42,    43,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
      29,     0,     0,     0,     0,    44,     0,     0,    12,     3,
      21,    45,    46,    47,   125,     0,     0,   252,     0,     0,
       0,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,     0,     0,     0,
       0,     0,     0,   169,    12,     3,   170,   171,     0,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,     0,   243,    86,     0,     0,     0,
       0,     0,   169,   181,   182,   170,   171,     0,   172,   173,
     174,     0,   175,   176,   177,   178,   179,   180,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,   314,     0,    86,    12,     3,     0,     0,
       0,   169,   181,   182,   170,   171,     0,   172,   173,   174,
       0,   175,   176,   177,   178,   179,   180,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,   316,     0,    86,    12,     3,     0,     0,     0,
     169,   181,   182,   170,   171,     0,   172,   173,   174,     0,
     175,   176,   177,   178,   179,   180,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,     0,   347,    86,    12,     3,     0,     0,     0,   169,
     181,   182,   170,   171,     0,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
     348,     0,    86,    12,     3,     0,     0,     0,   169,   181,
     182,   170,   171,     0,   172,   173,   174,     0,   175,   176,
     177,   178,   179,   180,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
     350,    86,    12,     3,     0,     0,     0,   169,   181,   182,
     170,   171,     0,   172,   173,   174,     0,   175,   176,   177,
     178,   179,   180,    26,     0,     0,    29,     0,     0,     0,
       0,    33,    34,    35,    36,     0,     0,     0,   352,     0,
      86,    12,     3,     0,     0,     0,   169,   181,   182,   170,
     171,     0,   172,   173,   174,     0,   175,   176,   177,   178,
     179,   180,    26,     0,     0,    29,     0,     0,     0,     0,
      33,    34,    35,    36,     0,     0,     0,     0,   355,    86,
      12,     3,     0,     0,     0,   169,   181,   182,   170,   171,
       0,   172,   173,   174,     0,   175,   176,   177,   178,   179,
     180,    26,     0,     0,    29,     0,     0,     0,     0,    33,
      34,    35,    36,     0,     0,     0,   367,     0,    86,    12,
       3,     0,     0,     0,   169,   181,   182,   170,   171,     0,
     172,   173,   174,     0,   175,   176,   177,   178,   179,   180,
      26,     0,     0,    29,     0,     0,     0,     0,    33,    34,
      35,    36,     0,     0,     0,     0,   369,    86,    12,     3,
       0,     0,     0,   169,   181,   182,   170,   171,     0,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,    26,
       0,     0,    29,     0,     0,     0,     0,    33,    34,    35,
      36,     0,     0,     0,   370,     0,    86,    12,     3,     0,
       0,     0,   169,   181,   182,   170,   171,     0,   172,   173,
     174,     0,   175,   176,   177,   178,   179,   180,    26,     0,
       0,    29,     0,     0,     0,     0,    33,    34,    35,    36,
       0,     0,     0,     0,   372,    86,    12,     3,     0,     0,
       0,   169,   181,   182,   170,   171,     0,   172,   173,   174,
       0,   175,   176,   177,   178,   179,   180,    26,     0,     0,
      29,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,   373,     0,    86,    12,     3,     0,     0,     0,
     169,   181,   182,   170,   171,     0,   172,   173,   174,     0,
     175,   176,   177,   178,   179,   180,    26,     0,     0,    29,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,     0,   378,    86,    12,     3,     0,     0,     0,   169,
     181,   182,   170,   171,     0,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,    26,     0,     0,    29,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
       0,   379,    86,    12,     3,     0,     0,     0,   169,   181,
     182,   170,   171,     0,   172,   173,   174,     0,   175,   176,
     177,   178,   179,   180,    26,     0,     0,    29,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
     380,    86,    12,     3,     0,     0,     0,   169,   181,   182,
     170,   171,     0,   172,   173,   174,     0,   175,   176,   177,
     178,   179,   180,    26,     0,     0,    29,     0,     0,    29,
       0,    33,    34,    35,    36,     0,     0,     0,     0,     0,
      86,    12,     3,   125,     0,     0,   252,   181,   182,     0,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   137,     0,     0,
      12,     3,   138,    12,     3,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     324,   105,   106,   107,     0,   325,   110,   111,   112,   113,
     114,   115,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   326,   105,   106,   107,     0,   327,   110,
     111,   112,   113,   114,   115,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,   119,   120,   121,   122,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   328,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,   301,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   302,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     306,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   312,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   323,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   336,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   363,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,   219,   116,   117,   118,   119,   120,   121,   122,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   116,   117,   118,   119,   120,   121,   122,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   116,   117,   118,   119,   120,   121,
     122,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   267,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   270,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   281,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122
  };

  const short
  parser::yycheck_[] =
  {
       0,    14,    26,    27,   129,     5,    26,    27,   228,     3,
       4,   314,    78,   316,    31,    17,    81,    83,    18,   322,
      86,    37,     0,    38,    85,    86,    26,    27,    43,    27,
      83,    38,    42,    43,    24,    25,    43,    27,    62,    50,
      40,    43,    62,    41,    37,   348,    44,    37,    64,   352,
      47,    41,    27,     1,    44,    24,    25,    82,    27,    38,
      24,    25,    62,    27,   367,    82,    41,   370,    79,    80,
     373,    38,    41,    41,    82,    44,    43,    41,    26,    27,
      44,    38,    38,    81,    82,    85,    43,    43,    82,    47,
      45,    81,    82,    39,   183,    45,    38,    38,   223,   123,
     124,    43,    43,   123,   124,    38,    81,    82,    24,    25,
      43,    27,    81,    82,    62,   335,    41,    81,    82,    50,
      51,    52,    37,   123,   124,    41,   126,    41,    44,    37,
     130,    37,   132,    24,    25,   135,    27,    24,    25,    37,
      27,    24,    25,    50,    27,    47,    77,    78,    79,    80,
      41,    37,    37,    44,    41,    37,    46,    44,    41,    47,
      86,    44,    46,   176,    37,    81,    82,    47,    47,    47,
      77,    78,    79,    80,   299,   123,   124,    47,    42,    46,
      46,   181,   182,   183,   132,   209,   311,    37,    37,   209,
      81,    82,    37,    37,    81,    82,    42,    37,    81,    82,
     325,    39,   327,    13,   329,    47,    47,    24,    25,   209,
      27,    17,   301,   302,    47,    47,    47,   241,   242,    47,
      13,   241,   242,    38,    41,    47,    47,    44,   228,   229,
      50,    51,    52,   181,   182,   183,    47,    57,    58,    59,
      60,   241,   242,   332,   333,   334,     5,   336,     5,   338,
     335,   275,   252,   176,   176,   275,    -1,    77,    78,    79,
      80,   209,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,   363,   275,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,   375,   376,   377,    24,
      25,    -1,    27,   241,   242,    -1,    -1,    -1,    -1,    -1,
      -1,   301,   302,    -1,    -1,   305,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,   314,    -1,   316,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,   332,   333,   334,   335,   336,    -1,   338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,   348,    -1,
      -1,    -1,   352,   301,   302,    -1,    -1,   132,    -1,   359,
     360,   361,   362,   363,    -1,    -1,   314,   367,   316,    -1,
     370,    -1,    19,   373,   322,   375,   376,   377,    -1,    -1,
      -1,    -1,    -1,    -1,   332,   333,   334,   335,   336,    -1,
     338,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
     348,    -1,    -1,    -1,   352,    -1,   181,   182,   183,    -1,
      -1,   359,   360,   361,   362,   363,    -1,    -1,    -1,   367,
      -1,    -1,   370,    -1,    -1,   373,    27,   375,   376,   377,
      27,    32,    33,    34,    35,    32,    33,    34,    35,    -1,
      41,    -1,    -1,    -1,    41,    -1,    -1,    -1,    95,    -1,
      -1,    48,    49,   228,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,   125,   132,
      81,    82,    -1,    -1,    81,    82,    -1,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   301,   302,   181,   182,
     183,    -1,    -1,   180,    76,    77,    78,    79,    80,   314,
      -1,   316,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   332,   333,   334,
     335,   336,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   348,    -1,   228,    -1,   352,    -1,   226,
     227,    -1,    -1,   230,   359,   360,   361,   362,   363,    -1,
      -1,    -1,   367,    -1,    -1,   370,    -1,    -1,   373,    -1,
     375,   376,   377,    -1,    -1,   181,   182,   183,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    -1,
     267,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,   302,
      -1,    -1,   228,    -1,    -1,    -1,   303,   304,    -1,    -1,
      -1,   314,    -1,   316,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,    -1,   332,
     333,   334,   335,   336,    -1,   338,    -1,    -1,    -1,    -1,
     337,    -1,    -1,   132,    -1,   348,    -1,    -1,    -1,   352,
      -1,    -1,    -1,    -1,    -1,    -1,   359,   360,   361,   362,
     363,    -1,    -1,    -1,   367,    -1,    -1,   370,    -1,   228,
     373,    -1,   375,   376,   377,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,
     316,    -1,   181,   182,   183,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,   333,   334,   335,
     336,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,    -1,    -1,    -1,   352,    -1,    -1,    -1,
      -1,    -1,   132,   359,   360,   361,   362,   363,    -1,   228,
      -1,   367,   301,   302,   370,    -1,    -1,   373,    -1,   375,
     376,   377,    -1,    -1,    -1,   314,    -1,   316,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   332,   333,   334,   335,   336,    -1,   338,
      -1,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,   348,
      -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,   363,    -1,    -1,    -1,   367,    -1,
      -1,   370,   301,   302,   373,   132,   375,   376,   377,    -1,
      -1,    -1,    -1,    -1,    -1,   314,    -1,   316,   228,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   332,   333,   334,   335,   336,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,
      -1,    -1,    -1,   352,   181,   182,   183,    -1,    -1,    -1,
     359,   360,   361,   362,   363,    -1,    -1,    -1,   367,    -1,
      -1,   370,    -1,    -1,   373,    -1,   375,   376,   377,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,   301,   302,    55,    56,    57,    58,    59,    60,    -1,
      -1,   228,    -1,    -1,   314,    -1,   316,    -1,    -1,    -1,
      -1,    -1,   322,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,   332,   333,   334,   335,   336,    -1,   338,    -1,
      -1,   181,   182,   183,   132,    -1,    -1,    -1,   348,    -1,
      -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,   359,
     360,   361,   362,   363,    -1,    -1,    -1,   367,    -1,    -1,
     370,    -1,    -1,   373,    -1,   375,   376,   377,    -1,    -1,
      -1,    -1,    -1,    -1,   301,   302,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,   314,    -1,   316,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,   333,   334,   335,   336,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   348,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,
      -1,    -1,   359,   360,   361,   362,   363,    -1,    -1,    -1,
     367,    -1,    -1,   370,    -1,    -1,   373,    -1,   375,   376,
     377,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,   316,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,   333,   334,   335,   336,    -1,   338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,
      -1,    -1,   352,   301,   302,    -1,    -1,    -1,    -1,   359,
     360,   361,   362,   363,    -1,    -1,   314,   367,   316,    -1,
     370,    -1,    -1,   373,   322,   375,   376,   377,    -1,    -1,
      -1,    -1,    -1,    -1,   332,   333,   334,    -1,   336,    -1,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     348,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,   359,   360,   361,   362,   363,     5,    -1,    -1,   367,
      -1,    -1,   370,    -1,    -1,   373,    -1,   375,   376,   377,
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
      -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,    82,
      83,    84,    85,    86,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    81,    82,    11,    12,    -1,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,     8,    48,    49,    11,    12,    -1,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    41,    81,    82,    -1,    -1,
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
      -1,    -1,    39,    -1,    41,    81,    82,    -1,    -1,    -1,
       8,    48,    49,    11,    12,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    81,    82,    -1,    -1,    -1,     8,
      48,    49,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    41,    81,    82,    -1,    -1,    -1,     8,    48,
      49,    11,    12,    -1,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    81,    82,    -1,    -1,    -1,     8,    48,    49,
      11,    12,    -1,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    27,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      41,    81,    82,    41,    -1,    -1,    44,    48,    49,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    38,    -1,    -1,
      81,    82,    43,    81,    82,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      38,    50,    51,    52,    -1,    43,    55,    56,    57,    58,
      59,    60,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    38,    50,    51,    52,    -1,    43,    55,
      56,    57,    58,    59,    60,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    38,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    38,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      38,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    38,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    38,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    38,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    38,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    42,    74,    75,    76,    77,    78,    79,    80,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    74,    75,    76,    77,    78,    79,    80,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    74,    75,    76,    77,    78,    79,
      80,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
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
     159,   160,   161,    38,    38,    43,    41,   133,   134,   151,
     152,   133,   134,    41,   125,    41,   125,   135,   151,    82,
     125,   125,    85,    86,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    74,    75,    76,    77,
      78,    79,    80,    24,    25,    41,    44,   133,   134,    37,
      45,    47,    39,   151,    41,    45,    41,    38,    43,   125,
      42,    43,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     133,   134,   133,   134,   125,    31,   151,   135,   151,     8,
      11,    12,    14,    15,    16,    18,    19,    20,    21,    22,
      23,    48,    49,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   126,   130,   131,   138,   139,   141,
     145,   146,   147,   148,   151,   125,   151,   125,   125,    42,
     125,    42,    38,    37,   125,    47,    37,    37,    37,    37,
      37,    78,   154,   157,   159,    46,    47,    47,    47,   125,
     130,   141,   141,    40,   103,    47,    47,    47,     6,     7,
       9,    10,    44,    48,    49,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    42,    43,    42,   135,
      47,   125,   125,   123,   126,   141,   151,   125,    46,    46,
      46,    47,    37,    37,    37,    37,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,    42,   125,    37,
      38,    38,    38,    47,    17,    43,    38,   125,   125,   125,
     125,    37,    38,   135,    39,   103,    39,   103,   124,   125,
     125,   151,    39,    38,    38,    43,    38,    43,    38,    43,
     135,    38,   102,    13,   102,    47,    38,    17,   102,    47,
      47,   135,    47,   135,    47,   135,    38,    40,    39,   103,
      40,   123,    39,   103,   125,    40,    38,    38,    38,    13,
     102,    38,   102,    38,    47,    47,    47,    39,   103,    40,
      39,   103,    40,    39,   103,   102,   102,   102,    40,    40,
      40
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    93,    94,    94,    95,    95,    95,    95,    96,    97,
      97,    97,    98,    99,   100,   101,   101,   101,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   106,   107,   107,   108,   109,   109,   110,
     110,   111,   112,   112,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   117,   118,   118,   118,
     119,   120,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   130,   130,   130,   130,   131,
     131,   131,   131,   132,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   136,   136,   137,   138,   139,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     1,     1,     3,     1,
       1,     1,     5,     4,     7,     3,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     6,     8,     6,     3,     8,     6,     8,
       6,     2,     7,     5,    11,     9,     9,     7,     7,     5,
      11,     9,     9,    11,     7,     9,     7,     3,     3,     3,
       2,     2,     2,     3,     2,     1,     0,     1,     0,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     2,     2,     3,     3,     4,     6,     8,
       9,     3,     1,     0,     2,     3,     3,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     7,     2,     2,     1,     1,     1,     1
  };




#if S2DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   154,   154,   155,   159,   161,   163,   165,   170,   175,
     176,   177,   181,   186,   191,   196,   198,   201,   205,   207,
     210,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     236,   238,   243,   248,   253,   255,   260,   265,   267,   272,
     274,   279,   284,   286,   295,   297,   303,   309,   320,   322,
     330,   332,   341,   343,   345,   351,   360,   365,   367,   369,
     374,   379,   384,   389,   391,   396,   397,   401,   402,   406,
     407,   408,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   430,   431,   432,
     433,   434,   435,   436,   437,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   487,   488,   489,   490,   494,
     495,   496,   497,   501,   502,   503,   504,   508,   510,   515,
     517,   522,   524,   527,   531,   533,   538,   543,   548,   553,
     558,   559,   560,   561,   562,   563,   564,   565,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587
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


#line 13 "S2.parser.ypp"
} // S2
#line 4225 "./S2/compiler_parser.cpp"

#line 589 "S2.parser.ypp"


void S2::parser::error(const gsc::location& loc, const std::string& msg)
{
    throw gsc::comp_error(loc, msg);
}
