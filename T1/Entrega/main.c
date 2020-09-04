/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

int main() {
    initMe();
    int tok = yylex();
    do {

        printf("Linha %d -> ", getLineNumber());

        switch(tok) {
            case KW_CHAR:   printf("Achei palavra reservada char em texto: %s\n", yytext); break;
            case KW_INT:    printf("Achei palavra reservada int em texto: %s\n", yytext); break;
            case KW_FLOAT:  printf("Achei palavra reservada float em texto: %s\n", yytext); break;
            case KW_BOOL:   printf("Achei palavra reservada bool em texto: %s\n", yytext); break;
            case KW_IF:     printf("Achei palavra reservada if em texto: %s\n", yytext); break;
            case KW_THEN:   printf("Achei palavra reservada then em texto: %s\n", yytext); break;
            case KW_ELSE:   printf("Achei palavra reservada else em texto: %s\n", yytext); break;
            case KW_WHILE:  printf("Achei palavra reservada while em texto: %s\n", yytext); break;
            case KW_LOOP:   printf("Achei palavra reservada loop em texto: %s\n", yytext); break;
            case KW_READ:   printf("Achei palavra reservada read em texto: %s\n", yytext); break;
            case KW_PRINT:  printf("Achei palavra reservada print em texto: %s\n", yytext); break;
            case KW_RETURN: printf("Achei palavra reservada return em texto: %s\n", yytext); break;

            case OPERATOR_LE:   printf("Achei operador <= em texto: %s\n", yytext); break;
            case OPERATOR_GE:   printf("Achei operador >= em texto: %s\n", yytext); break;
            case OPERATOR_EQ:   printf("Achei operador == em texto: %s\n", yytext); break;
            case OPERATOR_DIF:  printf("Achei operador != em texto: %s\n", yytext); break;

            case TK_IDENTIFIER: printf("Achei identificador em texto: %s\n", yytext); break;

            case LIT_INTEGER:   printf("Achei literal inteiro em texto: %s\n", yytext); break;
            case LIT_FLOAT:     printf("Achei literal float em texto: %s\n", yytext); break;
            case LIT_TRUE:      printf("Achei literal TRUE em texto: %s\n", yytext); break;
            case LIT_FALSE:     printf("Achei literal FALSE em texto: %s\n", yytext); break;
            case LIT_CHAR:      printf("Achei literal char em texto: %s\n", yytext); break;
            case LIT_STRING:    printf("Achei literal string em texto: %s\n", yytext); break;

            case TOKEN_ERROR: printf("achei ERRO em texto: %s\n", yytext); break;

            default: printf("Achei o simbolo %c\n", tok); break;
        }

        tok = yylex();
    } while(isRunning());

    hashPrint();
}
