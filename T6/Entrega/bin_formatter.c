// C program to convert a real value 
// to IEEE 754 floating point representaion 

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "bin_formatter.h"

myfloat myfloat_from_float(float f) {
    myfloat mf;
    mf.f = f;
    return mf;
}

char *concat_string(char* string, char* addition) {
	char* newStr = malloc(strlen(string)+strlen(addition)+1);
	newStr = strcpy(newStr, string);
	strcat(newStr, addition);
	return newStr;
}

// To return value of a char. For example, 2 is 
// returned for '2'.  10 is returned for 'A', 11 
// for 'B' 
int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 

// To return char for a value. For example '2' 
// is returned for 2. 'A' is returned for 10. 'B' 
// for 11 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
  
// Utility function to reverse a string 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 

// Function to convert a number from given base 'b' 
// to decimal 
int toDeci(char *str, int base) 
{ 

    int len = strlen(str); 
    int power = 1; // Initialize power of base 
    int num = 0;  // Initialize result 
    int i; 
  
    // Decimal equivalent is str[len-1]*1 + 
    // str[len-2]*base + str[len-3]*(base^2) + ... 
    for (i = len - 1; i >= 0; i--) 
    { 
        // A digit in input number must be 
        // less than number's base 
        if (val(str[i]) >= base) 
        { 
           printf("Invalid Number"); 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
}

// Function to convert a given decimal number 
// to a base 'base' and 
char* fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    // Reverse the result 
    strev(res); 
  
    return res; 
} 


char* getBinary(char* buffer, int n, int i) 
{ 
  
    // Returns the binary representation 
    // of a number n up to i-bits. 
    int k;

    for (k = i - 1; k >= 0; k--) { 
        if ((n >> k) & 1)
            buffer = concat_string(buffer, "1");
        else
            buffer = concat_string(buffer, "0");
    } 


    printf("\n\nbinary: %s\n\n", buffer);

    return buffer;
}
  
// Function to convert real value 
// to IEEE foating point representation 
char* getIEEE(char* buffer, float var) 
{ 
    // Prints the IEEE 754 representation 
    // of a float value (32 bits) 

    myfloat mf;
    mf.f = var;

    char temp_buffer1[1024] = "";
    char temp_buffer2[1024] = "";

    sprintf(buffer, "%d", mf.raw.sign); 
    sprintf(buffer,"%s", getBinary(temp_buffer1, mf.raw.exponent, 8)); 

    buffer = concat_string(buffer, getBinary(temp_buffer2, mf.raw.mantissa, 23));
    
    sprintf(buffer, "%d", toDeci(buffer,2));

    printf("\n\ndecimal: %s\n\n", buffer);

    return buffer;
} 