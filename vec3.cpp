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

Vec3& Vec3::operator+(const Vec3& o) const {
  x_ = x + o.x;
  y_ = y + o.y;
  z_ = z + o.z;
  Ve3 result = new Vec3(x_, y_, z_);
  return result;
}

Vec3& Vec3::operator-(const Vec3& o) const {
  x_ = x - o.x;
  y_ = y - o.y;
  z_ = z - o.z;
  Vec3 result = new Vec3(x_, y_, z_);
  return result;
}

float Vec3::operator*(const Vec3& o) const {
  x_ = x * o.x;
  y_ = y * o.y;
  z_ = z * o.z;
  return x_ + y_ + z_;
}

Vec3& Vec3::operator*(const float s) const {
  Vec3 result = new Vec3(s*x, s*y, s*z);
  return result;
}

void Vec3::operator+=(const Vec3& o) {
  x += o.x;
  y += o.y;
  z += o.z;
}

void Vec3::operator-=(const Vec3& o) {
  x -= o.x;
  y -= o.y;
  z -= o.z;
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
