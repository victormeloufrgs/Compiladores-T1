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
        case AST_SYMBOL_IDENTIFIER: fprintf(stderr,"AST_SYMBOL_IDENTIFIER"); break;
        case AST_SYMBOL_STRING: fprintf(stderr,"AST_SYMBOL_STRING"); break;               
        case AST_SYMBOL_CHAR: fprintf(stderr,"AST_SYMBOL_CHAR"); break;                 
        case AST_SYMBOL_INTEGER: fprintf(stderr,"AST_SYMBOL_INTEGER"); break;              
        case AST_SYMBOL_FLOAT: fprintf(stderr,"AST_SYMBOL_FLOAT"); break;                
        case AST_SYMBOL_TRUE: fprintf(stderr,"AST_SYMBOL_TRUE"); break;                 
        case AST_SYMBOL_FALSE: fprintf(stderr,"AST_SYMBOL_FALSE"); break;                

        case AST_PLUS: fprintf(stderr,"AST_PLUS"); break;
        case AST_MINUS: fprintf(stderr,"AST_MINUS"); break;
        case AST_MULT: fprintf(stderr,"AST_MULT"); break;
        case AST_DIV: fprintf(stderr,"AST_DIV"); break;
        case AST_LE: fprintf(stderr,"AST_LE"); break;
        case AST_LT: fprintf(stderr,"AST_LT"); break;
        case AST_GE: fprintf(stderr,"AST_GE"); break;
        case AST_GT: fprintf(stderr,"AST_GT"); break;
        case AST_EQ: fprintf(stderr,"AST_EQ"); break;
        case AST_DIF: fprintf(stderr,"AST_DIF"); break;
        case AST_OR: fprintf(stderr,"AST_OR"); break;
        case AST_AND: fprintf(stderr,"AST_AND"); break;
        case AST_NOT: fprintf(stderr,"AST_NOT"); break;
        case AST_ARRAY_CALL: fprintf(stderr, "AST_ARRAY_CALL"); break;        
        case AST_FUNC_CALL: fprintf(stderr, "AST_FUNC_CALL"); break;         
        case AST_FUNC_CALL_ARGS: fprintf(stderr, "AST_FUNC_CALL_ARGS"); break;    
        case AST_FUNC_CALL_ARGS_EXT: fprintf(stderr, "AST_FUNC_CALL_ARGS_EXT"); break;

        case AST_EXPR_CONT_LIST: fprintf(stderr, "AST_EXPR_CONT_LIST"); break; 

        case AST_MAYBE_ELSE: fprintf(stderr, "AST_MAYBE_ELSE"); break;          
        case AST_LOOP: fprintf(stderr, "AST_LOOP"); break;                
        case AST_WHILE: fprintf(stderr, "AST_WHILE"); break;               
        case AST_IF_THEN: fprintf(stderr, "AST_IF_THEN"); break;   

        case AST_PRINT_EXTRA_ELEMS: fprintf(stderr, "AST_PRINT_EXTRA_ELEMS"); break;   
        case AST_PRINT_LIST: fprintf(stderr, "AST_PRINT_LIST"); break;          
        case AST_ATTR_ARRAY: fprintf(stderr, "AST_ATTR_ARRAY"); break;          
        case AST_ATTR: fprintf(stderr, "AST_ATTR"); break;                
        case AST_PRINT: fprintf(stderr, "AST_PRINT"); break;               
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;              
        case AST_READ: fprintf(stderr, "AST_READ"); break;      

        case AST_CMD_SEQ: fprintf(stderr, "AST_CMD_SEQ"); break;             
        case AST_CMD_BLOCK: fprintf(stderr, "AST_CMD_BLOCK"); break;           
        case AST_PARAM: fprintf(stderr, "AST_PARAM"); break;               
        case AST_PARAM_LIST_EXT: fprintf(stderr, "AST_PARAM_LIST_EXT"); break;      
        case AST_PARAM_LIST: fprintf(stderr, "AST_PARAM_LIST"); break;          
        case AST_VET_VALUES: fprintf(stderr, "AST_VET_VALUES"); break;          
        case AST_VALUE: fprintf(stderr, "AST_VALUE"); break;               
        case AST_KW_FLOAT: fprintf(stderr, "AST_KW_FLOAT"); break;            
        case AST_KW_INT: fprintf(stderr, "AST_KW_INT"); break;              
        case AST_KW_BOOL: fprintf(stderr, "AST_KW_BOOL"); break;             
        case AST_KW_CHAR: fprintf(stderr, "AST_KW_CHAR"); break;             
        case AST_TYPE_AND_VALUE: fprintf(stderr, "AST_TYPE_AND_VALUE"); break;      
        case AST_TYPE_AND_VALUE_ARRAY: fprintf(stderr, "AST_TYPE_AND_VALUE_ARRAY"); break;
        case AST_DECL_FUNC: fprintf(stderr, "AST_DECL_FUNC"); break;           
        case AST_DECL_VAR: fprintf(stderr, "AST_DECL_VAR"); break;            
        case AST_DECL_LIST: fprintf(stderr, "AST_DECL_LIST"); break;                     

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