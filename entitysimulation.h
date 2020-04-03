#ifndef ENTITYSIMULATION_H
#define ENTITYSIMULATION_H
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "vec3.h"
#include "abstractsimulation.h"
#include <vector>

class EntitySimulation : public AbstractSimulation {
 private:
  std::vector<Molecule*> molecule_list;
  /* Check that a point is within boundaries */
  bool checkBounds(Vec3*, int) const;
  /* Try to react one molecule */
  bool reactOne(int);
  /* Try to react two molecules */
  bool reactTwo(int, int);
  /* Calculates the molecule in trajectory if any, parameter position in list, return position in list or -1 if none */
  int computeTrajectory(int) ; //retirer le const -> retire bug sinon pas compatible avec la fonction
  /* Print simulation state */
  void print(void) const;
  /* Print reactions in simulation */
  void printReactions(void) const;
 public:
  EntitySimulation();
  /* Add molecule to simulation (used by parser) */
  void addMolecule(char*, int) override;
  /* Run the simulation for t ticks */
  void run(int) override;
};

#endif
