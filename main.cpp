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

/**
 * 
 * @brief Lance le parsing de notre fichier comportant les paramètres de notre simulation.
 */
void initSim(void) {
  if(yyparse()) {
    std::cout << "Parser error, aborting!" << std::endl;
    std::exit(0);
  }
}

/**
 * @brief Lance la simulation.
 * 
 * @param argc le nombre d'arguments transmis par l'utilisateur en ligne de commande
 * @param argv Un tableau de pointeurs de caractères répertoriant tous les arguments.
 * @return int 
 */
int main(int argc, char** argv) {
  //Ouvre le fichier en prenant le premier argument qui est passé en ligne de commande par l'utilisateur.
  yyin = fopen(argv[1], "r");
  //On récupère le nombre d'itérations que l'on souhaite appliquer à notre modèle
  int iter = (argc>2)?atoi(argv[2]):10;

  if(NULL == yyin) std::exit(0);
  initSim();

  //on lance soit la simulation avec la méthode population centré, soit avec entité centré.
  if(solver) {
    entitySimulation.run(iter);
  } else {
    populationSimulation.run(iter);
  }

  //Affichage du graphique
  system("gnuplot plot-csv.gnp");
    
  return 0;
}
