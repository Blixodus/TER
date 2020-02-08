#include "molecule.h"

Molecule::Molecule(TypeMolecule& t, float x, float y, float z) : type(t) {
  flag_used = false;
  flag_move = false;
  pos = new Vec3(x, y, z);
  move = new Vec3(0, 0, 0);
}

Molecule::Molecule(TypeMolecule& t, Vec3& v) : type(t) {
  flag_used = false;
  flag_move = false;
  pos = new Vec3(v);
  move = new Vec3(0, 0, 0);
}

void Molecule::computeMove() {
  srand(time(NULL));
  float pi = 3.14159f;
  float r = type.getSpeed();
  float theta = pi*(float)rand()/(float)RAND_MAX;
  float phi =  2*pi*(float)rand()/(float)RAND_MAX;

  delete(move);
  move = new Vec3(r*cos(phi)*cos(theta), r*cos(phi)*sin(theta), r*sin(phi));
  flag_move = true;
}

Vec3 Molecule::getMove() {
  if(flag_move) {
    return new Vec3(move);
  } else {
    computeMove();
    return new Vec3(move);
  }
}

Vec3 Molecule::getPos() {
  return new Vec3(pos);
}

void Molecule::move() {
  if(flag_move) {
    pos += move;
  } else {
    computeMove();
    pos += move;
  }
  flag_move = false;
}

void Molecule::noMove() {
  delete(move);
  move = new Vec3(0, 0, 0);
  flag_move = true;
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

void Molecule::outOfBounds() {
  delete(move);
  move = new Vec3(0, 0, 0);
}
