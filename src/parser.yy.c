/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"


#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast/api.h"
#include "errcodes.h"
#include "globals.h"
#include "io.h"
#include "lexer.h"
#include "parser.h"

FILE *yyin = NULL;


#line 90 "src/parser.yy.c"

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

#include "parser.yy.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "<eof>"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_BANG = 3,                 /* "!"  */
  YYSYMBOL_TOKEN_LOGICAL_UNEQUAL = 4,      /* "!="  */
  YYSYMBOL_TOKEN_LOGICAL_UNIDENTICAL = 5,  /* "!=="  */
  YYSYMBOL_TOKEN_DQUOTE = 6,               /* TOKEN_DQUOTE  */
  YYSYMBOL_7_ = 7,                         /* '"'  */
  YYSYMBOL_TOKEN_DOLLAR = 8,               /* "$"  */
  YYSYMBOL_TOKEN_PERCENT = 9,              /* "%"  */
  YYSYMBOL_TOKEN_MODULO_ASSIGN = 10,       /* "%="  */
  YYSYMBOL_TOKEN_AMPERSAND = 11,           /* "&"  */
  YYSYMBOL_TOKEN_LOGICAL_AND = 12,         /* "&&"  */
  YYSYMBOL_TOKEN_LOGICAL_AND_ASSIGN = 13,  /* "&&="  */
  YYSYMBOL_TOKEN_BITWISE_AND_ASSIGN = 14,  /* "&="  */
  YYSYMBOL_TOKEN_SQUOTE = 15,              /* "'"  */
  YYSYMBOL_TOKEN_LBRACE_PAREN = 16,        /* "("  */
  YYSYMBOL_TOKEN_RBRACE_PAREN = 17,        /* ")"  */
  YYSYMBOL_TOKEN_ASTERIX = 18,             /* "*"  */
  YYSYMBOL_TOKEN_EXPONENT = 19,            /* "**"  */
  YYSYMBOL_TOKEN_EXPONENT_ASSIGN = 20,     /* "**="  */
  YYSYMBOL_TOKEN_MULTIPLY_ASSIGN = 21,     /* "*="  */
  YYSYMBOL_TOKEN_PLUS = 22,                /* "+"  */
  YYSYMBOL_TOKEN_INCREMENT = 23,           /* "++"  */
  YYSYMBOL_TOKEN_ADD_ASSIGN = 24,          /* "+="  */
  YYSYMBOL_TOKEN_COMMA = 25,               /* ","  */
  YYSYMBOL_TOKEN_MINUS = 26,               /* "-"  */
  YYSYMBOL_TOKEN_DECREMENT = 27,           /* "--"  */
  YYSYMBOL_TOKEN_SUBSTRACT_ASSIGN = 28,    /* "-="  */
  YYSYMBOL_TOKEN_SARROW = 29,              /* "->"  */
  YYSYMBOL_TOKEN_DOT = 30,                 /* "."  */
  YYSYMBOL_TOKEN_ELIPSIS = 31,             /* "..."  */
  YYSYMBOL_TOKEN_FSLASH = 32,              /* "/"  */
  YYSYMBOL_TOKEN_FLOOR_DIVIDE = 33,        /* "//"  */
  YYSYMBOL_TOKEN_FLOOR_DIVIDE_ASSIGN = 34, /* "//="  */
  YYSYMBOL_TOKEN_DIVIDE_ASSIGN = 35,       /* "/="  */
  YYSYMBOL_TOKEN_COLON = 36,               /* ":"  */
  YYSYMBOL_TOKEN_DCOLON = 37,              /* "::"  */
  YYSYMBOL_TOKEN_SEMICOLON = 38,           /* ";"  */
  YYSYMBOL_TOKEN_LBRACE_ANGULAR = 39,      /* "<"  */
  YYSYMBOL_TOKEN_BITWISE_LSHIFT = 40,      /* "<<"  */
  YYSYMBOL_TOKEN_BITWISE_LSHIFT_ASSIGN = 41, /* "<<="  */
  YYSYMBOL_TOKEN_LOGICAL_LESSER_EQUAL = 42, /* "<="  */
  YYSYMBOL_TOKEN_ASSIGN = 43,              /* "="  */
  YYSYMBOL_TOKEN_LOGICAL_EQUAL = 44,       /* "=="  */
  YYSYMBOL_TOKEN_LOGICAL_IDENTICAL = 45,   /* "==="  */
  YYSYMBOL_TOKEN_DARROW = 46,              /* "=>"  */
  YYSYMBOL_TOKEN_RBRACE_ANGULAR = 47,      /* ">"  */
  YYSYMBOL_TOKEN_LOGICAL_GREATER_EQUAL = 48, /* ">="  */
  YYSYMBOL_TOKEN_BITWISE_RSHIFT = 49,      /* ">>"  */
  YYSYMBOL_TOKEN_BITWISE_RSHIFT_ASSIGN = 50, /* ">>="  */
  YYSYMBOL_TOKEN_ARITH_RSHIFT = 51,        /* ">>>"  */
  YYSYMBOL_TOKEN_ARITH_RSHIFT_ASSIGN = 52, /* ">>>="  */
  YYSYMBOL_TOKEN_QUESTION = 53,            /* "?"  */
  YYSYMBOL_TOKEN_AT = 54,                  /* "@"  */
  YYSYMBOL_TOKEN_LBRACE_SQUARE = 55,       /* "["  */
  YYSYMBOL_TOKEN_BSLASH = 56,              /* "\\"  */
  YYSYMBOL_TOKEN_RBRACE_SQUARE = 57,       /* "]"  */
  YYSYMBOL_TOKEN_CARET = 58,               /* "^"  */
  YYSYMBOL_TOKEN_BITWISE_XOR_ASSIGN = 59,  /* "^="  */
  YYSYMBOL_TOKEN_BACKTICK = 60,            /* "`"  */
  YYSYMBOL_TOKEN_LBRACE_CURLY = 61,        /* "{"  */
  YYSYMBOL_TOKEN_PIPE = 62,                /* "|"  */
  YYSYMBOL_TOKEN_BITWISE_OR_ASSIGN = 63,   /* "|="  */
  YYSYMBOL_TOKEN_PIPEOUT = 64,             /* "|>"  */
  YYSYMBOL_TOKEN_LOGICAL_OR = 65,          /* "||"  */
  YYSYMBOL_TOKEN_LOGICAL_OR_ASSIGN = 66,   /* "||="  */
  YYSYMBOL_TOKEN_RBRACE_CURLY = 67,        /* "}"  */
  YYSYMBOL_TOKEN_TILDE = 68,               /* "~"  */
  YYSYMBOL_TOKOP_NOP = 69,                 /* TOKOP_NOP  */
  YYSYMBOL_TOKOP_FNCALL = 70,              /* TOKOP_FNCALL  */
  YYSYMBOL_TOKOP_INDEXING = 71,            /* TOKOP_INDEXING  */
  YYSYMBOL_TOKOP_TERNARY_COND = 72,        /* TOKOP_TERNARY_COND  */
  YYSYMBOL_TOKOP_FNARGS_INDEXING = 73,     /* TOKOP_FNARGS_INDEXING  */
  YYSYMBOL_TOKOP_ASSIGN_CONST = 74,        /* TOKOP_ASSIGN_CONST  */
  YYSYMBOL_TOKOP_ASSIGN_WEAK = 75,         /* TOKOP_ASSIGN_WEAK  */
  YYSYMBOL_TOKOP_ASSIGN_CONST_WEAK = 76,   /* TOKOP_ASSIGN_CONST_WEAK  */
  YYSYMBOL_TOKEN_NEWLINE = 77,             /* "\n"  */
  YYSYMBOL_TOKEN_KWD_MODULE = 78,          /* "module"  */
  YYSYMBOL_TOKEN_KWD_PROC = 79,            /* "proc"  */
  YYSYMBOL_TOKEN_KWD_START = 80,           /* "start"  */
  YYSYMBOL_TOKEN_KWD_END = 81,             /* "end"  */
  YYSYMBOL_TOKEN_KWD_BLOCK = 82,           /* "block"  */
  YYSYMBOL_TOKEN_KWD_IF = 83,              /* "if"  */
  YYSYMBOL_TOKEN_KWD_THEN = 84,            /* "then"  */
  YYSYMBOL_TOKEN_KWD_ELIF = 85,            /* "elif"  */
  YYSYMBOL_TOKEN_KWD_ELSE = 86,            /* "else"  */
  YYSYMBOL_TOKEN_KWD_WHILE = 87,           /* "while"  */
  YYSYMBOL_TOKEN_KWD_BREAK = 88,           /* "break"  */
  YYSYMBOL_TOKEN_KWD_CONTINUE = 89,        /* "continue"  */
  YYSYMBOL_TOKEN_KWD_FOR = 90,             /* "for"  */
  YYSYMBOL_TOKEN_KWD_FROM = 91,            /* "from"  */
  YYSYMBOL_TOKEN_KWD_TO = 92,              /* "to"  */
  YYSYMBOL_TOKEN_KWD_BY = 93,              /* "by"  */
  YYSYMBOL_TOKEN_KWD_IN = 94,              /* "in"  */
  YYSYMBOL_TOKEN_KWD_DO = 95,              /* "do"  */
  YYSYMBOL_TOKEN_KWD_VAR = 96,             /* "var"  */
  YYSYMBOL_TOKEN_KWD_CONST = 97,           /* "const"  */
  YYSYMBOL_TOKEN_KWD_PASS = 98,            /* "pass"  */
  YYSYMBOL_TOKEN_KWD_RETURN = 99,          /* "return"  */
  YYSYMBOL_TOKEN_KWD_WEAK = 100,           /* "weak"  */
  YYSYMBOL_TOKEN_INVALID = 101,            /* "<invalid>"  */
  YYSYMBOL_TOKEN_BOOL_LITERAL = 102,       /* "<boollit>"  */
  YYSYMBOL_TOKEN_CHAR_LITERAL = 103,       /* "<charlit>"  */
  YYSYMBOL_TOKEN_BINFLOAT_LITERAL = 104,   /* "<binfloattlit>"  */
  YYSYMBOL_TOKEN_OCTFLOAT_LITERAL = 105,   /* "<octfloattlit>"  */
  YYSYMBOL_TOKEN_DECFLOAT_LITERAL = 106,   /* "<decfloattlit>"  */
  YYSYMBOL_TOKEN_HEXFLOAT_LITERAL = 107,   /* "<hexfloattlit>"  */
  YYSYMBOL_TOKEN_BININT_LITERAL = 108,     /* "<binintlit>"  */
  YYSYMBOL_TOKEN_OCTINT_LITERAL = 109,     /* "<octintlit>"  */
  YYSYMBOL_TOKEN_DECINT_LITERAL = 110,     /* "<decintlit>"  */
  YYSYMBOL_TOKEN_HEXINT_LITERAL = 111,     /* "<hexintlit>"  */
  YYSYMBOL_TOKEN_STR_LITERAL = 112,        /* "<strlit>"  */
  YYSYMBOL_TOKEN_INTERP_STR_LITERAL = 113, /* "<interpstrlit>"  */
  YYSYMBOL_TOKEN_IDENTIFIER = 114,         /* "<identifier>"  */
  YYSYMBOL_YYACCEPT = 115,                 /* $accept  */
  YYSYMBOL_nws = 116,                      /* nws  */
  YYSYMBOL_nwp = 117,                      /* nwp  */
  YYSYMBOL_trm = 118,                      /* trm  */
  YYSYMBOL_module = 119,                   /* module  */
  YYSYMBOL_120_1 = 120,                    /* $@1  */
  YYSYMBOL_121_2 = 121,                    /* $@2  */
  YYSYMBOL_program = 122,                  /* program  */
  YYSYMBOL_procedure = 123,                /* procedure  */
  YYSYMBOL_fnargs_list = 124,              /* fnargs_list  */
  YYSYMBOL_statements = 125,               /* statements  */
  YYSYMBOL_statement = 126,                /* statement  */
  YYSYMBOL_assignment = 127,               /* assignment  */
  YYSYMBOL_compound_statement = 128,       /* compound_statement  */
  YYSYMBOL_if_block = 129,                 /* if_block  */
  YYSYMBOL_else_block = 130,               /* else_block  */
  YYSYMBOL_while_block = 131,              /* while_block  */
  YYSYMBOL_for_block = 132,                /* for_block  */
  YYSYMBOL_block = 133,                    /* block  */
  YYSYMBOL_condition = 134,                /* condition  */
  YYSYMBOL_expression = 135,               /* expression  */
  YYSYMBOL_assignment_expression = 136,    /* assignment_expression  */
  YYSYMBOL_conditional_expression = 137,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 138,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 139,   /* logical_and_expression  */
  YYSYMBOL_bitwise_or_expression = 140,    /* bitwise_or_expression  */
  YYSYMBOL_bitwise_xor_expression = 141,   /* bitwise_xor_expression  */
  YYSYMBOL_bitwise_and_expression = 142,   /* bitwise_and_expression  */
  YYSYMBOL_equality_expression = 143,      /* equality_expression  */
  YYSYMBOL_relational_expression = 144,    /* relational_expression  */
  YYSYMBOL_shift_expression = 145,         /* shift_expression  */
  YYSYMBOL_additive_expression = 146,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 147, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 148,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 149,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 150,       /* primary_expression  */
  YYSYMBOL_comma_list = 151,               /* comma_list  */
  YYSYMBOL_assoc_list = 152,               /* assoc_list  */
  YYSYMBOL_literal = 153,                  /* literal  */
  YYSYMBOL_string_literal = 154,           /* string_literal  */
  YYSYMBOL_list_literal = 155,             /* list_literal  */
  YYSYMBOL_map_literal = 156,              /* map_literal  */
  YYSYMBOL_lambda_literal = 157,           /* lambda_literal  */
  YYSYMBOL_identifier = 158                /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1698

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  372

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   368


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     7,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   243,   248,   249,   254,   255,   256,   257,
     262,   262,   263,   263,   268,   269,   274,   277,   280,   286,
     287,   288,   292,   293,   297,   298,   299,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   321,   322,   323,   324,   328,   329,   333,   334,
     335,   336,   337,   341,   345,   346,   347,   348,   352,   353,
     357,   361,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   389,   390,   394,   395,   399,   400,   404,
     405,   409,   410,   414,   415,   419,   420,   421,   425,   426,
     427,   428,   429,   433,   434,   435,   436,   440,   441,   442,
     446,   447,   448,   449,   450,   451,   455,   456,   457,   458,
     459,   460,   461,   465,   466,   467,   470,   471,   472,   473,
     477,   480,   481,   482,   486,   489,   495,   496,   497,   501,
     502,   503,   507,   508,   509,   510,   514,   518,   522,   536,
     550,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   584,   585,   589,   590,   594,
     595,   599,   600,   601,   602,   606
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"<eof>\"", "error", "\"invalid token\"", "\"!\"", "\"!=\"", "\"!==\"",
  "TOKEN_DQUOTE", "'\"'", "\"$\"", "\"%\"", "\"%=\"", "\"&\"", "\"&&\"",
  "\"&&=\"", "\"&=\"", "\"'\"", "\"(\"", "\")\"", "\"*\"", "\"**\"",
  "\"**=\"", "\"*=\"", "\"+\"", "\"++\"", "\"+=\"", "\",\"", "\"-\"",
  "\"--\"", "\"-=\"", "\"->\"", "\".\"", "\"...\"", "\"/\"", "\"//\"",
  "\"//=\"", "\"/=\"", "\":\"", "\"::\"", "\";\"", "\"<\"", "\"<<\"",
  "\"<<=\"", "\"<=\"", "\"=\"", "\"==\"", "\"===\"", "\"=>\"", "\">\"",
  "\">=\"", "\">>\"", "\">>=\"", "\">>>\"", "\">>>=\"", "\"?\"", "\"@\"",
  "\"[\"", "\"\\\\\"", "\"]\"", "\"^\"", "\"^=\"", "\"`\"", "\"{\"",
  "\"|\"", "\"|=\"", "\"|>\"", "\"||\"", "\"||=\"", "\"}\"", "\"~\"",
  "TOKOP_NOP", "TOKOP_FNCALL", "TOKOP_INDEXING", "TOKOP_TERNARY_COND",
  "TOKOP_FNARGS_INDEXING", "TOKOP_ASSIGN_CONST", "TOKOP_ASSIGN_WEAK",
  "TOKOP_ASSIGN_CONST_WEAK", "\"\\n\"", "\"module\"", "\"proc\"",
  "\"start\"", "\"end\"", "\"block\"", "\"if\"", "\"then\"", "\"elif\"",
  "\"else\"", "\"while\"", "\"break\"", "\"continue\"", "\"for\"",
  "\"from\"", "\"to\"", "\"by\"", "\"in\"", "\"do\"", "\"var\"",
  "\"const\"", "\"pass\"", "\"return\"", "\"weak\"", "\"<invalid>\"",
  "\"<boollit>\"", "\"<charlit>\"", "\"<binfloattlit>\"",
  "\"<octfloattlit>\"", "\"<decfloattlit>\"", "\"<hexfloattlit>\"",
  "\"<binintlit>\"", "\"<octintlit>\"", "\"<decintlit>\"",
  "\"<hexintlit>\"", "\"<strlit>\"", "\"<interpstrlit>\"",
  "\"<identifier>\"", "$accept", "nws", "nwp", "trm", "module", "$@1",
  "$@2", "program", "procedure", "fnargs_list", "statements", "statement",
  "assignment", "compound_statement", "if_block", "else_block",
  "while_block", "for_block", "block", "condition", "expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "bitwise_or_expression", "bitwise_xor_expression",
  "bitwise_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "comma_list", "assoc_list", "literal", "string_literal", "list_literal",
  "map_literal", "lambda_literal", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-310)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,   -71,   -48,    85,  -310,    -4,  -310,  -310,  -310,  -310,
    -310,     1,    13,  -310,  -310,  -310,   -71,  -310,    13,    -8,
     -15,    44,    44,   126,   119,  -310,   439,   439,    44,  -310,
     -48,  1456,    -3,   929,  1456,  1456,  1456,  1456,    88,   -14,
    1456,  -310,    44,  1456,  1456,    -4,    -4,   -71,   -71,    -4,
     663,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,    65,   551,    -4,    -4,  -310,  -310,  -310,
    -310,  -310,  -310,    64,    83,   137,    89,    94,   143,    12,
      54,    57,   106,    27,   136,  1599,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,    75,   439,   -65,    90,  -310,    82,  1456,
    1456,  -310,  -310,   129,   144,   146,    10,  -310,  -310,  -310,
    -310,  -310,   945,  -310,     2,   439,  -310,   439,    76,    64,
      70,     1,     1,   -20,   123,     5,     1,     1,    -4,    -4,
    -310,     1,     1,  1456,  1456,  1456,  1456,  1456,  1456,  1456,
    1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,
    1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,   152,  1456,
    1456,  -310,  1456,  -310,  1456,   -71,  1456,  1456,   -71,   -71,
    1456,   684,  1456,  1456,  1456,  1456,  1456,  1456,    -4,    91,
    -310,   153,   114,  1472,   148,  -310,   154,   121,   -71,   113,
     145,   147,   115,   103,    44,    44,   -71,  1456,  1456,   796,
     817,     1,     1,    99,   137,    89,    94,   143,    12,    54,
      54,    57,    57,    57,    57,   106,   106,   106,    27,    27,
    -310,  -310,  -310,  -310,    98,  -310,  -310,  -310,  -310,   945,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    1057,  1078,  -310,  -310,  -310,   131,  -310,  -310,  -310,     1,
      -4,  -310,  -310,   -14,  -310,  1584,  -310,   -48,  -310,   132,
    -310,  1456,  1456,  -310,  -310,   439,   439,    92,   100,    96,
    1190,  1211,  -310,  1323,  1344,  -310,  1456,   176,  1456,  -310,
    1456,  -310,  -310,     1,   439,   -14,  -310,   945,   158,   175,
     177,   -19,   120,  1456,  1456,    44,  1456,  -310,  1456,  -310,
    1456,  -310,  1456,  -310,  -310,  -310,  -310,  -310,   139,   439,
    -310,  1456,  -310,   -48,  -310,   -48,  -310,  1456,    40,  -310,
    -310,   108,    43,   439,  -310,  -310,  -310,  -310,  -310,   140,
     179,     2,     2,   124,  1456,   439,    44,  1456,    44,   128,
    -310,  -310,   -48,  -310,  -310,    44,   127,   133,   439,   117,
     439,  -310,     2,   439,    44,  -310,   134,    44,   138,  -310,
      39,   439,  -310,   439,  -310,  -310,  -310,    41,   141,  -310,
    -310,  -310
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    10,     0,   175,     0,     3,    14,     1,     7,
       9,    12,    11,     6,     8,    14,     0,    15,    13,     0,
       0,     0,     0,     0,     2,     4,    22,    22,     0,     2,
      19,     0,     0,     0,     0,     0,     0,     0,     2,     2,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   165,   166,     0,    22,     0,     0,    42,    43,    44,
      45,    41,    61,    62,    83,    85,    87,    89,    91,    93,
      95,    98,   103,   107,   110,   116,   123,   136,   161,   162,
     163,   164,   137,     0,    22,    20,     2,   119,   116,     0,
       0,   129,   130,     0,     0,     0,   137,   117,   121,   118,
     122,   167,     0,   169,     0,    22,   120,    22,     0,    60,
       0,    25,    26,     0,     0,     2,    24,    28,     0,     0,
      23,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,   131,     0,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,   138,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    16,     0,    86,    88,    90,    92,    94,    97,
      96,    99,   101,   100,   102,   105,   106,   104,   108,   109,
     113,   111,   112,   115,   114,    80,    69,    72,   124,     0,
      81,    78,    76,    77,   133,    82,    79,   135,   134,    74,
       0,     0,    63,    75,    73,     0,    71,    70,    68,    17,
       0,   128,   127,     2,   173,     0,     2,   139,   168,     0,
     170,     0,     0,    59,    58,    22,    22,     0,     0,     0,
       0,     0,    36,     0,     0,    31,     0,     0,     0,    64,
       0,    65,   126,    18,    22,     2,   174,   140,     0,     2,
       2,     0,     0,     0,     0,     0,     0,    37,     0,    38,
       0,    32,     0,    33,    84,   125,    66,    67,     0,    22,
     141,     0,     2,   142,     2,   145,    46,     0,     0,    47,
      53,     0,     0,    22,    39,    40,    34,    35,   171,     0,
       2,   143,   146,     0,     0,    22,     0,     0,     0,     0,
     172,     2,   148,   144,   147,     0,     0,     0,    22,     0,
      22,    56,   149,    22,     0,    48,     0,     0,     0,   150,
       0,    22,    57,    22,    54,    51,    52,     0,     0,    49,
      50,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -310,     4,    22,   -25,  -310,  -310,  -310,   195,  -310,   -11,
     -26,  -310,  -310,  -310,  -310,  -309,  -310,  -310,  -310,   -38,
     -24,   256,   -33,  -310,    79,    93,    87,    81,    86,   -85,
      -2,   -12,  -131,    46,   255,  -310,  -222,  -262,  -310,  -111,
    -310,  -310,  -310,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   114,    26,    11,     3,     7,    15,    12,    17,    23,
      63,    64,    65,    66,    67,   319,    68,    69,    70,   118,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   187,   189,    87,    88,
      89,    90,    91,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    93,    22,   190,     2,   196,   120,   277,    20,   105,
     119,   119,     6,    99,     1,    19,   139,   218,   219,    24,
     121,   122,   104,   224,   126,   127,   128,    -2,    30,     6,
      29,   102,   106,    95,     9,    29,   150,   124,   130,    13,
     131,   132,   112,     4,    27,   151,   123,   125,   200,     4,
      94,   366,   100,   113,   209,   210,   140,   188,   370,   152,
     153,   115,   316,    25,   117,   310,   317,   318,   179,   343,
     344,   197,    21,    10,   198,   181,   182,    97,    14,     6,
     107,   108,   109,   110,   180,     8,   116,    -2,   186,   192,
     359,   193,    16,   141,    24,   203,   142,   145,   158,     4,
     119,   143,   144,   201,   202,   161,   146,   101,   147,   163,
      30,     4,   165,   191,    61,    62,     4,    25,   168,   169,
     365,    25,   369,   334,   317,   318,   317,   318,   148,    30,
     152,   153,   149,   215,   216,   217,   337,   174,   338,   211,
     212,   213,   214,    28,    29,   111,   129,   133,   134,   135,
     245,   136,   137,   249,   138,   154,   178,   113,   183,   254,
     194,   184,   229,   185,   234,   195,   199,   237,   238,   228,
     251,   252,   250,   268,   269,   272,   275,   255,   258,   256,
     260,   261,   263,   262,   264,   276,   293,   259,   282,   288,
     257,   295,   294,   305,   311,   267,   220,   221,   222,   223,
     312,   320,   314,   336,   341,   186,   328,   340,   345,   351,
      18,   354,   357,   204,   355,   362,   265,   266,   207,   364,
     190,   190,   371,   206,   208,   283,     0,     0,   205,     0,
       0,   286,     0,     0,     0,     0,     0,   289,   290,   291,
     292,   190,     0,   304,     0,     0,   297,   299,     0,   301,
     303,     0,     0,     0,     0,     0,     0,     0,   308,     0,
     287,     0,     0,   186,     0,     0,     0,     0,     0,   321,
     322,     0,   324,     0,   325,   284,   326,     0,   327,   333,
       0,     0,     0,   329,   119,     0,    98,   330,     0,    98,
      98,    98,    98,   313,   315,    98,   346,   339,    98,    98,
       0,   119,     0,     0,     0,     0,     0,   309,     0,   347,
       0,     0,     0,   349,     0,     0,   331,   323,   332,     0,
       0,     0,   356,     0,   358,     0,     0,   360,     0,     0,
     191,   191,     0,     0,   342,   367,     0,   368,     0,     0,
     335,     0,     0,     0,     0,   352,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,   348,     0,
     350,     0,     0,     0,     0,     0,     0,   353,     0,     0,
       0,     0,     0,     0,     0,     0,   361,     0,     0,   363,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
       0,   225,   226,   227,     0,   230,   231,     0,   232,     0,
     233,     0,   235,   236,     0,     0,   239,   242,   243,   244,
       0,   246,   247,   248,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,    34,    35,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,   279,   281,     0,     0,
      39,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,    42,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    98,     0,     0,   306,    48,   307,    49,    50,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     4,    31,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,    98,    34,    35,     0,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,     0,    44,    45,
      46,    47,     0,     0,     0,     0,     0,    48,     0,    49,
      50,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     4,    31,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    34,    35,    31,     0,    36,
      37,     0,    32,     0,     0,     0,     0,     0,     0,     0,
      33,     9,     0,     0,     0,     0,    34,    35,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,    38,
      10,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     4,     0,     0,
       0,   240,     0,     0,   241,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     4,    31,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,    34,    35,
      31,     0,    36,    37,     0,    32,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,    34,
      35,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,   271,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       4,     0,     0,     0,   273,     0,     0,   274,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     4,    31,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,    33,   103,     0,    31,     0,
       0,    34,    35,    32,     0,    36,    37,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,    34,    35,     0,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,    40,     0,     0,
      38,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     4,     0,     0,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     4,
      31,     0,     0,     0,     0,    32,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,    34,
      35,    31,     0,    36,    37,     0,    32,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
      34,    35,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     4,     0,     0,     0,   280,     0,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     4,    31,     0,     0,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,    34,    35,    31,     0,    36,    37,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,    34,    35,     0,     0,    36,    37,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     4,     0,     0,     0,   298,     0,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     4,    31,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    34,    35,    31,     0,    36,
      37,     0,    32,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,    34,    35,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     4,     0,     0,
       0,   302,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     4,    31,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    31,     0,     0,    34,    35,
      32,     0,    36,    37,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,    34,    35,     0,     0,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    38,     0,     0,
       0,     0,     0,   253,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       4,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     4,    31,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,    34,    35,     0,   155,
      36,    37,   156,   157,     0,   158,     0,     0,     0,   159,
     160,     0,   161,   162,     0,     0,   163,   164,     0,   165,
       0,     0,     0,   166,   167,   168,   169,     0,     0,    38,
     170,     0,   171,     0,     0,   285,     0,     0,     0,   172,
       0,   173,    40,     0,   174,     0,     0,     0,   175,     0,
       0,     0,   176,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     4
};

