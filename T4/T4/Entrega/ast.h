// AST - Abstract Syntax Tree  

#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS     4

// AST DEFINITIONS

// symbols
#define AST_SYMBOL_IDENTIFIER           1
#define AST_SYMBOL_STRING               2
#define AST_SYMBOL_CHAR                 3
#define AST_SYMBOL_INTEGER              4
#define AST_SYMBOL_FLOAT                5
#define AST_SYMBOL_TRUE                 6
#define AST_SYMBOL_FALSE                7

// expressions:

#define AST_PLUS                        8
#define AST_MINUS                       9
#define AST_MULT                        10
#define AST_DIV                         11
#define AST_LE                          12
#define AST_LT                          13
#define AST_GE                          14
#define AST_GT                          15
#define AST_EQ                          16
#define AST_DIF                         17
#define AST_OR                          18
#define AST_AND                         19
#define AST_NOT                         20
#define AST_ARRAY_CALL                  21
#define AST_FUNC_CALL                   22
#define AST_FUNC_CALL_ARGS              23
#define AST_FUNC_CALL_ARGS_EXT          24

// control flow:

#define AST_MAYBE_ELSE                  25
#define AST_LOOP                        26
#define AST_WHILE                       27
#define AST_IF_THEN                     28

// command:

#define AST_PRINT_EXTRA_ELEMS           29
#define AST_PRINT_LIST                  30
#define AST_ATTR_ARRAY                  31
#define AST_ATTR                        32
#define AST_PRINT                       33
#define AST_RETURN                      34
#define AST_READ                        35
#define AST_CMD_SEQ                     36
#define AST_CMD_BLOCK                   37

// params:

#define AST_PARAM                       38
#define AST_PARAM_LIST_EXT              39
#define AST_PARAM_LIST                  40

// values:

#define AST_VET_VALUES                  41
#define AST_VALUE                       42

// keywords:

#define AST_KW_FLOAT                    43
#define AST_KW_INT                      44
#define AST_KW_BOOL                     45
#define AST_KW_CHAR                     46

// types and values: 

#define AST_TYPE_AND_VALUE              47
#define AST_TYPE_AND_VALUE_ARRAY        48

// declarations:

#define AST_DECL_FUNC                   49
#define AST_DECL_VAR                    50
#define AST_DECL_LIST                   51

typedef struct astnode
{ 
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
    struct astnode* next_decl_param;
    struct astnode* next_arg_param;
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void *astPrint(AST *node, int level);
char* decompileTree(AST *ast);

AST *tree;

#endif

// END OF FILE