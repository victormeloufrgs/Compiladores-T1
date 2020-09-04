/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_SIZE 997

typedef struct hash_node_struct
{
    int type;
    char *text;
    struct hash_node_struct* next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *value);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint(void);

#endif