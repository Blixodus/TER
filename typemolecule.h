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
  unsigned int get_id() const;
  char* get_name() const;
  float get_speed() const;
  int get_size() const;
};

#endif
