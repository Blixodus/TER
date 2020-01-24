#ifndef TYPEMOLECULE_H
#define TYPEMOLECULE_H

class TypeMolecule {
 private:
  const unsigned int type_id;
  const char* name;
  float speed;
  int size;
 public:
  TypeMolecule(unsigned int, char*);
  void setSpeed(float);
  void setSize(int);
};

#endif
