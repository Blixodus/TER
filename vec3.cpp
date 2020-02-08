#include "vec3.h"

Vec3::Vec3(float x_, float y_, float z_) {
  x = x_;
  y = y_;
  z = z_;
}

Vec3::Vec3(const Vec3& o) {
  x = o.x;
  y = o.y;
  z = o.z;
}

Vec3& Vec3::operator+(const Vec3& o) {
  x_ = x + o.x;
  y_ = y + o.y;
  z_ = z + o.z;
  return new Vec3(x_, y_, z_);
}

Vec3& Vec3::operator*(const Vec3& o) {
  x_ = x * o.x;
  y_ = y * o.y;
  z_ = z * o.z;
  return new Vec3(x_, y_, z_);  
}

void Vec3::operator+=(const Vec3& o) {
  x += o.x;
  y += o.y;
  z += o.z;
}

void Vec3::operator*=(const Vec3& o) {
  x *= o.x;
  y *= o.y;
  z *= o.z;
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
