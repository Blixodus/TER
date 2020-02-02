#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"

class Molecule {
 private:
  float x, y, z;
  float x_new, y_new, z_new;
  /* Whether or not the molecule has already reacted or moved */
  bool flag_used;
  /* Whether or not the molecule has already computed a new move */
  bool flag_move;
 public:
  const TypeMolecule type;
  Molecule(TypeMolecule&, float, float, float);
  /* Get position onto which the molecule would move */
  void getMove(float&, float&, float&);
  /* Get current position */
  void getPos(float&, float&, float&);
  /* Move to calculated position */
  void move();
  /* Mark used */
  void setUsed();
  /* Mark unused */
  void setUnused();
  /* Get used/unused state */
  bool getState();
};

#endif
