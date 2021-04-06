#include "matrix.h"

#include "gtest/gtest.h"

TEST(matrixTest, matrixEquality) {
  Matrix<2, 2> matrix_a;
  Matrix<2, 2> matrix_b;
  Matrix<2, 2> matrix_c;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 2; i++) {
      matrix_a.set(i, j, i + j);
      matrix_b.set(i, j, i + j);
      matrix_c.set(i, j, i + j);
    }
  }
  matrix_c.set(0, 0, 42);
  EXPECT_EQ(matrix_a, matrix_a);
  EXPECT_EQ(matrix_a, matrix_b);
  EXPECT_EQ(matrix_b, matrix_b);
  EXPECT_NE(matrix_b, matrix_c);
  EXPECT_NE(matrix_a, matrix_c);
  EXPECT_EQ(matrix_c, matrix_c);
}

// TODO(bbastian) test equality
// TODO(bbastian) test multiplcation
// TODO(bbastian) test matrix/vector multiplication
// TODO(bbastian) test multiply by identity
// TODO(bbastian) test transpose
// TODO(bbastian) matrix inversion
// TODO(bbastian) determinant
