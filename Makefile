LEX = flex
YACC = bison -d
CXX = g++

main: main.cpp simulation.o molecule.o typemolecule.o reaction.o vec3.o
	$(CXX) main.cpp simulation.o molecule.o typemolecule.o reaction.o vec3.o -o main

#lexer.o: lexer.c parser.o
#	$(CXX) -lfl -c lexer.c parser.o

#parser.o: parser.c simulation.o molecule.o typemolecule.o reaction.o
#	$(CXX) -lfl -c parser.c simulation.o molecule.o typemolecule.o reaction.o

#lexer.c: lexer.l
#	$(LEX) -o lexer.c lexer.l

#parser.c: parser.y
#	$(YACC) -o parser.c parser.y

simulation.o: simulation.cpp
	$(CXX) -c simulation.cpp

molecule.o: molecule.cpp
	$(CXX) -c molecule.cpp

typemolecule.o: typemolecule.cpp
	$(CXX) -c typemolecule.cpp

reaction.o: reaction.cpp
	$(CXX) -c reaction.cpp

vec3.o: vec3.cpp
	$(CXX) -c vec3.cpp
