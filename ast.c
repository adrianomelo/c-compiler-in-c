
/**
 * Autor: Adriano Melo <astm@cin.ufpe.br>
 * Modificado por:
 *
 * ast.c : implementa as funções necessárias para criação da AST.
 **/

#include <stdlib.h>
#include "ast.h"

/**
 * Aloca memória para um program_t e zera os seus atributos
 */
program_t* new_program()
{
    program_t* programa = (program_t*) malloc (sizeof(program_t));

    programa->node_type = type_program;
    programa->head = 0;
    programa->tail = 0;

    return programa;
}

/**
 *  Adiciona um statement a um programa.
 */
void add_statement(program_t* program, statement_list_t* stmt)
{
    if (program->head == 0){
        program->head = stmt;
        program->tail = stmt;
    } else if (stmt != 0) {
        program->tail->next = stmt;
        program->tail = stmt;
    }
}

statement_list_t* new_statement_list(ast_t* stmt)
{
    statement_list_t* stmt_list = (statement_list_t*) malloc (sizeof(statement_list_t));

    stmt_list->node_type = type_statement_list;
    stmt_list->stmt = stmt;
    stmt_list->next = 0;

    return stmt_list;
}

attribution_t* new_attribution(identifier_t* identifier, ast_t* expression)
{
    attribution_t* att = (attribution_t*) malloc (sizeof(attribution_t));

    att->node_type  = type_attribution;
    att->identifier = identifier;
    att->value      = expression;

    return att;
}

expression_t* new_expression(ast_t* left, ast_t* operation, ast_t* right)
{
    expression_t* exp = (expression_t*) malloc (sizeof(expression_t));

    exp->node_type  = type_expression;
    exp->left       = left;
    exp->operation  = operation;
    exp->right      = right;

    return exp;
}

operation_t* new_operation(char* operation)
{
    operation_t* op = (operation_t*) malloc (sizeof(operation_t));

    op->operation = operation;

    return op;
}

identifier_t* new_identifier(char* identifier)
{
    identifier_t* id = (identifier_t*) malloc (sizeof(identifier_t));

    id->node_type  = type_identifier;
    id->identifier = identifier;

    return id;
}

type_t* new_type(char* name)
{
    type_t* tipo = (type_t*) malloc (sizeof(type_t));

    tipo->name = name;

    if (strcmp(name, "int") == 0){
        tipo->node_type = type_int;
    } else if (strcmp(name, "double") == 0){
        tipo->node_type = type_double; 
    } else if (strcmp(name, "char") == 0) {
        tipo->node_type = type_char;
    }

    return tipo;
}

number_t* new_number(double value)
{
    number_t* num = (number_t*) malloc (sizeof(number_t));

    num->node_type = type_number;
    num->value = value;

    return num;
}

