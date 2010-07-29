#include "ce.tab.h"
#include "ast.h"

int main (int argc, char* argv[])
{
    root = new_program();

    while(1)
        yyparse();

}
