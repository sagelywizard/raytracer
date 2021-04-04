#include "tuple.h"

#include <cmath>

Tuple Tuple::operator+(const Tuple& other) {
  Tuple tuple(x_ + other.getX(), y_ + other.getY(), z_ + other.getZ(),
              w_ + other.getW());
  return tuple;
}

Tuple Tuple::operator-(const Tuple& other) {
  Tuple tuple(x_ - other.getX(), y_ - other.getY(), z_ - other.getZ(),
              w_ - other.getW());
  return tuple;
}

Tuple Tuple::operator-() {
  Tuple tuple(-x_, -y_, -z_, -w_);
  return tuple;
}

// Hadamard product
Tuple Tuple::operator*(const Tuple& other) {
  Tuple tuple(other.getX() * x_, other.getY() * y_, other.getZ() * z_,
              other.getW() * w_);
  return tuple;
}

Tuple Tuple::operator*(float multiple) {
  Tuple tuple(multiple * x_, multiple * y_, multiple * z_, multiple * w_);
  return tuple;
}

Tuple operator*(float multiple, const Tuple& tuple) {
  Tuple newTuple(multiple * tuple.getX(), multiple * tuple.getY(),
                 multiple * tuple.getZ(), multiple * tuple.getW());
  return newTuple;
}

// Vector dot product
float Tuple::dot(const Tuple& other) {
  return x_ * other.getX() + y_ * other.getY() + z_ * other.getZ();
}

float Tuple::magnitude() { return sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_); }

Tuple Tuple::cross(const Tuple& other) {
  Tuple tuple(y_ * other.getZ() - z_ * other.getY(),
              z_ * other.getX() - x_ * other.getZ(),
              x_ * other.getY() - y_ * other.getX(), w_);
  return tuple;
}

float Tuple::getX() const { return x_; }
float Tuple::getY() const { return y_; }
float Tuple::getZ() const { return z_; }
float Tuple::getW() const { return w_; }

void Tuple::setX(float x) { x_ = x; }
void Tuple::setY(float y) { y_ = y; }
void Tuple::setZ(float z) { z_ = z; }
void Tuple::setW(float w) { w_ = w; }

void Tuple::normalize() {
  float mag = magnitude();
  x_ /= mag;
  y_ /= mag;
  z_ /= mag;
  w_ /= mag;
}
