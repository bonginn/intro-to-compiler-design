# hw1 report

|Field|Value|
|-:|:-|
|Name|Chung, Pang-Chun|
|ID|111652031|

## How much time did you spend on this project

About 3 hours.

## Project overview

### Project Structure
``` markdown
hw1-bonginn/
├── src/
│   ├── Makefile        
│   └── scanner.l       # Scanner
└── report/
    └── README.md       # This report
```
### Implementation
#### 1. Helper Functions
* **updateCurrentLine**: Updates line/column counters and prints source lines when S is enabled.
* **listToken**: Prints a token (e.g., <KWbegin>).
* **listLiteral**: Prints tokens with their lexeme (e.g., <id: abc> or <integer: 123>).
* **yywrap**: Ensures the last line is printed even if the input file does not end with a newline.

#### 2. Helper Definitions
```flex
nonzero_integer  [1-9][0-9]*
nonzero_float1   [1-9][0-9]*\.(0|[0-9]*[1-9])
nonzero_float2   (0|[1-9][0-9]*)\.([0-9]*[1-9])
integer          0|[1-9][0-9]*
oct_integer      0[0-7]+ 
float            (0|[1-9]+[0-9]*)\.(0|[0-9]*[1-9])
string           \"([^"\n]|\"\")*\"
```
I additionally defined nonzero_integer and nonzero_float due to the rule mentioned in spec: 

> ...coefficient a is a nonzero decimal number (either a nonzero decimal integer or a nonzero floating-point number)

#### 3. Discard
```flex
[ \t\r\0\n]*   ;  

"//&S+"[^\n]*    { opt_src = 1; }
"//&S-"[^\n]*    { opt_src = 0; }
"//&T+"[^\n]*    { opt_tok = 1; }
"//&T-"[^\n]*    { opt_tok = 0; }

"//".*     { }
"/*"([^*]|\*+[^/])*\*+"/"   {  }
```

The transition rules for pseudocomments are written explicitly before the general comment rules.
This prevents 
```pascal
//&T- // less output
```
from being viewd as a normal comment  instead of a pseudocomment.

#### 4. Delimiters 
```flex
","    { listToken(","); }
";"    { listToken(";"); }
":"    { listToken(":"); }
"("    { listToken("("); }
")"    { listToken(")"); }
"["    { listToken("["); }
"]"    { listToken("]"); }
```

#### 5. Operator
```flex
":="       { listToken(":="); }
"<="       { listToken("<="); }
"<>"       { listToken("<>"); }
">="       { listToken(">="); }
"<"        { listToken("<"); }
">"        { listToken(">"); }
"="        { listToken("="); }
"+"        { listToken("+"); }
"-"        { listToken("-"); }
"*"        { listToken("*"); }
"/"        { listToken("/"); }
"mod"      { listToken("mod"); }
"and"      { listToken("and"); }
"or"       { listToken("or"); }
"not"      { listToken("not"); }
```

#### 6. Reserved Words
```flex
"var"       { listToken("KWvar"); }
"def"       { listToken("KWdef"); }

"array"     { listToken("KWarray"); }
"of"        { listToken("KWof"); }
"boolean"   { listToken("KWboolean"); }
"integer"   { listToken("KWinteger"); }
"real"      { listToken("KWreal"); }
"string"    { listToken("KWstring"); }

"true"      { listToken("KWtrue"); }
"false"     { listToken("KWfalse"); }

"while"     { listToken("KWwhile"); }
"do"        { listToken("KWdo"); }
"if"        { listToken("KWif"); }
"then"      { listToken("KWthen"); }
"else"      { listToken("KWelse"); }
"for"       { listToken("KWfor"); }
"to"        { listToken("KWto"); }

"begin"     { listToken("KWbegin"); }
"end"       { listToken("KWend"); }

"print"     { listToken("KWprint"); }
"read"      { listToken("KWread"); }
"return"    { listToken("KWreturn"); }
```

#### 7. Identifiers
```flex
[a-zA-Z][a-zA-Z0-9]*  {listLiteral("id", yytext); }
```

#### 8. Scientific Notations
```flex
({nonzero_integer}|{nonzero_float1}|{nonzero_float2})[eE][+-]?({integer}) {listLiteral("scientific", yytext); }
```
> Note we need to ensure `a` is a nonzero decimal number

#### 9. String Constants
```flex
{string}            {
    static char tmpLine[MAX_LINE_LEN];
    int idx = 0;
    for(int i=1;i<yyleng-1;i++){
        tmpLine[idx++] = yytext[i];
        if(yytext[i] == '\"' && yytext[i+1] == '\"')
            i++;
    }
    tmpLine[idx] = '\0';
    listLiteral("string", tmpLine);
}
```
In the action code:
* I skip the first (") and last (") characters by looping from index 1 to yyleng-2.
* Each character in between is copied into tmpLine.
* When two consecutive double quotes ("") are encountered, the loop skips the second one so that only a single " is stored in the final string. This implements the spec rule that two quotes inside a string literal denote one literal quote.

## What is the hardest you think in this project
This is my first time implementing a scanner. I think the hardest part was understanding the Lex/Flex syntax and correctly handling the corner cases (such as floats with trailing zeros, scientific notation rules and pseudocomments).

## Feedback to T.A.s
Nice homework! But I hope future assignments can provide a bit more guidance or examples.
