#include <cfloat>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "populationsimulation.h"

PopulationSimulation::PopulationSimulation() : reaction_list(), typemolecule_list() {
  diameter = 0;
  length_molecule_list = 0;
}

/* PRIVATE METHODS */

int PopulationSimulation::findTypeID(char* name) const {
  if(NULL != name) {
    for(Typemolecule_struct* t : typemolecule_list) {
      if(!strcmp(t->name, name)) return t->id;
    }
  }
  return -1;
}

void PopulationSimulation::print(int etat) const {
  std::cout<<etat<< "---"<< length_molecule_list<<std::endl;

  for(int i = 0; i < length_molecule_list; i++) {
    std::cout << "-- " << molecule_list[i] << " molecules of type " << typemolecule_list.at(i)->name << std::endl;
  }

  //Ouverture en écriture, l'arg app, permet de rajouter à la fin du fichier
  std::ofstream file("data.csv", std::ios::app); 
if(file){
      file<<"coucou"<<std::endl;
      file << etat << "\t" << molecule_list[0] << "\t"<< molecule_list[1]<< "\t"<< molecule_list[2]<< "\t"<< molecule_list[3] << std::endl;
  }
  else{
      std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
  }
}

void PopulationSimulation::printReactions(void) const {
  for(Reaction_struct* r : reaction_list) {
    const char* r1 = (r->r1!=-1)?typemolecule_list.at(r->r1)->name:"None";
    const char* r2 = (r->r2!=-1)?typemolecule_list.at(r->r2)->name:"None";
    const char* p1 = (r->p1!=-1)?typemolecule_list.at(r->p1)->name:"None";
    const char* p2 = (r->p2!=-1)?typemolecule_list.at(r->p2)->name:"None";
    std::cout << p1 << " + " << p2 << " -> " << r1 << " + " << r2 << std::endl;
  }
}

/* PUBLIC METHODS */

void PopulationSimulation::setDiameter(int d) {
  diameter = d;
}

void PopulationSimulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  int id_r1 = findTypeID(r1);
  int id_r2 = findTypeID(r2);
  int id_p1 = findTypeID(p1);
  int id_p2 = findTypeID(p2);
  Reaction_struct* r = new Reaction_struct();
  r->id = reaction_list.size();
  r->r1 = id_r1;
  r->r2 = id_r2;
  r->p1 = id_p1;
  r->p2 = id_p2;
  r->p = p;
  reaction_list.push_back(r);
}

void PopulationSimulation::addMolecule(char* name, int amount) {
  /* If molecule_list is empty, give it the same size as typemolecule_list */
  if(0 == length_molecule_list) {
    length_molecule_list = typemolecule_list.size();
    molecule_list = new int[length_molecule_list];
  }

  /* Add a certain amount of this molecule type */
  int typeID = findTypeID(name);
  if(typeID != -1) {
    molecule_list[typeID] = amount;
  } else {
    std::cout << "ERROR: Adding molecule of undefined molecule type " << name << std::endl;
    exit(0);
  }
}

void PopulationSimulation::addTypeMolecule(char* name) {
  Typemolecule_struct* t = new Typemolecule_struct();
  t->id = typemolecule_list.size();
  t->name = name;
  t->speed = 0;
  t->size = 0;
  typemolecule_list.push_back(t);
}

void PopulationSimulation::setTypeMoleculeSpeed(char* name, float s) {
  int id_type = findTypeID(name);
  typemolecule_list.at(id_type)->speed = s;
}

void PopulationSimulation::setTypeMoleculeSize(char* name, int s) {
  int id_type = findTypeID(name);
  typemolecule_list.at(id_type)->size = s;
}

void PopulationSimulation::run(int t_max) {
  std::srand(std::time(nullptr));
  std::cout << "Reactions in simulation:" << std::endl;
  printReactions();
  /* Each iteration is tau = 100µs */
  double alpha = 7.4e-7;
  double volume = 1./6 * M_PI * pow(diameter, 3);

  //On créer le fichier, version on écrit toujours sur le même ->
  std::ofstream file("data.csv"); 
  if(file){
    file << "Etape" << "\t" << "Es" << "\t"<< "p"<< "\t"<< "s" << "\t" << "E" << std::endl;
  }
  else{
      std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
  }

  for(int t = 0; t < t_max; t++) {
    std::cout << "ITERATION " << t << std::endl;
    /* Shuffle reaction_list */
    std::random_shuffle(reaction_list.begin(), reaction_list.end());
    print(t+1);
  
    for(Reaction_struct* r : reaction_list) {
      int r1 = r->r1;
      int r2 = r->r2;
      int p1 = r->p1;
      int p2 = r->p2;
      float p = r->p;
      /* If no reactives or products warn user an continue */
      if(r1 == -1) r1 = r2;
      if(r1 == -1) {
	std::cout << "Error in reaction, no reactives" << std::endl;
	break;
      }
      if(p1 == -1) p1 = p2;
      if(p1 == -1) {
	std::cout << "Error in reaction, no products" << std::endl;
	break;
      }
      /* If no error simulate! */
      if(r2 != -1) {
	/* Calculate propensity */
	double prop = (alpha * (molecule_list[r1] + molecule_list[r2]) * p) / volume;
	if(r1 == r2) prop /= 2;
	int e = prop;
	double f = prop-e;
	double r = (double)std::rand() / (float)RAND_MAX;
	int num_appl = e + ((r<f)?1:0);
	std::cout << r << " " << prop << " " << e << " " << num_appl << std::endl;
	/* Do reactions */
	molecule_list[r1] -= num_appl;
	molecule_list[r2] -= num_appl;
	molecule_list[p1] += num_appl;
	if(p2 != -1) molecule_list[p2] += num_appl;
      } else {
	/* Calculate propensity */
	double prop = molecule_list[r1] * p;
	int e = prop;
	double f = prop-e;
	double r = (double)std::rand() / (float)RAND_MAX;
	int num_appl = e + ((r<f)?1:0);
	std::cout << r << " " << prop << " " << e << " " << num_appl << std::endl;
        /* Do reactions */
	molecule_list[r1] -= num_appl;
	molecule_list[p1] += num_appl;
	if(p2 != -1) molecule_list[p2] += num_appl;	
      }
    }
    std::cout << std::endl << std::endl;
  }
}
