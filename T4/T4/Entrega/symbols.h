/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

#define SYMBOL_LIT_INTEGER  1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_LIT_TRUE 5
#define SYMBOL_LIT_FALSE 6
#define SYMBOL_IDENTIFIER 7
#define SYMBOL_VARIABLE 8
#define SYMBOL_FUNCTION 9
#define SYMBOL_VECTOR 10

#define DATATYPE_INT    1
#define DATATYPE_BOOL   2
#define DATATYPE_FLOAT  3
#define DATATYPE_CHAR   4

const char* getSymbolName(int symbol);
const char* getDataTypeName(int datatype);