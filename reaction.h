#ifndef REACTION_H
#define REACTION_H

class Reaction {
 private:
  /* r1 + r2 -> p1 + p2 [prob] */
  const unsigned int react_id;
  const unsigned int r1; 
  const unsigned int r2;
  const unsigned int p1;
  const unsigned int p2;
  const float prob;
 public:
  Reaction(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const unsigned int, const float);
  /* Return true if reaction succesful else false */
  bool react();
};

#endif
