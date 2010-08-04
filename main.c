#include "ast.h"
#include "ce.tab.h"

int main (int argc, char* argv[])
{
    root = (ast_t*) new_program();

    while(1)
        yyparse();

}
