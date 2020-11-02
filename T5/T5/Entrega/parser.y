/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

%{
    #include "ast.h"
    #include "hash.h"
    #include "semantic.h"
    #include "tacs.h"

    void yyerror(const char *s);
    int getLineNumber();
    int yylex();
%}
 
%union
{
    HASH_NODE *symbol;
    AST *ast;
}

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

%token<symbol> TK_IDENTIFIER    

%token<symbol> LIT_INTEGER      
%token<symbol> LIT_FLOAT        
%token<symbol> LIT_TRUE         
%token<symbol> LIT_FALSE        
%token<symbol> LIT_CHAR         
%token<symbol> LIT_STRING

%token TOKEN_ERROR

%type<ast> expr
%type<ast> lit
%type<ast> bin_expr
%type<ast> command
%type<ast> command_seq
%type<ast> command_block
%type<ast> print_elem
%type<ast> function_call_args
%type<ast> func_args_extra
%type<ast> maybe_else
%type<ast> command_control
%type<ast> print_extra_elems
%type<ast> print_list
%type<ast> command_attribute
%type<ast> param
%type<ast> param_list_ext
%type<ast> param_list
%type<ast> maybe_params
%type<ast> vet_value
%type<ast> vet_maybe_value
%type<ast> type
%type<ast> type_and_value
%type<ast> declaration
%type<ast> declaration_list

%left OPERATOR_OR OPERATOR_AND
%left OPERATOR_LE OPERATOR_LT OPERATOR_GE OPERATOR_GT OPERATOR_EQ OPERATOR_DIF OPERATOR_NOT
%left OPERATOR_PLUS OPERATOR_MINUS
%left OPERATOR_MULT OPERATOR_DIV

%%

program: declaration_list                           { 
                                                      tree = $1; 
                                                      set_scope($1);
                                                      check_and_set_declarations($1);
                                                      check_vet_indexes($1);
                                                      check_var_vet_func_use($1);
                                                      check_undeclared();
                                                      check_operands($1);
                                                      tacPrintBackwards(generateCode($1));
                                                    }
    ;

declaration_list: declaration declaration_list          { $$ = astCreate(AST_DECL_LIST, 0, $1, $2, 0, 0); }
    |                                                   { $$ = 0; }
    ;

