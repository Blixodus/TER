#include <iostream>
#include <cstdlib>
#include "abstractsimulation.h"
#include "entitysimulation.h"
#include "populationsimulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "parser.h"
#include <stdio.h>

EntitySimulation simulation;
extern FILE* yyin;

void initSim(void) {
  if(yyparse()) {
    std::cout << "Parser error, aborting!" << std::endl;
    std::exit(0);
  }
}

int main(int argc, char** argv) {
  yyin = fopen(argv[1], "r");
  if(NULL == yyin) std::exit(0);
  initSim();
  
  /*
  simulation.setDiameter(5);
  char* E = (char*) "E";
  char* s = (char*) "s";
  char* p = (char*) "p";
  simulation.addTypeMolecule(E);
  simulation.addTypeMolecule(s);
  simulation.addTypeMolecule(p);
  simulation.addMolecule(E, 10);
  simulation.addMolecule(s, 30);
  simulation.addReaction(E, s, E, p, 0.3);
  simulation.addReaction(p, (char*) "", s, (char*) "", 0.1);
  simulation.setTypeMoleculeSize(E, 10);
  simulation.setTypeMoleculeSize(s, 4);
  simulation.setTypeMoleculeSize(p, 4);
  */
  
  simulation.run(10);
    
  return 0;
}
