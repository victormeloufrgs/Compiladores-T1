#include <stdio.h>
#include "lex.yy.h"
#include "hash.h"
#include "astree.h"
#include "semantic.h"
#include "tac.h"
#include "compiler.h"

extern int 	yyparse();
extern int  getLineNumber();
extern void initMe();
extern int  isRunning();
extern int	err;

int string_to_file(char *filePath, char *string) {
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

int main(int argc, char **argv) {
	printf("\n\n[STARTING]!\n\n\n");
	if (argc < 2) {
        printf("Error: invalid arguments.\nUsage: <input file> <output file (optional)>\n");
        return FILE_NOT_INFORMED;
    }

	FILE* file;
	if (!(file = fopen(argv[1], "r"))) {
		printf("Error: file %s can't be opened.\n", argv[1]);
		return FILE_NOT_FOUND;
	}

	initMe();
	yyin = file;	
	yyparse();

	if(!tree) {
		fprintf(stderr, "[COMPILATION FAILURE]\n %d error(s) detected\n", err);
		return SINTAX_ERROR;
	}

	printf("\n\nPrinting astree\n");
	astree_print(tree, 0);
	printf("--DONE--!\n\n\n");

	semantic_set_declarations(tree);
	semantic_check(tree);

	printf("\n\n\n[PROGRAM ACCEPTED]!\n\n\n");

	printf("Printing intermediary code from source file into stdout: %s...\n", argv[1]);
	tac_t *intermediary_code = tac_reverse(tac_generate(tree));
	tac_print_backward(intermediary_code);
	printf("--DONE--!\n\n\n");

	if(argc == 3) {
		printf("Printing assembly generated from %s into %s...\n", argv[1], argv[2]);
		if(comp_asm_generate(intermediary_code, argv[2]) > 0) {
			printf("Compiler error: unknown intermediary code found.\n");
			return COMPILATION_ERROR;
		}
		printf("--DONE--!\n\n\n");
	}


	// printf("Printing hash:\n");
	// hash_print();
	// printf("--DONE--!\n\n\n");

	return SUCCESS;
}