static const yytype_int16 yycheck[] =
{
       1,    27,    17,   114,     0,    25,    44,   229,    16,    33,
      43,    44,    77,    16,    78,    16,     4,   148,   149,    20,
      45,    46,    33,   154,    49,    50,    50,    17,    24,    77,
      25,    32,    33,    29,    38,    25,     9,    48,    64,    38,
      65,    66,    38,   114,    22,    18,    47,    48,    43,   114,
      28,   360,    55,    67,   139,   140,    44,    55,   367,    32,
      33,    39,    81,    77,    42,   287,    85,    86,    94,   331,
     332,    91,    80,    77,    94,    99,   100,    31,    77,    77,
      34,    35,    36,    37,    95,     0,    40,    77,   112,   115,
     352,   117,    79,    39,    95,   133,    42,    40,    16,   114,
     133,    47,    48,   128,   129,    23,    49,   110,    51,    27,
     106,   114,    30,   114,   112,   113,   114,    77,    36,    37,
      81,    77,    81,    83,    85,    86,    85,    86,    22,   125,
      32,    33,    26,   145,   146,   147,    93,    55,    95,   141,
     142,   143,   144,    17,    25,    57,    81,    83,    65,    12,
     174,    62,    58,   178,    11,    19,    81,    67,    29,   183,
      84,    17,   158,    17,   165,    95,    43,   168,   169,    17,
      17,    57,    81,   197,   198,   199,   200,    29,    57,    25,
      67,    36,    67,    36,    81,    86,    94,   188,    57,    57,
     186,    95,    92,    17,    36,   196,   150,   151,   152,   153,
      25,    81,    25,    95,    25,   229,    67,    67,    84,    81,
      15,    84,    95,   134,    81,    81,   194,   195,   137,    81,
     331,   332,    81,   136,   138,   250,    -1,    -1,   135,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   262,   265,
     266,   352,    -1,   276,    -1,    -1,   270,   271,    -1,   273,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
     256,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,   293,
     294,    -1,   296,    -1,   298,   253,   300,    -1,   302,   317,
      -1,    -1,    -1,   309,   317,    -1,    31,   311,    -1,    34,
      35,    36,    37,   289,   290,    40,   334,   323,    43,    44,
      -1,   334,    -1,    -1,    -1,    -1,    -1,   285,    -1,   335,
      -1,    -1,    -1,   337,    -1,    -1,   312,   295,   314,    -1,
      -1,    -1,   348,    -1,   350,    -1,    -1,   353,    -1,    -1,
     331,   332,    -1,    -1,   330,   361,    -1,   363,    -1,    -1,
     318,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
      -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,   336,    -1,
     338,    -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,   357,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   155,   156,   157,    -1,   159,   160,    -1,   162,    -1,
     164,    -1,   166,   167,    -1,    -1,   170,   171,   172,   173,
      -1,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,   240,   241,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    87,    88,    89,    90,
      -1,   276,    -1,    -1,   278,    96,   280,    98,    99,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     3,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,   317,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      99,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     3,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,     3,    -1,    26,
      27,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    38,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      77,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,
       3,    -1,    26,    27,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,     3,    -1,
      -1,    22,    23,     8,    -1,    26,    27,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      23,     3,    -1,    26,    27,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     3,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,     3,    -1,    26,    27,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     3,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,     3,    -1,    26,
      27,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,     3,    -1,    -1,    22,    23,
       8,    -1,    26,    27,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    10,
      26,    27,    13,    14,    -1,    16,    -1,    -1,    -1,    20,
      21,    -1,    23,    24,    -1,    -1,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,    55,
      41,    -1,    43,    -1,    -1,    61,    -1,    -1,    -1,    50,
      -1,    52,    68,    -1,    55,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    63,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,   116,   119,   114,   158,    77,   120,     0,    38,
      77,   118,   122,    38,    77,   121,    79,   123,   122,   158,
      16,    80,    17,   124,   158,    77,   117,   117,    17,    25,
     116,     3,     8,    16,    22,    23,    26,    27,    55,    61,
      68,    77,    82,    83,    87,    88,    89,    90,    96,    98,
      99,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   125,   126,   127,   128,   129,   131,   132,
     133,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   153,   154,   155,
     156,   157,   158,   125,   117,   116,    61,   148,   149,    16,
      55,   110,   158,    17,   124,   135,   158,   148,   148,   148,
     148,    57,   116,    67,   116,   117,   148,   117,   134,   137,
     134,   118,   118,   158,   124,   158,   118,   118,   135,    81,
     125,   118,   118,    83,    65,    12,    62,    58,    11,     4,
      44,    39,    42,    47,    48,    40,    49,    51,    22,    26,
       9,    18,    32,    33,    19,    10,    13,    14,    16,    20,
      21,    23,    24,    27,    28,    30,    34,    35,    36,    37,
      41,    43,    50,    52,    55,    59,    63,    66,    81,   125,
     124,   135,   135,    29,    17,    17,   135,   151,    55,   152,
     154,   158,   125,   125,    84,    95,    25,    91,    94,    43,
      43,   118,   118,   134,   139,   140,   141,   142,   143,   144,
     144,   145,   145,   145,   145,   146,   146,   146,   147,   147,
     148,   148,   148,   148,   147,   136,   136,   136,    17,   116,
     136,   136,   136,   136,   158,   136,   136,   158,   158,   136,
      97,   100,   136,   136,   136,   135,   136,   136,   136,   118,
      81,    17,    57,    61,   135,    29,    25,   116,    57,   158,
      67,    36,    36,    67,    81,   117,   117,   158,   135,   135,
      97,   100,   135,    97,   100,   135,    86,   151,   100,   136,
      97,   136,    57,   118,   117,    61,   135,   116,    57,   135,
     135,   125,   125,    94,    92,    95,   100,   135,    97,   135,
     100,   135,    97,   135,   137,    17,   136,   136,   125,   117,
     151,    36,    25,   116,    25,   116,    81,    85,    86,   130,
      81,   135,   135,   117,   135,   135,   135,   135,    67,   125,
     135,   116,   116,   134,    83,   117,    95,    93,    95,   125,
      67,    25,   116,   152,   152,    84,   134,   125,   117,   135,
     117,    81,   116,   117,    84,    81,   125,    95,   125,   152,
     125,   117,    81,   117,    81,    81,   130,   125,   125,    81,
     130,    81
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     120,   119,   121,   119,   122,   122,   123,   123,   123,   124,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   131,   132,   132,   132,   132,   133,   133,
     134,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   143,   144,   144,
     144,   144,   144,   145,   145,   145,   145,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     148,   148,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   150,   150,   150,   151,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   157,   157,   157,   157,   158
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     2,     1,
       0,     3,     0,     5,     0,     2,     7,     8,     9,     2,
       3,     4,     0,     2,     2,     2,     2,     3,     2,     2,
       2,     4,     5,     5,     6,     6,     4,     5,     5,     6,
       6,     1,     1,     1,     1,     1,     6,     6,     4,     7,
       7,     6,     6,     6,    10,    12,     8,    10,     4,     4,
       1,     1,     1,     3,     4,     4,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     1,     3,     5,     4,     4,     4,     2,
       2,     2,     2,     3,     3,     3,     1,     1,     3,     2,
       3,     4,     4,     5,     6,     4,     5,     6,     6,     7,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     2,
       4,     7,     8,     4,     5,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= TOKEN_EOF)
    {
      yychar = TOKEN_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* nws: %empty  */
#line 242 "src/parser.y"
               { (yyval.line_count) = 0; }
#line 1771 "src/parser.yy.c"
    break;

  case 3: /* nws: nws "\n"  */
#line 243 "src/parser.y"
               { (yyval.line_count) = (yyvsp[-1].line_count) + 1; }
#line 1777 "src/parser.yy.c"
    break;

  case 4: /* nwp: "\n"  */
#line 248 "src/parser.y"
               { (yyval.line_count) = 1; }
#line 1783 "src/parser.yy.c"
    break;

  case 5: /* nwp: nwp "\n"  */
#line 249 "src/parser.y"
               { (yyval.line_count) = (yyvsp[-1].line_count) + 1; }
#line 1789 "src/parser.yy.c"
    break;

  case 6: /* trm: trm ";"  */
#line 254 "src/parser.y"
               { (yyval.line_count) = (yyvsp[-1].line_count); }
#line 1795 "src/parser.yy.c"
    break;

  case 7: /* trm: ";"  */
#line 255 "src/parser.y"
               { (yyval.line_count) = 0; }
#line 1801 "src/parser.yy.c"
    break;

  case 8: /* trm: trm "\n"  */
#line 256 "src/parser.y"
               { (yyval.line_count) = (yyvsp[-1].line_count) + 1; }
#line 1807 "src/parser.yy.c"
    break;

  case 9: /* trm: "\n"  */
#line 257 "src/parser.y"
               { (yyval.line_count) = 1; }
#line 1813 "src/parser.yy.c"
    break;

  case 10: /* $@1: %empty  */
#line 262 "src/parser.y"
        { ast_ModuleStack_push(ast_Identifier(strdup("main"))); }
#line 1819 "src/parser.yy.c"
    break;

  case 11: /* module: nws $@1 program  */
#line 262 "src/parser.y"
                                                                          { ast_ModuleStack_pop(); }
#line 1825 "src/parser.yy.c"
    break;

  case 12: /* $@2: %empty  */
#line 263 "src/parser.y"
                              { ast_ModuleStack_push((yyvsp[-1].astnode_identifier)); }
#line 1831 "src/parser.yy.c"
    break;

  case 13: /* module: "module" identifier trm $@2 program  */
#line 263 "src/parser.y"
                                                                    { ast_ModuleStack_pop(); }
#line 1837 "src/parser.yy.c"
    break;

  case 16: /* procedure: "proc" identifier "start" nwp statements "end" trm  */
#line 274 "src/parser.y"
                                                                                                   { ast_util_ModuleAndProcTable_add(ast_ModuleStack_top(), (yyvsp[-5].astnode_identifier), NULL, (yyvsp[-2].astnode_statements));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-5].astnode_identifier));
                                                                                                   }
