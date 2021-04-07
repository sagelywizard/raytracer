#ifndef TUPLE_H_
#define TUPLE_H_

#include <iostream>

template <int N>
class Tuple {
 public:
  Tuple<N>(const float data[N]) {
    for (int i = 0; i < N; i++) {
      data_[i] = data[i];
    }
  }
  Tuple<N>() = default;

  Tuple<N> operator+(const Tuple<N> &otherTuple) const;
  Tuple<N> operator-(const Tuple<N> &otherTuple) const;
  Tuple<N> operator-() const;
  // Hadamard product
  Tuple<N> operator*(const Tuple<N> &other) const;
  // Scalar multiplication
  Tuple<N> operator*(float multiple) const;
  bool operator==(const Tuple<N> &other) const;
  float &operator[](int index);
  const float &operator[](int index) const;

  // Vector dot product
  float dot(const Tuple<N> &other) const;
  // Vector cross product
  Tuple<N> cross(const Tuple<N> &other) const;

  float magnitude() const;
  void normalize();

 private:
  float data_[N];
};

template <int N>
std::ostream &operator<<(std::ostream &output, const Tuple<N> &tuple) {
  output << "Tuple({ ";
  for (int i = 0; i < N; i++) {
    output << tuple[i] << " ";
  }
  return output << "})";
}

// Need to have this to be able to multiple float*Tuple and Tuple*float
template <int N>
Tuple<N> operator*(float multiple, const Tuple<N> &tuple);

using Color = Tuple<3>;

template <int N>
using Point = Tuple<N>;

template <int N>
using Vector = Tuple<N>;

#endif
