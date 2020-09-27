/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include <stdio.h>
#include "hash.h"
#include "ast.h"

extern FILE *yyin;
int yyparse();

int writeStringToFile(char *filePath, char *string) {
	FILE* f;
	if ((f = fopen(filePath, "w")) != NULL) {
		fprintf(f, "%s", string);
		return 1;
	} else {
		fprintf(stderr, "ERROR: Couldn't open %s\n", filePath);
		exit(1);
	}
}

int main(int argc, char ** argv) {
    hashInit();
    
    if (argc<3) {
        fprintf(stderr,"Error: argumentos inválidos\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    
    if (yyin ==0) {
        fprintf(stderr,"Can not open file\n");
        exit(2);
    }

    yyparse();

    astPrint(tree, 0);

    writeStringToFile(argv[2], decompileTree(tree));
    
    fprintf(stderr,"Compilation success!\n");
    
    // hashPrint();
    
    exit(0);
}
