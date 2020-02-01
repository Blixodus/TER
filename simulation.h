#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"

class Simulation {
 private:
  int diameter;
  std::vector<TypeMolecule> typemolecule_list;
  std::vector<Reaction> reaction_list;
  std::vector<Molecule> molecule_list;
 public:
  Simulation();
  /* Set simulation diameter (used by parser) */
  void setDiameter(int);
  /* Add reaction/molecule/type of molecule to simulation (used by parser) */
  void addReaction(char* r1, char* r2, char* p1, char* p2, float p);
  void addMolecule(char* name, int amount);
  void addTypeMolecule(char* name);
  /* Set molecule type parameters (used by parser) */
  void setTypeMoleculeSpeed(char* name, float speed);
  void setTypeMoleculeSize(char* name, int size);
  /* Check that a point is within boundaries */
  bool checkBounds(float, float, float) const;
  /* Try all reactions for one molecule in molecule_list, parameter position in list, return reaction id or -1 if unsuccessful */
  int reactOne(int) const;
  /* Try all reactions between two molecules in molecule_list, parameters positions in list, return reaction id or -1 if unsuccessful */
  int reactTwo(int, int) const;
  /* Calculates the molecule in trajectory if any, parameter position in list, return position in list or -1 if none */
  int computeTrajectory(int) const;
  /* Run the simulation for t ticks, default 1 tick */
  void run(int t = 1);
};

#endif
