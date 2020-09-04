%{
    /*
    Aluno:      Victor dos Santos Melo
    Matrícula:  00285640
    */
    
    #include "hash.h"
    #include "y.tab.h"
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

"TRUE"                           { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_TRUE); return LIT_TRUE; }
"FALSE"                          { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FALSE); return LIT_FALSE; }
[0-9|A-F]+                       { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_INTEGER); return LIT_INTEGER; }
[0-9|A-F]*\.[0-9|A-F]+           { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FLOAT); return LIT_FLOAT; }
'[!-~]'                          { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_CHAR); return LIT_CHAR; }
\"[!|#-~|\\\"|\\n ]+\"           { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_STRING); return LIT_STRING; }

[@|_|A-Z|a-z][0-9|@|_|A-Z|a-z]*  { yylval.symbol = hashInsert(yytext, SYMBOL_IDENTIFIER); return TK_IDENTIFIER; }


"//".*
"/*"                            BEGIN(COMMENT);

<COMMENT>.
<COMMENT>"\n"                   ++lineNumber;
<COMMENT>"*/"                   BEGIN(INITIAL);

.                               return TOKEN_ERROR;

%%

#include "hash.c"
#include "y.tab.c"
#include "main.c"
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