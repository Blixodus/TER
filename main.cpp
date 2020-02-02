#include <iostream>
#include "simulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "parser.h"

Simulation simulation;

void initSim(void) {
  if(yyparse()) {
    std::cout << "Parser error, aborting!" << std::endl;
    exit(0);
  }
}

int main(int argc, char** argv) {
  simulation = new Simulation();
  initSim();
  return 0;
}
