#ifndef REACTION_H
#define REACTION_H

class Reaction {
 private:
  /* r1 + r2 -> p1 + p2 [prob] */
  const unsigned int react_id;
  const float prob;
 public:
  /* r1, r2, p1, p2 are type_id, r2 and p2 can be -1 if none */
  const unsigned int r1; 
  const unsigned int r2;
  const unsigned int p1;
  const unsigned int p2;
  Reaction(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, float);
  /* Return true if reaction succesful else false */
  bool react() const;
};

#endif
