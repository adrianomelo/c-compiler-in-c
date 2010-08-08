%{
#include <stdio.h>
#include "ast.h"

#define YYERROR_VERBOSE
void yyerror(const char *msg){printf("ERROR(PARSER): %s\n", msg);}
%}

%union {
    int     number;
    char    caracter;
    char*   string;
    ast_t*  tree;
}

%start program

%token SEPARADOR ATRIBUICAO L_PAREN R_PAREN L_COLCH R_COLCH
%token <string> SOMA SUBTRACAO DIVISAO MULTIPLICACAO
%token <string> TIPO VARIAVEL 
%token <number> NUMERO
%type <tree> expressao termo fator attribution statement

%%

program:
    function
;

function:
    TIPO VARIAVEL L_PAREN R_PAREN L_COLCH statementList R_COLCH
;

statementList:
    statementList statement
    {
        printf("[ce.y] statementList\n");
        statement_list_t* stmt = new_statement_list ($2);
        add_statement ((program_t*) root, stmt);
    }
|   statement
    { 
        printf("[ce.y] statement\n");
        statement_list_t* stmt = new_statement_list ($1);
        add_statement ((program_t*) root, stmt);
    }
;

statement:
    attribution SEPARADOR
    {
        printf("[ce.y] statement attribution\n");
        $$ = $1;
    }
;

attribution:
    TIPO VARIAVEL ATRIBUICAO expressao  
    {
        printf("[ce.y] attribution. tipo: %s, var: %s\n", $1, $2);
        identifier_t* id = new_identifier($2);
        $$ = (ast_t*) new_attribution (id, $4);
    }
;

expressao:
    termo
    {
        printf("[ce.y] termo\n");
        $$ = $1;
    }
|   expressao SOMA termo 
|   expressao SUBTRACAO termo 
    {
        printf("[ce.y] expressao som termo \n"); 
        $$ = (ast_t*) new_expression ($1, (ast_t*) new_operation($2), $3);
    }
;

termo:
    fator
    {
        printf("[ce.y] fator\n"); 
        $$ = $1;
    }
|   termo MULTIPLICACAO fator 
|   fator DIVISAO fator 
    {
        printf("[ce.y] fator div fator \n"); 
        $$ = (ast_t*) new_expression ($1, (ast_t*) new_operation($2), $3);
    }
;

fator:
    NUMERO
    {
        printf("[ce.y] number: %d \n", $1); 
        $$ = (ast_t*) new_number($1);
    }
|   VARIAVEL
    {
        printf("[ce.y] identifier: %s \n", $1);
        $$ = (ast_t*) new_identifier($1);
    }
;

%%
/*main(int argc, char* argv[])
{
    while(1)
        yyparse();
}*/
