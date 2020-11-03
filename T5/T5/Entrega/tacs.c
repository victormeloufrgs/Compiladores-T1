
#include "tacs.h"

HASH_NODE *getResFrom(TAC *code);
TAC* makeArithmetic(AST* node, TAC* code0, TAC* code1);
TAC* makeBoolean(AST* node, TAC* code0, TAC* code1);
TAC* makeLogical(AST* node, TAC* code0, TAC* code1);
TAC* makeNot(AST* node, TAC* code0);
TAC* makeArrayCall(AST* node, TAC* code0);
TAC* makeFunctionCall(AST* node, TAC* code0);
TAC* makeFunctionCallArgs(AST* node, TAC* code0, TAC* code1);
TAC* makePrint(AST* node, TAC* code0, TAC* code1);
TAC* makeIfThen(AST* node, TAC* code0, TAC* code1, TAC* code2);
TAC* makeIfThenElse(AST* node, TAC* code0, TAC* code1, TAC* code2);

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
        case TAC_SYMBOL : fprintf(stderr, "TAC_SYMBOL"); break;
        case TAC_ADD    : fprintf(stderr, "TAC_ADD"); break;
        case TAC_SUB    : fprintf(stderr, "TAC_SUB"); break;
        case TAC_MOVE   : fprintf(stderr, "TAC_MOVE"); break;
        case TAC_JFALSE : fprintf(stderr, "TAC_JFALSE"); break;
        case TAC_JUMP   : fprintf(stderr, "TAC_JUMP"); break;
        case TAC_LABEL  : fprintf(stderr, "TAC_LABEL"); break;
        case TAC_MULT   : fprintf(stderr,"TAC_MULT"); break;
        case TAC_DIV    : fprintf(stderr,"TAC_DIV"); break;
        case TAC_LE     : fprintf(stderr,"TAC_LE"); break;
        case TAC_LT     : fprintf(stderr,"TAC_LT"); break;
        case TAC_GE     : fprintf(stderr,"TAC_GE"); break;
        case TAC_GT     : fprintf(stderr,"TAC_GT"); break;
        case TAC_EQ     : fprintf(stderr,"TAC_EQ"); break;
        case TAC_DIF    : fprintf(stderr,"TAC_DIF"); break;
        case TAC_OR     : fprintf(stderr,"TAC_OR"); break;
        case TAC_AND    : fprintf(stderr,"TAC_AND"); break;
        case TAC_NOT    : fprintf(stderr,"TAC_NOT"); break;
        case TAC_ACALL  : fprintf(stderr,"TAC_ACALL"); break;
        case TAC_FCALL  : fprintf(stderr,"TAC_FCALL"); break;
        case TAC_PRINT  : fprintf(stderr,"TAC_PRINT"); break;
        default         : fprintf(stderr, "TAC_UNKNOWN"); break;
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

        // SYMBOLS
        case AST_SYMBOL_CHAR:       
        case AST_SYMBOL_FALSE:      
        case AST_SYMBOL_FLOAT:      
        case AST_SYMBOL_IDENTIFIER: 
        case AST_SYMBOL_INTEGER:    
        case AST_SYMBOL_STRING:     
        case AST_SYMBOL_TRUE:           result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;

        // ARITHMETIC
        case AST_PLUS:              
        case AST_MINUS:             
        case AST_MULT:              
        case AST_DIV:                   result = makeArithmetic(node, code[0], code[1]); break;

        // BOOLEAN
        case AST_LE:                
        case AST_LT:                
        case AST_GE:                
        case AST_GT:                
        case AST_EQ:                
        case AST_DIF:                   result = makeBoolean(node,  code[0], code[1]); break;

        case AST_OR:                    
        case AST_AND:                   result = makeLogical(node, code[0], code[1]); break;
        case AST_NOT:                   result = makeNot(node, code[0]); break;        
        case AST_ARRAY_CALL:            result = makeArrayCall(node, code[0]); break;
        case AST_FUNC_CALL:             result = makeFunctionCall(node, code[0]); break;
        case AST_FUNC_CALL_ARGS:    
        case AST_FUNC_CALL_ARGS_EXT:    result = makeFunctionCallArgs(node, code[0], code[1]); break;

        // CONTROL FLOW
     
        // case AST_LOOP: break;           
        // case AST_WHILE: break;           
        case AST_IF_THEN:               result = makeIfThen(node, code[0], code[1], code[2]); break;

        // COMMAND

        case AST_PRINT_LIST:
        case AST_PRINT_EXTRA_ELEMS:     result = makePrint(node, code[0], code[1]); break;           
        // case AST_ATTR_ARRAY: break;
        case AST_ATTR:                  result = tacJoin(code[0], tacCreate(TAC_MOVE, node->symbol, getResFrom(code[0]), 0)); break;
        // case AST_RETURN: break;
        // case AST_READ: break;
        // case AST_CMD_SEQ: break;
        // case AST_CMD_BLOCK: break;


        // PARAMS:

        // case AST_PARAM: break;
        // case AST_PARAM_LIST_EXT: break;
        // case AST_PARAM_LIST: break;

        // // VALUES:

        // case AST_VET_VALUES: break;
        // case AST_VALUE: break;

        // // KEYWORDS:

        // case AST_KW_FLOAT: break;
        // case AST_KW_INT: break;
        // case AST_KW_BOOL: break;
        // case AST_KW_CHAR: break;

        // // TYPES AND VALUES:

        // case AST_TYPE_AND_VALUE: break;
        // case AST_TYPE_AND_VALUE_ARRAY: break;

        // // DECLARATIONS:

        // case AST_DECL_FUNC: break;
        // case AST_DECL_VAR: break;
        // case AST_DECL_LIST: break;

        default: result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3]))); break;
    }

    return result;
}

