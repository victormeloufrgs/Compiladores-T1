
#include "tacs.h"

HASH_NODE *getResFrom(TAC *code);
TAC* makeBinaryOperation(int tac_operator, TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0, TAC* code1);

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2) {
    TAC* newtac = 0;
    newtac = (TAC*) calloc(1, sizeof(TAC));
    newtac->type = type;
    newtac->res = res;
    newtac->op1 = op1;
    newtac->op2 = op2;
    newtac->prev = 0;
    newtac->next = 0;

    return newtac;
}
void tacPrint(TAC* tac) {
    if(!tac) return;
    if(tac->type == TAC_SYMBOL) return;

    fprintf(stderr,"TAC(");

    switch(tac->type) {
        case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
        case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
        case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
        case TAC_COPY: fprintf(stderr, "TAC_COPY"); break;
        case TAC_JFALSE: fprintf(stderr, "TAC_JFALSE"); break;
        case TAC_LABEL: fprintf(stderr, "TAC_LABEL"); break;
        default: fprintf(stderr, "TAC_UNKNOWN"); break;
    }

    fprintf(stderr, ",%s", (tac->res) ? tac->res->text : "0");
    fprintf(stderr, ",%s", (tac->op1) ? tac->op1->text : "0");
    fprintf(stderr, ",%s", (tac->op2) ? tac->op2->text : "0");
    fprintf(stderr,");\n");
}

void tacPrintBackwards(TAC* tac) {
    if(!tac) return;
    tacPrintBackwards(tac->prev);
    tacPrint(tac);
}

TAC* tacJoin(TAC* l1, TAC* l2) {
    TAC *point;
    if(!l1) return l2;
    if(!l2) return l1;

    for(point = l2; point->prev != 0; point = point->prev)
        ;
    point->prev = l1;
    return l2;
}

// CODE GENERATION

TAC* generateCode(AST* node) {
    int i;
    TAC* result = 0;

    TAC* code[MAX_SONS];

    if(!node) return 0;

    // PROCESS CHILDREN
    for(i=0; i<MAX_SONS; ++i)
      code[i] = generateCode(node->son[i]);

    // PROCESS THIS NODE
    switch (node->type) {
        case AST_SYMBOL_CHAR: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_FALSE: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_FLOAT: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_IDENTIFIER: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_INTEGER: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_STRING: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
        case AST_SYMBOL_TRUE: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;

        case AST_PLUS: 
            result = makeBinaryOperation(TAC_ADD, code[0], code[1]);
            break;
        case AST_MINUS:
            result = makeBinaryOperation(TAC_SUB, code[0], code[1]);
            break;
        case AST_IF_THEN:
            result = makeIfThen(code[0], code[1]);
            break;
        case AST_ATTR:
            result = tacJoin(code[0], tacCreate(TAC_COPY, node->symbol, getResFrom(code[0]), 0));
            break;

        default: 
            result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3]))); 
            break;
    }

    return result;
}

TAC* makeBinaryOperation(int tac_operator, TAC* code0, TAC* code1) {
    return tacJoin(tacJoin(code0, code1), tacCreate(tac_operator, makeTemp(), getResFrom(code0), getResFrom(code1)));
}


TAC* makeIfThen(TAC* code0, TAC* code1) {
    TAC* jumptac = 0;
    TAC* labeltac = 0;
    HASH_NODE* newlabel = 0;
    newlabel = makeLabel();

    jumptac = tacCreate(TAC_JFALSE, newlabel, getResFrom(code0), 0);
    jumptac->prev = code0;

    labeltac = tacCreate(TAC_LABEL, newlabel, 0, 0);
    labeltac->prev = code1;

    return tacJoin(jumptac, labeltac);
}


HASH_NODE *getResFrom(TAC *code) {
    if(!code) return 0;
    return code->res;
}