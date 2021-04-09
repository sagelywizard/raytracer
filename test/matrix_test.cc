#include "matrix.h"

#include <optional>

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
  float mat_array_a[2][2] = {{1, 2}, {2, 3}};
  Matrix<2, 2> matrix_a(mat_array_a);
  float mat_array_b[2][2] = {{-1, 2}, {-0.4, 0.2}};
  Matrix<2, 2> matrix_b(mat_array_b);
  Matrix<2, 2> multiplication = matrix_a * matrix_b;
  float mat_array_result[2][2] = {{-1.8, 2.4}, {-3.2, 4.6}};
  Matrix<2, 2> desired_result(mat_array_result);
  EXPECT_EQ(multiplication, desired_result);
}

TEST(matrixTest, matrixTranspose2x2) {
  float mat_array_a[2][2] = {{1, 2}, {3, 4}};
  Matrix<2, 2> matrix_a(mat_array_a);
  float mat_array_b[2][2] = {{1, 3}, {2, 4}};
  Matrix<2, 2> matrix_b(mat_array_b);
  EXPECT_EQ(matrix_a.transpose(), matrix_b);
}

TEST(matrixTest, matrixTranspose3x3) {
  float mat_array_a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix<3, 3> matrix_a(mat_array_a);
  float mat_array_b[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
  Matrix<3, 3> matrix_b(mat_array_b);
  EXPECT_EQ(matrix_a.transpose(), matrix_b);
}

TEST(matrixTest, matrixVectorMultiplication) {
  float mat_array_a[3][3] = {{1, -2, 3}, {-4, 5, 6}, {7, 8, -9}};
  Matrix<3, 3> matrix_a(mat_array_a);
  float vector_coords[3] = {1, 4, -7};
  Vector<3> vector(vector_coords);
  float result_coords[3] = {-28, -26, 102};
  Vector<3> result(result_coords);
  EXPECT_EQ(matrix_a * vector, result);
}

TEST(matrixTest, matrixMultiplyByIdentity) {
  float mat_array_a[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  Matrix<3, 3> matrix_a(mat_array_a);
  float vector_coords[3] = {1, 4, -7};
  Vector<3> vector(vector_coords);
  float result_coords[3] = {1, 4, -7};
  Vector<3> result(result_coords);
  EXPECT_EQ(matrix_a * vector, result);
}

TEST(matrixTest, determinant2x2) {
  float mat_array[2][2] = {{1, 2}, {-2, 3}};
  Matrix<2, 2> matrix(mat_array);
  EXPECT_EQ(matrix.determinant(), 7.0f);
}

TEST(matrixTest, determinant3x3) {
  float mat_array[3][3] = {{1, 2, 3}, {-2, 3, -2}, {0, 1, 2}};
  Matrix<3, 3> matrix(mat_array);
  EXPECT_EQ(matrix.determinant(), 10.0f);
}

TEST(matrixTest, determinant4x4) {
  float mat_array[4][4] = {
      {1, 2, 3, -2}, {-2, 3, -2, 1}, {3, 1, -2, 3}, {0, 1, 2, -3}};
  Matrix<4, 4> matrix(mat_array);
  EXPECT_EQ(matrix.determinant(), 78.0f);
}

TEST(matrixTest, cofactor2x2) {
  float mat_array[2][2] = {{1, -2}, {-2, 3}};
  Matrix<2, 2> matrix(mat_array);
  EXPECT_EQ(matrix.cofactor(0, 0), 3);
  EXPECT_EQ(matrix.cofactor(0, 1), 2);
  EXPECT_EQ(matrix.cofactor(1, 0), 2);
  EXPECT_EQ(matrix.cofactor(1, 1), 1);
}

TEST(matrixTest, cofactor3x3) {
  float mat_array[3][3] = {{1, -2, 3}, {-2, 3, 0}, {-1, -2, 0}};
  Matrix<3, 3> matrix(mat_array);
  float cofactor_mat[3][3] = {{0, 0, 7}, {-6, 3, 4}, {-9, -6, -1}};
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      EXPECT_EQ(matrix.cofactor(row, column), cofactor_mat[row][column]);
    }
  }
}
