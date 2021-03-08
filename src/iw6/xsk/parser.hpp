// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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


/**
 ** \file parser.hpp
 ** Define the xsk::gsc::iw6::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_IW6_PARSER_HPP_INCLUDED
# define YY_IW6_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 33 "parser.ypp"

#include "iw6.hpp"
typedef void *yyscan_t;
#define YY_DECL xsk::gsc::iw6::parser::symbol_type IW6lex(yyscan_t yyscanner, xsk::gsc::location& loc)

#line 55 "parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef IW6_ASSERT
# include <cassert>
# define IW6_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef IW6DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define IW6DEBUG 1
#  else
#   define IW6DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define IW6DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined IW6DEBUG */

#line 13 "parser.ypp"
namespace xsk { namespace gsc { namespace iw6 {
#line 198 "parser.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef IW6STYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      IW6_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      IW6_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      IW6_ASSERT (!yytypeid_);
      IW6_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      IW6_ASSERT (!yytypeid_);
      IW6_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      IW6_ASSERT (!yytypeid_);
      IW6_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      IW6_ASSERT (yytypeid_);
      IW6_ASSERT (*yytypeid_ == typeid (T));
      IW6_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      IW6_ASSERT (yytypeid_);
      IW6_ASSERT (*yytypeid_ == typeid (T));
      IW6_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      IW6_ASSERT (yytypeid_);
      IW6_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // anim
      char dummy1[sizeof (anim_ptr)];

      // animation
      char dummy2[sizeof (animation_ptr)];

      // animtree
      char dummy3[sizeof (animtree_ptr)];

      // constant
      char dummy4[sizeof (constant_ptr)];

      // define
      char dummy5[sizeof (define_ptr)];

      // empty_array
      char dummy6[sizeof (empty_array_ptr)];

      // expr_arguments
      // expr_arguments_filled
      // expr_arguments_empty
      char dummy7[sizeof (expr_arguments_ptr)];

      // expr_assign
      char dummy8[sizeof (expr_assign_ptr)];

      // expr_call
      // expr_call_thread
      // expr_call_childthread
      char dummy9[sizeof (expr_call_ptr)];

      // expr_call_function
      // expr_call_pointer
      char dummy10[sizeof (expr_call_type_ptr)];

      // for_stmt
      // for_expr
      // expr
      // expr_compare
      // expr_binary
      // expr_primitive
      char dummy11[sizeof (expr_ptr)];

      // false
      char dummy12[sizeof (false_ptr)];

      // file
      char dummy13[sizeof (file_ptr)];

      // neg_float
      // float
      char dummy14[sizeof (float_ptr)];

      // game
      char dummy15[sizeof (game_ptr)];

      // include
      char dummy16[sizeof (include_ptr)];

      // neg_integer
      // integer
      char dummy17[sizeof (integer_ptr)];

      // istring
      char dummy18[sizeof (istring_ptr)];

      // level
      char dummy19[sizeof (level_ptr)];

      // name
      char dummy20[sizeof (name_ptr)];

      // expr_function
      // expr_add_array
      // expr_array
      // expr_field
      // expr_size
      // object
      char dummy21[sizeof (node_ptr)];

      // parameters
      char dummy22[sizeof (parameters_ptr)];

      // program
      char dummy23[sizeof (program_ptr)];

      // self
      char dummy24[sizeof (self_ptr)];

      // "file path"
      // "identifier"
      // "string literal"
      // "localized string"
      // "float"
      // "int"
      char dummy25[sizeof (std::string)];

      // stmt_assign
      char dummy26[sizeof (stmt_assign_ptr)];

      // stmt_break
      char dummy27[sizeof (stmt_break_ptr)];

      // stmt_call
      char dummy28[sizeof (stmt_call_ptr)];

      // stmt_case
      char dummy29[sizeof (stmt_case_ptr)];

      // stmt_continue
      char dummy30[sizeof (stmt_continue_ptr)];

      // stmt_default
      char dummy31[sizeof (stmt_default_ptr)];

      // stmt_endon
      char dummy32[sizeof (stmt_endon_ptr)];

      // stmt_for
      char dummy33[sizeof (stmt_for_ptr)];

      // stmt_foreach
      char dummy34[sizeof (stmt_foreach_ptr)];

      // stmt_if
      char dummy35[sizeof (stmt_if_ptr)];

      // stmt_ifelse
      char dummy36[sizeof (stmt_ifelse_ptr)];

      // stmt_block
      // stmt_list
      char dummy37[sizeof (stmt_list_ptr)];

      // stmt_notify
      char dummy38[sizeof (stmt_notify_ptr)];

      // stmt
      char dummy39[sizeof (stmt_ptr)];

      // stmt_return
      char dummy40[sizeof (stmt_return_ptr)];

      // stmt_switch
      char dummy41[sizeof (stmt_switch_ptr)];

      // stmt_wait
      char dummy42[sizeof (stmt_wait_ptr)];

      // stmt_waittill
      char dummy43[sizeof (stmt_waittill_ptr)];

      // stmt_waittillframeend
      char dummy44[sizeof (stmt_waittillframeend_ptr)];

      // stmt_waittillmatch
      char dummy45[sizeof (stmt_waittillmatch_ptr)];

      // stmt_while
      char dummy46[sizeof (stmt_while_ptr)];

      // string
      char dummy47[sizeof (string_ptr)];