declaration: TK_IDENTIFIER '=' type_and_value ';'                       { $$ = astCreate(AST_DECL_VAR, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '(' maybe_params ')' '=' type command_block ';'     { $$ = astCreate(AST_DECL_FUNC, $1, $3, $6, $7, 0); }
    ;
    
type_and_value: type ':' lit                                            { $$ = astCreate(AST_TYPE_AND_VALUE, 0, $1, $3, 0, 0); }
    | type '[' expr ']' vet_maybe_value                          { $$ = astCreate(AST_TYPE_AND_VALUE_ARRAY, 0, $1, $3, $5, 0); }
    ;


type: KW_CHAR                                   { $$ = astCreate(AST_KW_CHAR, 0, 0, 0, 0, 0); }
    | KW_BOOL                                   { $$ = astCreate(AST_KW_BOOL, 0, 0, 0, 0, 0); }
    | KW_INT                                    { $$ = astCreate(AST_KW_INT, 0, 0, 0, 0, 0); }
    | KW_FLOAT                                  { $$ = astCreate(AST_KW_FLOAT, 0, 0, 0, 0, 0); }
    ;

lit: LIT_CHAR                                   { $$ = astCreate(AST_SYMBOL_CHAR, $1, 0, 0, 0, 0); }
    | LIT_INTEGER                               { $$ = astCreate(AST_SYMBOL_INTEGER, $1, 0, 0, 0, 0); }
    | LIT_FLOAT                                 { $$ = astCreate(AST_SYMBOL_FLOAT, $1, 0, 0, 0, 0); }
    | LIT_TRUE                                  { $$ = astCreate(AST_SYMBOL_TRUE, $1, 0, 0, 0, 0); }
    | LIT_FALSE                                 { $$ = astCreate(AST_SYMBOL_FALSE, $1, 0, 0, 0, 0); }
    ;

vet_maybe_value: ':' vet_value                  { $$ = astCreate(AST_VALUE, 0, $2, 0, 0, 0); }
    |                                           { $$ = 0; }
    ;

vet_value: lit vet_value                        { $$ = astCreate(AST_VET_VALUES, 0, $1, $2, 0, 0); }
    | lit                                       { $$ = $1; }
    ;

maybe_params: param_list                        { $$ = $1; }
    |                                           { $$ = 0; }
    ;
    
param_list: param param_list_ext                { $$ = astCreate(AST_PARAM_LIST, 0, $1, $2, 0, 0); }
    ;

param_list_ext: ',' param param_list_ext        { $$ = astCreate(AST_PARAM_LIST_EXT, 0, $2, $3, 0, 0); }
    |                                           { $$ = 0; }
    ;

param: TK_IDENTIFIER '=' type                   { $$ = astCreate(AST_PARAM, $1, $3, 0, 0, 0); }                   
    ;

command_block: '{' command_seq '}'              { $$ = astCreate(AST_CMD_BLOCK, 0, $2, 0, 0, 0); }
    ;

command_seq: command_seq command                { $$ = astCreate(AST_CMD_SEQ, 0, $1, $2, 0, 0); }
    |                                           { $$ = 0; }
    ;

command: command_attribute                      { $$ = $1; }
    | KW_READ TK_IDENTIFIER                     { $$ = astCreate(AST_READ, $2, 0, 0, 0, 0); }             
    | KW_RETURN expr                            { $$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0); }
    | KW_PRINT print_list                       { $$ = astCreate(AST_PRINT, 0, $2, 0, 0, 0); }
    | command_control                           { $$ = $1; }
    | command_block                             { $$ = $1; }
    |                                           { $$ = 0; }
    ;

command_attribute: TK_IDENTIFIER '=' expr               { $$ = astCreate(AST_ATTR, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']' '=' expr               { $$ = astCreate(AST_ATTR_ARRAY, $1, $3, $6, 0, 0); }
    ;

print_list:  print_elem print_extra_elems               { $$ = astCreate(AST_PRINT_LIST, 0, $1, $2, 0, 0); }
    ;

print_extra_elems: ',' print_elem print_extra_elems     { $$ = astCreate(AST_PRINT_EXTRA_ELEMS, 0, $2, $3, 0, 0); }
    |                                                   { $$ = 0; }
    ;

print_elem: LIT_STRING                                  { $$ = astCreate(AST_SYMBOL_STRING, $1, 0, 0, 0, 0); }
    | expr                                              { $$ = $1; }
    ;

command_control: KW_IF '(' expr ')' KW_THEN command maybe_else              { $$ = astCreate(AST_IF_THEN, 0, $3, $6, $7, 0); }
    | KW_WHILE '(' expr ')' command                                         { $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0); }
    | KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' command      { $$ = astCreate(AST_LOOP, $3, $5, $7, $9, $11); }
    ;

maybe_else: KW_ELSE command                             { $$ = astCreate(AST_MAYBE_ELSE, 0, $2, 0, 0, 0); }
    |                                                   { $$ = 0; }
    ;

expr: bin_expr                                          { $$ = $1; }
    | '(' expr ')'                                      { $$ = $2; }
    | OPERATOR_NOT expr                                 { $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0); }
    | TK_IDENTIFIER                                     { $$ = astCreate(AST_SYMBOL_IDENTIFIER, $1, 0, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']'                        { $$ = astCreate(AST_ARRAY_CALL, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '(' function_call_args ')'          { $$ = astCreate(AST_FUNC_CALL, $1, $3, 0, 0, 0); }
    | lit                                               { $$ = $1; }
    ;

bin_expr: expr OPERATOR_PLUS expr                   { $$ = astCreate(AST_PLUS, 0, $1, $3, 0, 0); }
    | expr OPERATOR_MINUS expr                      { $$ = astCreate(AST_MINUS, 0, $1, $3, 0, 0); }
    | expr OPERATOR_MULT expr                       { $$ = astCreate(AST_MULT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_DIV expr                        { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LE expr                         { $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LT expr                         { $$ = astCreate(AST_LT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_GE expr                         { $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_GT expr                         { $$ = astCreate(AST_GT, 0, $1, $3, 0, 0); }
    | expr OPERATOR_EQ expr                         { $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
    | expr OPERATOR_DIF expr                        { $$ = astCreate(AST_DIF, 0, $1, $3, 0, 0); }
    | expr OPERATOR_OR expr                         { $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
    | expr OPERATOR_AND expr                        { $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
    ;


function_call_args: expr func_args_extra            { $$ = astCreate(AST_FUNC_CALL_ARGS, 0, $1, $2, 0, 0); }     
    |                                               { $$ = 0; }
    ;

func_args_extra: ',' expr func_args_extra           { $$ = astCreate(AST_FUNC_CALL_ARGS_EXT, 0, $2, $3, 0, 0); }
    |                                               { $$ = 0; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}