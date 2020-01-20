#ifndef SIMULATION_H
#define SIMULATION_H
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"

class Simulation {
 private:
  const int diameter;
  TypeMolecule* types;
  Reaction* reacs;
  Molecule** moles;
 public:
  Simulation(int d);
  void addReaction(Reaction r);
  void addMolecule(Molecule m);
  void addTypeMolecule(TypeMolecule t);
  /* Run the simulation for t ticks, default 1 tick */
  void run(int t = 1);
  
};

#endif
