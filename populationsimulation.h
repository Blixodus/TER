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

class PopulationSimulation {
 private:
  int diameter;
  std::vector<reaction*> reaction_list;
  std::vector<typemolecule*> typemolecule_list;
  int* molecule_list;
  int length_molecule_list;
  /* Find id */
  int findTypeID(char*) const;
  /* Print simulation state */
  void print(void) const;
  /* Print reactions in simulation */
  void printReactions(void) const;
 public:
  PopulationSimulation();
  /* Set simulation diameter (used by parser) */
  void setDiameter(int);
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addReaction(char*, char*, char*, char*, float);
  void addMolecule(char*, int);
  void addTypeMolecule(char*);
  /* Set molecule type parameters (used by parser) */
  void setTypeMoleculeSpeed(char*, float);
  void setTypeMoleculeSize(char*, int);
  /* Run the simulation for t ticks */
  void run(int);
};

#endif
