#ifndef TUPLE_H_
#define TUPLE_H_

class Tuple {
 public:
  Tuple(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}
  Tuple() : x_(0), y_(0), z_(0), w_(0) {}

  Tuple operator+(const Tuple &otherTuple);
  Tuple operator-(const Tuple &otherTuple);
  Tuple operator-();
  // Hadamard product
  Tuple operator*(const Tuple &other);
  // Scalar multiplication
  Tuple operator*(float multiple);

  // Vector dot product
  float dot(const Tuple &other);
  // Vector cross product
  Tuple cross(const Tuple &other);

  float magnitude();
  void normalize();

  void setX(float x);
  void setY(float y);
  void setZ(float z);
  void setW(float w);

  float getX() const;
  float getY() const;
  float getZ() const;
  float getW() const;

 private:
  float x_;
  float y_;
  float z_;
  float w_;
};

// Need to have this to be able to multiple float*Tuple and Tuple*float
Tuple operator*(float multiple, const Tuple &tuple);

#endif
