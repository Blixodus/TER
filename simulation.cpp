#include "simulation.h"

Simulation::Simulation():typemolecule_list(), reaction_list(), molecule_list(){
}

int Simulation::findTypeID(char* name) {
  for(TypeMolecule t : typemolecule_list) {
    if(!std::strcmp(name, t.name)) return t.type_id;
  }
}

bool Simulation::checkBounds(float x, float y, float z, int t) {
  int r = t.getSize();
  return (x*x + y*y + z*z + r) <= diameter*diameter;
}

void Simulation::reactOne(int r1) {

}

void Simulation::reactTwo(int r1, int r2) {

}

void Simulation::setDiameter(int d) {
  diameter = d;
}

void Simulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  tr1 = findTypeID(r1);
  tr2 = findTypeID(r2);
  tp1 = findTypeID(p1);
  tp2 = findTypeID(p2);
  /* Check if reaction exists with same r1 and r2 */
  /* Otherwise create new reaction */
}

void Simulation::addMolecule(char* name, int amount) {
  t = findTypeID(name);
  x = 0.0;
  y = 0.0;
  z = 0.0;
  Molecule m = new Molecule(&typemolecule_list.at(t), x, y, z);
  molecule_list.push_back(m);
}

void Simulation::addTypeMolecule(char* name) {
  TypeMolecule t = new TypeMolecule(typemolecule_list.size(), name);
  typemolecule_list.push_back(t);
}

void Simulation::setTypeMoleculeSpeed(char* name, float speed) {
  int t = findTypeID(name);
  t.setSpeed(speed);
}

void Simulation::setTypeMoleculeSize(char* name, int size) {
  int t = findTypeID(name);
  t.setSize(size);
}

void Simulation::run(int t = 1) {
  /* TODO */
  /* Calculate molecule intersections */
  /* Compute reactions */
  /* Move all molecules */
}
