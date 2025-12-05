%option never-interactive
%option nounput
%option noinput

%{
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 512
/* Code runs each time a token is matched. */
#define YY_USER_ACTION updateCurrentLine(yytext);

uint32_t line_num = 1;
uint32_t col_num = 1;
static uint32_t opt_src = 1;
static uint32_t opt_tok = 1;
static char current_line[MAX_LINE_LEN];

static void updateCurrentLine(const char *source);
static void listToken(const char *name);
static void listLiteral(const char *name, const char *literal);

%}
    /* Helper Definition */
nonzero_integer  [1-9][0-9]*
nonzero_float1   [1-9][0-9]*\.(0|[0-9]*[1-9])
nonzero_float2   (0|[1-9][0-9]*)\.([0-9]*[1-9])
integer          0|[1-9][0-9]*
oct_integer      0[0-7]+ 
float            (0|[1-9]+[0-9]*)\.(0|[0-9]*[1-9])
string           \"([^"\n]|\"\")*\"

%%
    /* Discard */
[ \t\r\0\n]*   ;  
 
"//&S+"[^\n]*    { opt_src = 1; }
"//&S-"[^\n]*    { opt_src = 0; }
"//&T+"[^\n]*    { opt_tok = 1; }
"//&T-"[^\n]*    { opt_tok = 0; }

"//".*     { }
"/*"([^*]|\*+[^/])*\*+"/"   {  }

    /* Delimiters */
","    { listToken(","); }
";"    { listToken(";"); }
":"    { listToken(":"); }
"("    { listToken("("); }
")"    { listToken(")"); }
"["    { listToken("["); }
"]"    { listToken("]"); }

    /* Operators */
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

    /* Reserved Words */
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

    /* Identifiers */
[a-zA-Z][a-zA-Z0-9]*  {listLiteral("id", yytext); }

    /* Constants */
{integer}             {listLiteral("integer", yytext); }
{oct_integer}         {listLiteral("oct_integer", yytext); }
{float}               {listLiteral("float", yytext); }

    /* Scientific Notations */
({nonzero_integer}|{nonzero_float1}|{nonzero_float2})[eE][+-]?({integer}) {listLiteral("scientific", yytext); }

    /* String Constants */
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

    /* Catch the character which is not accepted by rules above */
. {
    printf("Error at line %d: bad character \"%s\"\n", line_num, yytext);
    exit(-1);
}

%%

/** @note The line is printed out and flushed when a newline character is encountered. */
static void updateCurrentLine(const char *source) {
    /* col_num is one-based */
    for (const char *c = source; *c; ++c) {
        if (*c == '\n') {
            if (opt_src) {
                printf("%d: %s\n", line_num, current_line);
            }
            ++line_num;
            col_num = 1;
            current_line[0] = '\0';
        } else {
            if (col_num < MAX_LINE_LEN) {
                current_line[col_num - 1] = *c;
                current_line[col_num] = '\0';
            } else {
                /* Truncate silently; doesn't affect the program's correctness. */
            }
            ++col_num;
        }
    }
}

static void listToken(const char *name) {
    if (opt_tok) {
        printf("<%s>\n", name);
    }
}

static void listLiteral(const char *name, const char *literal) {
    if (opt_tok) {
        printf("<%s: %s>\n", name, literal);
    }
}

/** @note This function is not required if the input file is guaranteed to end
 * with a newline. However, students may find it useful to handle the case where
 * the input file does not end with a newline, as it has been reported several
 * times in the past.
 */
int yywrap(void) {
    /* If the file is not ended with a newline, fake it to print out the last line. */
    if (col_num > 1) {
        updateCurrentLine("\n");
    }
    /* no more input file */
    return 1;
}

int main(int argc, const char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(-1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Open file error\n");
        exit(-1);
    }

    yylex();

    fclose(yyin);
    /* Free resources used by the scanner; otherwise, unused data structures
    will persist throughout the successive compiler phases. */
    yylex_destroy();

    return 0;
}
