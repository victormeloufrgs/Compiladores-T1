#ifndef BIN_FORMATTER_HEADER
#define BIN_FORMATTER_HEADER

typedef union { 
  
    float f; 
    struct
    { 
  
        // Order is important. 
        // Here the members of the union data structure 
        // use the same memory (32 bits). 
        // The ordering is taken 
        // from the LSB to the MSB. 
        unsigned int mantissa : 23; 
        unsigned int exponent : 8; 
        unsigned int sign : 1; 
  
    } raw; 
} myfloat; 

char *concat_string(char* string, char* addition);
float hexFloatToDecimalFloat(char *hexFloat);
float toDeci(char *str, int base, int floating_length);
char* fromDeci(char res[], int base, int inputNum);
char* getIEEE(char* buffer, float var);
char* getBinary(char* buffer, int n, int i);
char* remover_aspas_do_char(char* char_com_aspas);

#endif