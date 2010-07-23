%{
#include <stdio.h>

#define YYERROR_VERBOSE

void yyerror(const char *msg){printf("ERROR(PARSER): %s\n", msg);}

%}

%union {
    int     number;
    char    caracter;
    char*   string;
}

%start statementList

%token SEPARADOR ATRIBUICAO
%token <caracter> SOMA SUBTRACAO DIVISAO MULTIPLICACAO
%token <string> TIPO VARIAVEL 
%token <number> NUMERO
%type  <number> expressao termo fator

%%

statementList:
    statement
|   statement SEPARADOR statementList
;

statement:
|   atribuicao  
;

atribuicao:
    TIPO VARIAVEL ATRIBUICAO expressao  {printf("tipo: %s, var: %s, exp: %d", $1, $2, $4);}
;

expressao:
    termo
|   expressao SOMA termo 
        {printf("expr: %d + %d = %d\n", $1, $3, $1 + $3); $$ = $1 + $3;}
|   expressao SUBTRACAO termo 
        {printf("expr: %d - %d = %d\n", $1, $3, $1 - $3); $$ = $1 - $3;}
;

termo:
    fator
|   termo MULTIPLICACAO fator 
        {printf("term: %d * %d = %d\n", $1, $3, $1 * $3); $$ = $1 * $3;}
|   fator DIVISAO fator 
        {printf("term: %d / %d = %d\n", $1, $3, $1 / $3); $$ = $1 / $3;}
;

fator:
    NUMERO          {printf("fator: %d \n", $1); $$ = $1;}
;

%%
main(int argc, char* argv[])
{
    while(1)
        yyparse();
}
