#include "reaction.h"
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <ctime>

Reaction::Reaction(int ar1, int ar2, unsigned int reac_id) : r1(ar1), r2(ar2), react_id(reac_id) {
  prob_sum = 0.0;
}

Reaction::Reaction(int ar1, unsigned int reac_id) : r1(ar1), r2(-1), react_id(reac_id) {
  prob_sum = 0.0;
}

void Reaction::add(int p1, int p2, float p) {
  prob_sum += p;
  if(prob_sum <= 1.00001) {
    prob.push_back(prob_sum);
    product_id.push_back(std::make_tuple(p1, p2));
  } else {
    std::cout << "Probability max surpassed in reaction" << std::endl;
    std::exit(0);
  }
}

void Reaction::add(int p1, float p) {
  add(p1, -1, p);
}

void Reaction::react(int& p1, int& p2) const {
  std::srand(std::time(nullptr));
  float r = static_cast <float>(std::rand()) / static_cast <float>(RAND_MAX);
  int reac = 0;
  for(float i : prob) {
    if(i > r) {
      p1 = std::get<0>(product_id.at(reac));
      p2 = std::get<1>(product_id.at(reac));
      return;
    } else {
      reac++;
    }
  }
  p1 = -1;
  p2 = -1;
}
