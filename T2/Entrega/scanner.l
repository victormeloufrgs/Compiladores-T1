%{
    /*
    Aluno:      Victor dos Santos Melo
    Matrícula:  00285640
    */
    
    #include "y.tab.h"
    #include "hash.h"
    #include "symbols.h"

    int running = 1;
    int lineNumber = 1;

    int getLineNumber(void);
%}

%x COMMENT

%%

[ \t]
"\n"                            ++lineNumber;

"char"                          return KW_CHAR; 
"int"                           return KW_INT; 
"float"                         return KW_FLOAT;   
"bool"                          return KW_BOOL;  
"if"                            return KW_IF;
"then"                          return KW_THEN;  
"else"                          return KW_ELSE;  
"while"                         return KW_WHILE;   
"loop"                          return KW_LOOP;  
"read"                          return KW_READ;  
"print"                         return KW_PRINT;   
"return"                        return KW_RETURN;

[,|;|:|(|)|\[|\]|{|}|+|-|*|/|<|>|=|\||^|~|&|$|#]    return yytext[0];

"<="                            return OPERATOR_LE;  
">="                            return OPERATOR_GE;  
"=="                            return OPERATOR_EQ;  
"!="                            return OPERATOR_DIF;

"TRUE"                          hashInsert(LIT_TRUE, yytext); return LIT_TRUE;
"FALSE"                         hashInsert(LIT_FALSE, yytext); return LIT_FALSE;
[0-9|A-F]+                      hashInsert(LIT_INTEGER, yytext); return LIT_INTEGER;
[0-9|A-F]*\.[0-9|A-F]+         hashInsert(LIT_FLOAT, yytext); return LIT_FLOAT;
'[!-~]'                         hashInsert(LIT_CHAR, yytext); return LIT_CHAR;
\"[!|#-~|\\\"|\\n ]+\"           hashInsert(LIT_STRING, yytext); return LIT_STRING;

[@|_|A-z][0-9|@|_|A-z]*         hashInsert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;  


"//".*
"/*"                            BEGIN(COMMENT);

<COMMENT>.
<COMMENT>"\n"                   ++lineNumber;
<COMMENT>"*/"                   BEGIN(INITIAL);

.                               return TOKEN_ERROR;

%%

#include "y.tab.c"
#include "main.c"
#include "hash.c"
#include "symbols.c"

int yywrap() {
    running = 0;
    return 1;
}

int isRunning(void) {
    return running;
}

int getLineNumber(void) {
    return lineNumber;
}