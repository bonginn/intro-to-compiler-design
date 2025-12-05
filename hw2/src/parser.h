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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    ID = 258,                      /* ID  */
    VAR = 259,                     /* VAR  */
    TYPE = 260,                    /* TYPE  */
    INTEGER = 261,                 /* INTEGER  */
    BOOLEAN = 262,                 /* BOOLEAN  */
    STRING = 263,                  /* STRING  */
    REAL = 264,                    /* REAL  */
    INTEGER_LITERAL = 265,         /* INTEGER_LITERAL  */
    BOOLEAN_LITERAL = 266,         /* BOOLEAN_LITERAL  */
    STRING_LITERAL = 267,          /* STRING_LITERAL  */
    REAL_LITERAL = 268,            /* REAL_LITERAL  */
    COLON = 269,                   /* COLON  */
    SEMICOLON = 270,               /* SEMICOLON  */
    COMMA = 271,                   /* COMMA  */
    LPAREN = 272,                  /* LPAREN  */
    RPAREN = 273,                  /* RPAREN  */
    LBRAKET = 274,                 /* LBRAKET  */
    RBRAKET = 275,                 /* RBRAKET  */
    START = 276,                   /* START  */
    END = 277,                     /* END  */
    PRINT = 278,                   /* PRINT  */
    ASSIGN = 279,                  /* ASSIGN  */
    READ = 280,                    /* READ  */
    DEF = 281,                     /* DEF  */
    IF = 282,                      /* IF  */
    THEN = 283,                    /* THEN  */
    ELSE = 284,                    /* ELSE  */
    WHILE = 285,                   /* WHILE  */
    DO = 286,                      /* DO  */
    FOR = 287,                     /* FOR  */
    TO = 288,                      /* TO  */
    RETURN = 289,                  /* RETURN  */
    ARRAY = 290,                   /* ARRAY  */
    OF = 291,                      /* OF  */
    ADD = 292,                     /* ADD  */
    SUB = 293,                     /* SUB  */
    MUL = 294,                     /* MUL  */
    DIV = 295,                     /* DIV  */
    MOD = 296,                     /* MOD  */
    LE = 297,                      /* LE  */
    NE = 298,                      /* NE  */
    GE = 299,                      /* GE  */
    GT = 300,                      /* GT  */
    LT = 301,                      /* LT  */
    EQ = 302,                      /* EQ  */
    AND = 303,                     /* AND  */
    OR = 304,                      /* OR  */
    NOT = 305,                     /* NOT  */
    UMINUS = 306                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
