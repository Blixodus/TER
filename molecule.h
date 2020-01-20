#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"

class Molecule {
 private:
  /* Molecule type represented by unsigned int to save space and avoid memory leaks */
  const unsigned int type;
  const unsigned int* reacs;
  float x, y, z;
 public:
  Molecule(TypeMolecule t, float x, float y, float z);
  Molecule(TypeMolecule t);
  void move();
  void getPos(float &x, float &y, float &z);
  void react(Molecule m);
};

#endif
