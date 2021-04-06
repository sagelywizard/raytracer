#include "matrix.h"

template <int R, int C>
void Matrix<R, C>::set(int row, int column, float value) {
  data_[row * R + column] = value;
}

template <int R, int C>
Matrix<R, C> Matrix<R, C>::operator*(const Matrix<R, C>& other) {
  Matrix<R, C> result;
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      result.data_[row * R + column] = 0;
      for (int i = 0; i < R; i++) {
        result.data_[row * R + column] +=
            data_[row * R + i] * other.data_[i * R + column];
      }
    }
  }
  return result;
}

template <int R, int C>
bool operator==(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b) {
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      if (matrix_a.data_[row * R + column] !=
          matrix_b.data_[row * R + column]) {
        return false;
      }
    }
  }
  return true;
}

template <int R, int C>
bool operator!=(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b) {
  return !(matrix_a == matrix_b);
}

template bool operator==<2, 2>(const Matrix<2, 2>&, const Matrix<2, 2>&);
template bool operator==<3, 3>(const Matrix<3, 3>&, const Matrix<3, 3>&);
template bool operator==<4, 4>(const Matrix<4, 4>&, const Matrix<4, 4>&);
template bool operator!=<2, 2>(const Matrix<2, 2>&, const Matrix<2, 2>&);
template bool operator!=<3, 3>(const Matrix<3, 3>&, const Matrix<3, 3>&);
template bool operator!=<4, 4>(const Matrix<4, 4>&, const Matrix<4, 4>&);

template class Matrix<2, 2>;
template class Matrix<3, 3>;
template class Matrix<4, 4>;
