/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include "hash.h"
#include <string.h>
#include <stdlib.h>
#include "symbols.h"

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
    printf("-------TYPE--------|----DATATYPE----|---VALUE---");
    for(i=0; i < HASH_SIZE; i++) {
        HASH_NODE* node = hash_table[i];
        if(node == NULL) continue;

        do {
            printf("\n%s | %s | %s", getSymbolName(node->type), getDataTypeName(node->datatype), node->text);
            node = node->next;
        } while(node != NULL);

    }

    printf("\n------------------------------------------------\n\n");
}

int hash_check_undeclared() {
    int undeclared = 0;
    int i;
    HASH_NODE *node;
    for(i=0; i < HASH_SIZE; i++)
        for(node=hash_table[i]; node; node = node->next)
            if(node->type == SYMBOL_IDENTIFIER) {
                fprintf(stderr, "SEMANTIC ERROR: identifier %s undeclared\n", node->text);
                ++undeclared;
            }

    return undeclared;
}

HASH_NODE* makeTemp(void) {
    static int serial = 0;
    char buffer[256] = "";

    sprintf(buffer, "1temp_%d",serial++);
    return hashInsert(buffer, SYMBOL_VARIABLE);
}

HASH_NODE* makeLabel(void) {
    static int serial = 0;
    char buffer[256] = "";

    sprintf(buffer, "1label_%d",serial++);
    return hashInsert(buffer, SYMBOL_LABEL);
}