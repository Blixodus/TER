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
  char* p1 = (char*) "p1";
  simulation.addTypeMolecule(p1);
  simulation.addMolecule(p1, 12);
  simulation.addReaction(p1, p1, p1, p1, 0.02);
  simulation.setTypeMoleculeSpeed(p1, 0.09 );
  simulation.setTypeMoleculeSize(p1, 4);
  simulation.run(1);
  
  
  return 0;
}
