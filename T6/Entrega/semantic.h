/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "hash.h"
#include "symbols.h"
#include "ast.h"

extern int SemanticErrors;

void check_and_set_declarations(AST *node);
void set_scope(AST *node);
void check_vet_indexes(AST *node);
void check_var_vet_func_use(AST *node);
void check_undeclared();
void check_operands(AST *node);
int get_semantic_errors();
int get_datatype_of_var_decl(AST *node);
int get_datatype_of_vet_decl(AST *node);
int get_datatype_of_func_decl(AST *node);
int get_datatype_of_type(int kw);
int get_datatype_of_type(int kw);
int get_datatype_of_operator(AST *node);

#endif