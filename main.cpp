#include <iostream>
#include <cstdlib>
#include "entitysimulation.h"
#include "populationsimulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "parser.h"
#include <stdio.h>

EntitySimulation entitySimulation;
PopulationSimulation populationSimulation;
bool solver; // true = entity, false = population
extern FILE* yyin;

void initSim(void) {
  if(yyparse()) {
    std::cout << "Parser error, aborting!" << std::endl;
    std::exit(0);
  }
}

int main(int argc, char** argv) {
  yyin = fopen(argv[1], "r");
  int iter = (argc>2)?atoi(argv[2]):10;
  if(NULL == yyin) std::exit(0);
  initSim();

  if(solver) {
    entitySimulation.run(iter);
  } else {
    populationSimulation.run(iter);
  }
  //Affichage du graphique
  system("gnuplot plot-csv.gnp");
    
  return 0;
}
