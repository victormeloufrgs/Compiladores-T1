/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "parser.y"

    #include "ast.h"
    #include "hash.h"
    #include "semantic.h"
    #include "tacs.h"
    #include "assembler.h"

    void yyerror(const char *s);
    int getLineNumber();
    int yylex();
    int syntax_errors = 0;

#line 84 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_BOOL = 261,                 /* KW_BOOL  */
    KW_IF = 262,                   /* KW_IF  */
    KW_THEN = 263,                 /* KW_THEN  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_WHILE = 265,                /* KW_WHILE  */
    KW_LOOP = 266,                 /* KW_LOOP  */
    KW_READ = 267,                 /* KW_READ  */
    KW_PRINT = 268,                /* KW_PRINT  */
    KW_RETURN = 269,               /* KW_RETURN  */
    OPERATOR_LE = 270,             /* OPERATOR_LE  */
    OPERATOR_LT = 271,             /* OPERATOR_LT  */
    OPERATOR_GE = 272,             /* OPERATOR_GE  */
    OPERATOR_GT = 273,             /* OPERATOR_GT  */
    OPERATOR_EQ = 274,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 275,            /* OPERATOR_DIF  */
    OPERATOR_OR = 276,             /* OPERATOR_OR  */
    OPERATOR_AND = 277,            /* OPERATOR_AND  */
    OPERATOR_NOT = 278,            /* OPERATOR_NOT  */
    OPERATOR_PLUS = 279,           /* OPERATOR_PLUS  */
    OPERATOR_MINUS = 280,          /* OPERATOR_MINUS  */
    OPERATOR_MULT = 281,           /* OPERATOR_MULT  */
    OPERATOR_DIV = 282,            /* OPERATOR_DIV  */
    TK_IDENTIFIER = 283,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 284,             /* LIT_INTEGER  */
    LIT_FLOAT = 285,               /* LIT_FLOAT  */
    LIT_TRUE = 286,                /* LIT_TRUE  */
    LIT_FALSE = 287,               /* LIT_FALSE  */
    LIT_CHAR = 288,                /* LIT_CHAR  */
    LIT_STRING = 289,              /* LIT_STRING  */
    TOKEN_ERROR = 290              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_LOOP 266
