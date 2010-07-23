%option noyywrap
%{
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

"+"         {yylval.caracter = yytext[0]; return SOMA;}
"-"         {yylval.caracter = yytext[0]; return SUBTRACAO;}
"*"         {yylval.caracter = yytext[0]; return MULTIPLICACAO;}
"/"         {yylval.caracter = yytext[0]; return DIVISAO;}

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

