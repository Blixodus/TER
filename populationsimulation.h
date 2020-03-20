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
  std::vector<TypeMolecule*> typemolecule_list;
  std::vector<Reaction*> reaction_list;
  /* Find id */
  int findTypeID(char*) const;
  /* Print simulation state */
  void print(void) const;
  /* Print reactions in simulation */
  void printReactions(void) const;
 public:
  PopulationSimulation();
  /* Set simulation diameter (used by parser) */
  void setDiameter(int) override;
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addReaction(char*, char*, char*, char*, float) override;
  void addMolecule(char*, int) override;
  void addTypeMolecule(char*) override;
  /* Set molecule type parameters (used by parser) */
  void setTypeMoleculeSpeed(char*, float) override;
  void setTypeMoleculeSize(char*, int) override;
  /* Run the simulation for t ticks */
  void run(int) override;
};

#endif