TAC* makeArithmetic(AST* node, TAC* code0, TAC* code1) {
    int tac_operator = 0;

    switch(node->type) {
        case AST_PLUS:  tac_operator = TAC_ADD; break;
        case AST_MINUS: tac_operator = TAC_SUB; break;
        case AST_MULT:  tac_operator = TAC_MULT; break;
        case AST_DIV:   tac_operator = TAC_DIV; break;
    }

    return tacJoin(tacJoin(code0, code1), tacCreate(tac_operator, makeTemp(), getResFrom(code0), getResFrom(code1)));
}


TAC* makeBoolean(AST* node, TAC* code0, TAC* code1) {

    HASH_NODE* label1 = makeLabel();
    HASH_NODE* label2 = makeLabel();
    HASH_NODE* temp = makeTemp();

    TAC* branch;
    TAC* mov0      = tacCreate(TAC_MOVE, temp, hashFalse, 0);
    TAC* jump      = tacCreate(TAC_JUMP, label2, 0, 0);
    TAC* label1t   = tacCreate(TAC_LABEL, label1, 0, 0);
    TAC* mov1      = tacCreate(TAC_MOVE, temp, hashTrue, 0);
    TAC* label2t   = tacCreate(TAC_LABEL, label2, 0, 0);

    switch(node->type) {
        case AST_LE:    branch = tacCreate(TAC_LE, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_LT:    branch = tacCreate(TAC_LT, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_GE:    branch = tacCreate(TAC_GE, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_GT:    branch = tacCreate(TAC_GT, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_EQ:    branch = tacCreate(TAC_EQ, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_DIF:   branch = tacCreate(TAC_DIF, label1, getResFrom(code0), getResFrom(code1)); break;
        case AST_NOT:   branch = tacCreate(TAC_NOT, label1, getResFrom(code0), getResFrom(code1)); break;
    }

    TAC* boolean = tacCreate(TAC_SYMBOL, temp, 0, 0);
    TAC* sequence = tacJoin(tacJoin(branch, tacJoin(mov0, tacJoin(jump, tacJoin(label1t, tacJoin(mov1, label2t))))), boolean);

    return tacJoin(tacJoin(code0, code1), sequence);
    // return tacJoin(tacJoin(code0, code1), tacCreate(tac_operator, makeTemp(), getResFrom(code0), getResFrom(code1)));
}


TAC* makeLogical(AST* node, TAC* code0, TAC* code1) {
    HASH_NODE* temp = makeTemp();

    TAC* logical = tacCreate(node->type == AST_AND ? TAC_AND : TAC_OR, temp, code0->res, code1->res);
    return tacJoin(code0, tacJoin(code1, logical));
}

TAC* makeNot(AST* node, TAC* code0) {
    TAC* not = tacCreate(TAC_NOT, makeTemp(), code0->res, 0);
    return tacJoin(code0, not);
}


TAC* makeArrayCall(AST* node, TAC* code0) {
    if(!node || !node->son[0]) return code0;
    return tacJoin(code0, tacCreate(TAC_ACALL, makeTemp(), node->symbol, node->son[0]->symbol));
}


TAC* makeFunctionCall(AST* node, TAC* code0) {
    if(!node) return code0;
    return tacJoin(code0, tacCreate(TAC_FCALL, node->symbol, node->symbol, 0));
}

TAC* makeFunctionCallArgs(AST* node, TAC* code0, TAC* code1) {
    if(!node || !node->son[0]) return tacJoin(code0, code1);
    TAC* arg = tacCreate(TAC_ARG, node->son[0]->symbol, 0, 0);
    return code1 ? tacJoin(code0, tacJoin(code1, arg)) : tacJoin(arg, code0);
}


TAC* makePrint(AST* node, TAC* code0, TAC* code1) {
    TAC* print = tacCreate(TAC_PRINT, code0 ? code0->res : 0, 0, 0);
    return tacJoin(code0, code1 ? tacJoin(print, code1) : print);
}

TAC* makeIfThen(AST* node, TAC* code0, TAC* code1, TAC* code2) {
    if (code2) return makeIfThenElse(node, code0, code1, code2);

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

TAC* makeIfThenElse(AST* node, TAC* code0, TAC* code1, TAC* code2) {
    /*
        JFALSE else
        <code>
        JUMP end
        :else
        <code>
        :end
    */

    printf("CHAMOOOU!!!\n");
    HASH_NODE* elseLabelSymbol = makeLabel();
    HASH_NODE* endLabelSymbol = makeLabel();    

    TAC* jFalse = tacCreate(TAC_JFALSE, elseLabelSymbol, code0->res, 0);
    TAC* jump = tacCreate(TAC_JUMP, endLabelSymbol, 0, 0);
    TAC* elseLabel = tacCreate(TAC_LABEL, elseLabelSymbol, 0, 0);
    TAC* endLabel = tacCreate(TAC_LABEL, endLabelSymbol, 0, 0);

    return tacJoin(code0, tacJoin(jFalse, tacJoin(code1, tacJoin(jump, tacJoin(elseLabel, tacJoin(code2, endLabel))))));
}

HASH_NODE *getResFrom(TAC *code) {
    if(!code) return 0;
    return code->res;
}