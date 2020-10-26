
#include "semantic.h"
#include "stdbool.h"

int SemanticErrors = 0;

void set_func_datatype(AST *node);
void set_var_datatype(AST *node);

void check_var_decl_attr(AST *node);
void check_array_decl_attr(AST *node);
void check_array_values(int expected_datatype, AST *node);
void check_array_decl_attr(AST *node);
void check_params_datatype(AST *function_call_args, AST *param_list, char *func_name);

bool is_number_operator(AST *node);
bool is_boolean_operator(AST *node);
bool is_number(AST *son);
bool is_boolean(AST *son);

void verify_scalar_operator(AST *node, char* operator_name);
void verify_boolean_operator(AST *node, char* operator_name);
void verify_attr_var_operator(AST *node);


int get_datatype_of_operator(AST *node);
bool is_compatible_datatypes(int d1, int d2);
bool is_valid_attr(int identifier_datatype, AST *expr);

// Verifica se uma declaração já foi feita antes.
// Se não foi declarado, seta o DATATYPE.
void check_and_set_declarations(AST *node) {
    int i, data_type;
    if (node == 0)
        return;

    switch (node->type) {
    case AST_DECL_VAR: 
        set_var_datatype(node);
        break;
    case AST_DECL_FUNC:
        set_func_datatype(node);   
        break;    
    case AST_PARAM_LIST:
        break;
    }

    for (i = 0; i < MAX_SONS; ++i)
        check_and_set_declarations(node->son[i]);
}

void set_var_datatype(AST *node) {
    int i, data_type;

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

            check_var_decl_attr(node);
            break;
        case AST_TYPE_AND_VALUE_ARRAY:
            node->symbol->type = SYMBOL_VECTOR;
            data_type = get_datatype_of_vet_decl(node);
            if (data_type != -1)
                node->symbol->datatype = data_type;

            check_array_decl_attr(node);
            break;
    }
}

//verifica se o tipo é igual a atribuição, se existir
void check_var_decl_attr(AST *node) {
    if(node->son[0]->son[1])
        if(!is_compatible_datatypes(get_datatype_of_var_decl(node), get_datatype_of_type(node->son[0]->son[1]->type))) {
            fprintf(stderr,"SEMANTIC ERROR: in variable %s declaration, tried to set invalid value\n", node->symbol->text);
            ++ SemanticErrors;
        }
}

//verifica se cada um dos valores passados na lista são do tipo correto

void check_array_decl_attr(AST *node) {

    //saber qual o tipo correto
    int expected_datatype = node->symbol->datatype;

    if (node->son[0] && node->son[0]->son[2]) {
        AST *vet_maybe_value = node->son[0]->son[2];
        AST *vet_value = vet_maybe_value->son[0];

        //percorrer a lista
            //comparar o tipo de cada elemento com o tipo correto (is_compatible)
        check_array_values(expected_datatype, vet_value);
    }
}

void check_array_values(int expected_datatype, AST *node) {
    if(node == 0)
        return;

    if (node->son[1])
        check_array_values(expected_datatype, node->son[1]);
    
    if(node->son[0]) { // tem n elementos setados
        if(!is_compatible_datatypes(expected_datatype, get_datatype_of_type(node->son[0]->type))){
            fprintf(stderr,"SEMANTIC ERROR: tried to attribute invalid data type \'%s\' into vector position \n", node->son[0]->symbol->text);
            ++ SemanticErrors;
        }
    } else { // só tem 1 elemento setado
        if(!is_compatible_datatypes(expected_datatype, get_datatype_of_type(node->type))){
            fprintf(stderr,"SEMANTIC ERROR: tried to attribute invalid data type \'%s\' into vector position \n", node->symbol->text);
            ++ SemanticErrors;
        }
    }
}

void set_func_datatype(AST *node) {
    int i, data_type;
    if(node->symbol)
        if (node->symbol->type != SYMBOL_IDENTIFIER) {
            fprintf(stderr,"SEMANTIC ERROR: function %s already declared\n", node->symbol->text);
            ++ SemanticErrors;
        }

    node->symbol->type = SYMBOL_FUNCTION;
    data_type = get_datatype_of_func_decl(node);

    if (data_type != -1)
        node->symbol->datatype = data_type;

    node->symbol->astnode = node;
}

