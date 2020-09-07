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

program: declaration_list
    ;

declaration_list: declaration declaration_list
    |
    ;

declaration: var_declaration | function_declaration
    ;
    
var_declaration: TK_IDENTIFIER '=' type_and_value ';'
    ;
    
type_and_value: type ':' lit
    | type '[' LIT_INTEGER ']' vet_maybe_value
    ;


type: KW_CHAR | KW_BOOL | KW_INT | KW_FLOAT
    ;

lit: LIT_CHAR | LIT_INTEGER | LIT_FLOAT | LIT_TRUE | LIT_FALSE
    ;

vet_maybe_value: ':' vet_value
    |
    ;

vet_value: lit vet_value
    | lit
    ;

function_declaration: TK_IDENTIFIER '(' parameters ')' '=' type command_block ';'
    ;

parameters: parameter_list
    |
    ;
    
parameter_list: param ',' parameter_list | param
    ;

param: TK_IDENTIFIER '=' type
    ;

command_block: '{' command_seq '}'
    ;

command_seq: command_seq command
    |
    ;

command: command_attribute
    | KW_READ TK_IDENTIFIER
    | KW_RETURN expr
    | KW_PRINT print_list
    | command_control
    | command_block
    |
    ;

command_attribute: TK_IDENTIFIER '=' expr
    | TK_IDENTIFIER '[' expr ']' '=' expr
    ;

print_list: print_element ',' print_list | print_element
    ;

print_element: LIT_STRING | expr
    ;

command_control: KW_IF '(' expr ')' KW_THEN command maybe_else
    | KW_WHILE '(' expr ')' command
    | KW_LOOP '(' TK_IDENTIFIER ':' expr expr_cont_list ')' command
    ;

maybe_else: KW_ELSE command
    |
    ;

expr_cont_list: ',' expr expr_cont_list
    |
    ;

expr: bin_expr
    | '(' expr ')'
    | OPERATOR_NOT expr
    | TK_IDENTIFIER
    | TK_IDENTIFIER '[' expr ']'
    | TK_IDENTIFIER '(' function_call_args ')'
    | lit
    ;

bin_expr: expr OPERATOR_PLUS expr
    | expr OPERATOR_MINUS expr
    | expr OPERATOR_MULT expr
    | expr OPERATOR_DIV expr
    | expr OPERATOR_LE expr
    | expr OPERATOR_LT expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_GT expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_DIF expr
    | expr OPERATOR_OR expr
    | expr OPERATOR_AND expr
    ;

function_call_args: expr
    | expr ',' function_call_args
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}