#line 1845 "src/parser.yy.c"
    break;

  case 17: /* procedure: "proc" identifier "(" ")" nwp statements "end" trm  */
#line 277 "src/parser.y"
                                                                                                   { ast_util_ModuleAndProcTable_add(ast_ModuleStack_top(), (yyvsp[-6].astnode_identifier), NULL, (yyvsp[-2].astnode_statements));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-6].astnode_identifier));
                                                                                                   }
#line 1853 "src/parser.yy.c"
    break;

  case 18: /* procedure: "proc" identifier "(" fnargs_list ")" nwp statements "end" trm  */
#line 280 "src/parser.y"
                                                                                                   { ast_util_ModuleAndProcTable_add(ast_ModuleStack_top(), (yyvsp[-7].astnode_identifier), (yyvsp[-5].astnode_fnargs_list), (yyvsp[-2].astnode_statements));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-7].astnode_identifier));
                                                                                                   }
#line 1861 "src/parser.yy.c"
    break;

  case 19: /* fnargs_list: identifier nws  */
#line 286 "src/parser.y"
                                                                                                   { (yyval.astnode_fnargs_list) = ast_FnArgsList(NULL, (yyvsp[-1].astnode_identifier)); }
#line 1867 "src/parser.yy.c"
    break;

  case 20: /* fnargs_list: identifier "," nws  */
