
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbols.h"

symbol_t simbolos[500];
int next = 0;

int add_symbol (char* identifier, int node_type)
{
    if (identifier == 0)
        return 0;

    if (has_symbol(identifier))
        return 0;

    symbol_t* sym = new_symbol(identifier, node_type);
    
    if (next < 500){
        simbolos[next] = *sym;
        next = next + 1;
        return 1;
    }

    return 0;
}

int has_symbol (char* identifier)
{
    if (identifier == 0)
        return 0;

    int i;
    for(i=0; i<next; i++) {
        if (strcmp(simbolos[i].identifier, identifier) == 0) {
            return 1;
            printf("[has_symbol] var ja usada\n");
        }
    }

    return 0;
}

int is_type (char* identifier, int node_type)
{
    if (identifier == 0)
        return 0;

    int i;
    for(i=0; i<next; i++) {
        if (strcmp(simbolos[i].identifier, identifier) == 0) {
            int real_type = simbolos[i].node_type;
            if (real_type == node_type) {
                return 1;
            } else {
                return 0;
            }

        }
    }

    return 0;
}

symbol_t* new_symbol(char* identifier, int node_type)
{
    symbol_t* sym = (symbol_t*) malloc (sizeof(symbol_t));

    sym->identifier = (char*) malloc (sizeof(char) * 200);

    strcpy(sym->identifier, identifier);
    sym->node_type = node_type;

    return sym;
}
