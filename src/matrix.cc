#include "matrix.h"

#include <cstddef>

template <size_t R, size_t C>
void Matrix<R, C>::set(int row, int column, float value) {
  data_[row * R + column] = value;
}

// template <size_t R, size_t C>
// bool Matrix<R, C>::operator==(const Matrix<R, C>& other) const {
//  for (size_t row = 0; row < R; row++) {
//    for (size_t column = 0; column < C; column++) {
//      if (data_[row * R + column] != other.data_[row * R + column]) {
//        return false;
//      }
//    }
//  }
//  return true;
//}

template <size_t R, size_t C>
bool operator==(const Matrix<R, C>& matrix_a, const Matrix<R, C>& matrix_b) {
  for (size_t row = 0; row < R; row++) {
    for (size_t column = 0; column < C; column++) {
      if (matrix_a.data_[row * R + column] !=
          matrix_b.data_[row * R + column]) {
        return false;
      }
    }
  }
  return true;
}

template <size_t R, size_t C>
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