#line 287 "src/parser.y"
                                                                                                   { (yyval.astnode_fnargs_list) = ast_FnArgsList(NULL, (yyvsp[-2].astnode_identifier)); }
#line 1873 "src/parser.yy.c"
    break;

  case 21: /* fnargs_list: identifier "," nws fnargs_list  */
#line 288 "src/parser.y"
                                                                                                   { (yyval.astnode_fnargs_list) = ast_FnArgsList((yyvsp[0].astnode_fnargs_list), (yyvsp[-3].astnode_identifier)); }
#line 1879 "src/parser.yy.c"
    break;

  case 22: /* statements: %empty  */
#line 292 "src/parser.y"
                                                                                                   { (yyval.astnode_statements) = NULL; }
#line 1885 "src/parser.yy.c"
    break;

  case 23: /* statements: statement statements  */
#line 293 "src/parser.y"
                                                                                                   { (yyval.astnode_statements) = ast_Statements((yyvsp[0].astnode_statements), (yyvsp[-1].astnode_statement)); }
#line 1891 "src/parser.yy.c"
    break;

  case 24: /* statement: "pass" trm  */
#line 297 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_empty(lex_line_no - (yyvsp[0].line_count)); }
#line 1897 "src/parser.yy.c"
    break;

  case 25: /* statement: "break" trm  */
