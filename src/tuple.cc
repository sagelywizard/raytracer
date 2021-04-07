#include "tuple.h"

#include <cmath>
#include <iostream>

template <int N>
float& Tuple<N>::operator[](int index) {
  return data_[index];
}

template <int N>
const float& Tuple<N>::operator[](int index) const {
  return data_[index];
}

template <int N>
Tuple<N> Tuple<N>::operator+(const Tuple& other) const {
  Tuple tuple = other;
  for (int i = 0; i < N; i++) {
    tuple[i] += data_[i];
  }
  return tuple;
}

template <int N>
Tuple<N> Tuple<N>::operator-(const Tuple& other) const {
  Tuple tuple(data_);
  for (int i = 0; i < N; i++) {
    tuple[i] -= other[i];
  }
  return tuple;
}

template <int N>
Tuple<N> Tuple<N>::operator-() const {
  Tuple<N> tuple(data_);
  for (int i = 0; i < N; i++) {
    tuple.data_[i] *= -1.0f;
  }
  return tuple;
}

// Hadamard product
template <int N>
Tuple<N> Tuple<N>::operator*(const Tuple& other) const {
  Tuple<N> tuple = other;
  for (int i = 0; i < N; i++) {
    tuple[i] *= data_[i];
  }
  return tuple;
}

template <int N>
bool Tuple<N>::operator==(const Tuple<N>& other) const {
  for (int i = 0; i < N; i++) {
    if (other[i] != data_[i]) {
      return false;
    }
  }
  return true;
}

template <int N>
Tuple<N> Tuple<N>::operator*(float multiple) const {
  Tuple tuple(data_);
  for (int i = 0; i < N; i++) {
    tuple[i] *= multiple;
  }
  return tuple;
}

template <int N>
Tuple<N> operator*(float multiple, const Tuple<N>& other) {
  return other * multiple;
}

// Vector dot product
template <int N>
float Tuple<N>::dot(const Tuple<N>& other) const {
  float dot_product = 0;
  for (int i = 0; i < N; i++) {
    dot_product += (other[i] * data_[i]);
  }
  return dot_product;
}

template <int N>
float Tuple<N>::magnitude() const {
  float sum = 0;
  for (int i = 0; i < N; i++) {
    sum += data_[i] * data_[i];
  }
  return sqrt(sum);
}

template <int N>
Tuple<N> Tuple<N>::cross(const Tuple<N>& other) const {
  Tuple<N> tuple;
  for (int i = 0; i < N; i++) {
    tuple[i % N] = data_[(1 + i) % N] * other.data_[(2 + i) % N] -
                   data_[(2 + i) % N] * other.data_[(1 + i) % N];
  }
  return tuple;
}

template <int N>
void Tuple<N>::normalize() {
  float mag = magnitude();
  for (int i = 0; i < N; i++) {
    data_[i] /= mag;
  }
}

template class Tuple<2>;
template class Tuple<3>;
template class Tuple<4>;

template Tuple<2> operator*(float multiple, const Tuple<2>& other);
template Tuple<3> operator*(float multiple, const Tuple<3>& other);
template Tuple<4> operator*(float multiple, const Tuple<4>& other);
