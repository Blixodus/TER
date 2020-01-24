#include "simulation.h"
#include "molecule.h"
#include "typemolecule.h"
#include "reaction.h"
#include "parser.h"

Simulation simulation;

int main(int argc, char** argv) {
  simulation = new Simulation();
  return 0;
}
