/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include "hash.h"
#include <string.h>
#include <stdlib.h>

TOKEN *hash_table[HASH_SIZE];

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

TOKEN *hashFind(char *value) 
{
    int address = hashAddress(value);
    TOKEN* token = hash_table[address];

    if(strcmp(token->value, value) == 0) {
        return token;
    }

    while(token->next != NULL) {
        token = token->next;

        if(strcmp(token->value, value) == 0) {
            return token;
        }
    }

    return 0;
}

TOKEN *hashInsert(int id, char *value) 
{
    int address = hashAddress(value);
    TOKEN *token = (TOKEN*) calloc(1, sizeof(TOKEN));
    token->id = id;
    token->value = (char*) calloc(strlen(value)+1, sizeof(char));
    strcpy(token->value, value);
    token->next = hash_table[address];
    hash_table[address] = token;

    return token;
}

void hashPrint() {
    int i = 0;

    printf("TOKENS:\n-------------------------------------------");
    for(i=0; i < HASH_SIZE; i++) {
        TOKEN* token = hash_table[i];
        if(token == NULL) continue;

        do {
            printf("\nType = %d | Value = %s",token->id, token->value);
            token = token->next;
        } while(token != NULL);

    }

    printf("\n-------------------------------------------\n");
}