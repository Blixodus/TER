LEX = flex
YACC = bison -d
CXX = g++

main: main.cpp lexer.o parser.o simulation.o molecule.o typemolecule.o reaction.o
	$(CXX) main.cpp lexer.o parser.o simulation.o molecule.o typemolecule.o reaction.o -o main

lexer.o: lexer.c parser.o
	$(CXX) -lfl -c lexer.c parser.o

parser.o: parser.c simulation.o molecule.o typemolecule.o reaction.o
	$(CXX) -lfl -c parser.c simulation.o molecule.o typemolecule.o reaction.o

lexer.c: lexer.l
	$(LEX) -o lexer.c lexer.l

parser.c: parser.y
	$(YACC) -o parser.c parser.y

simulation.o: simulation.cpp molecule.o typemolecule.o reaction.o
	$(CXX) simulation.cpp molecule.o typemolecule.o reaction.o

molecule.o: molecule.cpp typemolecule.o
	$(CXX) molecule.cpp typemolecule.o

typemolecule.o: typemolecule.cpp
	$(CXX) typemolecule.cpp

reaction.o: reaction.cpp
	$(CXX) reaction.cpp
