
GCC = gcc
FLEX = flex
BISON = bison
    
all: bisonflex
	$(GCC) ast.c main.c ce.tab.c lex.yy.c semantic.c -o bin/exec_main

bisonflex: ce.y ce.lex
	$(BISON) -d ce.y
	$(FLEX) --header-file=ce.lex.h  ce.lex

clean:
	rm ce.*.* lex.yy.c
