#ifndef ABSTRACTSIMULATION_H
#define ABSTRACTSIMULATION_H

#include "typemolecule.h"
#include "reaction.h"

class AbstractSimulation {
 protected:
  std::vector<TypeMolecule*> typemolecule_list;
  std::vector<Reaction*> reaction_list;
  int diameter;
 public:
  AbstractSimulation();
  /* Find id */
  int findTypeID(char*) const;
  /* Set simulation diameter (used by parser) */
  void setDiameter(int);
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addReaction(char*, char*, char*, char*, float);
  virtual void addMolecule(char*, int) = 0;
  void addTypeMolecule(char*);
  /* Set molecule type parameters (used by parser) */
  void setTypeMoleculeSpeed(char*, float);
  void setTypeMoleculeSize(char*, int);
  /* Run the simulation for t ticks */
  virtual void run(int) = 0;
};

#endif
