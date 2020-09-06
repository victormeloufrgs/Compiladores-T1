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
     KW_BYTE = 258,
     KW_SHORT = 259,
     KW_LONG = 260,
     KW_FLOAT = 261,
     KW_DOUBLE = 262,
     KW_WHEN = 263,
     KW_THEN = 264,
     KW_ELSE = 265,
     KW_WHILE = 266,
     KW_FOR = 267,
     KW_TO = 268,
     KW_READ = 269,
     KW_RETURN = 270,
     KW_PRINT = 271,
     OPERATOR_LE = 272,
     OPERATOR_GE = 273,
     OPERATOR_EQ = 274,
     OPERATOR_NE = 275,
     OPERATOR_AND = 276,
     OPERATOR_OR = 277,
     LIT_INTEGER = 278,
     LIT_REAL = 279,
     LIT_CHAR = 280,
     LIT_STRING = 281,
     TK_IDENTIFIER = 282,
     TOKEN_ERROR = 283,
     LOWER_THAN_ELSE = 284
   };
#endif
/* Tokens.  */
#define KW_BYTE 258
#define KW_SHORT 259
#define KW_LONG 260
#define KW_FLOAT 261
#define KW_DOUBLE 262
#define KW_WHEN 263
#define KW_THEN 264
#define KW_ELSE 265
#define KW_WHILE 266
#define KW_FOR 267
#define KW_TO 268
#define KW_READ 269
#define KW_RETURN 270
#define KW_PRINT 271
#define OPERATOR_LE 272
#define OPERATOR_GE 273
#define OPERATOR_EQ 274
#define OPERATOR_NE 275
#define OPERATOR_AND 276
#define OPERATOR_OR 277
#define LIT_INTEGER 278
#define LIT_REAL 279
#define LIT_CHAR 280
#define LIT_STRING 281
#define TK_IDENTIFIER 282
#define TOKEN_ERROR 283
#define LOWER_THAN_ELSE 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "parser.y"
{ HASH_NODE *symbol; }
/* Line 1529 of yacc.c.  */
#line 109 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

