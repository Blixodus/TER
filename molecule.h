#ifndef MOLECULE_H
#define MOLECULE_H
#include "typemolecule.h"
#include "reaction.h"

class Molecule {
 private:
  const TypeMolecule type;
  vector<Reaction> reacs;
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
