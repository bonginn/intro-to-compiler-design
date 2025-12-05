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
/* "%code requires" blocks.  */
#line 54 "parser.y"

    class AstNode;
    class CompoundStatementNode;
    class DeclNode;
    class FunctionNode;
    class VariableNode;
    class PType;
    class ConstantValueNode;
    class IfNode;
    class WhileNode;
    class ReturnNode;
    class ForNode;
    class ExpressionNode;
    class PrintNode;
    class FunctionInvocationNode;
    class VariableReferenceNode;
    class AssignmentNode;
    class ReadNode;

#line 69 "parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_YYEMPTY = -2,
    TOK_YYEOF = 0,                 /* "end of file"  */
    TOK_YYerror = 256,             /* error  */
    TOK_YYUNDEF = 257,             /* "invalid token"  */
    TOK_COMMA = 258,               /* COMMA  */
    TOK_SEMICOLON = 259,           /* SEMICOLON  */
    TOK_COLON = 260,               /* COLON  */
    TOK_L_PARENTHESIS = 261,       /* L_PARENTHESIS  */
    TOK_R_PARENTHESIS = 262,       /* R_PARENTHESIS  */
    TOK_L_BRACKET = 263,           /* L_BRACKET  */
    TOK_R_BRACKET = 264,           /* R_BRACKET  */
    TOK_ASSIGN = 265,              /* ASSIGN  */
    TOK_MULTIPLY = 266,            /* MULTIPLY  */
    TOK_DIVIDE = 267,              /* DIVIDE  */
    TOK_MOD = 268,                 /* MOD  */
    TOK_LESS = 269,                /* LESS  */
    TOK_LESS_OR_EQUAL = 270,       /* LESS_OR_EQUAL  */
    TOK_EQUAL = 271,               /* EQUAL  */
    TOK_GREATER = 272,             /* GREATER  */
    TOK_GREATER_OR_EQUAL = 273,    /* GREATER_OR_EQUAL  */
    TOK_NOT_EQUAL = 274,           /* NOT_EQUAL  */
    TOK_OR = 275,                  /* OR  */
    TOK_AND = 276,                 /* AND  */
    TOK_NOT = 277,                 /* NOT  */
    TOK_PLUS = 278,                /* PLUS  */
    TOK_MINUS = 279,               /* MINUS  */
    TOK_ARRAY = 280,               /* ARRAY  */
    TOK_BOOLEAN = 281,             /* BOOLEAN  */
    TOK_INTEGER = 282,             /* INTEGER  */
    TOK_REAL = 283,                /* REAL  */
    TOK_STRING = 284,              /* STRING  */
    TOK_END = 285,                 /* END  */
    TOK_BEGIN = 286,               /* BEGIN  */
    TOK_DO = 287,                  /* DO  */
    TOK_ELSE = 288,                /* ELSE  */
    TOK_FOR = 289,                 /* FOR  */
    TOK_IF = 290,                  /* IF  */
    TOK_THEN = 291,                /* THEN  */
    TOK_WHILE = 292,               /* WHILE  */
    TOK_DEF = 293,                 /* DEF  */
    TOK_OF = 294,                  /* OF  */
    TOK_TO = 295,                  /* TO  */
    TOK_RETURN = 296,              /* RETURN  */
    TOK_VAR = 297,                 /* VAR  */
    TOK_FALSE = 298,               /* FALSE  */
    TOK_TRUE = 299,                /* TRUE  */
    TOK_PRINT = 300,               /* PRINT  */
    TOK_READ = 301,                /* READ  */
    TOK_ID = 302,                  /* ID  */
    TOK_INT_LITERAL = 303,         /* INT_LITERAL  */
    TOK_REAL_LITERAL = 304,        /* REAL_LITERAL  */
    TOK_STRING_LITERAL = 305,      /* STRING_LITERAL  */
    TOK_UMINUS = 306               /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "parser.y"

    /* basic semantic value */
    char *identifier;

    AstNode *node;
    std::vector <AstNode*> *node_list_ptr;
    CompoundStatementNode *compound_stmt_ptr;
    DeclNode *declaration_ptr;
    std::vector <DeclNode*> *declaration_list_ptr;
    FunctionNode *function_ptr;
    std::vector <FunctionNode*> *function_list_ptr;
    VariableNode *variable_ptr;
    std::vector <VariableNode*> *variable_list_ptr;
    PType *type_ptr;
    std::vector <int> *dimension_list_ptr;
    ConstantValueNode *constant_value_ptr;
    FunctionInvocationNode *function_invocation_ptr;
    IfNode *if_ptr;
    WhileNode *while_ptr;
    ReturnNode *return_ptr;
    ForNode *for_ptr;
    ExpressionNode *expression_ptr;
    std::vector <ExpressionNode*> *expression_list_ptr;
    PrintNode *print_ptr;
    VariableReferenceNode *variable_reference_ptr;
    AssignmentNode *assignment_ptr;
    ReadNode *read_ptr;
    int int_literal;
    float real_literal;
    const char *string_literal;
    bool neg_or_not;

#line 170 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
