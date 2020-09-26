/*
Aluno:      Victor dos Santos Melo
Matrícula:  00285640
*/

%{
    #include "ast.h"
    #include "hash.h"

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
%type<ast> expr_cont_list
%type<ast> command
%type<ast> command_seq
%type<ast> print_element
%type<ast> function_call_args
%type<ast> func_args_extra

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

declaration: TK_IDENTIFIER '=' type_and_value ';' 
    | TK_IDENTIFIER '(' parameters ')' '=' type command_block ';'
    ;
    
type_and_value: type ':' lit
    | type '[' LIT_INTEGER ']' vet_maybe_value
    ;


type: KW_CHAR | KW_BOOL | KW_INT | KW_FLOAT
    ;

lit: LIT_CHAR                   { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_INTEGER               { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_FLOAT                 { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_TRUE                  { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_FALSE                 { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    ;

vet_maybe_value: ':' vet_value
    |
    ;

vet_value: lit vet_value
    | lit
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

command_seq: command_seq command                { $$ = 0; } // TODO
    |                                           { $$ = 0; } // TODO
    ;

command: command_attribute                      { $$ = 0; } // TODO
    | KW_READ TK_IDENTIFIER                     { $$ = 0; } // TODO                
    | KW_RETURN expr                            { $$ = 0; } // TODO
    | KW_PRINT print_list                       { $$ = 0; } // TODO
    | command_control                           { $$ = 0; } // TODO
    | command_block                             { $$ = 0; } // TODO
    |                                           { $$ = 0; } // TODO
    ;

command_attribute: TK_IDENTIFIER '=' expr
    | TK_IDENTIFIER '[' expr ']' '=' expr
    ;

print_list: print_element ',' print_list | print_element
    ;

print_element: LIT_STRING                   { $$ = 0; } // TODO
    | expr                                  { astPrint($1, 0); }
    ;

command_control: KW_IF '(' expr ')' KW_THEN command maybe_else
    | KW_WHILE '(' expr ')' command
    | KW_LOOP '(' TK_IDENTIFIER ':' expr expr_cont_list ')' command
    ;

maybe_else: KW_ELSE command
    |
    ;

expr_cont_list: ',' expr expr_cont_list             { $$ = 0; } // TODO
    |                                               { $$ = 0; }
    ;

expr: bin_expr                                      { $$ = $1; }
    | '(' expr ')'                                  { $$ = $2; }
    | OPERATOR_NOT expr                             { $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0); }
    | TK_IDENTIFIER                                 { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']'                    { $$ = astCreate(AST_ARRAY_CALL, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER '(' function_call_args ')'      { $$ = astCreate(AST_FUNC_CALL, $1, $3, 0, 0, 0); }
    | lit                                           { $$ = $1; }
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


function_call_args: expr func_args_extra      { $$ = astCreate(AST_FUNC_CALL_ARGS, 0, $1, $2, 0, 0); }     
    |                                         { $$ = 0; }
    ;

func_args_extra: ',' expr func_args_extra     { $$ = astCreate(AST_FUNC_CALL_ARGS_EXT, 0, $2, $3, 0, 0); }
    |                                         { $$ = 0; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}