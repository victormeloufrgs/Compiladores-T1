/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

struct astnode;

typedef struct hash_node_struct
{
    int type;
    int datatype;
    char *text;
    struct hash_node_struct* next;
    struct astnode* func_decl_node;
    int is_global_scope_declaration;
} HASH_NODE;

HASH_NODE* hashFalse;
HASH_NODE* hashTrue;

void hashInit(void);
int hashAddress(char *value);
HASH_NODE* hashFind(char *text);
HASH_NODE* hashInsert(char *text, int type);
void hashPrint(void);
int hash_check_undeclared(void);
HASH_NODE* makeTemp(void);
HASH_NODE* makeLabel(void);

#endif