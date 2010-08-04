%option noyywrap
%{
#include "ast.h"
#include "ce.tab.h"
%}

NUMERO      [0-9]*
LETRA       [A-Za-z_]
VARIAVEL    [A-z_][0-9A-z_]*

SEPARADOR   [ \t]+

TIPO        (int|char|long|void|short)

ATRIBUICAO  "="

MAIOR       ">"
MENOR       "<"
IGUAL       "=="
MAIOR_IGUAL ">="
MENOR_IGUAL "<="
DIFERENTE   "!="

SOMA            "+"
SUBTRACAO       "-"
DIVISAO         "/"
MULTIPLICACAO   "*"

%%

("\n"|";")  {return SEPARADOR;}

"+"         {yylval.string = strdup(yytext); return SOMA;}
"-"         {yylval.string = strdup(yytext); return SUBTRACAO;}
"*"         {yylval.string = strdup(yytext); return MULTIPLICACAO;}
"/"         {yylval.string = strdup(yytext); return DIVISAO;}

{NUMERO}    {yylval.number = atof(yytext); return NUMERO;}
{TIPO}      {yylval.string = strdup(yytext); return TIPO;}

{VARIAVEL}  {yylval.string = strdup(yytext); return VARIAVEL;}

{ATRIBUICAO} {yylval.caracter = yytext[0]; return ATRIBUICAO;}

%%

/**
main(int argc, char* argv[])
{
    yylex();
}*/

