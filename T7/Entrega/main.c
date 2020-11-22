/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include <stdio.h>
#include "hash.h"
#include "ast.h"
#include "semantic.h"
#include "tacs.h"
#include "assembler.h"

extern FILE *yyin;
extern int	syntax_errors;
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

#define SUCCESS 0
#define FILE_NOT_INFORMED 1
#define FILE_NOT_FOUND 2

#define SINTAX_ERROR 3
#define SEMANTIC_ERROR 4
#define COMPILATION_ERROR 5

int main(int argc, char ** argv) {
    hashInit();
    
    if (argc<3) {
        fprintf(stderr,"CALL FAILURE: invalid arguments\n");
        exit(FILE_NOT_INFORMED);
    }

    yyin = fopen(argv[1], "r");
    
    if (yyin ==0) {
        fprintf(stderr,"CALL FAILURE: Can't open file\n");
        exit(FILE_NOT_FOUND);
    }

    // VERIFICAÇÃO SINTÁTICA
    
    yyparse();
    astPrint(tree, 0);

    // VERIFICAÇÃO SEMÂNTICA

    semantic_verification(tree);

    if(syntax_errors > 0) {
        fprintf(stderr, "COMPILATION FAILURE: %d syntactic error(s) detected\n", syntax_errors);
        if (get_semantic_errors() > 0) {
            fprintf(stderr, "COMPILATION FAILURE: There are semantic errors\n");
        }

        exit(SINTAX_ERROR);
   }

    if (get_semantic_errors() > 0) {
        fprintf(stderr, "COMPILATION FAILURE: There are semantic errors\n");
        exit(SEMANTIC_ERROR);
    }


    // GERAÇÃO DE CÓDIGO INTERMEDIÁRIO

    TAC* code = generateCode(tree);
    fillFuncCalls(code);
    
    tacPrintBackwards(code);
    
    // GERAÇÃO DE CÓDIGO ASSEMBLY
    
    code = tacReverse(code);    
    generateAsm(code);

    writeStringToFile(argv[2], decompileTree(tree));

    hashPrint();

    fprintf(stderr,"Compilation success!\n");
    
    exit(SUCCESS);
}
