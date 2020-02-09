#include "simulation.h"
#include <cfloat>
#include <cmath>
#include <cstring>


Simulation::Simulation():typemolecule_list(), reaction_list(), molecule_list(){
}

int Simulation::findTypeID(char* name) {
  for(TypeMolecule t : typemolecule_list) {
    if(!strcmp(name, t.name)) return t.type_id;
  }
}

bool Simulation::checkBounds(Vec3& v, int t) {
  int r = typemolecule_list.at(t).getSize();
  return 2*(v.length() + r) <= diameter;
}

bool Simulation::reactOne(int m) {
  bool flag_reacted = false;
  Molecule mole = molecule_list.at(m);
  Vec3 pos = mole.getPos();
  int t = mole.type;
  int p1, p2;
  for(Reaction r : reaction_list) {
    if(r.r1 == t && r.r2 == -1) {
      r.react(p1, p2);
      if(p1 != -1) {
	Molecule m = new Molecule(&typemolecule_list.at(p1), pos);
	m.setUsed();
	molecule_list.push_back(m);
      }
      if(p2 != -1) {
	Molecule m = new Molecule(&typemolecule_list.at(p2), pos);
	m.setUsed();
	molecule_list.push_back(m);
      }
      if(p1 != -1 || p2 != -1) {
	molecule_list.erase(molecule_list.begin() + m);
	flag_reacted = true;
      }
      break;
    }
  }
  delete(&pos);
  delete(&mole);
  return flag_reacted;
}

bool Simulation::reactTwo(int m1, int m2) {
  bool flag_reacted = false;
  Molecule mole1 = molecule_list.at(m1);
  Molecule mole2 = molecule_list.at(m2);
  Vec3 pos1 = mole1.getPos();
  Vec3 pos2 = mole2.getPos();
  int t1 = mole1.type;
  int t2 = mole2.type;
  int p1, p2;
  for(Reaction r : reaction_list) {
    if(r.r1 == t1 && r.r2 == t2) {
      r.react(p1, p2);
      if(p1 != -1) {
	Molecule m = new Molecule(&typemolecule_list.at(p1), pos1);
	m.setUsed();
	molecule_list.push_back(m);
      }
      if(p2 != -1) {
	Molecule m = new Molecule(&typemolecule_list.at(p2), pos2);
	m.setUsed();
	molecule_list.push_back(m);
      }
      if(p1 != -1 || p2 != -1) {
	molecule_list.erase(molecule_list.begin() + m1);
	molecule_list.erase(molecule_list.begin() + m2);
	flag_reacted = true;
      }
      break;
    }
  }
  delete(&pos1);
  delete(&pos2);
  delete(&mole1);
  delete(&mole2);
  return flag_reacted;
}

int Simulation::computeTrajectory(int m) {
  int r1, r2;
  Molecule mole = molecule_list.at(m);
  r1 = mole.type.getSize();
  Vec3 pos = mole.getPos();
  Vec3 dir = mole.getMove();
  /* Keep movement distance and normalize */
  float length_dir = dir.length();
  dir.normalize();
  /* TODO Calculate nearest molecule on trajectory */
  bool flag_nearest = false;
  int nearest = -1;
  float dist_nearest = FLT_MAX;
  Vec3 pos2;
  for(int i = 0; i < molecule_list.size(); i++) {
    /* Skip itself */
    if(i == m) i++;
    Molecule mole2 = molecule_list.at(i);
    r2 = mole2.type.getSize();
    delete(&pos2);
    pos2 = mole2.getPos();
    /* Recentre space on pos */
    pos2 -= pos;
    /* Calculate projection of pos2 onto vector dir */
    Vec3 proj = dir * ((pos2*dir)/(dir*dir));
    float proj_length = proj.length();
    /* If distance between proj and pos2 is smaller than the sum of the radii then there is a collision */
    float dist = (pos2-proj).length();
    if(dist < r1 + r2 && proj_length < length_dir && proj_length < dist_nearest) {
      nearest = i;
      dist_nearest = proj_length;
    }
  }
  return nearest;
}

void Simulation::setDiameter(int d) {
  diameter = d;
}

void Simulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  int tr1 = findTypeID(r1);
  int tr2 = findTypeID(r2);
  int tp1 = findTypeID(p1);
  int tp2 = findTypeID(p2);
  bool flag_test = false;
  /* TODO */
  /* Check if reaction exists with same r1 and r2 */
  /* Otherwise create new reaction */
  for(Reaction r : reaction_list) {
    if(r.r1 == tr1 && r.r2 == tr2) {
	    flag_test = true;
      }
  }
  if(flag_test){
    Reaction reac = new Reaction(/* Ajouter p1 et p2*/);
    reaction_list.push_back(reac);
  }
}

void Simulation::addMolecule(char* name, int amount) {
  int t = findTypeID(name);
  float x = 0.0;
  float y = 0.0;
  float nz = 0.0;
  Molecule m = new Molecule(&typemolecule_list.at(t), x, y, z);
  molecule_list.push_back(m);
}

void Simulation::addTypeMolecule(char* name) {
  TypeMolecule t = new TypeMolecule(typemolecule_list.size(), name);
  typemolecule_list.push_back(t);
}

void Simulation::setTypeMoleculeSpeed(char* name, float speed) {
  int t = findTypeID(name);
  t.setSpeed(speed);
}

void Simulation::setTypeMoleculeSize(char* name, int size) {
  int t = findTypeID(name);
  t.setSize(size);
}

void Simulation::run(int t = 1) {
  /* TODO */
  for(int i = 0; i < t; i++) {
    for(int m = 0; m < molecule_list.size(); m++) {
      /* Find nearest molecule in trajectory */
      int collision = computeTrajectory(m);
      bool collides = (collision != -1);
      bool reacted;
      /* In case of collision try to react */
      if(collides) reacted = reactTwo(m, collision);
      /* In case of no collision or no reaction try to react alone */
      if(!collides || !reacted) reacted = reactOne(m);
      /* In case of no collision and no reaction move */
      if(collides && !reacted) {
	molecule_list.at(m).setUsed();
	molecule_list.at(m).noMove();
      }
      /* In case of no collision and no reaction move */
      if(!collides && !reacted) {
	molecule_list.at(m).setUsed();
	molecule_list.at(m).move();
      }
    }
    /* Reset all molecules */
    for(Molecule m : molecule_list) {
      m.setUnused();
    }
  }
}
