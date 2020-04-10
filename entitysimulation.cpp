#include "entitysimulation.h"
#include <cfloat>
#include <cmath>
#include <cstring>
#include <iostream>

EntitySimulation::EntitySimulation() : AbstractSimulation(), typemolecule_list(), reaction_list(), molecule_list() {
}

bool EntitySimulation::checkBounds(Vec3* v, int t) const {
  int r = typemolecule_list.at(t)->getSize();
  return 2*(v->length() + r) <= diameter;
}

void EntitySimulation::printReactions(void) const {
  for(Reaction* r : reaction_list) {
    int len;
    int* products = r->getProducts(len);
    const char* r1 = (r->r1==-1)?"None":typemolecule_list.at(r->r1)->name;
    const char* r2 = (r->r2==-1)?"None":typemolecule_list.at(r->r2)->name;
    for(int i = 0; i < len; i++) {
      const char* p1 = (products[2*i]==-1)?"None":typemolecule_list.at(products[2*i])->name;
      const char* p2 = (products[2*i+1]==-1)?"None":typemolecule_list.at(products[2*i+1])->name;
      std::cout << r1 << " + " << r2 << " -> " << p1 << " + " << p2 << std::endl;
    }
    delete [] products;
  }
}

int EntitySimulation::findTypeID(char* name) const {
  if(name != NULL){
    for(TypeMolecule* t : typemolecule_list) {
      if(!strcmp(name, t->name)) return t->type_id;
    }
  }
  return -1;
}

bool EntitySimulation::reactOne(int m) {
  bool flag_reacted = false;
  Molecule* mole = molecule_list.at(m);
  Vec3* pos = mole->getPos();
  int t = mole->type.type_id;
  int p1, p2;
  for(Reaction* r : reaction_list) {
    if(r->r1 == t && r->r2 == -1) {
      r->react(p1, p2);
      if(p1 != -1) {
	Molecule* m = new Molecule(*typemolecule_list.at(p1), pos);
	m->setUsed();
	molecule_list.push_back(m);
      }
      if(p2 != -1) {
	Molecule* m = new Molecule(*typemolecule_list.at(p2), pos);
	m->setUsed();
	molecule_list.push_back(m);
      }
      if(p1 != -1 || p2 != -1) {
	molecule_list.erase(molecule_list.begin() + m);
	flag_reacted = true;
	delete mole;
      }
      break;
    }
  }
  delete pos;
  return flag_reacted;
}

bool EntitySimulation::reactTwo(int m1, int m2) {
  bool flag_reacted = false;
  Molecule* mole1 = molecule_list.at(m1);
  Molecule* mole2 = molecule_list.at(m2);
  Vec3* pos1 = mole1->getPos();
  Vec3* pos2 = mole2->getPos();
  int t1 = mole1->type.type_id;
  int t2 = mole2->type.type_id;
  int p1, p2;
  for(Reaction* r : reaction_list) {
    if(r->r1 == t1 && r->r2 == t2 || r->r1 == t2 && r->r2 == t1) {
      r->react(p1, p2);
      if(p1 != -1) {
	Molecule* m = new Molecule(*typemolecule_list.at(p1), pos1);
	m->setUsed();
	molecule_list.push_back(m);
      }
      if(p2 != -1) {
	Molecule* m = new Molecule(*typemolecule_list.at(p2), pos2);
	m->setUsed();
	molecule_list.push_back(m);
      }
      if(p1 != -1 || p2 != -1) {
	molecule_list.erase(molecule_list.begin() + m1);
	molecule_list.erase(molecule_list.begin() + m2);
	flag_reacted = true;
	delete mole1;
	delete mole2;
      }
      break;
    }
  }
  delete pos1;
  delete pos2;
  return flag_reacted;
}

