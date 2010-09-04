
#include <stdio.h>
#include "semantic.h"

void* s_visit_program(program_t* programa, ... )
{
    printf("[semantic] Visitando programa (%d)...\n", programa->node_type);

    statement_list_t* stmt = programa->head;
    while (stmt != 0) {
        s_visit_statement_list (stmt);
        stmt = stmt->next;
    }
}

void* s_visit_statement_list (statement_list_t* stmt, ... )
{
    printf("[semantic]  Visitando statement list...\n");
    
    if (stmt->stmt != 0 && stmt->stmt->node_type == type_attribution) {
        s_visit_attribution ((attribution_t*) stmt->stmt);
    }
}

void* switch_expression(ast_t* exp)
{
    if (exp != 0) {
        switch (exp->node_type){
            case type_expression:
                return s_visit_expression((expression_t*) exp);
                break;                                                          
            case type_number:
                return s_visit_number((number_t*) exp);          
                break;
            case type_identifier:
                return s_visit_identifier((identifier_t*) exp);
            default:
                printf("[semantic] ERRO AO IDENTIFICAR EXP DA ATRIBUICAO\n");   
        } 
    }
}

void* s_visit_attribution (attribution_t* att, ... )
{
    printf("[semantic]   Visitando atribuicao\n");

    s_visit_identifier (att->identifier);

    switch_expression (att->value);
}

void* s_visit_identifier (identifier_t* id, ... )
{
    printf("[semantic]    Visitando identifier %s\n", id->identifier);
}

void* s_visit_expression (expression_t* exp, ... )
{
    operation_t* op = (operation_t*) exp->operation;
    printf("[semantic]    Visitando expression %s\n", op->operation);

    switch_expression (exp->right); 
    switch_expression (exp->left);
}

void* s_visit_number (number_t* num, ... )
{
    printf("[semantic]    Visitando number %f\n", num->value);
}




