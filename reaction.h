#ifndef REACTION_H
#define REACTION_H
#include <vector>


class Reaction {
 private:
  /* r1 + r2 -> products [prob] */
  const unsigned int react_id;
  float prob_sum;
  std::vector<float> prob;
  std::vector<std::tuple<int, int>> product_id;
 public:
  /* r1, r2, -1 if none */
  const int r1; 
  const int r2;
  Reaction(int, int, unsigned int);
  Reaction(int, unsigned int);
  /* Add new products with a certain probability */
  void add(int, int, float);
  void add(int, float);
  /* Set product id into p1 and p2 */
  void react(int&, int&) const;
  void printReaction(void) const;
};

#endif
