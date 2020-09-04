#define SYMBOL_LIT_INTEGER  1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_LIT_TRUE 5
#define SYMBOL_LIT_FALSE 6
#define SYMBOL_IDENTIFIER 7

const char* getSymbolName(int symbol);
int getSymbolFromToken(int id);