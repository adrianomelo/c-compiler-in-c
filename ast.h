/**
 * Autor: Adriano Melo <astm@cin.ufpe.br>
 * Modificado por:
 *
 * ast.h : escreve estruturas usadas para construir a AST.
 **/

#ifndef AST_H
#define AST_H

// enum with the number identfifies for the ast nodes
enum {type_program, type_statement_list, type_attribution, type_identifier, type_expression, type_number, type_operation, type_int, type_double, type_char};

typedef struct program          program_t;
typedef struct statement_list   statement_list_t;
typedef struct attribution      attribution_t;
typedef struct identifier       identifier_t;
typedef struct type             type_t;
typedef struct expression       expression_t;
typedef struct number           number_t;
typedef struct operation        operation_t;

typedef struct ast_node         ast_t;

program_t* root;

struct ast_node {
    int node_type;
};

struct program {
    int node_type;
    statement_list_t* head;
    statement_list_t* tail;
};
program_t* new_program();
void add_statement(program_t* program, statement_list_t* stmt);

struct statement_list {
    int node_type;
    ast_t* stmt;
    statement_list_t* next;
};
statement_list_t* new_statement_list(ast_t* stmt);

struct attribution {
    int node_type;
    identifier_t* identifier;
    ast_t* value; // expression, number
};
attribution_t* new_attribution(identifier_t* identifier, ast_t* expression);

struct expression {
    int node_type;
    ast_t* left;
    ast_t* operation;
    ast_t* right;
};
expression_t* new_expression(ast_t* left, ast_t* operation, ast_t* right);

struct operation {
    int node_type;
    char* operation;
};
operation_t* new_operation(char* operation);

struct identifier {
    int node_type;
    char* identifier;
};
identifier_t* new_identifier(char* identifier);

struct type {
    int node_type;
    char* name;
};
type_t* new_type(char* name);

struct number {
    int node_type;
    double value;
};
number_t* new_number(double value);

#endif

