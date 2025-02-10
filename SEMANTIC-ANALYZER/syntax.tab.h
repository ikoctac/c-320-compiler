
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_TYPEDEF = 258,
     T_CHAR = 259,
     T_INT = 260,
     T_FLOAT = 261,
     T_STRING = 262,
     T_CLASS = 263,
     T_PRIVATE = 264,
     T_PROTECTED = 265,
     T_PUBLIC = 266,
     T_VOID = 267,
     T_STATIC = 268,
     T_UNION = 269,
     T_ENUM = 270,
     T_LIST = 271,
     T_CONTINUE = 272,
     T_BREAK = 273,
     T_IF = 274,
     T_ELSE = 275,
     T_WHILE = 276,
     T_FOR = 277,
     T_SWITCH = 278,
     T_CASE = 279,
     T_DEFAULT = 280,
     T_RETURN = 281,
     T_LENGTH = 282,
     T_NEW = 283,
     T_CIN = 284,
     T_COUT = 285,
     T_MAIN = 286,
     T_THIS = 287,
     T_ID = 288,
     T_ICONST = 289,
     T_FCONST = 290,
     T_CCONST = 291,
     T_SCONST = 292,
     T_OROP = 293,
     T_ANDOP = 294,
     T_EQUOP = 295,
     T_RELOP = 296,
     T_ADDOP = 297,
     T_MULOP = 298,
     T_NOTOP = 299,
     T_INCDEC = 300,
     T_SIZEOP = 301,
     T_LISTFUNC = 302,
     T_LPAREN = 303,
     T_RPAREN = 304,
     T_SEMI = 305,
     T_DOT = 306,
     T_COMMA = 307,
     T_ASSIGN = 308,
     T_COLON = 309,
     T_LBRACK = 310,
     T_RBRACK = 311,
     T_REFER = 312,
     T_LBRACE = 313,
     T_RBRACE = 314,
     T_METH = 315,
     T_INP = 316,
     T_OUT = 317,
     LOWER_THAN_ELSE = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 22 ".\\syntax.y"
        //used to define multiple data types that a token or nonterminal can hold
    int ival;   //integer numbers 123,3421 etc
    float fval; //floating point numbers
    char cval; //single digits 'a'/'n'
    char* sval; //string like "hello"

    //union is like a magic box where you can store different types of things but only one thing at a time
    //the lexer (scanner) reads words/numbers and puts them into yylval
    //the parser (bison) takes yylval and decides what to do with it.
    //each token (integer, string, etc.) knows where to store its value inside the %union



/* Line 1676 of yacc.c  */
#line 130 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


