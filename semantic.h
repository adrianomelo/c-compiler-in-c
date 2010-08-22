/**
 * Autor: Adriano Melo <astm@cin.ufpe.br>
 * Modificado por:
 *
 * semantic.h : descreve as funções que precisam ser implementadas
 * para fazer a análise semântica.
 *
 * Utiliza uma idéia parecida com o padrão de projeto "Visitor"
 *
 * As funções comecam com "s_" para indicar que fazem parte da análise
 * semantica do compilador.
 **/

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

void* s_visit_program (program_t* programa, ... );

void* s_visit_statement_list (statement_list_t* stmt, ... );

void* s_visit_attribution (attribution_t* att, ... );

void* s_visit_expression (expression_t* exp, ... );

void* s_visit_operation (operation_t* op, ... );

void* s_visit_identifier (identifier_t* id, ... );

void* s_visit_type (type_t* tipo, ... );

void* s_visit_number (number_t* num, ... );

#endif
