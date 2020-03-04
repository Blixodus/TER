#ifndef VEC3_H
#define VEC3_H


class Vec3 {
 private:
  float x, y, z;
 public:
  Vec3();
  Vec3(float, float, float);
  /* Copy constructor */
  Vec3(const Vec3*);
  /* Vector addition */
  void add(const Vec3*) const;
  /* Vector subtraction */
  void sub(const Vec3*) const;
  /* Dot product */
  float dot(const Vec3*) const;
  /* Scalar product */
  void scal(const float) const;
  /* Normalize */
  void normalize();
  /* Get vector length */
  float length();
};

#endif
