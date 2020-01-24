#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"

class Simulation {
 private:
  int diameter;
  vector<TypeMolecule> typemolecule_list;
  vector<Reaction> reaction_list;
  vector<vector<Molecule>> molecule_list;
 public:
  Simulation();
  void setDiameter(int);
  void addReaction(Reaction);
  void addMolecule(Molecule);
  void addTypeMolecule(TypeMolecule);
  /* Run the simulation for t ticks, default 1 tick */
  void run(int t = 1);
};

#endif
