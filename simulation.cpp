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

void Simulation::addReaction(Reaction r) {
  reaction_list.push_back(r);
}

void Simulation::addMolecule(Molecule m) {
  molecule_list.push_back(m);
}

void Simulation::addTypeMolecule(TypeMolecule t) {
  typemolecule_list.push_back(t);
}

void Simulation::run(int t = 1) {
  /* TODO */
  /* Calculate molecule intersections */
  /* Compute reactions */
  /* Move all molecules */
}
