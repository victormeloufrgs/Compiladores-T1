// AST - Abstract Syntax Tree  

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3) {
    AST *newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;

    return newnode;
}

void *astPrint(AST *node, int level) {
    int i=0;

    if (node == 0) return 0;

    for(i=0; i<level; ++i)
        fprintf(stderr, "  ");

    fprintf(stderr, "ast(");
    switch(node->type) {
        case AST_SYMBOL: fprintf(stderr,"AST_SYMBOL"); break;
        case AST_PLUS: fprintf(stderr,"AST_PLUS"); break;
        case AST_MINUS: fprintf(stderr,"AST_MINUS"); break;
        case AST_MULT: fprintf(stderr,"AST_MULT"); break;
        case AST_DIV: fprintf(stderr,"AST_DIV"); break;
        case AST_LE: fprintf(stderr,"AST_LE"); break;
        default: fprintf(stderr,"AST_UNKNOWN"); break;
    }

    if (node->symbol != 0)
        fprintf(stderr, ",%s\n", node->symbol->text);
    else
        fprintf(stderr, ",0\n");

    for(i=0; i< MAX_SONS; ++i)
        astPrint(node->son[i], level+1);

    return 0;
}

// END OF FILE