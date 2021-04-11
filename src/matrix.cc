#include "matrix.h"

#include "tuple.h"

template <int R, int C>
void Matrix<R, C>::set(int row, int column, float value) {
  data_[row * R + column] = value;
}

template <int R, int C>
Matrix<R, C> Matrix<R, C>::transpose() {
  Matrix result;
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      result.data_[column * R + row] = data_[row * R + column];
    }
  }
  return result;
}

template <>
float Matrix<2, 2>::determinant() {
  return data_[0] * data_[3] - data_[1] * data_[2];
}

template <>
float Matrix<3, 3>::determinant() {
  return data_[0] * (data_[4] * data_[8] - data_[5] * data_[7]) -
         data_[1] * (data_[3] * data_[8] - data_[5] * data_[6]) +
         data_[2] * (data_[3] * data_[7] - data_[4] * data_[6]);
}

template <>
float Matrix<4, 4>::determinant() {
  return data_[0] *
             (data_[5] * (data_[10] * data_[15] - data_[11] * data_[14]) -
              data_[6] * (data_[9] * data_[15] - data_[11] * data_[13]) +
              data_[7] * (data_[9] * data_[14] - data_[10] * data_[13])) -
         data_[1] *
             (data_[4] * (data_[10] * data_[15] - data_[11] * data_[14]) -
              data_[6] * (data_[8] * data_[15] - data_[11] * data_[12]) +
              data_[7] * (data_[8] * data_[14] - data_[10] * data_[12])) +
         data_[2] * (data_[4] * (data_[9] * data_[15] - data_[11] * data_[13]) -
                     data_[5] * (data_[8] * data_[15] - data_[11] * data_[12]) +
                     data_[7] * (data_[8] * data_[13] - data_[9] * data_[12])) -
         data_[3] * (data_[4] * (data_[9] * data_[14] - data_[10] * data_[13]) -
                     data_[5] * (data_[8] * data_[14] - data_[10] * data_[12]) +
                     data_[6] * (data_[8] * data_[13] - data_[9] * data_[12]));
}

template <>
float Matrix<2, 2>::cofactor(int row, int column) {
  return (row == column ? 1 : -1) *
         data_[2 * ((row + 1) % 2) + ((column + 1) % 2)];
}

template <int R, int C>
float Matrix<R, C>::cofactor(int row, int column) {
  Matrix<R - 1, C - 1> submatrix;
  int submat_row = 0;
  for (int i = 0; i < R; i++) {
    if (i == row) continue;
    int submat_col = 0;
    for (int j = 0; j < C; j++) {
      if (j == column) continue;
      submatrix.set(submat_row, submat_col, data_[i * R + j]);
      submat_col += 1;
    }
    submat_row += 1;
  }
  return ((row * R + column) % 2 == 0 ? 1 : -1) * submatrix.determinant();
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
Vector<R> Matrix<R, C>::operator*(const Vector<R>& vector) {
  Vector<R> output_vector;
  for (int row = 0; row < R; row++) {
    output_vector[row] = 0;
    for (int column = 0; column < C; column++) {
      output_vector[row] += data_[row * R + column] * vector[column];
    }
  }
  return output_vector;
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

template <int R, int C>
bool Matrix<R, C>::approx_eq(const Matrix<R, C>& other, float max_difference) {
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      if (fabs(data_[row * R + column] - other.data_[row * R + column]) >
          max_difference) {
        return false;
      }
    }
  }
  return true;
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
