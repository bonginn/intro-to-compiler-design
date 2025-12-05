# hw3 report

|      |                 |
| ---: | :-------------- |
| Name | Pang-Chun, Chung        |
|   ID | 111652031 |

## How much time did you spend on this project

> More than 24 hours.

## Project overview

There are three main layers in this project: scanner, parser, and AST.
1. For the scanner, I used the previous assignment's scanner as a reference. The only modification is that I added some semantic actions for numeric literals, e.g. `yylval.int_literal = atoi(yytext);` and `yylval.real_literal = strtod(yytext, NULL);`, so that the parsed tokens can carry the corresponding numeric values into the parser.
2. For the parser, the key additions include:
    - A `%union` definition to carry every AST pointer and literal type I need.
    - `%type` annotations to declare the types of the semantic values of the non-terminals.
    - Operator precedence and associativity rules (`%left`, `%right`, `%nonassoc`) to correctly handle complex expressions without ambiguity.
    - A set of grammar rules that define the entire language structure, from the top-level `Program` down to individual `Statement`s and `Expression`s. In the action block of each rule, I dynamically create the corresponding AST node (e.g., `new IfNode(...)`, `new BinaryOperatorNode(...)`) and link them together, passing the newly created node up the parse tree via `$$`. For example, the declaration rule is defined as follows:
        ```yacc
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
        ```
3. For the AST, I designed a tree structure to represent the source code's logic.
    - A base class `AstNode` is defined with a virtual `accept` method, implementing the Visitor design pattern. This allows for operations like `AstDumper` to traverse the tree without modifying the node classes.
    - A hierarchy of node classes inherits from `AstNode`, each representing a specific language construct (e.g., `ProgramNode`, `FunctionNode`, `IfNode`, `ForNode`). Each class stores pointers to its children, accurately capturing the program's structure. For instance, an `IfNode` holds a pointer to the condition expression, the "then" statement block, and the optional "else" statement block.
    - The `AstDumper` class is responsible for dumping the AST in the designated format using visitor pattern. 

## What is the hardest you think in this project

> I think the hardest part is understanding the structure of the project at the beginning, because the codebase is very large and complex, and there are many files and data structures to learn and implement. However, once I gained a clear understanding of the overall structure, the implementation itself was not very difficult.

## Feedback to T.A.s

> Maybe this assignment is one of the most challenging one I have ever done in NYCU. However, I think the quality of specification and instructions in this assignment is very good and clear, I learned a lot from it.