#define KW_READ 267
#define KW_PRINT 268
#define KW_RETURN 269
#define OPERATOR_LE 270
#define OPERATOR_LT 271
#define OPERATOR_GE 272
#define OPERATOR_GT 273
#define OPERATOR_EQ 274
#define OPERATOR_DIF 275
#define OPERATOR_OR 276
#define OPERATOR_AND 277
#define OPERATOR_NOT 278
#define OPERATOR_PLUS 279
#define OPERATOR_MINUS 280
#define OPERATOR_MULT 281
#define OPERATOR_DIV 282
#define TK_IDENTIFIER 283
#define LIT_INTEGER 284
#define LIT_FLOAT 285
#define LIT_TRUE 286
#define LIT_FALSE 287
#define LIT_CHAR 288
#define LIT_STRING 289
#define TOKEN_ERROR 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 211 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_BOOL = 6,                    /* KW_BOOL  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_THEN = 8,                    /* KW_THEN  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 10,                  /* KW_WHILE  */
  YYSYMBOL_KW_LOOP = 11,                   /* KW_LOOP  */
  YYSYMBOL_KW_READ = 12,                   /* KW_READ  */
  YYSYMBOL_KW_PRINT = 13,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 14,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 15,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_LT = 16,               /* OPERATOR_LT  */
  YYSYMBOL_OPERATOR_GE = 17,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_GT = 18,               /* OPERATOR_GT  */
  YYSYMBOL_OPERATOR_EQ = 19,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 20,              /* OPERATOR_DIF  */
  YYSYMBOL_OPERATOR_OR = 21,               /* OPERATOR_OR  */
  YYSYMBOL_OPERATOR_AND = 22,              /* OPERATOR_AND  */
  YYSYMBOL_OPERATOR_NOT = 23,              /* OPERATOR_NOT  */
  YYSYMBOL_OPERATOR_PLUS = 24,             /* OPERATOR_PLUS  */
  YYSYMBOL_OPERATOR_MINUS = 25,            /* OPERATOR_MINUS  */
  YYSYMBOL_OPERATOR_MULT = 26,             /* OPERATOR_MULT  */
  YYSYMBOL_OPERATOR_DIV = 27,              /* OPERATOR_DIV  */
  YYSYMBOL_TK_IDENTIFIER = 28,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INTEGER = 29,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_FLOAT = 30,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_TRUE = 31,                  /* LIT_TRUE  */
  YYSYMBOL_LIT_FALSE = 32,                 /* LIT_FALSE  */
  YYSYMBOL_LIT_CHAR = 33,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 34,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 35,               /* TOKEN_ERROR  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_declaration_list = 48,          /* declaration_list  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_type_and_value = 50,            /* type_and_value  */
  YYSYMBOL_type = 51,                      /* type  */
  YYSYMBOL_lit = 52,                       /* lit  */
  YYSYMBOL_vet_maybe_value = 53,           /* vet_maybe_value  */
  YYSYMBOL_vet_value = 54,                 /* vet_value  */
  YYSYMBOL_maybe_params = 55,              /* maybe_params  */
  YYSYMBOL_param_list = 56,                /* param_list  */
  YYSYMBOL_param_list_ext = 57,            /* param_list_ext  */
  YYSYMBOL_param = 58,                     /* param  */
  YYSYMBOL_command_block = 59,             /* command_block  */
  YYSYMBOL_command_seq = 60,               /* command_seq  */
  YYSYMBOL_command = 61,                   /* command  */
  YYSYMBOL_command_attribute = 62,         /* command_attribute  */
  YYSYMBOL_print_list = 63,                /* print_list  */
  YYSYMBOL_print_extra_elems = 64,         /* print_extra_elems  */
  YYSYMBOL_print_elem = 65,                /* print_elem  */
  YYSYMBOL_command_control = 66,           /* command_control  */
  YYSYMBOL_maybe_else = 67,                /* maybe_else  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_bin_expr = 69,                  /* bin_expr  */
  YYSYMBOL_function_call_args = 70,        /* function_call_args  */
  YYSYMBOL_func_args_extra = 71            /* func_args_extra  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    37,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    98,    98,   101,   102,   105,   106,   107,   108,   109,
     110,   113,   114,   115,   119,   120,   121,   122,   125,   126,
     127,   128,   129,   132,   133,   136,   137,   140,   141,   144,
     147,   148,   151,   154,   157,   158,   161,   162,   163,   164,
     165,   166,   167,   170,   171,   174,   177,   178,   181,   182,
     185,   186,   187,   188,   189,   190,   193,   194,   197,   198,
     199,   200,   201,   202,   203,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   222,   223,
     226,   227
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE",
  "KW_LOOP", "KW_READ", "KW_PRINT", "KW_RETURN", "OPERATOR_LE",
  "OPERATOR_LT", "OPERATOR_GE", "OPERATOR_GT", "OPERATOR_EQ",
  "OPERATOR_DIF", "OPERATOR_OR", "OPERATOR_AND", "OPERATOR_NOT",
  "OPERATOR_PLUS", "OPERATOR_MINUS", "OPERATOR_MULT", "OPERATOR_DIV",
  "TK_IDENTIFIER", "LIT_INTEGER", "LIT_FLOAT", "LIT_TRUE", "LIT_FALSE",
  "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "'='", "';'", "'('", "')'",
  "':'", "'['", "']'", "','", "'{'", "'}'", "$accept", "program",
  "declaration_list", "declaration", "type_and_value", "type", "lit",
  "vet_maybe_value", "vet_value", "maybe_params", "param_list",
  "param_list_ext", "param", "command_block", "command_seq", "command",
  "command_attribute", "print_list", "print_extra_elems", "print_elem",
  "command_control", "maybe_else", "expr", "bin_expr",
  "function_call_args", "func_args_extra", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    61,    59,    40,    41,
      58,    91,    93,    44,   123,   125
};
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,    22,    16,   -32,   -17,     3,    18,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,    14,    12,   -32,    19,    20,   -32,
      21,   -32,   -32,    59,    59,    79,   146,    27,    37,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,    79,   -21,    79,
     -32,   930,   -32,   -32,   146,    21,   120,    79,    79,  1014,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    28,    39,   -32,    55,    45,   958,   -32,
     159,   198,   237,   276,   315,   354,   393,   432,   471,   510,
     549,   588,   627,    59,   -32,   -32,    17,    79,   -32,   -32,
     -32,    59,   -32,   867,   -32,   -32,    55,   -32,    29,    47,
      61,    65,  1136,    79,   -31,   -32,   -32,   -32,   -32,   -32,
     -32,    79,    79,    69,   -32,   -32,   -32,    57,   666,   705,
      79,    79,  1041,  1068,    63,  1136,   -32,   744,   986,    93,
     896,    79,    57,    68,   896,   -32,    23,   -32,    79,    96,
      79,    79,   783,   896,   -32,   872,   901,   -32,    79,    79,
      79,    79,   814,  1095,   843,  1122,   896,   896,   896,   896,
     -32,   -32,   -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     0,     1,     3,     7,
      14,    16,    17,    15,     0,     0,    10,     0,     0,    27,
      31,     6,     5,     0,     0,     0,     0,     0,     0,    29,
      19,    20,    21,    22,    18,    12,    11,     0,    61,     0,
      64,     0,    58,    32,     0,    31,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    30,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    35,     0,     0,    78,    63,
      62,    26,    23,     0,     9,     8,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    33,    41,    34,    36,    40,
      80,     0,     0,     0,    37,    48,    39,    47,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
      42,     0,    47,     0,    42,    51,     0,    46,     0,    57,
       0,     0,     0,    42,    50,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    42,    42,    42,
      55,    53,    54,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   110,   -32,   -32,   -23,   -22,   -32,    31,   -32,
     -32,    73,    91,    56,   -32,  1020,   -32,   -32,    -4,    30,
     -32,   -32,   -25,   -32,   -32,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    14,    15,    40,    84,    92,    18,
      19,    29,    20,   106,    93,   107,   108,   116,   126,   117,
     109,   144,   118,    42,    67,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    35,    36,    43,     9,   120,    10,    11,    12,    13,
     121,     1,    46,    23,    49,    21,     7,    47,    94,    16,
      48,    64,    66,    68,   140,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    51,    52,
      53,    54,    55,    56,    57,    58,    17,    59,    60,    61,
      62,    22,    24,    25,    95,    26,    50,   -28,     5,    27,
       6,    91,    96,    44,    28,    17,   141,   111,    83,    91,
      51,    52,    53,    54,    55,    56,    57,    58,   119,    59,
      60,    61,    62,    85,    89,   112,   122,   123,    30,    31,
      32,    33,    34,   114,   -81,   127,   128,   124,    87,   113,
     125,   134,    37,   131,   138,   143,   136,    38,    30,    31,
      32,    33,    34,   142,     8,   145,   146,    39,    65,    45,
      86,    50,    97,   152,   153,   154,   155,   -60,   137,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,     0,    59,    60,    61,    62,   -60,    10,
      11,    12,    13,     0,   110,   132,     0,     0,     0,   -60,
      50,     0,   -60,   -60,   -60,   -60,   -77,     0,   -77,   -77,
     -77,   -77,   -77,   -77,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    59,    60,    61,    62,   -77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -77,    50,
       0,   -77,   -77,   -77,   -77,   -69,     0,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,     0,    59,    60,    61,    62,   -69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -69,    50,     0,
     -69,   -69,   -69,   -69,   -70,     0,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0,    59,    60,    61,    62,   -70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -70,    50,     0,   -70,
     -70,   -70,   -70,   -71,     0,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,
      59,    60,    61,    62,   -71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -71,    50,     0,   -71,   -71,
     -71,   -71,   -72,     0,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,    59,
      60,    61,    62,   -72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -72,    50,     0,   -72,   -72,   -72,
     -72,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,    59,    60,
      61,    62,   -73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73,    50,     0,   -73,   -73,   -73,   -73,
     -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,     0,    59,    60,    61,
      62,   -74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -74,    50,     0,   -74,   -74,   -74,   -74,   -75,
       0,   -75,   -75,   -75,   -75,   -75,   -75,    51,    52,    53,
      54,    55,    56,   -75,   -75,     0,    59,    60,    61,    62,
     -75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -75,    50,     0,   -75,   -75,   -75,   -75,   -76,     0,
     -76,   -76,   -76,   -76,   -76,   -76,    51,    52,    53,    54,
      55,    56,   -76,   -76,     0,    59,    60,    61,    62,   -76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -76,    50,     0,   -76,   -76,   -76,   -76,   -65,     0,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,     0,   -65,   -65,    61,    62,   -65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -65,
      50,     0,   -65,   -65,   -65,   -65,   -66,     0,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,   -66,   -66,    61,    62,   -66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -66,    50,
       0,   -66,   -66,   -66,   -66,   -67,     0,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,     0,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -67,    50,     0,
     -67,   -67,   -67,   -67,   -68,     0,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
       0,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68,    50,     0,   -68,
     -68,   -68,   -68,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,   -49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,   -49,
     -49,   -49,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,
      51,    52,    53,    54,    55,    56,    57,    58,     0,    59,
      60,    61,    62,   -38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,   -38,
     -38,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,   -43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,   -43,   -43,
     -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,    51,    52,
      53,    54,    55,    56,    57,    58,     0,    59,    60,    61,
      62,   -44,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -44,   -44,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,   -77,    51,    52,
      53,    54,    55,    56,    57,    58,     0,    59,    60,    61,
      62,     0,     0,   148,    98,     0,     0,    99,   100,   101,
     102,   103,   158,     0,     0,     0,   -77,    51,    52,    53,
      54,    55,    56,    57,    58,   104,    59,    60,    61,    62,
       0,     0,   150,    98,     0,     0,    99,   100,   101,   102,
     103,    85,   105,     0,     0,   149,    51,    52,    53,    54,
      55,    56,    57,    58,   104,    59,    60,    61,    62,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,   151,    51,    52,    53,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,    51,    52,    53,    54,
      55,    56,    57,    58,     0,    59,    60,    61,    62,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
      51,    52,    53,    54,    55,    56,    57,    58,     0,    59,
      60,    61,    62,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,     0,    51,    52,    53,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
     135,     0,     0,     0,   139,     0,     0,     0,     0,    37,
       0,   159,     0,   147,    38,    30,    31,    32,    33,    34,
     115,     0,     0,     0,    39,     0,   160,   161,   162,   163
};

static const yytype_int16 yycheck[] =
{
      25,    23,    24,    26,     1,    36,     3,     4,     5,     6,
      41,    28,    37,     1,    39,     1,     0,    38,     1,     1,
      41,    44,    47,    48,     1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    15,    16,
      17,    18,    19,    20,    21,    22,    28,    24,    25,    26,
      27,    37,    40,    41,    37,    36,     1,    39,    36,    39,
      38,    83,    87,    36,    43,    28,    43,    38,    40,    91,
      15,    16,    17,    18,    19,    20,    21,    22,   103,    24,
      25,    26,    27,    44,    39,    38,   111,   112,    29,    30,
      31,    32,    33,    28,    39,   120,   121,    28,    43,    38,
      43,     8,    23,    40,    36,     9,   131,    28,    29,    30,
      31,    32,    33,   138,     4,   140,   141,    38,    45,    28,
      64,     1,    91,   148,   149,   150,   151,     7,   132,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,     3,
       4,     5,     6,    -1,    96,   125,    -1,    -1,    -1,    39,
       1,    -1,    42,    43,    44,    45,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     1,
      -1,    42,    43,    44,    45,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     1,    -1,
      42,    43,    44,    45,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,     1,    -1,    42,
      43,    44,    45,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,     1,    -1,    42,    43,
      44,    45,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,     1,    -1,    42,    43,    44,
      45,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,     1,    -1,    42,    43,    44,    45,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,     1,    -1,    42,    43,    44,    45,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,     1,    -1,    42,    43,    44,    45,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,     1,    -1,    42,    43,    44,    45,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
       1,    -1,    42,    43,    44,    45,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     1,
      -1,    42,    43,    44,    45,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     1,    -1,
      42,    43,    44,    45,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,     1,    -1,    42,
      43,    44,    45,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    43,
      44,    45,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    44,
      45,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    44,    45,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,     1,     7,    -1,    -1,    10,    11,    12,
      13,    14,    39,    -1,    -1,    -1,    43,    15,    16,    17,
      18,    19,    20,    21,    22,    28,    24,    25,    26,    27,
      -1,    -1,     1,     7,    -1,    -1,    10,    11,    12,    13,
      14,    44,    45,    -1,    -1,    43,    15,    16,    17,    18,
      19,    20,    21,    22,    28,    24,    25,    26,    27,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    43,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
     130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    23,
      -1,    39,    -1,   143,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    -1,   156,   157,   158,   159
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    47,    48,    49,    36,    38,     0,    48,     1,
       3,     4,     5,     6,    50,    51,     1,    28,    55,    56,
      58,     1,    37,     1,    40,    41,    36,    39,    43,    57,
      29,    30,    31,    32,    33,    52,    52,    23,    28,    38,
      52,    68,    69,    51,    36,    58,    68,    38,    41,    68,
       1,    15,    16,    17,    18,    19,    20,    21,    22,    24,
      25,    26,    27,    42,    51,    57,    68,    70,    68,    39,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    40,    53,    44,    59,    43,    71,    39,
      42,    52,    54,    60,     1,    37,    68,    54,     7,    10,
      11,    12,    13,    14,    28,    45,    59,    61,    62,    66,
      71,    38,    38,    38,    28,    34,    63,    65,    68,    68,
      36,    41,    68,    68,    28,    43,    64,    68,    68,    39,
      39,    40,    65,    42,     8,    61,    68,    64,    36,    61,
       1,    43,    68,     9,    67,    68,    68,    61,     1,    43,
       1,    43,    68,    68,    68,    68,    39,    39,    39,    39,
      61,    61,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      57,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     4,     3,     8,     8,
       3,     3,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     1,     1,     0,     2,
       3,     0,     3,     3,     2,     0,     1,     2,     2,     2,
       1,     1,     0,     3,     6,     2,     3,     0,     1,     1,
       7,     5,    11,    11,    11,    11,     2,     0,     1,     3,
       2,     1,     4,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     0,
       3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
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
  case 2: /* program: declaration_list  */
