# hw2 report

|||
|-:|:-|
|Name|Chung, Pang-Chun|
|ID|111652031|

## How much time did you spend on this project

> 5 hours. 

## Project overview

> Please describe the structure of your code and the ideas behind your implementation in an organized way. \
> The point is to show us how you deal with the problems. It is not necessary to write a lot of words or paste all of your code here. 

### Code Structure
``` markdown
hw2-bonginn/
├── src/
│   ├── Makefile        
│   ├── scanner.l       # Scanner
|   └── parser.y        # Parser (Implemented in this assignment)
└── report/
    └── README.md       # This report
```
### Design Ideas
1. Program Structure and Scoping
    The parser's foundation lies in defining clear structural blocks, which naturally supports scoping:

* Structure: The language is defined by a top-level `ProgramUnit`, distinguishing between a full `Program` (with declarations and a main body) and simple `Functions`.

* Scoping Mechanism: The `CompoundStatement` rule, bracketed by `START...END`, is the universal container for executable code. It houses local `Declarations` and `Statements`. This clear block structure is fundamental for implementing lexical scope during later semantic analysis.

2. Declarations and Type System Modeling
    The grammar explicitly models the language's variable and constant definitions:

* Declaration Handling: The `Declarations` section allows for global and local symbol registration. The use of `IDList` simplifies the declaration of multiple variables of the same type.

* Type System: `Type` is partitioned into basic `ScalarType` (e.g., INTEGER, BOOLEAN) and the structured `ArrayType`. The reason I separated them into two is because there is no function returning an `ArrayType` in this assignment.
> .... However, we do not have a function return an array_type for simplicity.

3. Function Design (Interface vs. Implementation)
    The design separates a function's usage from its execution logic:

* Separation of Concerns: The grammar distinguishes between a `FunctionDeclaration` (interface/signature only, ending with a semicolon) and a `FunctionDefinition` (signature followed by a `CompoundStatement` body). This supports the concept of forward declarations.

* Interface Definition: The `FunctionHeader` clearly specifies the function's name, its `FormalArguments`, and its return type (`COLON ScalarType`).

4. Expression Parsing and Precedence Management
    Correctly parsing expressions is handled by leveraging Bison's associativity and precedence features:

* Operator Hierarchy: Yacc/Bison directives (`%left`, `%nonassoc`, `%right`) are used extensively to enforce the standard mathematical operator precedence and associativity for arithmetic, relational, and logical operators.

* Unary Operator Solution: The specific issue of the unary minus operator is solved by assigning it the highest precedence using the `%prec UMINUS` directive, ensuring correct parsing in expressions like `-a+b`.

* Composition: The `Expression` rule is recursively defined to allow any valid combination of literals, variables, function calls, and parenthesized sub-expressions.

5. Control Flow Statements

    The control flow is defined using clear, well-delimited syntax rules:

* Block Structure: Conditional (`IF`) and loop (`WHILE`, `FOR`) statements are designed to strictly contain a `CompoundStatement` body, guaranteeing that their execution blocks have defined boundaries.

* Termination: Constructs like `IF` use an explicit `END IF` and loops use `END DO`, eliminating common ambiguities such as the Dangling Else problem.

## What is the hardest you think in this project
I think the hardest part is the unary minus and not handling. Distinguishing them is tricky because they use the same token.

## Feedback to T.A.s

I love you.