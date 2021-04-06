#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>

template <size_t R, size_t C>
class Matrix {
 public:
  //  Matrix multiply(const Matrix& other) {
  //    Matrix matrix;
  //    for (int col = 0; col < COLS; col++) {
  //      for (int row = 0; row < ROWS; row++) {
  //        data_[row * col];
  //      }
  //    }
  //    return matrix;
  //  }
  void set(int row, int column, float value);
  //  bool operator==(const Matrix<R, C>& other) const;

  float data_[R * C];
};

template <size_t R, size_t C>
bool operator==(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

template <size_t R, size_t C>
bool operator!=(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b);

#endif
