#ifndef POPULATIONSIMULATION_H
#define POPULATIONSIMULATION_H

#include <vector>
#include "abstractsimulation.h"

struct typemolecule {
  int ID;
  char* name;
  float speed;
  int size;
};

struct reaction {
  int ID;
  int r1;
  int r2;
  int p1;
  int p2;
  float prob;
};

class PopulationSimulation : public AbstractSimulation {
 private:
  std::vector<reaction*> reaction_list;
  std::vector<typemolecule*> typemolecule_list;
  int* molecule_list;
  int length_molecule_list;
  /* Print simulation state */
  void print(void) const;
 public:
  PopulationSimulation();
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
