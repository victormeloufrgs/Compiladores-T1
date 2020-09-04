%{
    #include "tokens.h"
    int Running = 1;
    int lineNumber = 1;
%}

%x COMMENT

%%

"int"          return KW_INT;
[;:(),]        return yytext[0];
[1-9]+         hashInsert(yytext); return LIT_INTEGER;
[a-z]+         hashInsert(yytext); return TK_IDENTIFIER;
[ \t]
"\n"           ++lineNumber;
"//".*         
"/*"           BEGIN(COMMENT);
.              return TOKEN_ERROR;

<COMMENT>.
<COMMENT>"\n" ++lineNumber;
<COMMENT>"*/" BEGIN(INITIAL);

%%

#include "main.c"

int yywrap() {
    Running = 0;
    return 1;
}