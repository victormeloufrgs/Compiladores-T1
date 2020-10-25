
#include "semantic.h"
#include "stdbool.h"

int SemanticErrors = 0;

bool is_number_operator(AST *node);
bool is_number(AST *son);
bool is_integer(AST *node);
bool is_boolean(AST *son);

void verify_scalar_operator(AST *node, char* operator_name);
void verify_boolean_operator(AST *node, char* operator_name);


// Verifica se uma variável/função/vetor já foi declarado antes.
void check_and_set_declarations(AST *node) {
    int i, data_type;
    if (node == 0)
        return;

    switch (node->type) {
    case AST_DECL_VAR: 
        if(node->symbol)
            if (node->symbol->type != SYMBOL_IDENTIFIER) {
                fprintf(stderr,"SEMANTIC ERROR: variable %s already declared\n", node->symbol->text);
                ++ SemanticErrors;
            }
    
        switch(node->son[0]->type) {
            case AST_TYPE_AND_VALUE:
                node->symbol->type = SYMBOL_VARIABLE;
                data_type = get_datatype_of_var_decl(node);
                if (data_type != -1)
                    node->symbol->datatype = data_type;
                break;
            case AST_TYPE_AND_VALUE_ARRAY:
                node->symbol->type = SYMBOL_VECTOR;
                data_type = get_datatype_of_vet_decl(node);
                if (data_type != -1)
                    node->symbol->datatype = data_type;
                break;
        }

        break;
    case AST_DECL_FUNC:
        if(node->symbol)
            if (node->symbol->type != SYMBOL_IDENTIFIER) {
                fprintf(stderr,"SEMANTIC ERROR: function %s already declared\n", node->symbol->text);
                ++ SemanticErrors;
            }
        node->symbol->type = SYMBOL_FUNCTION;
        data_type = get_datatype_of_func_decl(node);

        if (data_type != -1)
            node->symbol->datatype = data_type;

        // fprintf(stderr,"node type is %d\n", node->son[1]->type);
        // fprintf(stderr,"data_type is %d\n", data_type);
        break;        
    }

    for (i = 0; i < MAX_SONS; ++i)
        check_and_set_declarations(node->son[i]);
}

void check_vet_indexes(AST *node) {
    int i, data_type;
    if (node == 0)
        return;

    switch (node->type) {
    case AST_TYPE_AND_VALUE_ARRAY: // Verificar se índice do vetor é um inteiro
        if(!is_integer(node->son[1])) {
            fprintf(stderr,"SEMANTIC ERROR: size of vector is not an integer\n");
                ++ SemanticErrors;
        }
        break;
    case AST_ARRAY_CALL:
        if(!is_integer(node->son[0])) { // garante que índice do vetor é inteiro
            fprintf(stderr,"SEMANTIC ERROR: index of vector is not an integer\n");
                ++ SemanticErrors;
        }
        break;
    }

    for (i = 0; i < MAX_SONS; ++i)
        check_vet_indexes(node->son[i]);
}

void check_var_vet_func_use(AST *node) {
    int i, data_type;
    if (node == 0)
        return;

    switch (node->type) {
        if(node->symbol->type != SYMBOL_VECTOR) { // garante que identifier usada como vetor é realmente vetor (não é func nem var)
            fprintf(stderr,"SEMANTIC ERROR: %s is not a vector\n", node->symbol->text);
                ++ SemanticErrors;
        }
        break;
    case AST_FUNC_CALL:
        if(node->symbol->type != SYMBOL_FUNCTION) { // garante que identifier usada como função é realmente função (não é vet nem var)
            fprintf(stderr,"SEMANTIC ERROR: %s is not a function \n", node->symbol->text);
                ++ SemanticErrors;
        }
        break;
    case AST_SYMBOL_IDENTIFIER:
        if(node->symbol->type != SYMBOL_VARIABLE) { // garante que identifier usado como var é realmente var (não é vet nem func)
            fprintf(stderr,"SEMANTIC ERROR: %s is not a variable \n", node->symbol->text);
            ++ SemanticErrors;
        }
        break;
    }

    for (i = 0; i < MAX_SONS; ++i)
        check_var_vet_func_use(node->son[i]);
}

// Verifica se os operandos usados numa operação são do tipo correto (ex: números para +, -, * e /, e bools pra ^, |, ==,...)
void check_operands(AST *node) {
    if (node == 0)
        return;

    int i, data_type;
    
    // fprintf(stderr, "node->type == %d\n\n", node->type);
    
    switch (node->type) {
    case AST_PLUS: // IF OPERANDS ARE *NOT* VALID
        verify_scalar_operator(node, "ADD");
        break;
    case AST_MINUS:
        verify_scalar_operator(node, "SUB");
       break;
    case AST_MULT:
        verify_scalar_operator(node, "MULT");
        break;   
    case AST_DIV:
        verify_scalar_operator(node, "DIV");
        break;
    case AST_GE:
        verify_boolean_operator(node, "GE");
        break;
    case AST_GT:
        verify_boolean_operator(node, "GT");
        break;
    case AST_LE:
        verify_boolean_operator(node, "LE");
        break;
    case AST_LT:
        verify_boolean_operator(node, "LT");
        break;
    case AST_EQ:
        verify_boolean_operator(node, "EQ");
        break;
    case AST_DIF:
        verify_boolean_operator(node, "DIF");
        break;
    case AST_OR:
        verify_boolean_operator(node, "OR");
        break;
    case AST_AND:
        verify_boolean_operator(node, "AND");
        break;
    case AST_NOT:
        verify_boolean_operator(node, "NOT");
    }

    for (i = 0; i < MAX_SONS; i++)
        check_operands(node->son[i]);
}

