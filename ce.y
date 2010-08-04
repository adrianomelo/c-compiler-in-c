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

%token SEPARADOR ATRIBUICAO
%token <string> SOMA SUBTRACAO DIVISAO MULTIPLICACAO
%token <string> TIPO VARIAVEL 
%token <number> NUMERO
%type <tree> expressao termo fator atribuicao statement

%%

program:
    statementList       {root = (ast_t*) new_program();}
;

statementList:
    statement
|   statement SEPARADOR statementList
    { 
        statement_list_t* stmt = new_statement_list ($1);
        add_statement ((program_t*) root, stmt);
    }
;

statement:
    atribuicao
    {
        $$ = $1;
    }
;

atribuicao:
    TIPO VARIAVEL ATRIBUICAO expressao  
    {
        printf("tipo: %s, var: %s, exp:\n", $1, $2);
        identifier_t* id = new_identifier($2);
        $$ = (ast_t*) new_attribution (id, $4);
    }
;

expressao:
    termo
    {
        $$ = $1;
    }
|   expressao SOMA termo 
|   expressao SUBTRACAO termo 
    {
        printf(" exp +/- exp \n"); 
        $$ = (ast_t*) new_expression ($1, (ast_t*) new_operation($2), $3);
    }
;

termo:
    fator
    {
        $$ = $1;
    }
|   termo MULTIPLICACAO fator 
|   fator DIVISAO fator 
    {
        printf("termo/fator *// fator \n"); 
        $$ = (ast_t*) new_expression ($1, (ast_t*) new_operation($2), $3);
    }
;

fator:
    NUMERO
    {
        printf("fator: %d \n", $1); 
        $$ = (ast_t*) new_number($1);
    }
;

%%
/*main(int argc, char* argv[])
{
    while(1)
        yyparse();
}*/
