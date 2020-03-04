#include "vec3.h"
#include <cmath>


Vec3::Vec3() {
  x = 0;
  y = 0;
  z = 0;
}

Vec3::Vec3(float x_, float y_, float z_) {
  x = x_;
  y = y_;
  z = z_;
}

Vec3::Vec3(const Vec3* o) {
  x = o->x;
  y = o->y;
  z = o->z;
}

void Vec3::add(const Vec3* o) {
  x = x + o->x;
  y = y + o->y;
  z = z + o->z;
}

void Vec3::sub(const Vec3* o) {
  x = x - o->x;
  y = y - o->y;
  z = z - o->z;
}

float Vec3::dot(const Vec3* o) const {
  float x_ = x * o->x;
  float y_ = y * o->y;
  float z_ = z * o->z;
  return x_ + y_ + z_;
}

void Vec3::scal(const float s) {
  x = x * s;
  y = y * s;
  z = z * s;
}

void Vec3::normalize() {
  float l = length();
  x /= l;
  y /= l;
  z /= l;
}

float Vec3::length() {
  return sqrt(x*x+y*y+z*z);
}
