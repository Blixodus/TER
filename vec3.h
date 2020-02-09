#ifndef VEC3_H
#define VEC3_H
#include <cmath>

class Vec3 {
 private:
  float x, y, z;
 public:
  Vec3(float, float, float);
  /* Copy constructor */
  Vec3(const Vec3&);
  /* Vector addition */
  Vec3& operator+(const Vec3&) const;
  /* Vector subtraction */
  Vec3& operator-(const Vec3&) const;
  /* Dot product */
  float operator*(const Vec3&) const;
  /* Scalar product */
  Vec3& operator*(const float) const;
  /* Add and affect */
  void operator+=(const Vec3&);
  /* Sub and affect */
  void operator-=(const Vec3&);
  /* Normalize */
  void normalize();
  /* Get vector length */
  float length();
};

#endif
