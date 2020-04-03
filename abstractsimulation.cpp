#include <iostream>
#include <cstring>
#include "abstractsimulation.h"

AbstractSimulation::AbstractSimulation() : typemolecule_list(), reaction_list() {
}

int AbstractSimulation::findTypeID(char* name) const {
  if(name != NULL){
    for(TypeMolecule* t : typemolecule_list) {
      if(!strcmp(name, t->name)) return t->type_id;
    }
  }
  return -1;
}

void AbstractSimulation::setDiameter(int d) {
  diameter = d;
}

void AbstractSimulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  int tr1 = findTypeID(r1);
  int tr2 = findTypeID(r2);
  int tp1 = findTypeID(p1);
  int tp2 = findTypeID(p2);
  if(tr1 == -1 && tr2 == -1 || tp1 == -1 && tp2 == -1) {
    std::cerr << "Undefined reaction types" << std::endl;
    exit(0);
  }
  /* Check if reaction exists with same r1 and r2 */
  for(Reaction* r : reaction_list) {
    if(r->r1 == tr1 && r->r2 == tr2) {
      r->add(tp1, tp2, p);
      return;
    }
  }
  /* Otherwise create new reaction */
  Reaction* r = new Reaction(tr1, tr2, reaction_list.size());
  r->add(tp1, tp2, p);
  reaction_list.push_back(r);
}

void AbstractSimulation::addTypeMolecule(char* name) {
  TypeMolecule* t = new TypeMolecule(typemolecule_list.size(), name);
  typemolecule_list.push_back(t);
  for(TypeMolecule* type : typemolecule_list) {
    std::cout << type << " " << type->name << std::endl;
  }
  std::cout << std::endl;
}

void AbstractSimulation::setTypeMoleculeSpeed(char* name, float speed) {
  int t = findTypeID(name);
  if(t!=-1) typemolecule_list.at(t)->setSpeed(speed);
  else {
    std::cerr << "Undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void AbstractSimulation::setTypeMoleculeSize(char* name, int size) {
  int t = findTypeID(name);
  if(t!=-1) typemolecule_list.at(t)->setSize(size);
  else {
    std::cerr << "Undefined molecule type " << name << std::endl;
    exit(0);
  }
}
