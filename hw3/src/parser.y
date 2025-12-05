%{
#include "AST/BinaryOperator.hpp"
#include "AST/CompoundStatement.hpp"
#include "AST/ConstantValue.hpp"
#include "AST/FunctionInvocation.hpp"
#include "AST/UnaryOperator.hpp"
#include "AST/VariableReference.hpp"
#include "AST/assignment.hpp"
#include "AST/ast.hpp"
#include "AST/decl.hpp"
#include "AST/expression.hpp"
#include "AST/for.hpp"
#include "AST/function.hpp"
#include "AST/if.hpp"
#include "AST/print.hpp"
#include "AST/program.hpp"
#include "AST/read.hpp"
#include "AST/return.hpp"
#include "AST/variable.hpp"
#include "AST/while.hpp"
#include "AST/AstDumper.hpp"
#include "AST/PType.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define YYLTYPE yyltype

typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;

extern uint32_t line_num;   /* declared in scanner.l */
extern char current_line[]; /* declared in scanner.l */
extern FILE *yyin;          /* declared by lex */
extern char *yytext;        /* declared by lex */

static AstNode *root;

extern "C" int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);
%}

// This guarantees that headers do not conflict when included together.
%define api.token.prefix {TOK_}

%code requires {
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
}   

    /* For yylval */
%union {
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
};

%type <node> Statement Simple FunctionCall 
%type <identifier> ProgramName ID FunctionName
%type <compound_stmt_ptr> CompoundStatement ElseOrNot
%type <declaration_ptr> Declaration FormalArg
%type <declaration_list_ptr> DeclarationList Declarations
%type <function_ptr> Function FunctionDeclaration FunctionDefinition
%type <function_list_ptr> FunctionList Functions
%type <variable_list_ptr> IdList
%type <declaration_list_ptr> FormalArgList FormalArgs
%type <type_ptr> ScalarType ArrType Type ReturnType
%type <dimension_list_ptr> ArrDecl
%type <constant_value_ptr> LiteralConstant StringAndBoolean IntegerAndReal
%type <neg_or_not> NegOrNot
%type <node_list_ptr> StatementList Statements
%type <if_ptr> Condition
%type <while_ptr> While
%type <for_ptr> For
%type <return_ptr> Return
%type <expression_ptr> Expression
%type <print_ptr> Print
%type <function_invocation_ptr> FunctionInvocation
%type <expression_list_ptr> ExpressionList Expressions ArrRefs ArrRefList
%type <variable_reference_ptr> VariableReference
%type <assignment_ptr> Assignment
%type <read_ptr> Read
%type <if_ptr> If

    /* Follow the order in scanner.l */

    /* Delimiter */
%token COMMA SEMICOLON COLON
%token L_PARENTHESIS R_PARENTHESIS
%token L_BRACKET R_BRACKET

    /* Operator */
%token ASSIGN
    /* TODO: specify the precedence of the following operators */
%token MULTIPLY DIVIDE MOD
%token LESS LESS_OR_EQUAL EQUAL GREATER GREATER_OR_EQUAL NOT_EQUAL
%token OR AND NOT
%token PLUS MINUS

    /* Keyword */
%token ARRAY BOOLEAN INTEGER REAL STRING
%token END BEGIN
%token DO ELSE FOR IF THEN WHILE
%token DEF OF TO RETURN VAR
%token FALSE TRUE
%token PRINT READ

    /* Identifier */
%token ID

    /* Literal */
%token <int_literal> INT_LITERAL
%token <real_literal> REAL_LITERAL
%token <string_literal> STRING_LITERAL

/* Operator precedence and associativity (low -> high) */
%left OR
%left AND
%nonassoc LESS LESS_OR_EQUAL GREATER GREATER_OR_EQUAL EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%right NOT
%right UMINUS

%%

ProgramUnit:
    Program
    |
    Function
;

Program:
    ProgramName SEMICOLON
    /* ProgramBody */
    DeclarationList FunctionList CompoundStatement
    /* End of ProgramBody */
    END {
        root = new ProgramNode(@1.first_line, @1.first_column,
                               $1, $3, $4, $5);

        free($1);
    }
;

ProgramName:
    ID
;

DeclarationList:
    Epsilon { $$ = new std::vector <DeclNode *>(); }
    |
    Declarations { $$ = $1; }
;

Declarations:
    Declaration { $$ = new std::vector <DeclNode *>(1, $1); }
    |
    Declarations Declaration {
        $$ = $1;
        $$->push_back($2);
    }
;

FunctionList:
    Epsilon { $$ = new std::vector <FunctionNode *>(); }
    |
    Functions { $$ = $1; }
;

Functions:
    Function { $$ = new std::vector <FunctionNode *>(1, $1); }
    |
    Functions Function {
        $$ = $1;
        $$->push_back($2);
    }
;

Function:
    FunctionDeclaration { $$ = $1; }
    |
    FunctionDefinition { $$ = $1; }
;

FunctionDeclaration:
    FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType SEMICOLON {
        $$ = new FunctionNode(@1.first_line, @1.first_column, $1, $3, $5, nullptr);
    }
