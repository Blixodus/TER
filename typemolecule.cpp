#include "typemolecule.h"

TypeMolecule::TypeMolecule(const unsigned int id, const char* n): type_id(id), name(n){
    speed = 1;
    size = 10; //nm
}

void TypeMolecule::setSpeed(float speed){
    this -> speed = speed;
}

void TypeMolecule::setSize(int size){
    this -> size = size;
}

unsigned int TypeMolecule::get_id() {
  return type_id;
}

char* get_name() {
  char* n;
  strcpy(n, name);
  return n;
}

float get_speed() {
  return speed;
}

int get_size() {
  return size;
}
