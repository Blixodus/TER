#include "simulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include <vector>


Simulation::Simulation():typemolecule_list(), reaction_list(), molecule_list(){
}

void Simulation::setDiameter(int d) {
  diameter = d;
}

void Simulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  /* TODO */
}

void Simulation::addMolecule(char* name, int amount) {
  /* TODO */
}

void Simulation::addTypeMolecule(char* name) {
  TypeMolecule t = new TypeMolecule(typemolecule_list.size(), name);
  typemolecule_list.push_back(t);
}

void Simulation::setTypeMoleculeSpeed(char* name, float speed) {
  for(int i = 0; i < typemolecule_list.size(); i++) {
    TypeMolecule t = typemolecule_list.at(i);
    if(strcmp(t.getName(), name) == 0) {
      t.setSpeed(speed);
      break;
    }
  }
}

void Simulation::setTypeMoleculeSize(char* name, int size) {
  
}

TypeMolecule& Simulation::getType(unsigned int id) {
  return typemolecule_list.at(id);
}

Reaction& Simulation::getReaction(unsigned int id) {
  return reaction_list.at(id);
}

void Simulation::run(int t = 1) {
  /* TODO */
  /* Calculate molecule intersections */
  /* Compute reactions */
  /* Move all molecules */
}