;

FunctionDefinition:
    FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType
    CompoundStatement
    END {
        $$ = new FunctionNode(@1.first_line, @1.first_column, $1, $3, $5, $6);
    }
;

FunctionName:
    ID { $$ = $1; }
;

FormalArgList:
    Epsilon { $$ = new std::vector <DeclNode *>(); }
    |
    FormalArgs {
        $$ = $1;
    }
;

FormalArgs:
    FormalArg {
        $$ = new std::vector <DeclNode *>(1, $1);
    }
    |
    FormalArgs SEMICOLON FormalArg {
        $$ = $1;
        $$->push_back($3);
    }
;

FormalArg:
    IdList COLON Type {
        for (auto &v : *$1) {
            v->setType($3);
        }
        $$ = new DeclNode(@1.first_line, @1.first_column, $1);
    }
;

IdList:
    ID {
        $$ = new std::vector<VariableNode*>();
        $$->push_back(new VariableNode(@1.first_line, @1.first_column, $1));
    }
    |
    IdList COMMA ID {
        $$ = $1;
        $$->push_back(new VariableNode(@3.first_line, @3.first_column, $3));
    }
;

ReturnType:
    COLON ScalarType { $$ = $2; }
    |
    Epsilon { $$ = nullptr; }
;

    /*
       Data Types and Declarations
                                   */

Declaration:
    VAR IdList COLON Type SEMICOLON {
        for (auto &v : *$2) {
            v->setType($4);
        }
        $$ = new DeclNode(@1.first_line, @1.first_column, $2);
    }
    |
    VAR IdList COLON LiteralConstant SEMICOLON {
        for (auto &v : *$2){
            v->setConstant($4);
        }
        $$ = new DeclNode(@1.first_line, @1.first_column, $2);
    }
;

Type:
    ScalarType { $$ = $1; }
    |
    ArrType { $$ = $1; }
;

ScalarType:
    INTEGER { $$ = new PType(PType::kInteger); }
    |
    REAL { $$ = new PType(PType::kReal); }
    |
    STRING { $$ = new PType(PType::kString); }
    |
    BOOLEAN { $$ = new PType(PType::kBoolean); }
;

ArrType:
    ArrDecl ScalarType {
        $$ = $2;
        for (auto &dim : *$1) {
            $$->addDimension(dim);
        }
    }
;

ArrDecl:
    ARRAY INT_LITERAL OF {
        $$ = new std::vector <int>(1, $2);
    }
    |
    ArrDecl ARRAY INT_LITERAL OF{
        $$ = $1;
        $$->push_back($3);
    }
;

LiteralConstant:
    NegOrNot INT_LITERAL {
        $$ = ($1) ? 
            new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kInteger), -$2) :
            new ConstantValueNode(@2.first_line, @2.first_column, new PType(PType::kInteger), $2);
    }
    |
    NegOrNot REAL_LITERAL {
        $$ = ($1) ? 
            new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kReal), -$2) :
            new ConstantValueNode(@2.first_line, @2.first_column, new PType(PType::kReal), $2);
    }
    |
    StringAndBoolean {
        $$ = $1;
    }
;

NegOrNot:
    Epsilon { $$ = false;}
    |
    MINUS { $$ = true;}
;

StringAndBoolean:
    STRING_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kString), $1);
    }
    |
    TRUE {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kBoolean), true);
    }
    |
    FALSE {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kBoolean), false);
    }
;

IntegerAndReal:
    INT_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kInteger), $1);
    }
    |
    REAL_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column, new PType(PType::kReal), $1);
    }
;

    /*
       Statements
                  */

Statement:
    CompoundStatement { $$ = $1; }
    |
    Simple { $$ = $1; }
    |
    Condition { $$ = $1; }
    |
    While { $$ = $1; }
    |
    For { $$ = $1; }
    |
    Return { $$ = $1; }
    |
    FunctionCall { $$ = $1; }
;

CompoundStatement:
    BEGIN
    DeclarationList
    StatementList
    END {
        $$ = new CompoundStatementNode(@1.first_line, @1.first_column, $2, $3);
    }
;

Simple:
    VariableReference ASSIGN Expression SEMICOLON {
        $$ = new AssignmentNode(@2.first_line, @2.first_column, $1, $3);
    }
    |
    PRINT Expression SEMICOLON {
        $$ = new PrintNode(@1.first_line, @1.first_column, $2);
    }
    |
    READ VariableReference SEMICOLON {
        $$ = new ReadNode(@1.first_line, @1.first_column, $2);
    }
;

VariableReference:
    ID ArrRefList {
        $$ = new VariableReferenceNode(@1.first_line, @1.first_column, $1, $2);
    }
;

ArrRefList:
    Epsilon { $$ = new std::vector <ExpressionNode*>(); }
    |
    ArrRefs {
        $$ = $1;
    }
;

ArrRefs:
    L_BRACKET Expression R_BRACKET {
        $$ = new std::vector <ExpressionNode*>(1, $2);
    }
    |
    ArrRefs L_BRACKET Expression R_BRACKET {
        $$ = $1;
        $$->push_back($3);
    }
