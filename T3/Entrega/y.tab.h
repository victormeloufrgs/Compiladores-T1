/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 16 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
