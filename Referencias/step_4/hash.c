
#define HASH_SIZE 997
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

hash_node_t *hash_table[HASH_SIZE];

void hash_init(void) {
	int i;
	for(i = 0; i < HASH_SIZE; i++)
		hash_table[i] = 0;
}

int hash_address(char *text) {
	int address = 1, i;
	for(i = 0; i< strlen(text); i++)
		address = (address * text[i])%HASH_SIZE + 1;
	return address - 1;
}

int hash_equal(hash_node_t *n1, hash_node_t *n2) {

	if(n1->type == n2->type && !strcmp(n1->text, n2->text))
		return 1;
	else
		return 0;
}

hash_node_t* hash_find(hash_node_t *node) {

	hash_node_t *aux = hash_table[hash_address(node->text)];

	while(aux != NULL) {
		if(!hash_equal(node, aux))
			aux = aux->next;
		else
			return aux;		
	}	
	
	return NULL;
}

hash_node_t *hash_insert(char *text, int type, int dataType, int nature) {
	
	hash_node_t *new_node;
	int address = hash_address(text);

	new_node = (hash_node_t *) calloc(1, sizeof(hash_node_t));
	new_node->text = calloc(strlen(text)+1, sizeof(char));

	new_node->type = type;
	new_node->dataType = dataType;
	new_node->nature = nature;
	new_node->parametersNumber = -1;
	new_node->isVariableOrFuncionDeclared = 0;
	new_node->expressionType = 0;

	strcpy(new_node->text, text);

	hash_node_t *aux = hash_find(new_node);

	if(aux == NULL) {
		new_node->next = hash_table[address];
		hash_table[address] = new_node;
		return new_node;
	}
	
	return aux;
}
	
void hash_print(void) {
	int i;
	hash_node_t *node = 0;
	for(i = 0; i < HASH_SIZE; i++)
		for(node = hash_table[i]; node; node =  node->next)
			printf("Table[%d] = %s\n", i, node->text);
}