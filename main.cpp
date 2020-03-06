#include <iostream>
#include <cstdlib>
#include "simulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "parser.h"

Simulation simulation;

void initSim(void) {
  if(yyparse()) {
    std::cout << "Parser error, aborting!" << std::endl;
    std::exit(0);
  }
}

int main(int argc, char** argv) {
  initSim();
  simulation.setDiameter(5);
<<<<<<< HEAD
  char* p1 = (char*) "p1";
  simulation.addTypeMolecule(p1);
  simulation.addMolecule(p1, 12);
  simulation.addReaction(p1, p1, p1, p1, 0.02);
  simulation.setTypeMoleculeSpeed(p1, 0.09 );
  simulation.setTypeMoleculeSize(p1, 4);
  simulation.run(1);
=======
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
  simulation.run(10);
>>>>>>> 60765e2baccca290fe0f3040b784a0a15fdc4c67
  
  
  return 0;
}