int EntitySimulation::computeTrajectory(int m) {
  int r1, r2;
  Molecule* mole = molecule_list.at(m);
  r1 = mole->type.getSize();
  Vec3* pos = mole->getPos();
  Vec3* dir = mole->getMove();
  /* Keep movement distance and normalize */
  float length_dir = dir->length();
  dir->normalize();
  /* TODO Calculate nearest molecule on trajectory */
  bool flag_nearest = false;
  int nearest = -1;
  float dist_nearest = FLT_MAX;
  Vec3* pos2 = mole->getPos();
  for(int i = 0; i < molecule_list.size(); i++) {
    /* Skip itself */
    if(i == m) i++;
    if(i >= molecule_list.size()) break;
    Molecule* mole2 = molecule_list.at(i);
    r2 = mole2->type.getSize();
    delete(pos2);
    pos2 = mole2->getPos();
    /* Recentre space on pos */
    pos2->add(pos);
    Vec3* proj = new Vec3(dir);
    /* Calculate projection of pos2 onto vector dir */
    proj->scal((pos2->dot(dir))/(dir->dot(dir)));
    float proj_length = proj->length();
    /* If distance between proj and pos2 is smaller than the sum of the radii then there is a collision */
    Vec3* dis = new Vec3(pos2);
    dis->sub(proj);
    float dist = dis->length();
    if(dist < r1 + r2 && proj_length < length_dir && proj_length < dist_nearest) {
      nearest = i;
      dist_nearest = proj_length;
    }
  }
  return nearest;
}

void EntitySimulation::print(void) const {
  int size = typemolecule_list.size();
  int nbMolecule[size] ;
  for(int i = 0; i < size; i++) {
    nbMolecule[i] = 0;
  }
  /* Count molecules for each type */
  for(Molecule* m : molecule_list) {
    int tID = m->type.type_id;
    nbMolecule[tID] += 1;
  }
  for(int i = 0; i < size; i++) {
    std::cout << "-- " << nbMolecule[i] << " molecules of type " << typemolecule_list.at(i)->name << std::endl;
  } 
}

void EntitySimulation::addMolecule(char* name, int amount) {
  int t = findTypeID(name);
  if(t != -1) {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    for(int i = 0; i < amount; i++) {
      Molecule* m = new Molecule(*typemolecule_list.at(t), x, y, z);
      molecule_list.push_back(m);
    }
  } else {
    std::cerr << "Undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void EntitySimulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
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

void EntitySimulation::addTypeMolecule(char* name) {
  TypeMolecule* t = new TypeMolecule(typemolecule_list.size(), name);
  typemolecule_list.push_back(t);
  for(TypeMolecule* type : typemolecule_list) {
    std::cout << type << " " << type->name << std::endl;
  }
  std::cout << std::endl;
}

void EntitySimulation::setTypeMoleculeSpeed(char* name, float speed) {
  int t = findTypeID(name);
  if(t!=-1) typemolecule_list.at(t)->setSpeed(speed);
  else {
    std::cerr << "Undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void EntitySimulation::setTypeMoleculeSize(char* name, int size) {
  int t = findTypeID(name);
  if(t!=-1) typemolecule_list.at(t)->setSize(size);
  else {
    std::cerr << "Undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void EntitySimulation::run(int t) {
  std::cout << "Reactions in simulation" << std::endl;
  printReactions();
  std::cout << std::endl << "State before" << std::endl;
  print();
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
	molecule_list.at(m)->setUsed();
	molecule_list.at(m)->noMove();
      }
      /* In case of no collision and no reaction move */
      if(!collides && !reacted) {
	molecule_list.at(m)->setUsed();
	molecule_list.at(m)->move();
      }
      if(reacted) std::cout << "Molecule " << m << " : " << molecule_list.at(m)->type.name << " reacted" << std::endl;
    }
    /* Reset all molecules */
    for(Molecule* m : molecule_list) {
      m->resetState();
    }
    std::cout << std::endl << "State after " << i+1 << " iterations" << std::endl;
    print();
  }
}