void verify_scalar_operator(AST *node, char* operator_name) {
    if (node->son[0] != 0 && !is_number(node->son[0])) {
            fprintf(stderr,"Semantic ERROR: invalid left operand for %s \n", operator_name);
            ++ SemanticErrors;
        }

    if (node->son[1] != 0 &&!is_number(node->son[1])) {
        fprintf(stderr,"Semantic ERROR: invalid right operand for %s \n", operator_name);
        ++ SemanticErrors;
    }
}

void verify_boolean_operator(AST *node, char* operator_name) {
    if (node->son[0] != 0 && !is_boolean(node->son[0])) {
        fprintf(stderr,"Semantic ERROR: invalid left operand for %s \n", operator_name);
        ++ SemanticErrors;
    }

    if (node->son[1] != 0 &&!is_boolean(node->son[1])) {
        fprintf(stderr,"Semantic ERROR: invalid right operand for %s \n", operator_name);
        ++ SemanticErrors;
    }
}

bool is_boolean(AST *son) {
    return (
        son->type == AST_SYMBOL_TRUE ||
        son->type == AST_SYMBOL_FALSE ||
        son->type == AST_AND ||
        son->type == AST_OR ||
        son->type == AST_GT ||
        son->type == AST_GE ||
        son->type == AST_LT ||
        son->type == AST_LE ||
        son->type == AST_EQ ||
        son->type == AST_DIF ||
        son->type == AST_NOT ||
        (son->symbol->type == SYMBOL_FUNCTION && son->symbol->datatype == DATATYPE_BOOL) ||
        (son->type == AST_SYMBOL_IDENTIFIER && son->symbol->type == SYMBOL_VARIABLE && son->symbol->datatype == DATATYPE_BOOL)
        // TODO: FALTA TRATAR VETOR
    );
}

bool is_integer(AST *node) {
    return (
        node->type == AST_SYMBOL_INTEGER ||
        (is_number_operator(node) && is_integer(node->son[0]) && is_integer(node->son[1]))
    );
}

// retorna true se o nodo for do tipo número
bool is_number(AST *son) {
    return (
        is_number_operator(son) ||
        son->type == AST_SYMBOL_INTEGER ||
        son->type == AST_SYMBOL_FLOAT ||
        (son->type == AST_FUNC_CALL && son->symbol->datatype == DATATYPE_INT) ||
        (son->type == AST_SYMBOL_IDENTIFIER && son->symbol->type == SYMBOL_VARIABLE && son->symbol->datatype == DATATYPE_INT) ||
        (son->type == AST_SYMBOL_IDENTIFIER && son->symbol->type == SYMBOL_VARIABLE && son->symbol->datatype == DATATYPE_FLOAT)
        // TODO: FALTA TRATAR VETOR
    );
}

bool is_number_operator(AST *node) {
    return (
        node->type == AST_PLUS ||
        node->type == AST_MINUS ||
        node->type == AST_MULT ||
        node->type == AST_DIV
    );
}

// Verifica se existem variáveis não declaradas
void check_undeclared() {
    SemanticErrors += hash_check_undeclared();
}

int get_semantic_errors() {
    return SemanticErrors;
}

int get_datatype_of_vet_decl(AST *node) {
    if (node->son[0])
        if(node->son[0]->son[0])
            return get_datatype_of_type(node->son[0]->son[0]->type);
    return -1;
}

int get_datatype_of_var_decl(AST *node) {
    if (node->son[0])
        if(node->son[0]->son[0])
            return get_datatype_of_type(node->son[0]->son[0]->type);
    return -1;
}

int get_datatype_of_func_decl(AST *node) {
    if (node->son[1])
        return get_datatype_of_type(node->son[1]->type);
    return 0;
}

int get_datatype_of_type(int kw) {
    switch (kw) {
        case AST_KW_BOOL: return DATATYPE_BOOL;
        case AST_KW_CHAR: return DATATYPE_CHAR;
        case AST_KW_FLOAT: return DATATYPE_FLOAT;
        case AST_KW_INT: return DATATYPE_INT;
    }

    return 0;
}

//TODO: P/ TESTAR INDICES DO VETOR, TEMOS QUE GARANTIR QUE ELES SÃO NÚMEROS. SE HOUVER + ÍNDICES DO QUE O ESPECIFICADO, É VÁLIDO. 
//  EH PRECISO PERCORRER BOTTOM-UP (PASSAR A RECURSÃO PRO INÍCIO DO MÉTODO, ANTES DO TESTE)
//   CRAIR UM CAMPO NO AST PARA DISTINGUIR O FLOAT DO INT.

// TODO: P VERIFICAR ARGUMENTOS DE CHAMADA DE FUNÇÃO
// PRECISA PERCORRER 2 LISTAS ENCADEADAS
//      PRA ISSO, PRECISA MANTER UM PONTEIRO PARA APONTAR PRA AST PRA VER ONDE FOI O SÍMBOLO
//      NO CHECK_AND_SET_DECLARATIONS, APONTAR PRO NODO AST_FUNC_DECL, PARA QUANDO CHEGAR NO NODO DE USO, PRECISA SÓ OLHAR PRA HASH QUE CONTÉM 2 PONTEIROS (1 PRA LISTA DE PARAMETROS, E 1 PRA LISTA DE ARGUMENTOS), E AÍ EH SOH VER SE SÃO COMPATIVOS.
//      A HASH VAI TER QUE INCLUIR A AST.(precisa criar um protótipo de estrutura da ast na hash.h pra dizer que a hash vai apontar pra uma estrutura que não conhece ainda).