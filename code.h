
/**
 * Autor: Adriano Melo <astm@cin.ufpe.br>
 * Modificado por:
 *
 * code.h : descreve as funções que precisam ser implementadas
 * para fazer a geração de código.
 *
 * Utiliza uma idéia parecida com o padrão de projeto "Visitor"
 *
 * As funções comecam com "c_" para indicar que fazem parte da 
 * geração de código do compilador
 **/

#ifndef CODE_H
#define CODE_H

#include "ast.h"

void* c_visit_program (program_t* programa, ... );

void* c_visit_statement_list (statement_list_t* stmt, ... );

void* c_visit_attribution (attribution_t* att, ... );

void* c_visit_expression (expression_t* exp, ... );

void* c_visit_operation (operation_t* op, ... );

void* c_visit_identifier (identifier_t* id, ... );

void* c_visit_type (type_t* tipo, ... );

void* c_visit_number (number_t* num, ... );

#endif
