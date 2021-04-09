#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

#include "tuple.h"

template <int R, int C>
class Matrix {
 public:
  explicit Matrix() {}

  explicit Matrix(const float matrix[R][C]) {
    for (int row = 0; row < R; row++) {
      for (int column = 0; column < C; column++) {
        data_[row * R + column] = matrix[row][column];
      }
    }
  }

  Matrix<R, C> transpose();
  float determinant();
  float cofactor(int row, int column);

  Matrix<R, C> operator*(const Matrix<R, C>& other);
  Vector<R> operator*(const Vector<R>& vector);

  void set(int row, int column, float value);

  float data_[R * C];
};

template <int R, int C>
bool operator==(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

template <int R, int C>
bool operator!=(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

template <int R, int C>
std::ostream& operator<<(std::ostream& output, const Matrix<R, C>& matrix) {
  output << "Matrix({ ";
  for (int row = 0; row < R; row++) {
    output << "{ ";
    for (int column = 0; column < C; column++) {
      output << matrix.data_[row * R + column] << " ";
    }
    output << "} ";
  }
  return output << "})";
}

#endif
