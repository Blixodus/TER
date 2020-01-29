#include "typemolecule.h"
#include <cstring>

TypeMolecule::TypeMolecule(const unsigned int id, const char* n): type_id(id), name(n) {
    speed = 1;
    size = 10; //nm
}

void TypeMolecule::setSpeed(float s) {
    speed = s;
}

void TypeMolecule::setSize(int s) {
    size = s;
}

unsigned int TypeMolecule::getId() const {
  return type_id;
}

char* TypeMolecule::getName() const {
  char* n;
  strcpy(n, name);
  return n;
}

float TypeMolecule::getSpeed() const {
  return speed;
}

int TypeMolecule::getSize() const {
  return size;
	      
}
