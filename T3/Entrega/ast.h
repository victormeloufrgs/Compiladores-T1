// AST - Abstract Syntax Tree  

#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS                4

#define AST_SYMBOL              1
#define AST_ADD                 2
#define AST_SUB                 3
#define AST_ATTR                4
#define AST_LCMD                5

// expressions:

#define AST_PLUS                6
#define AST_MINUS               7
#define AST_MULT                8
#define AST_DIV                 9
#define AST_LE                  10
#define AST_LT                  11
#define AST_GE                  12
#define AST_GT                  13
#define AST_EQ                  14
#define AST_DIF                 15
#define AST_OR                  16
#define AST_AND                 17
#define AST_NOT                 18
#define AST_ARRAY_CALL          19
#define AST_FUNC_CALL           20
#define AST_FUNC_CALL_ARGS      21
#define AST_FUNC_CALL_ARGS_EXT  22

typedef struct astnode
{ 
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void *astPrint(AST *node, int level);

#endif

// END OF FILE