#line 298 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_break(lex_line_no - (yyvsp[0].line_count)); }
#line 1903 "src/parser.yy.c"
    break;

  case 26: /* statement: "continue" trm  */
#line 299 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_continue(lex_line_no - (yyvsp[0].line_count)); }
#line 1909 "src/parser.yy.c"
    break;

  case 27: /* statement: "return" expression trm  */
#line 300 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_return((yyvsp[-1].astnode_expression), lex_line_no - (yyvsp[0].line_count)); }
#line 1915 "src/parser.yy.c"
    break;

  case 28: /* statement: "return" trm  */
#line 301 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_return(NULL, lex_line_no - (yyvsp[0].line_count)); }
#line 1921 "src/parser.yy.c"
    break;

  case 29: /* statement: assignment trm  */
#line 302 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_Assignment((yyvsp[-1].astnode_assignment), lex_line_no - (yyvsp[0].line_count)); }
#line 1927 "src/parser.yy.c"
    break;

  case 30: /* statement: compound_statement trm  */
#line 303 "src/parser.y"
                                                                                                   { (yyval.astnode_statement) = ast_Statement_CompoundSt((yyvsp[-1].astnode_compound_statement), lex_line_no - (yyvsp[0].line_count)); }
#line 1933 "src/parser.yy.c"
    break;

  case 31: /* assignment: "var" identifier "=" expression  */
#line 307 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_create((yyvsp[-2].astnode_identifier), (yyvsp[0].astnode_expression), false, false); }
#line 1939 "src/parser.yy.c"
    break;

  case 32: /* assignment: "var" identifier "=" "const" expression  */
#line 308 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_create((yyvsp[-3].astnode_identifier), (yyvsp[0].astnode_expression), true, false); }
#line 1945 "src/parser.yy.c"
    break;

  case 33: /* assignment: "var" identifier "=" "weak" expression  */
#line 309 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_create((yyvsp[-3].astnode_identifier), (yyvsp[0].astnode_expression), false, true); }
#line 1951 "src/parser.yy.c"
    break;

  case 34: /* assignment: "var" identifier "=" "const" "weak" expression  */
#line 310 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_create((yyvsp[-4].astnode_identifier), (yyvsp[0].astnode_expression), true, true); }
#line 1957 "src/parser.yy.c"
    break;

  case 35: /* assignment: "var" identifier "=" "weak" "const" expression  */
#line 311 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_create((yyvsp[-4].astnode_identifier), (yyvsp[0].astnode_expression), true, true); }
#line 1963 "src/parser.yy.c"
    break;

  case 36: /* assignment: "var" fnargs_list "=" expression  */
#line 312 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_destructure((yyvsp[-2].astnode_fnargs_list), (yyvsp[0].astnode_expression), false, false); }
#line 1969 "src/parser.yy.c"
    break;

  case 37: /* assignment: "var" fnargs_list "=" "const" expression  */
#line 313 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_destructure((yyvsp[-3].astnode_fnargs_list), (yyvsp[0].astnode_expression), true, false); }
#line 1975 "src/parser.yy.c"
    break;

  case 38: /* assignment: "var" fnargs_list "=" "weak" expression  */
#line 314 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_destructure((yyvsp[-3].astnode_fnargs_list), (yyvsp[0].astnode_expression), false, true); }
#line 1981 "src/parser.yy.c"
    break;

  case 39: /* assignment: "var" fnargs_list "=" "const" "weak" expression  */
#line 315 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_destructure((yyvsp[-4].astnode_fnargs_list), (yyvsp[0].astnode_expression), true, true); }
#line 1987 "src/parser.yy.c"
    break;

  case 40: /* assignment: "var" fnargs_list "=" "weak" "const" expression  */
#line 316 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_destructure((yyvsp[-4].astnode_fnargs_list), (yyvsp[0].astnode_expression), true, true); }
#line 1993 "src/parser.yy.c"
    break;

  case 41: /* assignment: expression  */
#line 317 "src/parser.y"
                                                                                                   { (yyval.astnode_assignment) = ast_Assignment_tovoid((yyvsp[0].astnode_expression)); }
#line 1999 "src/parser.yy.c"
    break;

  case 42: /* compound_statement: if_block  */
#line 321 "src/parser.y"
                                                                                                   { (yyval.astnode_compound_statement) = ast_CompoundSt_IfBlock((yyvsp[0].astnode_if_block)); }
#line 2005 "src/parser.yy.c"
    break;

  case 43: /* compound_statement: while_block  */
#line 322 "src/parser.y"
                                                                                                   { (yyval.astnode_compound_statement) = ast_CompoundSt_WhileBlock((yyvsp[0].astnode_while_block)); }
#line 2011 "src/parser.yy.c"
    break;

  case 44: /* compound_statement: for_block  */
#line 323 "src/parser.y"
                                                                                                   { (yyval.astnode_compound_statement) = ast_CompoundSt_ForBlock((yyvsp[0].astnode_for_block)); }
#line 2017 "src/parser.yy.c"
    break;

  case 45: /* compound_statement: block  */
#line 324 "src/parser.y"
                                                                                                   { (yyval.astnode_compound_statement) = ast_CompoundSt_Block((yyvsp[0].astnode_block)); }
#line 2023 "src/parser.yy.c"
    break;

  case 46: /* if_block: "if" condition "then" nwp statements "end"  */
#line 328 "src/parser.y"
                                                                                                   { (yyval.astnode_if_block) = ast_IfBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), NULL); }
#line 2029 "src/parser.yy.c"
    break;

  case 47: /* if_block: "if" condition "then" nwp statements else_block  */
#line 329 "src/parser.y"
                                                                                                   { (yyval.astnode_if_block) = ast_IfBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), (yyvsp[0].astnode_else_block)); }
#line 2035 "src/parser.yy.c"
    break;

  case 48: /* else_block: "else" nwp statements "end"  */
#line 333 "src/parser.y"
                                                                                                   { (yyval.astnode_else_block) = ast_ElseBlock(NULL, (yyvsp[-1].astnode_statements), NULL); }
#line 2041 "src/parser.yy.c"
    break;

  case 49: /* else_block: "else" "if" condition "then" nwp statements "end"  */
#line 334 "src/parser.y"
                                                                                                   { (yyval.astnode_else_block) = ast_ElseBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), NULL); }
#line 2047 "src/parser.yy.c"
    break;

  case 50: /* else_block: "else" "if" condition "then" nwp statements else_block  */
#line 335 "src/parser.y"
                                                                                                   { (yyval.astnode_else_block) = ast_ElseBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), (yyvsp[0].astnode_else_block)); }
