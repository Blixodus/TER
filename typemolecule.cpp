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