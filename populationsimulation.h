#ifndef POPULATIONSIMULATION_H
#define POPULATIONSIMULATION_H

#include <vector>
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "vec3.h"
#include "abstractsimulation.h"

class PopulationSimulation : public AbstractSimulation {
 private:
  int* molecule_list;
  int length_molecule_list;
  /* Print simulation state */
  void print(void) const;
 public:
  PopulationSimulation();
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addMolecule(char*, int) override;
  /* Run the simulation for t ticks */
  void run(int) override;
};

#endif