#line 2053 "src/parser.yy.c"
    break;

  case 51: /* else_block: "elif" condition "then" nwp statements "end"  */
#line 336 "src/parser.y"
                                                                                                   { (yyval.astnode_else_block) = ast_ElseBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), NULL); }
#line 2059 "src/parser.yy.c"
    break;

  case 52: /* else_block: "elif" condition "then" nwp statements else_block  */
#line 337 "src/parser.y"
                                                                                                   { (yyval.astnode_else_block) = ast_ElseBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements), (yyvsp[0].astnode_else_block)); }
#line 2065 "src/parser.yy.c"
    break;

  case 53: /* while_block: "while" condition "do" nwp statements "end"  */
#line 341 "src/parser.y"
                                                                                                   { (yyval.astnode_while_block) = ast_WhileBlock((yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements)); }
#line 2071 "src/parser.yy.c"
    break;

  case 54: /* for_block: "for" identifier "from" expression "to" expression "do" nwp statements "end"  */
#line 345 "src/parser.y"
                                                                                                   { (yyval.astnode_for_block) = ast_ForBlock((yyvsp[-8].astnode_identifier), (yyvsp[-6].astnode_expression), (yyvsp[-4].astnode_expression), NULL, (yyvsp[-1].astnode_statements)); }
#line 2077 "src/parser.yy.c"
    break;

  case 55: /* for_block: "for" identifier "from" expression "to" expression "by" expression "do" nwp statements "end"  */
#line 346 "src/parser.y"
                                                                                                   { (yyval.astnode_for_block) = ast_ForBlock((yyvsp[-10].astnode_identifier), (yyvsp[-8].astnode_expression), (yyvsp[-6].astnode_expression), (yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements)); }
#line 2083 "src/parser.yy.c"
    break;

  case 56: /* for_block: "for" identifier "in" expression "do" nwp statements "end"  */
#line 347 "src/parser.y"
                                                                                                   { (yyval.astnode_for_block) = ast_ForBlock_iterate(NULL, (yyvsp[-6].astnode_identifier), (yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements)); }
#line 2089 "src/parser.yy.c"
    break;

  case 57: /* for_block: "for" identifier "," identifier "in" expression "do" nwp statements "end"  */
#line 348 "src/parser.y"
                                                                                                   { (yyval.astnode_for_block) = ast_ForBlock_iterate((yyvsp[-8].astnode_identifier), (yyvsp[-6].astnode_identifier), (yyvsp[-4].astnode_expression), (yyvsp[-1].astnode_statements)); }
#line 2095 "src/parser.yy.c"
    break;

  case 58: /* block: "block" nwp statements "end"  */
#line 352 "src/parser.y"
                                                                                                   { (yyval.astnode_block) = ast_Block((yyvsp[-1].astnode_statements)); }
#line 2101 "src/parser.yy.c"
    break;

  case 59: /* block: "{" nwp statements "}"  */
#line 353 "src/parser.y"
                                                                                                   { (yyval.astnode_block) = ast_Block((yyvsp[-1].astnode_statements)); }
#line 2107 "src/parser.yy.c"
    break;

  case 60: /* condition: conditional_expression  */
#line 357 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2113 "src/parser.yy.c"
    break;

  case 61: /* expression: assignment_expression  */
#line 361 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2119 "src/parser.yy.c"
    break;

  case 62: /* assignment_expression: conditional_expression  */
#line 365 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2125 "src/parser.yy.c"
    break;

  case 63: /* assignment_expression: postfix_expression "=" assignment_expression  */
#line 366 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2131 "src/parser.yy.c"
    break;

  case 64: /* assignment_expression: postfix_expression "=" "const" assignment_expression  */
#line 367 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_ASSIGN_CONST, (yyvsp[-3].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2137 "src/parser.yy.c"
    break;

  case 65: /* assignment_expression: postfix_expression "=" "weak" assignment_expression  */
#line 368 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_ASSIGN_WEAK, (yyvsp[-3].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2143 "src/parser.yy.c"
    break;

  case 66: /* assignment_expression: postfix_expression "=" "const" "weak" assignment_expression  */
#line 369 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_ASSIGN_CONST_WEAK, (yyvsp[-4].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2149 "src/parser.yy.c"
    break;

  case 67: /* assignment_expression: postfix_expression "=" "weak" "const" assignment_expression  */
#line 370 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_ASSIGN_CONST_WEAK, (yyvsp[-4].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2155 "src/parser.yy.c"
    break;

  case 68: /* assignment_expression: postfix_expression "||=" assignment_expression  */
#line 371 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2161 "src/parser.yy.c"
    break;

  case 69: /* assignment_expression: postfix_expression "&&=" assignment_expression  */
#line 372 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2167 "src/parser.yy.c"
    break;

  case 70: /* assignment_expression: postfix_expression "|=" assignment_expression  */
#line 373 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2173 "src/parser.yy.c"
    break;

  case 71: /* assignment_expression: postfix_expression "^=" assignment_expression  */
#line 374 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2179 "src/parser.yy.c"
    break;

  case 72: /* assignment_expression: postfix_expression "&=" assignment_expression  */
#line 375 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2185 "src/parser.yy.c"
    break;

  case 73: /* assignment_expression: postfix_expression ">>>=" assignment_expression  */
#line 376 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2191 "src/parser.yy.c"
    break;

  case 74: /* assignment_expression: postfix_expression "<<=" assignment_expression  */
#line 377 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2197 "src/parser.yy.c"
    break;

  case 75: /* assignment_expression: postfix_expression ">>=" assignment_expression  */
#line 378 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2203 "src/parser.yy.c"
    break;

  case 76: /* assignment_expression: postfix_expression "+=" assignment_expression  */
#line 379 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2209 "src/parser.yy.c"
    break;

  case 77: /* assignment_expression: postfix_expression "-=" assignment_expression  */
#line 380 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2215 "src/parser.yy.c"
    break;

  case 78: /* assignment_expression: postfix_expression "*=" assignment_expression  */
#line 381 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2221 "src/parser.yy.c"
    break;

  case 79: /* assignment_expression: postfix_expression "/=" assignment_expression  */
#line 382 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2227 "src/parser.yy.c"
    break;

  case 80: /* assignment_expression: postfix_expression "%=" assignment_expression  */
#line 383 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2233 "src/parser.yy.c"
    break;

  case 81: /* assignment_expression: postfix_expression "**=" assignment_expression  */
#line 384 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2239 "src/parser.yy.c"
    break;

  case 82: /* assignment_expression: postfix_expression "//=" assignment_expression  */
#line 385 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2245 "src/parser.yy.c"
    break;

  case 83: /* conditional_expression: logical_or_expression  */
#line 389 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2251 "src/parser.yy.c"
    break;

  case 84: /* conditional_expression: conditional_expression "if" condition "else" conditional_expression  */
#line 390 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_TERNARY_COND, (yyvsp[-4].astnode_expression), (yyvsp[0].astnode_expression), (yyvsp[-2].astnode_expression)); }
#line 2257 "src/parser.yy.c"
    break;

  case 85: /* logical_or_expression: logical_and_expression  */
#line 394 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2263 "src/parser.yy.c"
    break;

  case 86: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 395 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2269 "src/parser.yy.c"
    break;

  case 87: /* logical_and_expression: bitwise_or_expression  */
#line 399 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2275 "src/parser.yy.c"
    break;

  case 88: /* logical_and_expression: logical_and_expression "&&" bitwise_or_expression  */
#line 400 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2281 "src/parser.yy.c"
    break;

  case 89: /* bitwise_or_expression: bitwise_xor_expression  */
#line 404 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2287 "src/parser.yy.c"
    break;

  case 90: /* bitwise_or_expression: bitwise_or_expression "|" bitwise_xor_expression  */
#line 405 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2293 "src/parser.yy.c"
    break;

  case 91: /* bitwise_xor_expression: bitwise_and_expression  */
#line 409 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2299 "src/parser.yy.c"
    break;

  case 92: /* bitwise_xor_expression: bitwise_xor_expression "^" bitwise_and_expression  */
#line 410 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2305 "src/parser.yy.c"
    break;

  case 93: /* bitwise_and_expression: equality_expression  */
#line 414 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2311 "src/parser.yy.c"
    break;

  case 94: /* bitwise_and_expression: bitwise_and_expression "&" equality_expression  */
#line 415 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2317 "src/parser.yy.c"
    break;

  case 95: /* equality_expression: relational_expression  */
#line 419 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2323 "src/parser.yy.c"
    break;

  case 96: /* equality_expression: equality_expression "==" relational_expression  */
#line 420 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2329 "src/parser.yy.c"
    break;

  case 97: /* equality_expression: equality_expression "!=" relational_expression  */
#line 421 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2335 "src/parser.yy.c"
    break;

  case 98: /* relational_expression: shift_expression  */
#line 425 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2341 "src/parser.yy.c"
    break;

  case 99: /* relational_expression: relational_expression "<" shift_expression  */
#line 426 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2347 "src/parser.yy.c"
    break;

  case 100: /* relational_expression: relational_expression ">" shift_expression  */
#line 427 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2353 "src/parser.yy.c"
    break;

  case 101: /* relational_expression: relational_expression "<=" shift_expression  */
#line 428 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2359 "src/parser.yy.c"
    break;

  case 102: /* relational_expression: relational_expression ">=" shift_expression  */
#line 429 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2365 "src/parser.yy.c"
    break;

  case 103: /* shift_expression: additive_expression  */
#line 433 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2371 "src/parser.yy.c"
    break;

  case 104: /* shift_expression: shift_expression ">>>" additive_expression  */
