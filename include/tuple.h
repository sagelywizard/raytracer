#ifndef TUPLE_H_
#define TUPLE_H_

#include <cmath>

class Tuple {
 public:
  Tuple(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}

  Tuple operator+(const Tuple& otherTuple) {
    Tuple tuple(x_ + otherTuple.x_, y_ + otherTuple.y_, z_ + otherTuple.z_,
                w_ + otherTuple.w_);
    return tuple;
  }

  Tuple operator-(const Tuple& otherTuple) {
    Tuple tuple(x_ - otherTuple.x_, y_ - otherTuple.y_, z_ - otherTuple.z_,
                w_ - otherTuple.w_);
    return tuple;
  }

  Tuple operator-() {
    Tuple tuple(-x_, -y_, -z_, -w_);
    return tuple;
  }

  // Hadamard product
  Tuple operator*(const Tuple& other) {
    Tuple tuple(other.x_ * x_, other.y_ * y_, other.z_ * z_, other.w_ * w_);
    return tuple;
  }

  Tuple operator*(float multiple) {
    Tuple tuple(multiple * x_, multiple * y_, multiple * z_, multiple * w_);
    return tuple;
  }

  // Vector dot product
  float dot(const Tuple& other) {
    return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
  }

  float magnitude() { return sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_); }

  Tuple cross(const Tuple& other) {
    Tuple tuple(y_ * other.z_ - z_ * other.y_, z_ * other.x_ - x_ * other.z_,
                x_ * other.y_ - y_ * other.x_, w_);
    return tuple;
  }

  void normalize() {
    float mag = magnitude();
    x_ /= mag;
    y_ /= mag;
    z_ /= mag;
    w_ /= mag;
  }

  float x_;
  float y_;
  float z_;
  float w_;
};

Tuple operator*(float multiple, const Tuple& tuple) {
  Tuple newTuple(multiple * tuple.x_, multiple * tuple.y_, multiple * tuple.z_,
                 multiple * tuple.w_);
  return newTuple;
}

#endif
