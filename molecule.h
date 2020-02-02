#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"

class Molecule {
 private:
  float x, y, z;
  /* Whether or not the molecule has already reacted or moved */
  bool flag_used;
 public:
  const TypeMolecule type;
  Molecule(TypeMolecule&, float, float, float);
  /* Get position onto which the molecule would move */
  void getMove(float&, float&, float&);
  /* Get current position */
  void getPos(float&, float&, float&);
  /* Set position */
  void setPos(float, float, float);
  /* Mark used */
  void setUsed();
  /* Mark unused */
  void setUnused();
  /* Get used/unused state */
  bool getState();
};

#endif
