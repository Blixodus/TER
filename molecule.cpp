#include "molecule.h"
#include <cmath>
#include <time.h>
#include <vector>

Molecule::Molecule(TypeMolecule& t, float x, float y, float z) : type(t) {
  type = t;
  flag_used = false;
  this->x = x;
  this->y = y;
  this->z = z;
}

void Molecule::getMove(float& x_arg, float& y_arg, float& z_arg){
  srand(time(NULL));
  float pi = 3.14159f;
  float r = type.getSpeed();
  float theta = pi*(float)rand()/(float)RAND_MAX;
  float phi =  2*pi*(float)rand()/(float)RAND_MAX;
  
  float new_x = x + r*cos(phi)*cos(theta);
  float new_y = y + r*cos(phi)*sin(theta);
  float new_z = z + r*sin(phi); 

  x_arg = x_new;
  y_arg = y_new;
  z_arg = z_new;
}

void Molecule::getPos(float &x, float &y, float &z){
  x = this->x;
  y = this->y;
  z = this->z;
}

void Molecule::setPos(float x, float y, float z){
  this->x = x;
  this->y = y;
  this->z = z;
}

void Molecule::setUsed() {
  this->flag_used = true;
}

void Molecule::setUnused() {
  this->flag_used = false;
}

bool Molecule::getState() {
  return this->flag_used;
}