      // thisthread
      char dummy48[sizeof (thisthread_ptr)];

      // thread
      char dummy49[sizeof (thread_ptr)];

      // true
      char dummy50[sizeof (true_ptr)];

      // undefined
      char dummy51[sizeof (undefined_ptr)];

      // usingtree
      char dummy52[sizeof (usingtree_ptr)];

      // vector
      char dummy53[sizeof (vector_ptr)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef IW6STYPE semantic_type;
#endif
    /// Symbol locations.
    typedef xsk::gsc::location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        IW6EMPTY = -2,
    IW6EOF = 0,                    // "end of file"
    IW6error = 1,                  // error
    IW6UNDEF = 2,                  // "invalid token"
    INCLUDE = 3,                   // "#include"
    USINGTREE = 4,                 // "#using_animtree"
    ANIMTREE = 5,                  // "#animtree"
    ENDON = 6,                     // "endon"
    NOTIFY = 7,                    // "notify"
    WAIT = 8,                      // "wait"
    WAITTILL = 9,                  // "waittill"
    WAITTILLMATCH = 10,            // "waittillmatch"
    WAITTILLFRAMEEND = 11,         // "waittillframeend"
    IF = 12,                       // "if"
    ELSE = 13,                     // "else"
    WHILE = 14,                    // "while"
    FOR = 15,                      // "for"
    FOREACH = 16,                  // "foreach"
    IN = 17,                       // "in"
    SWITCH = 18,                   // "switch"
    CASE = 19,                     // "case"
    DEFAULT = 20,                  // "default"
    BREAK = 21,                    // "break"
    CONTINUE = 22,                 // "continue"
    RETURN = 23,                   // "return"
    THREAD = 24,                   // "thread"
    CHILDTHREAD = 25,              // "childthread"
    THISTHREAD = 26,               // "thisthread"
    CALL = 27,                     // "call"
    TRUE = 28,                     // "true"
    FALSE = 29,                    // "false"
    UNDEFINED = 30,                // "undefined"
    SIZE = 31,                     // "size"
    GAME = 32,                     // "game"
    SELF = 33,                     // "self"
    ANIM = 34,                     // "anim"
    LEVEL = 35,                    // "level"
    LPAREN = 36,                   // "("
    RPAREN = 37,                   // ")"
    LBRACE = 38,                   // "{"
    RBRACE = 39,                   // "}"
    LBRACKET = 40,                 // "["
    RBRACKET = 41,                 // "]"
    COMMA = 42,                    // ","
    DOT = 43,                      // "."
    DOUBLECOLON = 44,              // "::"
    COLON = 45,                    // ":"
    SEMICOLON = 46,                // ";"
    INCREMENT = 47,                // "++"
    DECREMENT = 48,                // "--"
    LSHIFT = 49,                   // "<<"
    RSHIFT = 50,                   // ">>"
    OR = 51,                       // "||"
    AND = 52,                      // "&&"
    EQUALITY = 53,                 // "=="
    INEQUALITY = 54,               // "!="
    LESS_EQUAL = 55,               // "<="
    GREATER_EQUAL = 56,            // ">="
    LESS = 57,                     // "<"
    GREATER = 58,                  // ">"
    NOT = 59,                      // "!"
    COMPLEMENT = 60,               // "~"
    ASSIGN = 61,                   // "="
    ASSIGN_ADD = 62,               // "+="
    ASSIGN_SUB = 63,               // "-="
    ASSIGN_MULT = 64,              // "*="
    ASSIGN_DIV = 65,               // "/="
    ASSIGN_MOD = 66,               // "%="
    ASSIGN_BITWISE_OR = 67,        // "|="
    ASSIGN_BITWISE_AND = 68,       // "&="
    ASSIGN_BITWISE_EXOR = 69,      // "^="
    ASSIGN_RSHIFT = 70,            // ">>="
    ASSIGN_LSHIFT = 71,            // "<<="
    BITWISE_OR = 72,               // "|"
    BITWISE_AND = 73,              // "&"
    BITWISE_EXOR = 74,             // "^"
    ADD = 75,                      // "+"
    SUB = 76,                      // "-"
    MULT = 77,                     // "*"
    DIV = 78,                      // "/"
    MOD = 79,                      // "%"
    FILE = 80,                     // "file path"
    NAME = 81,                     // "identifier"
    STRING = 82,                   // "string literal"
    ISTRING = 83,                  // "localized string"
    FLOAT = 84,                    // "float"
    INTEGER = 85,                  // "int"
    ADD_ARRAY = 86,                // ADD_ARRAY
    THEN = 87,                     // THEN
    NEG = 88,                      // NEG
    ANIMREF = 89,                  // ANIMREF
    PREINC = 90,                   // PREINC
    PREDEC = 91,                   // PREDEC
    POSTINC = 92,                  // POSTINC
    POSTDEC = 93                   // POSTDEC
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 94, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_INCLUDE = 3,                           // "#include"
        S_USINGTREE = 4,                         // "#using_animtree"
        S_ANIMTREE = 5,                          // "#animtree"
        S_ENDON = 6,                             // "endon"
        S_NOTIFY = 7,                            // "notify"
        S_WAIT = 8,                              // "wait"
        S_WAITTILL = 9,                          // "waittill"
        S_WAITTILLMATCH = 10,                    // "waittillmatch"
        S_WAITTILLFRAMEEND = 11,                 // "waittillframeend"
        S_IF = 12,                               // "if"
        S_ELSE = 13,                             // "else"
        S_WHILE = 14,                            // "while"
        S_FOR = 15,                              // "for"
        S_FOREACH = 16,                          // "foreach"
        S_IN = 17,                               // "in"
        S_SWITCH = 18,                           // "switch"
        S_CASE = 19,                             // "case"
        S_DEFAULT = 20,                          // "default"
        S_BREAK = 21,                            // "break"
        S_CONTINUE = 22,                         // "continue"
        S_RETURN = 23,                           // "return"
        S_THREAD = 24,                           // "thread"
        S_CHILDTHREAD = 25,                      // "childthread"
        S_THISTHREAD = 26,                       // "thisthread"
        S_CALL = 27,                             // "call"
        S_TRUE = 28,                             // "true"
        S_FALSE = 29,                            // "false"
        S_UNDEFINED = 30,                        // "undefined"
        S_SIZE = 31,                             // "size"
        S_GAME = 32,                             // "game"
        S_SELF = 33,                             // "self"
        S_ANIM = 34,                             // "anim"
        S_LEVEL = 35,                            // "level"
        S_LPAREN = 36,                           // "("
        S_RPAREN = 37,                           // ")"
        S_LBRACE = 38,                           // "{"
        S_RBRACE = 39,                           // "}"
        S_LBRACKET = 40,                         // "["
        S_RBRACKET = 41,                         // "]"
        S_COMMA = 42,                            // ","
        S_DOT = 43,                              // "."
        S_DOUBLECOLON = 44,                      // "::"
        S_COLON = 45,                            // ":"
        S_SEMICOLON = 46,                        // ";"
        S_INCREMENT = 47,                        // "++"
        S_DECREMENT = 48,                        // "--"
        S_LSHIFT = 49,                           // "<<"
        S_RSHIFT = 50,                           // ">>"
        S_OR = 51,                               // "||"
        S_AND = 52,                              // "&&"
        S_EQUALITY = 53,                         // "=="
        S_INEQUALITY = 54,                       // "!="
        S_LESS_EQUAL = 55,                       // "<="
        S_GREATER_EQUAL = 56,                    // ">="
        S_LESS = 57,                             // "<"
        S_GREATER = 58,                          // ">"
        S_NOT = 59,                              // "!"
        S_COMPLEMENT = 60,                       // "~"
        S_ASSIGN = 61,                           // "="
        S_ASSIGN_ADD = 62,                       // "+="
        S_ASSIGN_SUB = 63,                       // "-="
        S_ASSIGN_MULT = 64,                      // "*="
        S_ASSIGN_DIV = 65,                       // "/="
        S_ASSIGN_MOD = 66,                       // "%="
        S_ASSIGN_BITWISE_OR = 67,                // "|="
        S_ASSIGN_BITWISE_AND = 68,               // "&="
        S_ASSIGN_BITWISE_EXOR = 69,              // "^="
        S_ASSIGN_RSHIFT = 70,                    // ">>="
        S_ASSIGN_LSHIFT = 71,                    // "<<="
        S_BITWISE_OR = 72,                       // "|"
        S_BITWISE_AND = 73,                      // "&"
        S_BITWISE_EXOR = 74,                     // "^"
        S_ADD = 75,                              // "+"
        S_SUB = 76,                              // "-"
        S_MULT = 77,                             // "*"
        S_DIV = 78,                              // "/"
        S_MOD = 79,                              // "%"
        S_FILE = 80,                             // "file path"
        S_NAME = 81,                             // "identifier"
        S_STRING = 82,                           // "string literal"
        S_ISTRING = 83,                          // "localized string"
        S_FLOAT = 84,                            // "float"
        S_INTEGER = 85,                          // "int"
        S_ADD_ARRAY = 86,                        // ADD_ARRAY
        S_THEN = 87,                             // THEN
        S_NEG = 88,                              // NEG
        S_ANIMREF = 89,                          // ANIMREF
        S_PREINC = 90,                           // PREINC
        S_PREDEC = 91,                           // PREDEC
        S_POSTINC = 92,                          // POSTINC
        S_POSTDEC = 93,                          // POSTDEC
        S_YYACCEPT = 94,                         // $accept
        S_root = 95,                             // root
        S_program = 96,                          // program
        S_include = 97,                          // include
        S_define = 98,                           // define
        S_usingtree = 99,                        // usingtree
        S_constant = 100,                        // constant
        S_thread = 101,                          // thread
        S_parameters = 102,                      // parameters
        S_stmt = 103,                            // stmt
        S_stmt_block = 104,                      // stmt_block
        S_stmt_list = 105,                       // stmt_list
        S_stmt_call = 106,                       // stmt_call
        S_stmt_assign = 107,                     // stmt_assign
        S_stmt_endon = 108,                      // stmt_endon
        S_stmt_notify = 109,                     // stmt_notify
        S_stmt_wait = 110,                       // stmt_wait
        S_stmt_waittill = 111,                   // stmt_waittill
        S_stmt_waittillmatch = 112,              // stmt_waittillmatch
        S_stmt_waittillframeend = 113,           // stmt_waittillframeend
        S_stmt_if = 114,                         // stmt_if
        S_stmt_ifelse = 115,                     // stmt_ifelse
        S_stmt_while = 116,                      // stmt_while
        S_stmt_for = 117,                        // stmt_for
        S_stmt_foreach = 118,                    // stmt_foreach
        S_stmt_switch = 119,                     // stmt_switch
        S_stmt_case = 120,                       // stmt_case
        S_stmt_default = 121,                    // stmt_default
        S_stmt_break = 122,                      // stmt_break
        S_stmt_continue = 123,                   // stmt_continue
        S_stmt_return = 124,                     // stmt_return
        S_for_stmt = 125,                        // for_stmt
        S_for_expr = 126,                        // for_expr
        S_expr = 127,                            // expr
        S_expr_assign = 128,                     // expr_assign
        S_expr_compare = 129,                    // expr_compare
        S_expr_binary = 130,                     // expr_binary
        S_expr_primitive = 131,                  // expr_primitive
        S_expr_call = 132,                       // expr_call
        S_expr_call_thread = 133,                // expr_call_thread
        S_expr_call_childthread = 134,           // expr_call_childthread
        S_expr_call_function = 135,              // expr_call_function
        S_expr_call_pointer = 136,               // expr_call_pointer
        S_expr_arguments = 137,                  // expr_arguments
        S_expr_arguments_filled = 138,           // expr_arguments_filled
        S_expr_arguments_empty = 139,            // expr_arguments_empty
        S_expr_function = 140,                   // expr_function
        S_expr_add_array = 141,                  // expr_add_array
        S_expr_array = 142,                      // expr_array
        S_expr_field = 143,                      // expr_field
        S_expr_size = 144,                       // expr_size
        S_object = 145,                          // object
        S_thisthread = 146,                      // thisthread
        S_empty_array = 147,                     // empty_array
        S_undefined = 148,                       // undefined
        S_game = 149,                            // game
        S_self = 150,                            // self
        S_anim = 151,                            // anim
        S_level = 152,                           // level
        S_animation = 153,                       // animation
        S_animtree = 154,                        // animtree
        S_name = 155,                            // name
        S_file = 156,                            // file
        S_istring = 157,                         // istring
        S_string = 158,                          // string
        S_vector = 159,                          // vector
        S_neg_float = 160,                       // neg_float
        S_neg_integer = 161,                     // neg_integer
        S_float = 162,                           // float
        S_integer = 163,                         // integer
        S_false = 164,                           // false
        S_true = 165                             // true
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_anim: // anim
        value.move< anim_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_animation: // animation
        value.move< animation_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_animtree: // animtree
        value.move< animtree_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< constant_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_define: // define
        value.move< define_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.move< empty_array_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_filled: // expr_arguments_filled
      case symbol_kind::S_expr_arguments_empty: // expr_arguments_empty
        value.move< expr_arguments_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< expr_assign_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.move< expr_call_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< expr_call_type_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< expr_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_false: // false
        value.move< false_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_file: // file
        value.move< file_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.move< float_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_game: // game
        value.move< game_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_include: // include
        value.move< include_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.move< integer_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_istring: // istring
        value.move< istring_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_level: // level
        value.move< level_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_name: // name
        value.move< name_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
        value.move< node_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< parameters_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< program_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_self: // self
        value.move< self_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_FILE: // "file path"
      case symbol_kind::S_NAME: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "int"
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< stmt_assign_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< stmt_break_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< stmt_call_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< stmt_case_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< stmt_continue_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< stmt_default_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< stmt_endon_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< stmt_for_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< stmt_foreach_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< stmt_if_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< stmt_ifelse_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
        value.move< stmt_list_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< stmt_notify_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< stmt_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< stmt_return_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< stmt_switch_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< stmt_wait_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< stmt_waittill_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< stmt_waittillframeend_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< stmt_waittillmatch_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< stmt_while_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_string: // string
        value.move< string_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.move< thisthread_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.move< thread_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_true: // true
        value.move< true_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_undefined: // undefined
        value.move< undefined_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.move< usingtree_ptr > (std::move (that.value));
        break;

      case symbol_kind::S_vector: // vector
        value.move< vector_ptr > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, anim_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const anim_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, animation_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const animation_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, animtree_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const animtree_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, constant_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const constant_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, define_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const define_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, empty_array_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const empty_array_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expr_arguments_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expr_arguments_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expr_assign_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expr_assign_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expr_call_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expr_call_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expr_call_type_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expr_call_type_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expr_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expr_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, false_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const false_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, file_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const file_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, game_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const game_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, include_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const include_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, integer_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const integer_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, istring_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const istring_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, level_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const level_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, name_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const name_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, node_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const node_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, parameters_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const parameters_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, program_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const program_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, self_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const self_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_assign_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_assign_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_break_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_break_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_call_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_call_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_case_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_case_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_continue_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_continue_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_default_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_default_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_endon_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_endon_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_for_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_for_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_foreach_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_foreach_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_if_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_if_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_ifelse_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_ifelse_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_list_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_list_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_notify_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_notify_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_return_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_return_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_switch_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_switch_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_wait_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_wait_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_waittill_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_waittill_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_waittillframeend_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_waittillframeend_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_waittillmatch_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_waittillmatch_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, stmt_while_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const stmt_while_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, string_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const string_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, thisthread_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const thisthread_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, thread_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const thread_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, true_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const true_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, undefined_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const undefined_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, usingtree_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const usingtree_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector_ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector_ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_anim: // anim
        value.template destroy< anim_ptr > ();
        break;

      case symbol_kind::S_animation: // animation
        value.template destroy< animation_ptr > ();
        break;

      case symbol_kind::S_animtree: // animtree
        value.template destroy< animtree_ptr > ();
        break;

      case symbol_kind::S_constant: // constant
        value.template destroy< constant_ptr > ();
        break;

      case symbol_kind::S_define: // define
        value.template destroy< define_ptr > ();
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.template destroy< empty_array_ptr > ();
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_filled: // expr_arguments_filled
      case symbol_kind::S_expr_arguments_empty: // expr_arguments_empty
        value.template destroy< expr_arguments_ptr > ();
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.template destroy< expr_assign_ptr > ();
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.template destroy< expr_call_ptr > ();
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.template destroy< expr_call_type_ptr > ();
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.template destroy< expr_ptr > ();
        break;

      case symbol_kind::S_false: // false
        value.template destroy< false_ptr > ();
        break;

      case symbol_kind::S_file: // file
        value.template destroy< file_ptr > ();
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.template destroy< float_ptr > ();
        break;

      case symbol_kind::S_game: // game
        value.template destroy< game_ptr > ();
        break;

      case symbol_kind::S_include: // include
        value.template destroy< include_ptr > ();
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.template destroy< integer_ptr > ();
        break;

      case symbol_kind::S_istring: // istring
        value.template destroy< istring_ptr > ();
        break;

      case symbol_kind::S_level: // level
        value.template destroy< level_ptr > ();
        break;

      case symbol_kind::S_name: // name
        value.template destroy< name_ptr > ();
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
        value.template destroy< node_ptr > ();
        break;

      case symbol_kind::S_parameters: // parameters
        value.template destroy< parameters_ptr > ();
        break;

      case symbol_kind::S_program: // program
        value.template destroy< program_ptr > ();
        break;

      case symbol_kind::S_self: // self
        value.template destroy< self_ptr > ();
        break;

      case symbol_kind::S_FILE: // "file path"
      case symbol_kind::S_NAME: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "int"
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.template destroy< stmt_assign_ptr > ();
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.template destroy< stmt_break_ptr > ();
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.template destroy< stmt_call_ptr > ();
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.template destroy< stmt_case_ptr > ();
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.template destroy< stmt_continue_ptr > ();
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.template destroy< stmt_default_ptr > ();
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.template destroy< stmt_endon_ptr > ();
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.template destroy< stmt_for_ptr > ();
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.template destroy< stmt_foreach_ptr > ();
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.template destroy< stmt_if_ptr > ();
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.template destroy< stmt_ifelse_ptr > ();
        break;

      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
        value.template destroy< stmt_list_ptr > ();
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.template destroy< stmt_notify_ptr > ();
        break;

      case symbol_kind::S_stmt: // stmt
        value.template destroy< stmt_ptr > ();
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.template destroy< stmt_return_ptr > ();
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.template destroy< stmt_switch_ptr > ();
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.template destroy< stmt_wait_ptr > ();
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.template destroy< stmt_waittill_ptr > ();
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.template destroy< stmt_waittillframeend_ptr > ();
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.template destroy< stmt_waittillmatch_ptr > ();
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.template destroy< stmt_while_ptr > ();
        break;

      case symbol_kind::S_string: // string
        value.template destroy< string_ptr > ();
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.template destroy< thisthread_ptr > ();
        break;

      case symbol_kind::S_thread: // thread
        value.template destroy< thread_ptr > ();
        break;

      case symbol_kind::S_true: // true
        value.template destroy< true_ptr > ();
        break;

      case symbol_kind::S_undefined: // undefined
        value.template destroy< undefined_ptr > ();
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.template destroy< usingtree_ptr > ();
        break;

      case symbol_kind::S_vector: // vector
        value.template destroy< vector_ptr > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {
        IW6_ASSERT (tok == token::IW6EOF
                   || (token::IW6error <= tok && tok <= token::MOD)
                   || (token::ADD_ARRAY <= tok && tok <= token::POSTDEC));
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        IW6_ASSERT ((token::FILE <= tok && tok <= token::INTEGER));
      }
    };

