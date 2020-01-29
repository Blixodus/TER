#ifndef TYPEMOLECULE_H
#define TYPEMOLECULE_H

class TypeMolecule {
 private:
  const unsigned int type_id;
  const char* name;
  float speed;
  int size;

 public:
  TypeMolecule(const unsigned int, const char*);
  void setSpeed(float);
  void setSize(int);
  unsigned int getId() const;
  char* getName() const;
  float getSpeed() const;
  int getSize() const;
};

#endif
