%{
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern int32_t line_num;    /* declared in scanner.l */
extern char current_line[]; /* declared in scanner.l */
extern FILE *yyin;          /* declared by lex */
extern char *yytext;        /* declared by lex */

extern int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);
%}

%token ID
%token VAR TYPE
%token INTEGER BOOLEAN STRING REAL
%token INTEGER_LITERAL BOOLEAN_LITERAL STRING_LITERAL REAL_LITERAL
%token COLON SEMICOLON COMMA LPAREN RPAREN LBRAKET RBRAKET
%token START END
%token PRINT ASSIGN READ DEF
%token IF THEN ELSE 
%token WHILE DO FOR TO 
%token RETURN
%token ARRAY OF
%token ADD SUB MUL DIV MOD
%token LE NE GE GT LT EQ
%token AND OR NOT

/* Precedence */
%left AND OR NOT
%nonassoc LT LE NE GE GT EQ
%left ADD SUB
%left MUL DIV MOD
%right UMINUS

%start ProgramUnit

%%

ProgramUnit:
    Program
  | Functions;

Program:
    ID SEMICOLON
    Declarations
    Functions
    CompoundStatement
    END;

Functions:
    /* empty */
  | Functions FunctionDeclaration
  | Functions FunctionDefinition;

FunctionDeclaration:
    FunctionHeader SEMICOLON;

FunctionDefinition:
    FunctionHeader CompoundStatement END;

FunctionHeader:
    ID LPAREN OptFormalArguments RPAREN COLON ScalarType
  | ID LPAREN OptFormalArguments RPAREN ;

OptFormalArguments:
    /* empty */
  | FormalArguments;

FormalArguments:
    FormalArgument
  | FormalArguments SEMICOLON FormalArgument;

FormalArgument:
    IDList COLON Type;

CompoundStatement:
    START
    Declarations
    Statements
    END;

Statements: 
    /* empty */
  | Statements Statement;

Statement:
    SimpleStatement
  | ConditionalStatement
  | FunctionCallStatement
  | LoopStatement
  | ReturnStatement
  | CompoundStatement;

SimpleStatement:
    VariableReference ASSIGN Expression SEMICOLON
  | PRINT Expression SEMICOLON
  | READ VariableReference SEMICOLON;

VariableReference:
    ID OptBracketsExpression;

OptBracketsExpression:
    /* empty */
  | BracketsExpression;

BracketsExpression:
    LBRAKET Expression RBRAKET
  | LBRAKET Expression RBRAKET BracketsExpression;

ConditionalStatement:
    IF Expression THEN CompoundStatement ELSE CompoundStatement END IF
  | IF Expression THEN CompoundStatement END IF;

FunctionCallStatement:
    FunctionCall SEMICOLON;

FunctionCall:
    ID LPAREN OptExpressionList RPAREN;

OptExpressionList:
    /* empty */
  | ExpressionList;

ExpressionList:
    Expression
  | ExpressionList COMMA Expression;

LoopStatement:
    WHILE Expression DO CompoundStatement END DO
  | FOR ID ASSIGN INTEGER_LITERAL TO INTEGER_LITERAL DO CompoundStatement END DO;

ReturnStatement:
    RETURN Expression SEMICOLON;

LiteralConstant:
    INTEGER_LITERAL
  | REAL_LITERAL
  | STRING_LITERAL
  | BOOLEAN_LITERAL;

Expression:
    Expression ADD Expression
  | Expression SUB Expression
  | Expression MUL Expression
  | Expression DIV Expression
  | Expression MOD Expression
  | Expression LT Expression
  | Expression LE Expression
  | Expression NE Expression
  | Expression GE Expression
  | Expression GT Expression
  | Expression EQ Expression
  | Expression AND Expression
  | Expression OR Expression
  | NOT Expression
  | SUB Expression %prec UMINUS
  | LPAREN Expression RPAREN
  | VariableReference
  | FunctionCall
  | LiteralConstant
  ;

Declarations:
    /* empty */
  | Declarations Declaration;

Declaration:
    VariableDeclaration
  | ConstantDeclaration;

VariableDeclaration:
    VAR IDList COLON Type SEMICOLON;

ConstantDeclaration:
    VAR IDList COLON ConstValue SEMICOLON;

IDList:
    ID
  | IDList COMMA ID ;
  
ConstValue:
    OptMinus INTEGER_LITERAL
  | OptMinus REAL_LITERAL
  | STRING_LITERAL
  | BOOLEAN_LITERAL;
  
OptMinus:
    /* empty */
    | SUB;

Type:
    ScalarType
  | ArrayType;

ScalarType:
    INTEGER
  | BOOLEAN
  | STRING
  | REAL;

ArrayType:
    ARRAY INTEGER_LITERAL OF Type;

%%

void yyerror(const char *msg) {
    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            line_num, current_line, yytext);
    exit(-1);
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("fopen() failed");
        exit(-1);
    }

    yyparse();

    fclose(yyin);
    yylex_destroy();

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
