
#include <stdio.h>
#include "code.h"

void* c_visit_program(program_t* programa, ... ){

    printf("[code] Visitando programa...\n");

    statement_list_t* stmt = programa->head;

    while (stmt != 0) {
        //c_visit_statement_list (stmt);
        stmt = stmt->next;
    }
}

