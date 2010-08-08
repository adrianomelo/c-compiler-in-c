#include "ast.h"
#include "ce.lex.h"
#include "ce.tab.h"
#include "semantic.h"

extern FILE* yyin;

int main (int argc, char* argv[])
{
    root = (ast_t*) new_program();

    if(argc > 1 && !strcmp(argv[1], "-d")) {
        //yydebug = 1; 
        argc--; 
        argv++;
    }

    if(argc > 1 && (yyin = fopen(argv[1], "r")) == NULL) { 
        perror(argv[1]);
        exit(1);
    }
    
    if(!yyparse()){
        printf("Analise sintatica OK!\n");
    } else {
        printf("ERRO na analise sintatica!\n");
    }

    s_visit_program ((program_t*) root);

}
