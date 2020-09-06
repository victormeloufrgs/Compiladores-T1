/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

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
%token OPERATOR_LT      
%token OPERATOR_GE      
%token OPERATOR_GT      
%token OPERATOR_EQ      
%token OPERATOR_DIF     
%token OPERATOR_OR     
%token OPERATOR_AND     
%token OPERATOR_NOT

%token OPERATOR_PLUS 
%token OPERATOR_MINUS
%token OPERATOR_MULT
%token OPERATOR_DIV

%union { HASH_NODE *symbol; }

%token TK_IDENTIFIER    

%token LIT_INTEGER      
%token LIT_FLOAT        
%token LIT_TRUE         
%token LIT_FALSE        
%token LIT_CHAR         
%token LIT_STRING

%token TOKEN_ERROR

%left OPERATOR_OR OPERATOR_AND
%left OPERATOR_LE OPERATOR_LT OPERATOR_GE OPERATOR_GT OPERATOR_EQ OPERATOR_DIF OPERATOR_NOT
%left OPERATOR_PLUS OPERATOR_MINUS
%left OPERATOR_MULT OPERATOR_DIV

%%

program: global_var_declaration ';' program 
    | function ';' program
    |
    ;

global_var_declaration: TK_IDENTIFIER '=' type ':' lit 
    | vet_declaration
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

vet_value: LIT_INTEGER vet_value 
         | LIT_FLOAT vet_value 
         | LIT_CHAR vet_value
         | LIT_TRUE vet_value
         | LIT_FALSE vet_value
         | LIT_INTEGER
         | LIT_FLOAT
         | LIT_CHAR
         | LIT_TRUE
         | LIT_FALSE
         ;

function: function_header command_block
    ;

function_header: TK_IDENTIFIER '(' maybe_function_header_params ')' '=' type
    ;

maybe_function_header_params: function_header_params
    |
    ;
    
function_header_params: TK_IDENTIFIER '=' type ',' function_header_params
    | TK_IDENTIFIER '=' type
    ;

command_block: '{' command_seq '}'
    ;

command_seq: command command_seq
    |
    ;

command: command_attr
    | KW_READ TK_IDENTIFIER
    | KW_RETURN expr
    | command_flow
    | command_block
    | command_print
    |
    ;

command_print:  KW_PRINT print_elem maybe_print_elems
    ;

print_elem: LIT_STRING
    | expr
    ;

maybe_print_elems: ',' print_elem maybe_print_elems
    |
    ;

command_attr: TK_IDENTIFIER '=' expr
    | TK_IDENTIFIER '[' expr ']' '=' expr
    ;

command_flow: KW_IF '(' expr ')' KW_THEN command maybe_else
    | KW_WHILE '(' expr ')' command
    | KW_LOOP '(' TK_IDENTIFIER ':' expr expr_cont_list ')' command
    ;

maybe_else: KW_ELSE command
    |
    ;

expr_cont_list: ',' expr expr_cont_list
    |
    ;

expr: expr bin_operator expr
    | '(' expr ')'
    | OPERATOR_NOT expr
    | TK_IDENTIFIER opt_array_index
    | lit
    | function_call
    ;

opt_array_index: '[' expr ']' 
    | 
    ;

bin_operator: OPERATOR_PLUS
            | OPERATOR_MINUS
            | OPERATOR_MULT
            | OPERATOR_DIV
            | OPERATOR_LE
            | OPERATOR_LT      
            | OPERATOR_GE      
            | OPERATOR_GT      
            | OPERATOR_EQ      
            | OPERATOR_DIF     
            | OPERATOR_OR     
            | OPERATOR_AND
            ;

function_call: TK_IDENTIFIER '(' function_call_args ')'
    ;

function_call_args: expr
        | expr ',' function_call_args
        ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}