#line 98 "parser.y"
                                                    { tree = (yyvsp[0].ast); }
#line 1571 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration declaration_list  */
#line 101 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_DECL_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1577 "y.tab.c"
    break;

  case 4: /* declaration_list: %empty  */
#line 102 "parser.y"
                                                        { (yyval.ast) = 0; }
#line 1583 "y.tab.c"
    break;

  case 5: /* declaration: TK_IDENTIFIER '=' type_and_value ';'  */
#line 105 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECL_VAR, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1589 "y.tab.c"
    break;

  case 6: /* declaration: TK_IDENTIFIER '=' type_and_value error  */
#line 106 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECL_VAR, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); yyerrok; syntax_errors++;  fprintf(stderr, "Missing ';'\n");}
#line 1595 "y.tab.c"
    break;

  case 7: /* declaration: TK_IDENTIFIER '=' error  */
#line 107 "parser.y"
                                                                        { (yyval.ast) = 0; yyerrok; syntax_errors++;  fprintf(stderr, "Wrong assignment!\n");}
#line 1601 "y.tab.c"
    break;

  case 8: /* declaration: TK_IDENTIFIER '(' maybe_params ')' '=' type command_block ';'  */
#line 108 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECL_FUNC, (yyvsp[-7].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), 0); }
#line 1607 "y.tab.c"
    break;

  case 9: /* declaration: TK_IDENTIFIER '(' maybe_params ')' '=' type command_block error  */
