all:	clean y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -ly -lfl -o demo

y.tab.c:
	bison -y -d B092040016.y

lex.yy.c:
	flex B092040016.l

clean:
	rm -f demo lex.yy.c y.tab.c y.tab.h
