#ifndef TYPEMOLECULE_H
#define TYPEMOLECULE_H

class TypeMolecule {
 private:
  const unsigned int type_id;
  const char* name;
  const float speed;
  const int size;
 public:
  TypeMolecule();
}

#endif
