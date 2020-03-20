LEX = flex
YACC = bison -d
CXX = g++

main: main.cpp abstractsimulation.o populationsimulation.o entitysimulation.o molecule.o typemolecule.o reaction.o vec3.o
	$(CXX) main.cpp abstractsimulation.o populationsimulation.o entitysimulation.o molecule.o typemolecule.o reaction.o vec3.o -o main

#lexer.o: lexer.c
#	$(CXX) -lfl -c lexer.c 
#
#parser.o: parser.c
#	$(CXX) -lfl -c parser.c
#
#lexer.c: lexer.l
#	$(LEX) -o lexer.c lexer.l
#
#parser.c: parser.y
#	$(YACC) -o parser.c parser.y

populationsimulation.o: populationsimulation.cpp
	$(CXX) -c populationsimulation.cpp

entitysimulation.o: entitysimulation.cpp
	$(CXX) -c entitysimulation.cpp

abstractsimulation.o: abstractsimulation.cpp
	$(CXX) -c abstractsimulation.cpp

molecule.o: molecule.cpp
	$(CXX) -c molecule.cpp

typemolecule.o: typemolecule.cpp
	$(CXX) -c typemolecule.cpp

reaction.o: reaction.cpp
	$(CXX) -c reaction.cpp

vec3.o: vec3.cpp
	$(CXX) -c vec3.cpp
