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

TEST(matrixTest, matrixMultiplication) {
  Matrix<2, 2> matrix_a((float[2][2]){{1, 2}, {2, 3}});
  Matrix<2, 2> matrix_b((float[2][2]){{-1, 2}, {-0.4, 0.2}});
  Matrix<2, 2> multiplication = matrix_a * matrix_b;
  Matrix<2, 2> desired_result((float[2][2]){{-1.8, 2.4}, {-3.2, 4.6}});
  EXPECT_EQ(multiplication, desired_result);
}

// TODO(bbastian) test matrix/vector multiplication
// TODO(bbastian) test multiply by identity
// TODO(bbastian) test transpose
// TODO(bbastian) matrix inversion
// TODO(bbastian) determinant
