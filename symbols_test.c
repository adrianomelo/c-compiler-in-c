
#include <stdio.h>
#include "symbols.h"
#include "ast.h"

int main (int argc, char* argv[]) {

    int a = add_symbol("a", type_int);    
    printf("1 = %d\n", a);
    
    printf("1 = %d\n", add_symbol("b", type_double));

    printf("1 = %d\n", add_symbol("c", type_char));

    printf("0 = %d\n", add_symbol("a", type_char));     // ERRO: já declarada
    
    printf("0 = %d\n", add_symbol("b", type_double));   // ERRO: Já declarada

    printf("1 = %d\n", is_type("a", type_int));
}

