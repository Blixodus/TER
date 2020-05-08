#include "molecule.h"
#include <cmath>
#include <time.h>
#include <vector>
#include <iostream>

Molecule::Molecule(TypeMolecule& t, float x, float y, float z) : type(t) {
  flag_used = false;
  flag_move = false;
  pos_vect = new Vec3(x, y, z);
  move_vect = new Vec3(0.0, 0.0, 0.0);
}

Molecule::Molecule(TypeMolecule& t, Vec3* v) : type(t) {
  flag_used = false;
  flag_move = false;
  pos_vect = new Vec3(v);
  move_vect = new Vec3(0.0, 0.0, 0.0);
}

Molecule::~Molecule() {
  delete pos_vect;
  delete move_vect;
}

void Molecule::computeMove() {
  float pi = 3.14159f;
  float r = type.getSpeed();
  float theta = pi*(float)rand()/(float)RAND_MAX;
  float phi =  2*pi*(float)rand()/(float)RAND_MAX;

  float x = r*cos(phi)*cos(theta);
  float y = r*cos(phi)*sin(theta);
  float z = r*sin(phi);

  delete move_vect;
  move_vect = new Vec3(x, y, z);
  flag_move = true;
}

Vec3* Molecule::getMove() {
  if(flag_move) {
    return new Vec3(move_vect);
  } else {
    computeMove();
    return new Vec3(move_vect);
  }
}

Vec3* Molecule::getPos() {
  return new Vec3(pos_vect);
}

void Molecule::move() {
  if(flag_move) {
    pos_vect->add(move_vect);
  } else {
    computeMove();
    pos_vect->add(move_vect);
  }
  flag_move = false;
}

void Molecule::noMove() {
  delete move_vect;
  move_vect = new Vec3(0.0, 0.0, 0.0);
  flag_move = true;
}

void Molecule::setUsed() {
  this->flag_used = true;
}

void Molecule::setUnused() {
  this->flag_used = false;
}

void Molecule::resetState() {
  this->flag_used = false;
  this->flag_move = false;
}

bool Molecule::getState() {
  return this->flag_used;
}

void Molecule::outOfBounds() {
  delete move_vect;
  move_vect = new Vec3(0.0, 0.0, 0.0);
}
