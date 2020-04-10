#include <cfloat>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "populationsimulation.h"

PopulationSimulation::PopulationSimulation() : AbstractSimulation() {
  molecule_list = NULL;
}

void PopulationSimulation::print(void) const {
  for(int i = 0; i < length_molecule_list; i++) {
    std::cout << "-- " << molecule_list[i] << " molecules of type " typemolecule_list.at(i)->name << std::endl;
  }
}

void PopulationSimulation::addMolecule(char* name, int amount) override {
  /* If molecule_list is empty, give it the same size as typemolecule_list */
  if(NULL == molecule_list) {
    length_molecule_list = typemolecule_list.size();
    molecule_list = new int[length_molecule_list];
  }

  /* Add a certain amount of this molecule type */
  int typeID = findTypeID(name);
  if(typeID != -1) {
    molecule_list[typeID] = amount;
  } else {
    std::cout << "ERROR: Adding molecule of undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void PopulationSimulation::run(int t_max) override {
  /* Each iteration is tau = 100µs */
  double alpha = 7.4e-7;
  for(int t = 0; t < t_max; t++) {
    std::cout << "ITERATION " << t << std::endl
    /* Shuffle reaction_list */
    std::random_shuffle(reaction_list.begin(), reaction_list.end());
    printReactions();
    for(Reaction* r : reaction_list) {
      int r1 = r->r1;
      int r2 = r->r2;
      float p = r->p
      if(r1 != -1 && r2 != -1) {
	/* Calculate propensity */
	double prop = (alpha * (molecule_list[r1] + molecule_list[r2]) * )
	/* Do reactions */

      } else {
	/* Calculate propensity */

        /* Do reactions */
	
      }
    }
    std::cout << std::endl << std::endl;
  }
}
