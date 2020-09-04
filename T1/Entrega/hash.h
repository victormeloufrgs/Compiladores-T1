/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include <stdio.h>

#define HASH_SIZE 997

typedef struct TOKEN 
{
    int id;
    char *value;
    struct TOKEN* next;
} TOKEN;

void hashInit(void);
int hashAddress(char *value);
TOKEN *hashFind(char *value);
TOKEN *hashInsert(int id, char *value);
void hashPrint(void);