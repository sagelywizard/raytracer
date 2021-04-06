#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>

template <size_t R, size_t C>
class Matrix {
 public:
  void set(int row, int column, float value);

  float data_[R * C];
};

template <size_t R, size_t C>
bool operator==(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

template <size_t R, size_t C>
bool operator!=(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

#endif
