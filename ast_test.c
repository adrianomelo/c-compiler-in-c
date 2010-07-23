
/**
 * Autor: Adriano Melo <astm@cin.ufpe.br>
 * Modificado por:
 *
 * test_ast.c : arquivo para fazer testes no ast.h
 **/

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "semantic.h"
#include "code.h"

void visit(ast_t*);

int main(int argc, char* argv[])
{
    printf("Gerando uma AST pequena para teste...h\n");
    
    program_t* programa = new_program();

    int a = 5;
    int b = a + 6;
    double c = 4;

    type_t* inteiro          = new_type("int");
    identifier_t* id         = new_identifier("a");
    number_t* cinco          = new_number(5);
    attribution_t* att       = new_attribution(id, (ast_t*) cinco);
    statement_list_t* stmt_l = new_statement_list((ast_t*) att);

    add_statement(programa, stmt_l);

    type_t* inteiro2        = new_type("int");
    identifier_t* id2       = new_identifier("b");
    identifier_t* id3       = new_identifier("a");
    number_t* seis          = new_number(6);
    operation_t* mais       = new_operation("+");
    expression_t* a_mais_seis = new_expression((ast_t*) id3, (ast_t*) mais, (ast_t*) seis);
    attribution_t* att2     = new_attribution(id2,(ast_t*) a_mais_seis);
    statement_list_t* stmt_l2 = new_statement_list((ast_t*) att2);

    add_statement(programa, stmt_l2);

    type_t* daublo           = new_type("double");
    identifier_t* id4        = new_identifier("c");
    number_t* quatro         = new_number(4);
    attribution_t* att3       = new_attribution(id4, (ast_t*) quatro);
    statement_list_t* stmt_l3 = new_statement_list((ast_t*) att3);

    add_statement(programa, stmt_l3);

    printf("Nenhum erro na criação da ast...");

    //s_visit_program (programa);
    //c_visit_program (programa);
}