#line 109 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_DECL_FUNC, (yyvsp[-7].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), 0); yyerrok; syntax_errors++;  fprintf(stderr, "Missing ';'\n");}
#line 1613 "y.tab.c"
    break;

  case 10: /* declaration: TK_IDENTIFIER '(' error  */
#line 110 "parser.y"
                                                                        { (yyval.ast) = 0; yyerrok; syntax_errors++;  fprintf(stderr, "Wrong assignment!\n");}
#line 1619 "y.tab.c"
    break;

  case 11: /* type_and_value: type ':' lit  */
#line 113 "parser.y"
                                                                        { (yyval.ast) = astCreate(AST_TYPE_AND_VALUE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1625 "y.tab.c"
    break;

  case 12: /* type_and_value: type error lit  */
#line 114 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_TYPE_AND_VALUE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); yyerrok; syntax_errors++;  fprintf(stderr, "Wrong type and value (missing ':')!\n");}
#line 1631 "y.tab.c"
    break;

  case 13: /* type_and_value: type '[' expr ']' vet_maybe_value  */
#line 115 "parser.y"
                                                                 { (yyval.ast) = astCreate(AST_TYPE_AND_VALUE_ARRAY, 0, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1637 "y.tab.c"
    break;

  case 14: /* type: KW_CHAR  */
#line 119 "parser.y"
                                                { (yyval.ast) = astCreate(AST_KW_CHAR, 0, 0, 0, 0, 0); }
#line 1643 "y.tab.c"
    break;

  case 15: /* type: KW_BOOL  */
#line 120 "parser.y"
                                                { (yyval.ast) = astCreate(AST_KW_BOOL, 0, 0, 0, 0, 0); }
#line 1649 "y.tab.c"
    break;

  case 16: /* type: KW_INT  */
#line 121 "parser.y"
                                                { (yyval.ast) = astCreate(AST_KW_INT, 0, 0, 0, 0, 0); }
#line 1655 "y.tab.c"
    break;

  case 17: /* type: KW_FLOAT  */
#line 122 "parser.y"
                                                { (yyval.ast) = astCreate(AST_KW_FLOAT, 0, 0, 0, 0, 0); }
#line 1661 "y.tab.c"
    break;

  case 18: /* lit: LIT_CHAR  */
#line 125 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL_CHAR, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1667 "y.tab.c"
    break;

  case 19: /* lit: LIT_INTEGER  */
#line 126 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL_INTEGER, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1673 "y.tab.c"
    break;

  case 20: /* lit: LIT_FLOAT  */
#line 127 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL_FLOAT, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1679 "y.tab.c"
    break;

  case 21: /* lit: LIT_TRUE  */
#line 128 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL_TRUE, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1685 "y.tab.c"
    break;

  case 22: /* lit: LIT_FALSE  */
#line 129 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL_FALSE, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1691 "y.tab.c"
    break;

  case 23: /* vet_maybe_value: ':' vet_value  */
#line 132 "parser.y"
                                                { (yyval.ast) = astCreate(AST_VALUE, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1697 "y.tab.c"
    break;

  case 24: /* vet_maybe_value: %empty  */
#line 133 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1703 "y.tab.c"
    break;

  case 25: /* vet_value: lit vet_value  */
#line 136 "parser.y"
                                                { (yyval.ast) = astCreate(AST_VET_VALUES, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1709 "y.tab.c"
    break;

  case 26: /* vet_value: lit  */
#line 137 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1715 "y.tab.c"
    break;

  case 27: /* maybe_params: param_list  */
#line 140 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1721 "y.tab.c"
    break;

  case 28: /* maybe_params: %empty  */
#line 141 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1727 "y.tab.c"
    break;

  case 29: /* param_list: param param_list_ext  */
#line 144 "parser.y"
                                                { (yyval.ast) = astCreate(AST_PARAM_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1733 "y.tab.c"
    break;

  case 30: /* param_list_ext: ',' param param_list_ext  */
#line 147 "parser.y"
                                                { (yyval.ast) = astCreate(AST_PARAM_LIST_EXT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1739 "y.tab.c"
    break;

  case 31: /* param_list_ext: %empty  */
#line 148 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1745 "y.tab.c"
    break;

  case 32: /* param: TK_IDENTIFIER '=' type  */
#line 151 "parser.y"
                                                { (yyval.ast) = astCreate(AST_PARAM, (yyvsp[-2].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1751 "y.tab.c"
    break;

  case 33: /* command_block: '{' command_seq '}'  */
#line 154 "parser.y"
                                                { (yyval.ast) = astCreate(AST_CMD_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1757 "y.tab.c"
    break;

  case 34: /* command_seq: command_seq command  */
#line 157 "parser.y"
                                                { (yyval.ast) = astCreate(AST_CMD_SEQ, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1763 "y.tab.c"
    break;

  case 35: /* command_seq: %empty  */
#line 158 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1769 "y.tab.c"
    break;

  case 36: /* command: command_attribute  */
#line 161 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1775 "y.tab.c"
    break;

  case 37: /* command: KW_READ TK_IDENTIFIER  */
#line 162 "parser.y"
                                                { (yyval.ast) = astCreate(AST_READ, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1781 "y.tab.c"
    break;

  case 38: /* command: KW_RETURN expr  */
#line 163 "parser.y"
                                                { (yyval.ast) = astCreate(AST_RETURN, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1787 "y.tab.c"
    break;

  case 39: /* command: KW_PRINT print_list  */
#line 164 "parser.y"
                                                { (yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1793 "y.tab.c"
    break;

  case 40: /* command: command_control  */
#line 165 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1799 "y.tab.c"
    break;

  case 41: /* command: command_block  */
#line 166 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1805 "y.tab.c"
    break;

  case 42: /* command: %empty  */
#line 167 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1811 "y.tab.c"
    break;

  case 43: /* command_attribute: TK_IDENTIFIER '=' expr  */
#line 170 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_ATTR, (yyvsp[-2].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1817 "y.tab.c"
    break;

  case 44: /* command_attribute: TK_IDENTIFIER '[' expr ']' '=' expr  */
#line 171 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_ATTR_ARRAY, (yyvsp[-5].symbol), (yyvsp[-3].ast), (yyvsp[0].ast), 0, 0); }
#line 1823 "y.tab.c"
    break;

  case 45: /* print_list: print_elem print_extra_elems  */
#line 174 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_PRINT_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1829 "y.tab.c"
    break;

  case 46: /* print_extra_elems: ',' print_elem print_extra_elems  */
#line 177 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_PRINT_EXTRA_ELEMS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1835 "y.tab.c"
    break;

  case 47: /* print_extra_elems: %empty  */
#line 178 "parser.y"
                                                        { (yyval.ast) = 0; }
#line 1841 "y.tab.c"
    break;

  case 48: /* print_elem: LIT_STRING  */
#line 181 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_SYMBOL_STRING, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1847 "y.tab.c"
    break;

  case 49: /* print_elem: expr  */
#line 182 "parser.y"
                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1853 "y.tab.c"
    break;

  case 50: /* command_control: KW_IF '(' expr ')' KW_THEN command maybe_else  */
#line 185 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_IF_THEN, 0, (yyvsp[-4].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0); }
#line 1859 "y.tab.c"
    break;

  case 51: /* command_control: KW_WHILE '(' expr ')' command  */
#line 186 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1865 "y.tab.c"
    break;

  case 52: /* command_control: KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' command  */
#line 187 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_LOOP, (yyvsp[-8].symbol), (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1871 "y.tab.c"
    break;

  case 53: /* command_control: KW_LOOP '(' TK_IDENTIFIER ':' expr error expr ',' expr ')' command  */
#line 188 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_LOOP, (yyvsp[-8].symbol), (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); yyerrok; syntax_errors++; fprintf(stderr, "Missing first ',' in LOOP !\n");}
#line 1877 "y.tab.c"
    break;

  case 54: /* command_control: KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr error expr ')' command  */
#line 189 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_LOOP, (yyvsp[-8].symbol), (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); yyerrok; syntax_errors++; fprintf(stderr, "Missing second ',' in LOOP !\n");}
#line 1883 "y.tab.c"
    break;

  case 55: /* command_control: KW_LOOP '(' TK_IDENTIFIER ':' expr error expr error expr ')' command  */
#line 190 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_LOOP, (yyvsp[-8].symbol), (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); yyerrok; syntax_errors++; fprintf(stderr, "Missing both ',' in LOOP !\n");}
#line 1889 "y.tab.c"
    break;

  case 56: /* maybe_else: KW_ELSE command  */
#line 193 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_MAYBE_ELSE, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1895 "y.tab.c"
    break;

  case 57: /* maybe_else: %empty  */
#line 194 "parser.y"
                                                        { (yyval.ast) = 0; }
#line 1901 "y.tab.c"
    break;

  case 58: /* expr: bin_expr  */
#line 197 "parser.y"
                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1907 "y.tab.c"
    break;

  case 59: /* expr: '(' expr ')'  */
#line 198 "parser.y"
                                                        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1913 "y.tab.c"
    break;

  case 60: /* expr: OPERATOR_NOT expr  */
#line 199 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1919 "y.tab.c"
    break;

  case 61: /* expr: TK_IDENTIFIER  */
#line 200 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_SYMBOL_IDENTIFIER, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1925 "y.tab.c"
    break;

  case 62: /* expr: TK_IDENTIFIER '[' expr ']'  */
#line 201 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_ARRAY_CALL, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1931 "y.tab.c"
    break;

  case 63: /* expr: TK_IDENTIFIER '(' function_call_args ')'  */
#line 202 "parser.y"
                                                        { (yyval.ast) = astCreate(AST_FUNC_CALL, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1937 "y.tab.c"
    break;

  case 64: /* expr: lit  */
#line 203 "parser.y"
                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1943 "y.tab.c"
    break;

  case 65: /* bin_expr: expr OPERATOR_PLUS expr  */
#line 206 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_PLUS, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1949 "y.tab.c"
    break;

  case 66: /* bin_expr: expr OPERATOR_MINUS expr  */
#line 207 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_MINUS, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1955 "y.tab.c"
    break;

  case 67: /* bin_expr: expr OPERATOR_MULT expr  */
#line 208 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_MULT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1961 "y.tab.c"
    break;

  case 68: /* bin_expr: expr OPERATOR_DIV expr  */
#line 209 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1967 "y.tab.c"
    break;

  case 69: /* bin_expr: expr OPERATOR_LE expr  */
#line 210 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1973 "y.tab.c"
    break;

  case 70: /* bin_expr: expr OPERATOR_LT expr  */
#line 211 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1979 "y.tab.c"
    break;

  case 71: /* bin_expr: expr OPERATOR_GE expr  */
#line 212 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1985 "y.tab.c"
    break;

  case 72: /* bin_expr: expr OPERATOR_GT expr  */
#line 213 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1991 "y.tab.c"
    break;

  case 73: /* bin_expr: expr OPERATOR_EQ expr  */
#line 214 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1997 "y.tab.c"
    break;

  case 74: /* bin_expr: expr OPERATOR_DIF expr  */
#line 215 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 2003 "y.tab.c"
    break;

  case 75: /* bin_expr: expr OPERATOR_OR expr  */
#line 216 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 2009 "y.tab.c"
    break;

  case 76: /* bin_expr: expr OPERATOR_AND expr  */
#line 217 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 2015 "y.tab.c"
    break;

  case 77: /* bin_expr: expr error expr  */
#line 218 "parser.y"
                                                    { (yyval.ast) = 0; yyerrok; syntax_errors++; fprintf(stderr, "Invalid binary operation!\n");}
#line 2021 "y.tab.c"
    break;

  case 78: /* function_call_args: expr func_args_extra  */
#line 222 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_FUNC_CALL_ARGS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 2027 "y.tab.c"
    break;

  case 79: /* function_call_args: %empty  */
#line 223 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 2033 "y.tab.c"
    break;

  case 80: /* func_args_extra: ',' expr func_args_extra  */
#line 226 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_FUNC_CALL_ARGS_EXT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 2039 "y.tab.c"
    break;

  case 81: /* func_args_extra: %empty  */
#line 227 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 2045 "y.tab.c"
    break;


#line 2049 "y.tab.c"

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

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 230 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d.\n", getLineNumber());
}
