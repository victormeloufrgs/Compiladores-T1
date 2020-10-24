/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#include "symbols.h"

// Usado no hashPrint()
const char* getSymbolName(int symbol) {
    switch (symbol) {
        case SYMBOL_LIT_INTEGER: return "SYMBOL_LIT_INTEGER";
        case SYMBOL_LIT_FLOAT: return "SYMBOL_LIT_FLOAT  ";
        case SYMBOL_LIT_CHAR: return "SYMBOL_LIT_CHAR   ";
        case SYMBOL_LIT_STRING: return "SYMBOL_LIT_STRING ";
        case SYMBOL_LIT_TRUE: return "SYMBOL_LIT_TRUE   ";
        case SYMBOL_LIT_FALSE: return "SYMBOL_LIT_FALSE  ";
        case SYMBOL_VARIABLE: return "SYMBOL_VARIABLE   ";
        case SYMBOL_FUNCTION: return "SYMBOL_FUNCTION   ";
        case SYMBOL_VECTOR: return "SYMBOL_VECTOR     ";
        case SYMBOL_IDENTIFIER: return "SYMBOL_IDENTIFIER ";
        default: return "ERROR! UNDEFINED SYMBOL";
    }
}

const char* getDataTypeName(int datatype) {
    switch (datatype) {
        case DATATYPE_BOOL: return "DATATYPE_BOOL ";
        case DATATYPE_CHAR: return "DATATYPE_CHAR ";
        case DATATYPE_FLOAT: return "DATATYPE_FLOAT";
        case DATATYPE_INT: return "DATATYPE_INT  ";
        default: return "__UNDEFINED__ ";
    }
}