/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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
    PTYPE = 258,                   /* PTYPE  */
    PP = 259,                      /* PP  */
    MM = 260,                      /* MM  */
    LE = 261,                      /* LE  */
    GE = 262,                      /* GE  */
    EQ = 263,                      /* EQ  */
    NE = 264,                      /* NE  */
    AND = 265,                     /* AND  */
    OR = 266,                      /* OR  */
    LB = 267,                      /* LB  */
    RB = 268,                      /* RB  */
    CLASS = 269,                   /* CLASS  */
    ELSE = 270,                    /* ELSE  */
    FINAL = 271,                   /* FINAL  */
    FOR = 272,                     /* FOR  */
    IF = 273,                      /* IF  */
    MAIN = 274,                    /* MAIN  */
    NEW = 275,                     /* NEW  */
    PRINT = 276,                   /* PRINT  */
    RETURN = 277,                  /* RETURN  */
    STATIC = 278,                  /* STATIC  */
    VOID = 279,                    /* VOID  */
    WHILE = 280,                   /* WHILE  */
    ID = 281,                      /* ID  */
    INT_N = 282,                   /* INT_N  */
    FLOAT_N = 283,                 /* FLOAT_N  */
    STR = 284                      /* STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PTYPE 258
#define PP 259
#define MM 260
#define LE 261
#define GE 262
#define EQ 263
#define NE 264
#define AND 265
#define OR 266
#define LB 267
#define RB 268
#define CLASS 269
#define ELSE 270
#define FINAL 271
#define FOR 272
#define IF 273
#define MAIN 274
#define NEW 275
#define PRINT 276
#define RETURN 277
#define STATIC 278
#define VOID 279
#define WHILE 280
#define ID 281
#define INT_N 282
#define FLOAT_N 283
#define STR 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "B092040016.y"

    char strVal[80];

#line 129 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
