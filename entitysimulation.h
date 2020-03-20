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
  std::vector<TypeMolecule*> typemolecule_list;
  std::vector<Reaction*> reaction_list;
  std::vector<Molecule*> molecule_list;
  /* Find id */
  int findTypeID(char*) const;
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
