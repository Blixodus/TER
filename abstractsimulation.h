#ifndef ABSTRACTSIMULATION_H
#define ABSTRACTSIMULATION_H

#include "typemolecule.h"
#include "reaction.h"

class AbstractSimulation {
 protected:
  int diameter;
 public:
  AbstractSimulation();
  /* Set simulation diameter (used by parser) */
  void setDiameter(int);
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  virtual void addReaction(char*, char*, char*, char*, float) = 0;
  virtual void addMolecule(char*, int) = 0;
  virtual void addTypeMolecule(char*) = 0;
  /* Set molecule type parameters (used by parser) */
  virtual void setTypeMoleculeSpeed(char*, float) = 0;
  virtual void setTypeMoleculeSize(char*, int) = 0;
  /* Run the simulation for t ticks */
  virtual void run(int) = 0;
};

#endif
