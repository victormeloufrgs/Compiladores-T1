/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CHAR = 258,
     KW_INT = 259,
     KW_FLOAT = 260,
     KW_BOOL = 261,
     KW_IF = 262,
     KW_THEN = 263,
     KW_ELSE = 264,
     KW_WHILE = 265,
     KW_LOOP = 266,
     KW_READ = 267,
     KW_PRINT = 268,
     KW_RETURN = 269,
     OPERATOR_LE = 270,
     OPERATOR_LT = 271,
     OPERATOR_GE = 272,
     OPERATOR_GT = 273,
     OPERATOR_EQ = 274,
     OPERATOR_DIF = 275,
     OPERATOR_OR = 276,
     OPERATOR_AND = 277,
     OPERATOR_NOT = 278,
     OPERATOR_PLUS = 279,
     OPERATOR_MINUS = 280,
     OPERATOR_MULT = 281,
     OPERATOR_DIV = 282,
     TK_IDENTIFIER = 283,
     LIT_INTEGER = 284,
     LIT_FLOAT = 285,
     LIT_TRUE = 286,
     LIT_FALSE = 287,
     LIT_CHAR = 288,
     LIT_STRING = 289,
     TOKEN_ERROR = 290
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "parser.y"
{ HASH_NODE *symbol; }
/* Line 1529 of yacc.c.  */
#line 121 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

