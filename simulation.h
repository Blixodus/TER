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
  void addReaction(char* r1, char* r2, char* p1, char* p2, float p);
  void addMolecule(char* name, int amount);
  void addTypeMolecule(char* name);
  /* Run the simulation for t ticks, default 1 tick */
  void run(int t = 1);
};

#endif
