/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include "hash.h"
#include <string.h>
#include <stdlib.h>

HASH_NODE *hash_table[HASH_SIZE];

void hashInit(void) 
{
    int i;
    for(i = 0; i < HASH_SIZE; i++)
        hash_table[i] = 0;
}

// Algoritmo: soma os códigos ascii, multiplicando cada char por seu indice. Retorna soma % HASH_SIZE
int hashAddress(char *value) 
{
    int sum = 0;
    int i;
    for(i = 0; i < strlen(value); i++)
        sum += value[i] * i;

    return sum % HASH_SIZE;
}

HASH_NODE *hashFind(char *text) 
{
    HASH_NODE *node;
    int address = hashAddress(text);
    for (node=hash_table[address]; node; node = node->next)
        if (strcmp(node->text,text)==0)
            return node;
    return 0;
}

HASH_NODE *hashInsert(char *text, int type) 
{

    HASH_NODE *newnode;
    int address = hashAddress(text);

    if ((newnode = hashFind(text)) != 0)
        return newnode;

    newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newnode->type = type;
    newnode->text = (char*) calloc(strlen(text)+1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = hash_table[address];
    hash_table[address] = newnode;
    return newnode;
}

void hashPrint() {
    int i = 0;

    printf("\nSYMBOLS TABLE:\n");
    printf("-------TYPE--------|---VALUE--------");
    for(i=0; i < HASH_SIZE; i++) {
        HASH_NODE* node = hash_table[i];
        if(node == NULL) continue;

        do {
            printf("\n%s | %s",getSymbolName(node->type), node->text);
            node = node->next;
        } while(node != NULL);

    }

    printf("\n-------------------------------------\n\n");
}