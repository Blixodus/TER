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

unsigned int TypeMolecule::get_id() const {
  return type_id;
}

char* TypeMolecule::get_name() const {
  char* n;
  strcpy(n, name);
  return n;
}

float TypeMolecule::get_speed() const {
  return speed;
}

int TypeMolecule::get_size() const {
  return size;
	      
}
