/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include <stdio.h>
#include "hash.h"
#include "ast.h"
#include "semantic.h"

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

    if (get_semantic_errors() > 0) {
        fprintf(stderr, "COMPILATION FAILURE: There are semantic errors\n");
        exit(4);
    }

    writeStringToFile(argv[2], decompileTree(tree));

    // hashPrint();

    fprintf(stderr,"Compilation success!\n");
    
    exit(0);
}
