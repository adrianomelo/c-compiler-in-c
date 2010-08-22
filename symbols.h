#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "ast.h"

typedef struct symbol symbol_t;

struct symbol {
  char* identifier;
  int node_type;
};

symbol_t* new_symbol (char* identifier, int node_type);

int add_symbol(char* identifier, int node_type);

int has_symbol(char* identifier);

int is_type(char* identifier, int node_type);

#endif
