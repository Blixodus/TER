#ifndef TYPEMOLECULE_H
#define TYPEMOLECULE_H

class TypeMolecule {
 private:
  float speed;
  int size;
 public:
  const unsigned int type_id;
  const char* name;
  TypeMolecule(unsigned int, const char*);
  /* Set molecule type parameters */
  void setSpeed(float);
  void setSize(int);
  /* Get molecule type parameters */
  float getSpeed() const;
  int getSize() const;
};

#endif
