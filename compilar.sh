#!/bin/sh

#gcc ast_test.c ast.c code.c semantic.c -o exec_test

bison -d ce.y; flex ce.lex; gcc ast.c main.c ce.tab.c lex.yy.c -o exec