    /// Build a parser object.
    parser (yyscan_t yyscanner_yyarg, xsk::gsc::location& loc_yyarg, xsk::gsc::program_ptr& ast_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if IW6DEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IW6EOF (location_type l)
      {
        return symbol_type (token::IW6EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_IW6EOF (const location_type& l)
      {
        return symbol_type (token::IW6EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IW6error (location_type l)
      {
        return symbol_type (token::IW6error, std::move (l));
      }
#else
      static
      symbol_type
      make_IW6error (const location_type& l)
      {
        return symbol_type (token::IW6error, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IW6UNDEF (location_type l)
      {
        return symbol_type (token::IW6UNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_IW6UNDEF (const location_type& l)
      {
        return symbol_type (token::IW6UNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCLUDE (location_type l)
      {
        return symbol_type (token::INCLUDE, std::move (l));
      }
#else
      static
      symbol_type
      make_INCLUDE (const location_type& l)
      {
        return symbol_type (token::INCLUDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USINGTREE (location_type l)
      {
        return symbol_type (token::USINGTREE, std::move (l));
      }
#else
      static
      symbol_type
      make_USINGTREE (const location_type& l)
      {
        return symbol_type (token::USINGTREE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANIMTREE (location_type l)
      {
        return symbol_type (token::ANIMTREE, std::move (l));
      }
#else
      static
      symbol_type
      make_ANIMTREE (const location_type& l)
      {
        return symbol_type (token::ANIMTREE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDON (location_type l)
      {
        return symbol_type (token::ENDON, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDON (const location_type& l)
      {
        return symbol_type (token::ENDON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOTIFY (location_type l)
      {
        return symbol_type (token::NOTIFY, std::move (l));
      }
#else
      static
      symbol_type
      make_NOTIFY (const location_type& l)
      {
        return symbol_type (token::NOTIFY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAIT (location_type l)
      {
        return symbol_type (token::WAIT, std::move (l));
      }
#else
      static
      symbol_type
      make_WAIT (const location_type& l)
      {
        return symbol_type (token::WAIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAITTILL (location_type l)
      {
        return symbol_type (token::WAITTILL, std::move (l));
      }
#else
      static
      symbol_type
      make_WAITTILL (const location_type& l)
      {
        return symbol_type (token::WAITTILL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAITTILLMATCH (location_type l)
      {
        return symbol_type (token::WAITTILLMATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_WAITTILLMATCH (const location_type& l)
      {
        return symbol_type (token::WAITTILLMATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAITTILLFRAMEEND (location_type l)
      {
        return symbol_type (token::WAITTILLFRAMEEND, std::move (l));
      }
#else
      static
      symbol_type
      make_WAITTILLFRAMEEND (const location_type& l)
      {
        return symbol_type (token::WAITTILLFRAMEEND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOREACH (location_type l)
      {
        return symbol_type (token::FOREACH, std::move (l));
      }
#else
      static
      symbol_type
      make_FOREACH (const location_type& l)
      {
        return symbol_type (token::FOREACH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (location_type l)
      {
        return symbol_type (token::DEFAULT, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const location_type& l)
      {
        return symbol_type (token::DEFAULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THREAD (location_type l)
      {
        return symbol_type (token::THREAD, std::move (l));
      }
#else
      static
      symbol_type
      make_THREAD (const location_type& l)
      {
        return symbol_type (token::THREAD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHILDTHREAD (location_type l)
      {
        return symbol_type (token::CHILDTHREAD, std::move (l));
      }
#else
      static
      symbol_type
      make_CHILDTHREAD (const location_type& l)
      {
        return symbol_type (token::CHILDTHREAD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THISTHREAD (location_type l)
      {
        return symbol_type (token::THISTHREAD, std::move (l));
      }
#else
      static
      symbol_type
      make_THISTHREAD (const location_type& l)
      {
        return symbol_type (token::THISTHREAD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALL (location_type l)
      {
        return symbol_type (token::CALL, std::move (l));
      }
#else
      static
      symbol_type
      make_CALL (const location_type& l)
      {
        return symbol_type (token::CALL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDEFINED (location_type l)
      {
        return symbol_type (token::UNDEFINED, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDEFINED (const location_type& l)
      {
        return symbol_type (token::UNDEFINED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (location_type l)
      {
        return symbol_type (token::SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const location_type& l)
      {
        return symbol_type (token::SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GAME (location_type l)
      {
        return symbol_type (token::GAME, std::move (l));
      }
#else
      static
      symbol_type
      make_GAME (const location_type& l)
      {
        return symbol_type (token::GAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELF (location_type l)
      {
        return symbol_type (token::SELF, std::move (l));
      }
#else
      static
      symbol_type
      make_SELF (const location_type& l)
      {
        return symbol_type (token::SELF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANIM (location_type l)
      {
        return symbol_type (token::ANIM, std::move (l));
      }
#else
      static
      symbol_type
      make_ANIM (const location_type& l)
      {
        return symbol_type (token::ANIM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEVEL (location_type l)
      {
        return symbol_type (token::LEVEL, std::move (l));
      }
#else
      static
      symbol_type
      make_LEVEL (const location_type& l)
      {
        return symbol_type (token::LEVEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLECOLON (location_type l)
      {
        return symbol_type (token::DOUBLECOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLECOLON (const location_type& l)
      {
        return symbol_type (token::DOUBLECOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCREMENT (location_type l)
      {
        return symbol_type (token::INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_INCREMENT (const location_type& l)
      {
        return symbol_type (token::INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECREMENT (location_type l)
      {
        return symbol_type (token::DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DECREMENT (const location_type& l)
      {
        return symbol_type (token::DECREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSHIFT (location_type l)
      {
        return symbol_type (token::LSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LSHIFT (const location_type& l)
      {
        return symbol_type (token::LSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSHIFT (location_type l)
      {
        return symbol_type (token::RSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_RSHIFT (const location_type& l)
      {
        return symbol_type (token::RSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALITY (location_type l)
      {
        return symbol_type (token::EQUALITY, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUALITY (const location_type& l)
      {
        return symbol_type (token::EQUALITY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INEQUALITY (location_type l)
      {
        return symbol_type (token::INEQUALITY, std::move (l));
      }
#else
      static
      symbol_type
      make_INEQUALITY (const location_type& l)
      {
        return symbol_type (token::INEQUALITY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_EQUAL (location_type l)
      {
        return symbol_type (token::LESS_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_EQUAL (const location_type& l)
      {
        return symbol_type (token::LESS_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_EQUAL (location_type l)
      {
        return symbol_type (token::GREATER_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_EQUAL (const location_type& l)
      {
        return symbol_type (token::GREATER_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEMENT (location_type l)
      {
        return symbol_type (token::COMPLEMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMPLEMENT (const location_type& l)
      {
        return symbol_type (token::COMPLEMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_ADD (location_type l)
      {
        return symbol_type (token::ASSIGN_ADD, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_ADD (const location_type& l)
      {
        return symbol_type (token::ASSIGN_ADD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_SUB (location_type l)
      {
        return symbol_type (token::ASSIGN_SUB, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_SUB (const location_type& l)
      {
        return symbol_type (token::ASSIGN_SUB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_MULT (location_type l)
      {
        return symbol_type (token::ASSIGN_MULT, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_MULT (const location_type& l)
      {
        return symbol_type (token::ASSIGN_MULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_DIV (location_type l)
      {
        return symbol_type (token::ASSIGN_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_DIV (const location_type& l)
      {
        return symbol_type (token::ASSIGN_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_MOD (location_type l)
      {
        return symbol_type (token::ASSIGN_MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_MOD (const location_type& l)
      {
        return symbol_type (token::ASSIGN_MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BITWISE_OR (location_type l)
      {
        return symbol_type (token::ASSIGN_BITWISE_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BITWISE_OR (const location_type& l)
      {
        return symbol_type (token::ASSIGN_BITWISE_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BITWISE_AND (location_type l)
      {
        return symbol_type (token::ASSIGN_BITWISE_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BITWISE_AND (const location_type& l)
      {
        return symbol_type (token::ASSIGN_BITWISE_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BITWISE_EXOR (location_type l)
      {
        return symbol_type (token::ASSIGN_BITWISE_EXOR, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BITWISE_EXOR (const location_type& l)
      {
        return symbol_type (token::ASSIGN_BITWISE_EXOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_RSHIFT (location_type l)
      {
        return symbol_type (token::ASSIGN_RSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_RSHIFT (const location_type& l)
      {
        return symbol_type (token::ASSIGN_RSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_LSHIFT (location_type l)
      {
        return symbol_type (token::ASSIGN_LSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_LSHIFT (const location_type& l)
      {
        return symbol_type (token::ASSIGN_LSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITWISE_OR (location_type l)
      {
        return symbol_type (token::BITWISE_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_BITWISE_OR (const location_type& l)
      {
        return symbol_type (token::BITWISE_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITWISE_AND (location_type l)
      {
        return symbol_type (token::BITWISE_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_BITWISE_AND (const location_type& l)
      {
        return symbol_type (token::BITWISE_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BITWISE_EXOR (location_type l)
      {
        return symbol_type (token::BITWISE_EXOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BITWISE_EXOR (const location_type& l)
      {
        return symbol_type (token::BITWISE_EXOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (location_type l)
      {
        return symbol_type (token::ADD, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const location_type& l)
      {
        return symbol_type (token::ADD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (location_type l)
      {
        return symbol_type (token::SUB, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB (const location_type& l)
      {
        return symbol_type (token::SUB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (location_type l)
      {
        return symbol_type (token::MULT, std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const location_type& l)
      {
        return symbol_type (token::MULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILE (std::string v, location_type l)
      {
        return symbol_type (token::FILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v, location_type l)
      {
        return symbol_type (token::NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ISTRING (std::string v, location_type l)
      {
        return symbol_type (token::ISTRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ISTRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ISTRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ARRAY (location_type l)
      {
        return symbol_type (token::ADD_ARRAY, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_ARRAY (const location_type& l)
      {
        return symbol_type (token::ADD_ARRAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (location_type l)
      {
        return symbol_type (token::THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const location_type& l)
      {
        return symbol_type (token::THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANIMREF (location_type l)
      {
        return symbol_type (token::ANIMREF, std::move (l));
      }
#else
      static
      symbol_type
      make_ANIMREF (const location_type& l)
      {
        return symbol_type (token::ANIMREF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREINC (location_type l)
      {
        return symbol_type (token::PREINC, std::move (l));
      }
#else
      static
      symbol_type
      make_PREINC (const location_type& l)
      {
        return symbol_type (token::PREINC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREDEC (location_type l)
      {
        return symbol_type (token::PREDEC, std::move (l));
      }
#else
      static
      symbol_type
      make_PREDEC (const location_type& l)
      {
        return symbol_type (token::PREDEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POSTINC (location_type l)
      {
        return symbol_type (token::POSTINC, std::move (l));
      }
#else
      static
      symbol_type
      make_POSTINC (const location_type& l)
      {
        return symbol_type (token::POSTINC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POSTDEC (location_type l)
      {
        return symbol_type (token::POSTDEC, std::move (l));
      }
#else
      static
      symbol_type
      make_POSTDEC (const location_type& l)
      {
        return symbol_type (token::POSTDEC, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if IW6DEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1580,     ///< Last index in yytable_.
      yynnts_ = 72,  ///< Number of nonterminal symbols.
      yyfinal_ = 15 ///< Termination state number.
    };


    // User arguments.
    yyscan_t yyscanner;
    xsk::gsc::location& loc;
    xsk::gsc::program_ptr& ast;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_anim: // anim
        value.copy< anim_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animation: // animation
        value.copy< animation_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_animtree: // animtree
        value.copy< animtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant: // constant
        value.copy< constant_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_define: // define
        value.copy< define_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.copy< empty_array_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_filled: // expr_arguments_filled
      case symbol_kind::S_expr_arguments_empty: // expr_arguments_empty
        value.copy< expr_arguments_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.copy< expr_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.copy< expr_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.copy< expr_call_type_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.copy< expr_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_false: // false
        value.copy< false_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_file: // file
        value.copy< file_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.copy< float_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_game: // game
        value.copy< game_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_include: // include
        value.copy< include_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.copy< integer_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_istring: // istring
        value.copy< istring_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_level: // level
        value.copy< level_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_name: // name
        value.copy< name_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
        value.copy< node_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.copy< parameters_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.copy< program_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_self: // self
        value.copy< self_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FILE: // "file path"
      case symbol_kind::S_NAME: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "int"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.copy< stmt_assign_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.copy< stmt_break_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.copy< stmt_call_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.copy< stmt_case_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.copy< stmt_continue_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.copy< stmt_default_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.copy< stmt_endon_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.copy< stmt_for_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.copy< stmt_foreach_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.copy< stmt_if_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.copy< stmt_ifelse_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
        value.copy< stmt_list_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.copy< stmt_notify_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< stmt_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.copy< stmt_return_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.copy< stmt_switch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.copy< stmt_wait_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.copy< stmt_waittill_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.copy< stmt_waittillframeend_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.copy< stmt_waittillmatch_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.copy< stmt_while_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.copy< string_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.copy< thisthread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_thread: // thread
        value.copy< thread_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_true: // true
        value.copy< true_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_undefined: // undefined
        value.copy< undefined_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.copy< usingtree_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_vector: // vector
        value.copy< vector_ptr > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_anim: // anim
        value.move< anim_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_animation: // animation
        value.move< animation_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_animtree: // animtree
        value.move< animtree_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_constant: // constant
        value.move< constant_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_define: // define
        value.move< define_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_empty_array: // empty_array
        value.move< empty_array_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_arguments: // expr_arguments
      case symbol_kind::S_expr_arguments_filled: // expr_arguments_filled
      case symbol_kind::S_expr_arguments_empty: // expr_arguments_empty
        value.move< expr_arguments_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_assign: // expr_assign
        value.move< expr_assign_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_call: // expr_call
      case symbol_kind::S_expr_call_thread: // expr_call_thread
      case symbol_kind::S_expr_call_childthread: // expr_call_childthread
        value.move< expr_call_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_call_function: // expr_call_function
      case symbol_kind::S_expr_call_pointer: // expr_call_pointer
        value.move< expr_call_type_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_expr: // for_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_compare: // expr_compare
      case symbol_kind::S_expr_binary: // expr_binary
      case symbol_kind::S_expr_primitive: // expr_primitive
        value.move< expr_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_false: // false
        value.move< false_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_file: // file
        value.move< file_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_neg_float: // neg_float
      case symbol_kind::S_float: // float
        value.move< float_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_game: // game
        value.move< game_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_include: // include
        value.move< include_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_neg_integer: // neg_integer
      case symbol_kind::S_integer: // integer
        value.move< integer_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_istring: // istring
        value.move< istring_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_level: // level
        value.move< level_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_name: // name
        value.move< name_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_function: // expr_function
      case symbol_kind::S_expr_add_array: // expr_add_array
      case symbol_kind::S_expr_array: // expr_array
      case symbol_kind::S_expr_field: // expr_field
      case symbol_kind::S_expr_size: // expr_size
      case symbol_kind::S_object: // object
        value.move< node_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameters: // parameters
        value.move< parameters_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
        value.move< program_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_self: // self
        value.move< self_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FILE: // "file path"
      case symbol_kind::S_NAME: // "identifier"
      case symbol_kind::S_STRING: // "string literal"
      case symbol_kind::S_ISTRING: // "localized string"
      case symbol_kind::S_FLOAT: // "float"
      case symbol_kind::S_INTEGER: // "int"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_assign: // stmt_assign
        value.move< stmt_assign_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_break: // stmt_break
        value.move< stmt_break_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_call: // stmt_call
        value.move< stmt_call_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_case: // stmt_case
        value.move< stmt_case_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_continue: // stmt_continue
        value.move< stmt_continue_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_default: // stmt_default
        value.move< stmt_default_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_endon: // stmt_endon
        value.move< stmt_endon_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_for: // stmt_for
        value.move< stmt_for_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_foreach: // stmt_foreach
        value.move< stmt_foreach_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_if: // stmt_if
        value.move< stmt_if_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_ifelse: // stmt_ifelse
        value.move< stmt_ifelse_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
        value.move< stmt_list_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_notify: // stmt_notify
        value.move< stmt_notify_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< stmt_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_return: // stmt_return
        value.move< stmt_return_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_switch: // stmt_switch
        value.move< stmt_switch_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_wait: // stmt_wait
        value.move< stmt_wait_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_waittill: // stmt_waittill
        value.move< stmt_waittill_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_waittillframeend: // stmt_waittillframeend
        value.move< stmt_waittillframeend_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_waittillmatch: // stmt_waittillmatch
        value.move< stmt_waittillmatch_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_while: // stmt_while
        value.move< stmt_while_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string: // string
        value.move< string_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_thisthread: // thisthread
        value.move< thisthread_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_thread: // thread
        value.move< thread_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_true: // true
        value.move< true_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_undefined: // undefined
        value.move< undefined_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_usingtree: // usingtree
        value.move< usingtree_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_vector: // vector
        value.move< vector_ptr > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 13 "parser.ypp"
} } } // xsk::gsc::iw6
#line 4713 "parser.hpp"




#endif // !YY_IW6_PARSER_HPP_INCLUDED
