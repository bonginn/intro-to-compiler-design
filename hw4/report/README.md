# hw4 report

|||
|-:|:-|
|Name|Pang-Chun, Chung|
|ID|111652031|

## How much time did you spend on this project

> 12 hours.

## Project overview

### Overview
In this assignment, I implemented a semantic analyzer based on the AST from the previous assignment. The analyzer performs symbol table management, type checking, scope management and error reporting using the visitor pattern.

### Symbol Table Management
To manage the scope and symbol entry efficiently and correctly, I implemented a following three calsses:
1. SymbolEntry: To store the information of a symbol, including name, kind, level, type, attribute, etc.
2. SymbolTable: To store the symbol entries in a scope, member functions include addSymbol, lookup and dump.
3. SymbolManager: To manage the symbol tables(scopes), member functions include pushScope, popScope, lookup and addEntry.

### Switch Button
In this assignment, I also added a switch button of pseudocomment D for turning on/off the symbol table dumping. The implementation details invole modifying the `scanner.l` to recognize the pseudocomment `//&D+` and `//&D-` and set the global variable `dump_symbol_table` in `SemanticAnalyzer.hpp` to true or false accordingly. Before leaving a scope, if the flag is on, the symbol table will be dumped.

### Semantic Analysis
I implemented the SemanticAnalyzer class with Visitor Pattern to traverse the AST. The key features in my implementation are:
1. Context Management: 
    - Used `m_current_kind` to track the current context of variable declaration, distinguishing between program, parameter, loop_var, etc.
    - Used the `m_return_type_stack` to store the type of functions, validating the matching between the type of the return statement and the type of the function.
    - Used `m_just_enter_function_body` flag to prevent redundant scope creation when entering a function's body block.

2. Type Propagation & Checking:
    - Extended `ExpressionNode` to store a `PTypeSharedPtr`, allowing type information propagation from child nodes to parent nodes.
    - Implemented Array Dimension Peeling: When a variable reference involves indices, I cloned the original type and peeled off dimensions (using `popDimension`) to determine the actual type of the reference.
    - Type Coercion: Implemented `isCompatible` function to handle implicit type conversions between real and integer.

3. Error Handling:
    - Collected all semantic errors in the `m_error_messages` vector, and dumped them with precise line/column indication after analysis.


## What is the hardest you think in this project

I think the hardest part in this assignment is *Type Propagation & Checking*. It requires a lot of careful thinking and implementation to handle the type information propagation from child nodes to parent nodes. If not handled correctly, the type pointer will be nullptr and the program will crash. 


## Feedback to T.A.s

The reference code is helpful for me to understand the overall structure of this assignment, and the test cases are also helpful for me to test my implementation. Good! 