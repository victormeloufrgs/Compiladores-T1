%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "hash.h"

    int yylex();
    void yyerror(const char *s);
%}
 
%token KW_CHAR          
%token KW_INT          
%token KW_FLOAT         
%token KW_BOOL          

%token KW_IF            
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_LOOP          
%token KW_READ          
%token KW_PRINT         
%token KW_RETURN        

%token OPERATOR_LE      
%token OPERATOR_GE      
%token OPERATOR_EQ      
%token OPERATOR_DIF 

%union { HASH_NODE *symbol; }

%token TK_IDENTIFIER    

%token LIT_INTEGER      
%token LIT_FLOAT        
%token LIT_TRUE         
%token LIT_FALSE        
%token LIT_CHAR         
%token LIT_STRING

%token TOKEN_ERROR

%%

program: expr
    ;

expr: var_declaration ';' expr | function ';' expr
    |
    ;

var_declaration: TK_IDENTIFIER '=' type ':' lit | vet_declaration
    ;

type: KW_CHAR
    | KW_BOOL
    | KW_INT
    | KW_FLOAT
;

lit: LIT_CHAR
    | LIT_INTEGER
    | LIT_FLOAT
    | LIT_TRUE
    | LIT_FALSE
;

vet_declaration: TK_IDENTIFIER '=' vet_type;

vet_type: type '[' LIT_INTEGER ']' vet_maybe_value;

vet_maybe_value: ':' vet_value
        |
        ;

vet_value: vet_value_int 
        | vet_value_float 
        | vet_value_char
        ;

vet_value_int: LIT_INTEGER vet_value_int_opt;
vet_value_int_opt: LIT_INTEGER vet_value_int_opt
                |
                ;

vet_value_float: LIT_FLOAT vet_value_float_opt;
vet_value_float_opt: LIT_FLOAT vet_value_float_opt
                |
                ;

vet_value_char: LIT_CHAR vet_value_char_opt;
vet_value_char_opt: LIT_CHAR vet_value_char_opt
                |
                ;



function:
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}