;

Condition:
    IF Expression THEN 
    CompoundStatement
    ElseOrNot
    END IF {
        $$ = new IfNode(@1.first_line, @1.first_column, $2, $4, $5);
    }
;

ElseOrNot:
    ELSE
    CompoundStatement { $$ = $2; }
    |
    Epsilon { $$ = nullptr;}
;

While:
    WHILE Expression DO
    CompoundStatement
    END DO {
        $$ = new WhileNode(@1.first_line, @1.first_column, $2, $4);
    }
;

For:
    FOR ID ASSIGN INT_LITERAL TO INT_LITERAL DO
    CompoundStatement
    END DO {
        // Variable Node
        VariableNode *var = new VariableNode(@2.first_line, @2.first_column, $2);
        var->setType(new PType(PType::kInteger));

        // Declaration Node
        DeclNode *decl = new DeclNode(@2.first_line, @2.first_column, new std::vector<VariableNode*>(1, var));

        // Variable Reference Node
        VariableReferenceNode *var_ref = new VariableReferenceNode(@2.first_line, @2.first_column, $2, new std::vector<ExpressionNode*>());

        // Initial value
        ConstantValueNode *init_value = new ConstantValueNode(@4.first_line, @4.first_column, new PType(PType::kInteger), $4);

        // Assignment Node
        AssignmentNode *assign = new AssignmentNode(@3.first_line, @3.first_column, var_ref, init_value);

        // Upper Bound Node
        ConstantValueNode *upper_bound = new ConstantValueNode(@6.first_line, @6.first_column, new PType(PType::kInteger), $6);

        // For Node
        $$ = new ForNode(@1.first_line, @1.first_column, decl, assign, upper_bound, $8);
    }
;

Return:
    RETURN Expression SEMICOLON {
        $$ = new ReturnNode(@1.first_line, @1.first_column, $2);
    }
;

FunctionCall:
    FunctionInvocation SEMICOLON {
        $$ = $1;
    }
;

FunctionInvocation:
    ID L_PARENTHESIS ExpressionList R_PARENTHESIS {
        $$ = new FunctionInvocationNode(@1.first_line, @1.first_column, $1, $3);
    }
;

ExpressionList:
    Epsilon { $$ = new std::vector <ExpressionNode*>(); }
    |
    Expressions { $$ = $1; }
;

Expressions:
    Expression { $$ = new std::vector <ExpressionNode*>(1, $1); }
    |
    Expressions COMMA Expression {
        $$ = $1;
        $$->push_back($3);
    }
;

StatementList:
    Epsilon { $$ = new std::vector <AstNode*>(); }
    |
    Statements { $$ = $1; }
;

Statements:
    Statement { $$ = new std::vector <AstNode*>(1, $1); }
    |
    Statements Statement {
        $$ = $1;
        $$->push_back($2);
    }
;

Expression:
    L_PARENTHESIS Expression R_PARENTHESIS {
        $$ = $2;
    }
    |
    MINUS Expression %prec UMINUS {
        $$ = new UnaryOperatorNode(@1.first_line, @1.first_column, new OperatorNode(OperatorNode::UNARY_MINUS), $2);
    }
    |
    Expression MULTIPLY Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::MULTIPLY), $1, $3);
    }
    |
    Expression DIVIDE Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::DIVIDE), $1, $3);
    }
    |
    Expression MOD Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::MOD), $1, $3);
    }
    |
    Expression PLUS Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::PLUS), $1, $3);
    }
    |
    Expression MINUS Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::MINUS), $1, $3);
    }
    |
    Expression LESS Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::LESS), $1, $3);
    }
    |
    Expression LESS_OR_EQUAL Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::LESS_OR_EQUAL), $1, $3);
    }
    |
    Expression GREATER Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::GREATER), $1, $3);
    }
    |
    Expression GREATER_OR_EQUAL Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::GREATER_OR_EQUAL), $1, $3);
    }
    |
    Expression EQUAL Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::EQUAL), $1, $3);
    }
    |
    Expression NOT_EQUAL Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::NOT_EQUAL), $1, $3);
    }
    |
    NOT Expression {
        $$ = new UnaryOperatorNode(@1.first_line, @1.first_column, new OperatorNode(OperatorNode::NOT), $2);
    }
    |
    Expression AND Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::AND), $1, $3);
    }
    |
    Expression OR Expression {
        $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, new OperatorNode(OperatorNode::OR), $1, $3);
    }
    |
    IntegerAndReal { $$ = $1; }
    |
    StringAndBoolean { $$ = $1; }
    |
    VariableReference { $$ = $1; }
    |
    FunctionInvocation {
        $$ = $1;
    }
;

    /*
       misc
            */
Epsilon:
;

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
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename> [--dump-ast]\n", argv[0]);
        exit(-1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("fopen() failed");
        exit(-1);
    }

    yyparse();

    if (argc >= 3 && strcmp(argv[2], "--dump-ast") == 0) {
        AstDumper ast_dumper;
        root->accept(ast_dumper);
    }

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");

    delete root;
    fclose(yyin);
    yylex_destroy();
    return 0;
}