#line 434 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2377 "src/parser.yy.c"
    break;

  case 105: /* shift_expression: shift_expression "<<" additive_expression  */
#line 435 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2383 "src/parser.yy.c"
    break;

  case 106: /* shift_expression: shift_expression ">>" additive_expression  */
#line 436 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2389 "src/parser.yy.c"
    break;

  case 107: /* additive_expression: multiplicative_expression  */
#line 440 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2395 "src/parser.yy.c"
    break;

  case 108: /* additive_expression: additive_expression "+" multiplicative_expression  */
#line 441 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2401 "src/parser.yy.c"
    break;

  case 109: /* additive_expression: additive_expression "-" multiplicative_expression  */
#line 442 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2407 "src/parser.yy.c"
    break;

  case 110: /* multiplicative_expression: unary_expression  */
#line 446 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2413 "src/parser.yy.c"
    break;

  case 111: /* multiplicative_expression: multiplicative_expression "*" unary_expression  */
#line 447 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2419 "src/parser.yy.c"
    break;

  case 112: /* multiplicative_expression: multiplicative_expression "/" unary_expression  */
#line 448 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2425 "src/parser.yy.c"
    break;

  case 113: /* multiplicative_expression: multiplicative_expression "%" unary_expression  */
#line 449 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2431 "src/parser.yy.c"
    break;

  case 114: /* multiplicative_expression: unary_expression "**" multiplicative_expression  */
#line 450 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2437 "src/parser.yy.c"
    break;

  case 115: /* multiplicative_expression: multiplicative_expression "//" unary_expression  */
#line 451 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), (yyvsp[0].astnode_expression), NULL); }
#line 2443 "src/parser.yy.c"
    break;

  case 116: /* unary_expression: postfix_expression  */
#line 455 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2449 "src/parser.yy.c"
    break;

  case 117: /* unary_expression: "+" unary_expression  */
#line 456 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2455 "src/parser.yy.c"
    break;

  case 118: /* unary_expression: "-" unary_expression  */
#line 457 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2461 "src/parser.yy.c"
    break;

  case 119: /* unary_expression: "!" unary_expression  */
#line 458 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2467 "src/parser.yy.c"
    break;

  case 120: /* unary_expression: "~" unary_expression  */
#line 459 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2473 "src/parser.yy.c"
    break;

  case 121: /* unary_expression: "++" unary_expression  */
#line 460 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2479 "src/parser.yy.c"
    break;

  case 122: /* unary_expression: "--" unary_expression  */
#line 461 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), NULL, (yyvsp[0].astnode_expression), NULL); }
#line 2485 "src/parser.yy.c"
    break;

  case 123: /* postfix_expression: primary_expression  */
#line 465 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[0].astnode_expression); }
#line 2491 "src/parser.yy.c"
    break;

  case 124: /* postfix_expression: postfix_expression "(" ")"  */
#line 466 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNCALL, (yyvsp[-2].astnode_expression), NULL, NULL); }
#line 2497 "src/parser.yy.c"
    break;

  case 125: /* postfix_expression: postfix_expression "(" nws comma_list ")"  */
#line 467 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNCALL, (yyvsp[-4].astnode_expression),
                                                                                                       ast_Expression_CommaSepList((yyvsp[-1].astnode_comma_list)), NULL);
                                                                                                   }
#line 2505 "src/parser.yy.c"
    break;

  case 126: /* postfix_expression: postfix_expression "[" expression "]"  */
#line 470 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_INDEXING, (yyvsp[-3].astnode_expression), (yyvsp[-1].astnode_expression), NULL); }
#line 2511 "src/parser.yy.c"
    break;

  case 127: /* postfix_expression: "$" "[" expression "]"  */
#line 471 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNARGS_INDEXING, NULL, (yyvsp[-1].astnode_expression), NULL); }
#line 2517 "src/parser.yy.c"
    break;

  case 128: /* postfix_expression: "$" "(" expression ")"  */
#line 472 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNARGS_INDEXING, NULL, (yyvsp[-1].astnode_expression), NULL); }
#line 2523 "src/parser.yy.c"
    break;

  case 129: /* postfix_expression: "$" "<decintlit>"  */
#line 473 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNARGS_INDEXING, NULL,
                                                                                                       ast_Expression_Literal(
                                                                                                           ast_Literal_i64((yyvsp[0].literal_i64))), NULL);
                                                                                                   }
#line 2532 "src/parser.yy.c"
    break;

  case 130: /* postfix_expression: "$" identifier  */
#line 477 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKOP_FNARGS_INDEXING, NULL,
                                                                                                       ast_Expression_Identifier((yyvsp[0].astnode_identifier)), NULL);
                                                                                                   }
#line 2540 "src/parser.yy.c"
    break;

  case 131: /* postfix_expression: postfix_expression "++"  */
#line 480 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[0].tok), (yyvsp[-1].astnode_expression), NULL, NULL); }
#line 2546 "src/parser.yy.c"
    break;

  case 132: /* postfix_expression: postfix_expression "--"  */
#line 481 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[0].tok), (yyvsp[-1].astnode_expression), NULL, NULL); }
#line 2552 "src/parser.yy.c"
    break;

  case 133: /* postfix_expression: postfix_expression "." identifier  */
#line 482 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression), ast_Expression_Literal(
                                                                                                           ast_Literal_str(strdup((yyvsp[0].astnode_identifier)))), NULL);
                                                                                                       ast_Identifier_destroy(&(yyvsp[0].astnode_identifier));
                                                                                                   }
#line 2561 "src/parser.yy.c"
    break;

  case 134: /* postfix_expression: postfix_expression "::" identifier  */
#line 486 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression((yyvsp[-1].tok), (yyvsp[-2].astnode_expression),
                                                                                                       ast_Expression_Identifier((yyvsp[0].astnode_identifier)), NULL);
                                                                                                   }
#line 2569 "src/parser.yy.c"
    break;

  case 135: /* postfix_expression: postfix_expression ":" identifier  */
#line 489 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression(TOKEN_DCOLON, (yyvsp[-2].astnode_expression),
                                                                                                       ast_Expression_Identifier((yyvsp[0].astnode_identifier)), NULL);
                                                                                                   }
#line 2577 "src/parser.yy.c"
    break;

  case 136: /* primary_expression: literal  */
#line 495 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression_Literal((yyvsp[0].astnode_literal)); }
#line 2583 "src/parser.yy.c"
    break;

  case 137: /* primary_expression: identifier  */
#line 496 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = ast_Expression_Identifier((yyvsp[0].astnode_identifier)); }
#line 2589 "src/parser.yy.c"
    break;

  case 138: /* primary_expression: "(" expression ")"  */
#line 497 "src/parser.y"
                                                                                                   { (yyval.astnode_expression) = (yyvsp[-1].astnode_expression); }
#line 2595 "src/parser.yy.c"
    break;

  case 139: /* comma_list: expression nws  */
#line 501 "src/parser.y"
                                                                                                   { (yyval.astnode_comma_list) = ast_CommaSepList(NULL, (yyvsp[-1].astnode_expression)); }
#line 2601 "src/parser.yy.c"
    break;

  case 140: /* comma_list: expression "," nws  */
#line 502 "src/parser.y"
                                                                                                   { (yyval.astnode_comma_list) = ast_CommaSepList(NULL, (yyvsp[-2].astnode_expression)); }
#line 2607 "src/parser.yy.c"
    break;

  case 141: /* comma_list: expression "," nws comma_list  */
#line 503 "src/parser.y"
                                                                                                   { (yyval.astnode_comma_list) = ast_CommaSepList((yyvsp[0].astnode_comma_list), (yyvsp[-3].astnode_expression)); }
#line 2613 "src/parser.yy.c"
    break;

  case 142: /* assoc_list: string_literal ":" expression nws  */
#line 507 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList(NULL, (yyvsp[-3].astnode_literal), (yyvsp[-1].astnode_expression)); }
#line 2619 "src/parser.yy.c"
    break;

  case 143: /* assoc_list: string_literal ":" expression "," nws  */
#line 508 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList(NULL, (yyvsp[-4].astnode_literal), (yyvsp[-2].astnode_expression)); }
#line 2625 "src/parser.yy.c"
    break;

  case 144: /* assoc_list: string_literal ":" expression "," nws assoc_list  */
#line 509 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList((yyvsp[0].astnode_assoc_list), (yyvsp[-5].astnode_literal), (yyvsp[-3].astnode_expression)); }
#line 2631 "src/parser.yy.c"
    break;

  case 145: /* assoc_list: identifier ":" expression nws  */
#line 510 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList(NULL,
                                                                                                           ast_Literal_str(strdup((yyvsp[-3].astnode_identifier))), (yyvsp[-1].astnode_expression));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-3].astnode_identifier));
                                                                                                   }
#line 2640 "src/parser.yy.c"
    break;

  case 146: /* assoc_list: identifier ":" expression "," nws  */
#line 514 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList(NULL,
                                                                                                           ast_Literal_str(strdup((yyvsp[-4].astnode_identifier))), (yyvsp[-2].astnode_expression));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-4].astnode_identifier));
                                                                                                   }
#line 2649 "src/parser.yy.c"
    break;

  case 147: /* assoc_list: identifier ":" expression "," nws assoc_list  */
#line 518 "src/parser.y"
                                                                                                   { (yyval.astnode_assoc_list) = ast_AssociativeList((yyvsp[0].astnode_assoc_list),
                                                                                                           ast_Literal_str(strdup((yyvsp[-5].astnode_identifier))), (yyvsp[-3].astnode_expression));
                                                                                                       ast_Identifier_destroy(&(yyvsp[-5].astnode_identifier));
                                                                                                   }
