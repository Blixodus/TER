#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"
#include "vec3.h"

class Molecule {
 private:
  Vec3* pos_vect;
  /* Movement vector */
  Vec3* move_vect;
  /* Whether or not the molecule has already reacted or moved */
  bool flag_used;
  /* Whether or not the molecule has already computed a new move */
  bool flag_move;
  /* Compute next move */
  void computeMove();
 public:
  const TypeMolecule type;
  Molecule(TypeMolecule&, float, float, float);
  Molecule(TypeMolecule&, Vec3*);
  /* Destructor */
  ~Molecule();
  /* Get position onto which the molecule would move */
  Vec3* getMove();
  /* Get current position */
  Vec3* getPos();
  /* Move to calculated position or do not move */
  void move();
  void noMove();
  /* Mark used */
  void setUsed();
  /* Mark unused */
  void setUnused();
  /* Get used/unused state */
  bool getState();
  /* Set move to nothing in case of unlawful move */
  void outOfBounds();
};

#endif
