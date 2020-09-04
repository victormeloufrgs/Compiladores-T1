#include "symbols.h"

const char* getSymbolName(int symbol) {
    switch (symbol) {
        case SYMBOL_LIT_INTEGER: return "SYMBOL_LIT_INTEGER";
        case SYMBOL_LIT_FLOAT: return "SYMBOL_LIT_FLOAT  ";
        case SYMBOL_LIT_CHAR: return "SYMBOL_LIT_CHAR   ";
        case SYMBOL_LIT_STRING: return "SYMBOL_LIT_STRING ";
        case SYMBOL_LIT_TRUE: return "SYMBOL_LIT_TRUE   ";
        case SYMBOL_LIT_FALSE: return "SYMBOL_LIT_FALSE  ";
        case SYMBOL_IDENTIFIER: return "SYMBOL_IDENTIFIER ";
        default: return "ERROR! UNDEFINED SYMBOL";
    }
}

int getSymbolFromToken(int id) {
    switch(id) {
        case LIT_TRUE:
            return SYMBOL_LIT_TRUE;

        case LIT_FALSE:
            return SYMBOL_LIT_FALSE;

        case LIT_INTEGER:
            return SYMBOL_LIT_INTEGER;

        case LIT_FLOAT:
            return SYMBOL_LIT_FLOAT;

        case LIT_CHAR:
            return SYMBOL_LIT_CHAR;

        case LIT_STRING:
            return SYMBOL_LIT_STRING;

        case TK_IDENTIFIER:
            return SYMBOL_IDENTIFIER;

        default:
            return -1;
    }
}