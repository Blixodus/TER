#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"
#include "simulation.h"

class Molecule {
 private:
  /* Molecule type represented by unsigned int to save space and avoid memory leaks */
  const unsigned int type;
  const unsigned int* reacs;
  float x, y, z;
 public:
  Molecule(TypeMolecule, float, float, float);
  Molecule(TypeMolecule);
  //Diametre
  void move(Simulation* s, int d, float &x_arg, float &y_arg, float &z_arg);
  void getPos(float &x, float &y, float &z);
  // Demande à reaction si ok, si oui renvoie id sinon -1. 
  //On utilise Reaction.react pour prendre la décision
  int react(Molecule m);
};

#endif
