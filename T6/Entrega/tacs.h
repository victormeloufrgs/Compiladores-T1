
#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"
#include "symbols.h"

#define TAC_SYMBOL                  1

#define TAC_ADD                     2
#define TAC_SUB                     3
#define TAC_MULT                    4
#define TAC_DIV                     5
#define TAC_LE                      6
#define TAC_LT                      7
#define TAC_GE                      8
#define TAC_GT                      9
#define TAC_EQ                      10
#define TAC_DIF                     11
#define TAC_OR                      12
#define TAC_AND                     13
#define TAC_NOT                     14

#define TAC_MOVE                    15
#define TAC_JFALSE                  16
#define TAC_LABEL                   17
#define TAC_JUMP                    18
#define TAC_ACALL                   19
#define TAC_FCALL                   20
#define TAC_ARG                     21
#define TAC_PRINT                   22
#define TAC_JEQ                     23

#define TAC_AATTR                   24
#define TAC_RET                     25
#define TAC_READ                    26
#define TAC_PARAM                   27
#define TAC_FBEGIN                  28
#define TAC_FEND                    29
#define TAC_VAR                     30
#define TAC_ARR                     31


typedef struct tac_node {
    int type;
    HASH_NODE* res;
    HASH_NODE* op1;
    HASH_NODE* op2;
    struct tac_node* prev;
    struct tac_node* next;
} TAC;

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tacPrint(TAC* tac);
void tacPrintBackwards(TAC* tac);
TAC* tacJoin(TAC* l1, TAC* l2);

// CODE GENERATION

TAC* generateCode(AST* node);

#endif