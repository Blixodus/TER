#ifndef MOLECULE_H
#define MOLECULE_H

class Molecule {
 private:
  float x, y, z;
  /* Whether or not the molecule has already reacted or moved */
  bool flag_used;
 public:
  const unsigned int type;
  const unsigned int size;
  const float speed;
  Molecule(unsigned int, float, float, float);
  Molecule(unsigned int);
  ~Molecule();
  /* Get position onto which the molecule would move */
  void getMove(int d, float &x_arg, float &y_arg, float &z_arg);
  /* Get current position */
  void getPos(float &x, float &y, float &z);
  /* Set position */
  void setPos(float, float, float);
};

#endif
