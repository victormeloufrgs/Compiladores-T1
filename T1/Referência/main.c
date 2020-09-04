
int main() {
    int tok;
    while (Running) {
        // TODO: INICIALIZAR TABELA
        tok = yylex();

        switch(tok) {
            case KW_INT: printf("Achei palavra reservada int\n"); break;
            case LIT_INTEGER: printf("Achei o literal inteiro %s\n", yytext); break;
            case TK_IDENTIFIER: printf("Achei o identificador %s na linha %d\n", yytext, lineNumber); break;
            case TOKEN_ERROR: printf("ERRO\n"); break;
            default: printf("Achei o simbolo %c\n", tok); break;
        }          

        // TODO: PRINT TABELA
    }
}