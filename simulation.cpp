#include "simulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include <vector>


Simulation::Simulation() {
  
}

void Simulation::setDiameter(int d) {
  diameter = d;
}

void Simulation::addReaction(char* r1, char* r2, char* p1, char* p2, float p) {
  /* TODO */
}

void Simulation::addMolecule(char* name, int amount) {
  /* TODO */
}

void Simulation::addTypeMolecule(char* name) {
  /* TODO */
}

void Simulation::run(int t = 1) {
  /* TODO */
  /* Calculate molecule intersections */
  /* Compute reactions */
  /* Move all molecules */
}