void check_vet_indexes(AST *node) {
    int i, data_type;
    if (node == 0)
        return;

    switch (node->type) {
    case AST_TYPE_AND_VALUE_ARRAY: // Verificar se índice do vetor é um inteiro
        if(!is_number(node->son[1])) {
            fprintf(stderr,"SEMANTIC ERROR: size of vector is not a number\n");
                ++ SemanticErrors;
        }
        break;
    case AST_ARRAY_CALL:
        if(!is_number(node->son[0])) { // garante que índice do vetor é inteiro
            fprintf(stderr,"SEMANTIC ERROR: index of vector is not a numberr\n");
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

        AST *function_call_args = node->son[0];

        // se não tem parametros, termina aqui
        if(function_call_args == 0)
            break;



        // verifica se número de parâmetros é correto e se parâmetros são do tipo especificado
        if(node->symbol->astnode != 0) {
            AST *param_list = node->symbol->astnode->son[0];
                
            check_params_datatype(function_call_args, param_list, node->symbol->text);
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

void check_params_datatype(AST *function_call_args, AST *param_list, char *func_name) {
    
    if(function_call_args == 0 && param_list == 0)
        return;

    if(function_call_args == 0 || param_list == 0) {
        fprintf(stderr,"SEMANTIC ERROR: invalid parameters length for function \'%s\' \n", func_name);
        ++ SemanticErrors;
        return;
    }

    AST *arg = function_call_args->son[0];
    AST *param = param_list->son[0];

    if(!is_compatible_datatypes(get_datatype_of_operator(arg), get_datatype_of_type(param->type))) {
        fprintf(stderr,"SEMANTIC ERROR: incompatible parameters for function \'%s\' \n", func_name);
        ++ SemanticErrors;
    }
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
        break;
    case AST_ATTR: // garantir que a atribuição de uma variável está atribuindo o tipo correto
        // TODO

        // verifica se operando esquerdo é diferente de uma variável
        if (node->symbol->type != SYMBOL_VARIABLE) {
            fprintf(stderr,"SEMANTIC ERROR: trying to set a value to a not variable \'%s\' (should be SYMBOL_VARIABLE) \n", node->symbol->text);
            ++ SemanticErrors;
        }

        // verifica se operando esquerdo tem mesmo datatype do operando direito
        if(!is_valid_attr(node->symbol->datatype, node->son[0])) {
            fprintf(stderr,"SEMANTIC ERROR: trying to set a value to %s, but the type of expr is different \n", node->symbol->text);
            ++ SemanticErrors;
        }

        break;
    case AST_ATTR_ARRAY: // garantir que a atribuição de um índice de vetor está atribuindo o tipo correto

        // verifica se operando esquerdo é diferente de um índice de vetor
        if (node->symbol->type != SYMBOL_VECTOR) {
            fprintf(stderr,"SEMANTIC ERROR: trying to set a value to symbol \'%s\' indexed, but \'%s\' is not a vector (SYMBOL_VECTOR) \n", node->symbol->text, node->symbol->text);
            ++ SemanticErrors;
        }

        // verifica se operando esquerdo tem mesmo datatype do operando direito
        if(!is_valid_attr(node->symbol->datatype, node->son[0])) {
            fprintf(stderr,"SEMANTIC ERROR: trying to set a value to vector \'%s\', but the value data_type is wrong (should be %d) \n", node->symbol->text, node->symbol->datatype);
            ++ SemanticErrors;
        }

        break;
    }

    for (i = 0; i < MAX_SONS; i++)
        check_operands(node->son[i]);
}

// void verify_attr_var_operator(AST *node) {

//     if (!is_attributable(node->son[0]) || node->symbol->datatype != get_datatype_of_attributable(node->son[0]->type)) {
//         fprintf(stderr,"Semantic ERROR: invalid attribution to variable %s (the types are different) \n", node->symbol->text);
//         ++ SemanticErrors;
//     }
// }

// int is_attributable(AST *node) {
//     return (
//         is_boolean(node->type) ||
//         is_number(node->type) ||
//         node->type == AST_SYMBOL_STRING ||
//         node->type == AST_SYMBOL_CHAR ||
//         node->type == AST_SYMBOL_IDENTIFIER
//     );
// }

// int get_datatype_of_attributable(AST *node) {
//     int i;
//     if(node == 0)
//         return;
//     for (i = 0; i < MAX_SONS; i++)
//         check_operands(node->son[i]);
    
// }

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
        (son->type == AST_SYMBOL_IDENTIFIER && son->symbol->type == SYMBOL_VARIABLE && son->symbol->datatype == DATATYPE_BOOL) ||
        (son->type == AST_ARRAY_CALL && son->symbol->type == SYMBOL_VECTOR && son->symbol->datatype == DATATYPE_BOOL)
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
        (son->type == AST_SYMBOL_IDENTIFIER && son->symbol->type == SYMBOL_VARIABLE && son->symbol->datatype == DATATYPE_FLOAT) ||
        (son->type == AST_ARRAY_CALL && son->symbol->type == SYMBOL_VECTOR && son->symbol->datatype == DATATYPE_INT) ||
        (son->type == AST_ARRAY_CALL && son->symbol->type == SYMBOL_VECTOR && son->symbol->datatype == DATATYPE_FLOAT)
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

bool is_boolean_operator(AST *node) {
    return (
        node->type == AST_LE ||
        node->type == AST_LT ||
        node->type == AST_GE ||
        node->type == AST_GT ||
        node->type == AST_EQ ||
        node->type == AST_DIF ||
        node->type == AST_OR ||
        node->type == AST_AND ||
        node->type == AST_NOT
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

int get_datatype_of_operator(AST *node) {

    if(node == 0)
        return 0;
    
    if(get_datatype_of_type(node->type) != 0) {
        return get_datatype_of_type(node->type);
    }

    int data_type_0, data_type_1;
    if (node->son[0])
        data_type_0 = get_datatype_of_operator(node->son[0]);

    if (node->son[1])
        data_type_1 = get_datatype_of_operator(node->son[1]);

    if (is_compatible_datatypes(data_type_0, data_type_1)) {
        if (data_type_0 == DATATYPE_INT || data_type_1 == DATATYPE_INT)
            return DATATYPE_INT;

        return data_type_0;
    }

    return 0;
}

bool is_compatible_datatypes(int d1, int d2) {
    if (d1 == 0 || d2 == 0)
        return false;
    
    if (d1 == d2)
        return true;

    if (d1 == DATATYPE_INT && d2 == DATATYPE_FLOAT || 
        d1 == DATATYPE_FLOAT && d2 == DATATYPE_INT)
        return true;
    
    return false;
}

int get_datatype_of_type(int type) {
    switch (type) {
        case AST_KW_BOOL: return DATATYPE_BOOL;
        case AST_KW_CHAR: return DATATYPE_CHAR;
        case AST_KW_FLOAT: return DATATYPE_FLOAT;
        case AST_KW_INT: return DATATYPE_INT;

        case AST_SYMBOL_STRING: return DATATYPE_STRING;
        case AST_SYMBOL_CHAR: return DATATYPE_CHAR;
        case AST_SYMBOL_INTEGER: return DATATYPE_INT;
        case AST_SYMBOL_FLOAT: return DATATYPE_FLOAT;
        case AST_SYMBOL_TRUE: return DATATYPE_BOOL;
        case AST_SYMBOL_FALSE: return DATATYPE_BOOL;
    }

    return 0;
}

bool is_valid_attr(int identifier_datatype, AST *expr) {
    return (
        is_compatible_datatypes(identifier_datatype, get_datatype_of_operator(expr))
    );
}

//TODO: P/ TESTAR INDICES DO VETOR (ver se o tipo dos valores são os mesmos do tipo do vetor), TEMOS QUE GARANTIR QUE ELES SÃO NÚMEROS. SE HOUVER + ÍNDICES DO QUE O ESPECIFICADO, É VÁLIDO. 
//  EH PRECISO PERCORRER BOTTOM-UP (PASSAR A RECURSÃO PRO INÍCIO DO MÉTODO, ANTES DO TESTE)
//   CRIAR UM CAMPO NO AST PARA DISTINGUIR O FLOAT DO INT.

// TODO: P VERIFICAR ARGUMENTOS DE CHAMADA DE FUNÇÃO
// PRECISA PERCORRER 2 LISTAS ENCADEADAS
//      PRA ISSO, PRECISA MANTER UM PONTEIRO PARA APONTAR PRA AST PRA VER ONDE FOI O SÍMBOLO
//      NO CHECK_AND_SET_DECLARATIONS, APONTAR PRO NODO AST_FUNC_DECL, PARA QUANDO CHEGAR NO NODO DE USO, PRECISA SÓ OLHAR PRA HASH QUE CONTÉM 2 PONTEIROS (1 PRA LISTA DE PARAMETROS, E 1 PRA LISTA DE ARGUMENTOS), E AÍ EH SOH VER SE SÃO COMPATIVEIS.
//      A HASH VAI TER QUE INCLUIR A AST.(precisa criar um protótipo de estrutura da ast na hash.h pra dizer que a hash vai apontar pra uma estrutura que não conhece ainda).