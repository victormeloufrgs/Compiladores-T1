%{
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

%token TK_IDENTIFIER    

%token LIT_INTEGER      
%token LIT_FLOAT        
%token LIT_TRUE         
%token LIT_FALSE        
%token LIT_CHAR         
%token LIT_STRING

%token TOKEN_ERROR

%%

programa: KW_CHAR TK_IDENTIFIER '=' LIT_CHAR programa
        | KW_INT TK_IDENTIFIER '=' LIT_INTEGER programa
        |
        ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax  error at line %d.\n", getLineNumber());
    exit(3);
}