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
  this->x_new = x;
  this->y_new = y;
  this->z_new = z;
}

void Molecule::getMove(float& x_arg, float& y_arg, float& z_arg){
  if(flag_move) {
    x_arg = x_new;
    y_arg = y_new;
    z_arg = z_new;
    return;
  }
  
  srand(time(NULL));
  float pi = 3.14159f;
  float r = type.getSpeed();
  float theta = pi*(float)rand()/(float)RAND_MAX;
  float phi =  2*pi*(float)rand()/(float)RAND_MAX;
  
  x_new = x + r*cos(phi)*cos(theta);
  y_new = y + r*cos(phi)*sin(theta);
  z_new = z + r*sin(phi); 

  x_arg = x_new;
  y_arg = y_new;
  z_arg = z_new;

  flag_move = true
}

void Molecule::getPos(float &x, float &y, float &z){
  x = this->x;
  y = this->y;
  z = this->z;
}

void Molecule::move(){
  float a, b, c;
  getMove(a, b, c);
  this->x = this->x_new;
  this->y = this->y_new;
  this->z = this->z_new;
  flag_move = false;
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
