# Aluno:      Victor dos Santos Melo
# Matrícula:  00285640

etapa5: main.o y.tab.o lex.yy.o symbols.o hash.o ast.o semantic.o tacs.o val_converters.o assembler.o
	gcc main.o y.tab.o lex.yy.o symbols.o hash.o ast.o semantic.o tacs.o val_converters.o assembler.o -o etapa7

symbols.o: symbols.c
	gcc -c symbols.c

main.o: main.c
	gcc -c main.c

semantic.o: semantic.c
	gcc -c semantic.c

hash.o: hash.c
	gcc -c hash.c

tacs.o: tacs.c
	gcc -c tacs.c

val_converters.o: val_converters.c
	gcc -c val_converters.c

assembler.o: assembler.c
	gcc -c assembler.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c y.tab.h *.o etapa7