#line 2658 "src/parser.yy.c"
    break;

  case 148: /* assoc_list: "[" identifier "]" ":" expression nws  */
#line 522 "src/parser.y"
                                                                                                   {
                                                                                                       /* allocate memory for the template string
                                                                                                          ast_Literal_interp_str takes ownership so it
                                                                                                          needs not be freed */
                                                                                                       char *key = malloc(strlen((yyvsp[-4].astnode_identifier)) + 3);
                                                                                                       /* create the template string */
                                                                                                       sprintf(key, "{%s}", (yyvsp[-4].astnode_identifier));
                                                                                                       /* pretend that the map key is a template
                                                                                                          string literal */
                                                                                                       (yyval.astnode_assoc_list) = ast_AssociativeList(NULL,
                                                                                                           ast_Literal_interp_str(key), (yyvsp[-1].astnode_expression));
                                                                                                       /* destroy the identifier */
                                                                                                       ast_Identifier_destroy(&(yyvsp[-4].astnode_identifier));
                                                                                                   }
#line 2677 "src/parser.yy.c"
    break;

  case 149: /* assoc_list: "[" identifier "]" ":" expression "," nws  */
#line 536 "src/parser.y"
                                                                                                   {
                                                                                                       /* allocate memory for the template string
                                                                                                          ast_Literal_interp_str takes ownership so it
                                                                                                          needs not be freed */
                                                                                                       char *key = malloc(strlen((yyvsp[-5].astnode_identifier)) + 3);
                                                                                                       /* create the template string */
                                                                                                       sprintf(key, "{%s}", (yyvsp[-5].astnode_identifier));
                                                                                                       /* pretend that the map key is a template
                                                                                                          string literal */
                                                                                                       (yyval.astnode_assoc_list) = ast_AssociativeList(NULL,
                                                                                                           ast_Literal_interp_str(key), (yyvsp[-2].astnode_expression));
                                                                                                       /* destroy the identifier */
                                                                                                       ast_Identifier_destroy(&(yyvsp[-5].astnode_identifier));
                                                                                                   }
#line 2696 "src/parser.yy.c"
    break;

  case 150: /* assoc_list: "[" identifier "]" ":" expression "," nws assoc_list  */
#line 550 "src/parser.y"
                                                                                                   {
                                                                                                       /* allocate memory for the template string
                                                                                                          ast_Literal_interp_str takes ownership so it
                                                                                                          needs not be freed */
                                                                                                       char *key = malloc(strlen((yyvsp[-6].astnode_identifier)) + 3);
                                                                                                       /* create the template string */
                                                                                                       sprintf(key, "{%s}", (yyvsp[-6].astnode_identifier));
                                                                                                       /* pretend that the map key is a template
                                                                                                          string literal */
                                                                                                       (yyval.astnode_assoc_list) = ast_AssociativeList((yyvsp[0].astnode_assoc_list),
                                                                                                           ast_Literal_interp_str(key), (yyvsp[-3].astnode_expression));
                                                                                                       /* destroy the identifier */
                                                                                                       ast_Identifier_destroy(&(yyvsp[-6].astnode_identifier));
                                                                                                   }
#line 2715 "src/parser.yy.c"
    break;

  case 151: /* literal: "<boollit>"  */
#line 567 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_bul((yyvsp[0].literal_bool)); }
#line 2721 "src/parser.yy.c"
    break;

  case 152: /* literal: "<charlit>"  */
#line 568 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_chr((yyvsp[0].literal_char)); }
#line 2727 "src/parser.yy.c"
    break;

  case 153: /* literal: "<binfloattlit>"  */
#line 569 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_f64((yyvsp[0].literal_f64)); }
#line 2733 "src/parser.yy.c"
    break;

  case 154: /* literal: "<octfloattlit>"  */
#line 570 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_f64((yyvsp[0].literal_f64)); }
#line 2739 "src/parser.yy.c"
    break;

  case 155: /* literal: "<decfloattlit>"  */
#line 571 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_f64((yyvsp[0].literal_f64)); }
#line 2745 "src/parser.yy.c"
    break;

  case 156: /* literal: "<hexfloattlit>"  */
#line 572 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_f64((yyvsp[0].literal_f64)); }
#line 2751 "src/parser.yy.c"
    break;

  case 157: /* literal: "<binintlit>"  */
#line 573 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_i64((yyvsp[0].literal_i64)); }
#line 2757 "src/parser.yy.c"
    break;

  case 158: /* literal: "<octintlit>"  */
#line 574 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_i64((yyvsp[0].literal_i64)); }
#line 2763 "src/parser.yy.c"
    break;

  case 159: /* literal: "<decintlit>"  */
#line 575 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_i64((yyvsp[0].literal_i64)); }
#line 2769 "src/parser.yy.c"
    break;

  case 160: /* literal: "<hexintlit>"  */
#line 576 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_i64((yyvsp[0].literal_i64)); }
#line 2775 "src/parser.yy.c"
    break;

  case 161: /* literal: string_literal  */
#line 577 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = (yyvsp[0].astnode_literal); }
#line 2781 "src/parser.yy.c"
    break;

  case 162: /* literal: list_literal  */
#line 578 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = (yyvsp[0].astnode_literal); }
#line 2787 "src/parser.yy.c"
    break;

  case 163: /* literal: map_literal  */
#line 579 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = (yyvsp[0].astnode_literal); }
#line 2793 "src/parser.yy.c"
    break;

  case 164: /* literal: lambda_literal  */
#line 580 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = (yyvsp[0].astnode_literal); }
#line 2799 "src/parser.yy.c"
    break;

  case 165: /* string_literal: "<strlit>"  */
#line 584 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_str((yyvsp[0].literal_str)); }
#line 2805 "src/parser.yy.c"
    break;

  case 166: /* string_literal: "<interpstrlit>"  */
#line 585 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_interp_str((yyvsp[0].literal_str)); }
#line 2811 "src/parser.yy.c"
    break;

  case 167: /* list_literal: "[" "]"  */
#line 589 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lst(NULL); }
#line 2817 "src/parser.yy.c"
    break;

  case 168: /* list_literal: "[" nws comma_list "]"  */
#line 590 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lst((yyvsp[-1].astnode_comma_list)); }
#line 2823 "src/parser.yy.c"
    break;

  case 169: /* map_literal: "{" "}"  */
#line 594 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_map(NULL); }
#line 2829 "src/parser.yy.c"
    break;

  case 170: /* map_literal: "{" nws assoc_list "}"  */
#line 595 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_map((yyvsp[-1].astnode_assoc_list)); }
#line 2835 "src/parser.yy.c"
    break;

  case 171: /* lambda_literal: "(" ")" "->" "{" nwp statements "}"  */
#line 599 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lambda_block(NULL, (yyvsp[-1].astnode_statements)); }
#line 2841 "src/parser.yy.c"
    break;

  case 172: /* lambda_literal: "(" fnargs_list ")" "->" "{" nwp statements "}"  */
#line 600 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lambda_block((yyvsp[-6].astnode_fnargs_list), (yyvsp[-1].astnode_statements)); }
#line 2847 "src/parser.yy.c"
    break;

  case 173: /* lambda_literal: "(" ")" "->" expression  */
#line 601 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lambda_expr(NULL, (yyvsp[0].astnode_expression)); }
#line 2853 "src/parser.yy.c"
    break;

  case 174: /* lambda_literal: "(" fnargs_list ")" "->" expression  */
#line 602 "src/parser.y"
                                                                                                   { (yyval.astnode_literal) = ast_Literal_lambda_expr((yyvsp[-3].astnode_fnargs_list), (yyvsp[0].astnode_expression)); }
#line 2859 "src/parser.yy.c"
    break;

  case 175: /* identifier: "<identifier>"  */
#line 606 "src/parser.y"
                                                                                                   { (yyval.astnode_identifier) = ast_Identifier((yyvsp[0].identifier_name)); }
#line 2865 "src/parser.yy.c"
    break;


#line 2869 "src/parser.yy.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= TOKEN_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == TOKEN_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 609 "src/parser.y"


#include "parser/parse_bool.c.h"
#include "parser/parse_chr.c.h"
#include "parser/parse_f64.c.h"
#include "parser/parse_i64.c.h"
#include "parser/parse_str.c.h"

int yyerror(const char* msg)
{
    parse_throw(msg, true);
    return ERR_PARSER;
}

void parse_interpret(FILE *f)
{
    yyin = f;
    if (yyin == stdin) printf(
        "Welcome to Shsc Version %s\n"
        "Enter your code and when done, press CTRL+D\n"
        "%s", VERSION, ">> "
    );
    if (global_lex_dbg) {
        lex_Token_t tok = lex_Token_getnext(yyin);
        while (tok != TOKEN_EOF) {
            printf("%s: %s\n", lex_Token_getcode(tok), lex_Token_getsymbol(tok));
            tok = lex_Token_getnext(f);
        }
        printf("%s\n", lex_Token_getcode(tok));
    }
    else yyparse();
    lex_Buffer_free();
}

void parse_throw(const char *msg, bool on)
{
    if (!msg) abort();
    int line = lex_line_no;
    if (lex_currtok == TOKEN_NEWLINE) --line;
    if (on) io_print_srcerr(line, lex_char_no, "parsing error: %s on '%s'", msg, lex_Token_getsymbol(lex_currtok));
    else io_print_srcerr(line, lex_char_no, "parsing error: %s", msg);
#ifdef DEBUG
    abort();
#else
    exit(ERR_PARSER);
#endif
}
