/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include <stdio.h>
#include "hash.h"

extern FILE *yyin;
int yyparse();

int main(int argc, char ** argv) {
    hashInit();
    
    if (argc<2) {
        fprintf(stderr,"");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    
    if (yyin ==0) {
        fprintf(stderr,"Can not open file\n");
        exit(2);
    }

    yyparse();
    
    fprintf(stderr,"Compilation success!\n");
    
    hashPrint();
    
    exit(0);
}
