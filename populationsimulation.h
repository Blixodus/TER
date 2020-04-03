#ifndef POPULATIONSIMULATION_H
#define POPULATIONSIMULATION_H
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "vec3.h"
#include "abstractsimulation.h"
#include <vector>

class PopulationSimulation : public AbstractSimulation {
 private:
  /* Print simulation state */
  void print(void) const;
  /* Print reactions in simulation */
  void printReactions(void) const;
 public:
  PopulationSimulation();
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addMolecule(char*, int) override;
  /* Run the simulation for t ticks */
  void run(int) override;
};

#endif
