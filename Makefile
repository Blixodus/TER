LEX = flex
YACC = bison -d
CXX = g++

main: main.cpp lexer.o parser.o
	$(CXX) main.cpp lexer.o parser.o -o main

lexer.o: lexer.c parser.o
	$(CXX) -lfl -c lexer.c parser.o

parser.o: parser.c
	$(CXX) -lfl -c parser.c

lexer.c: lexer.l
	$(LEX) -o lexer.c lexer.l

parser.c: parser.y
	$(YACC) -o parser.c parser.y
