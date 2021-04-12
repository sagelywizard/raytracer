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

TEST(matrixTest, matrixMultiplication2x2) {
  float mat_array_a[2][2] = {{1, 2}, {2, 3}};
  Matrix<2, 2> matrix_a(mat_array_a);
  float mat_array_b[2][2] = {{-1, 2}, {-0.4, 0.2}};
  Matrix<2, 2> matrix_b(mat_array_b);
  Matrix<2, 2> multiplication = matrix_a * matrix_b;
  float mat_array_result[2][2] = {{-1.8, 2.4}, {-3.2, 4.6}};
  Matrix<2, 2> desired_result(mat_array_result);
  EXPECT_EQ(multiplication, desired_result);
}

TEST(matrixTest, matrixMultiplication3x3) {
  float mat_array_a[3][3] = {{1, 2, 3}, {2, 3, 4}, {-1, 0, -1}};
  Matrix<3, 3> matrix_a(mat_array_a);
  float mat_array_b[3][3] = {{-1, 2, -0.5}, {-0.4, 0.2, -0.1}, {0.1, 0.2, 0.3}};
  Matrix<3, 3> matrix_b(mat_array_b);
  Matrix<3, 3> multiplication = matrix_a * matrix_b;
  float mat_array_result[3][3] = {
      {-1.5, 3., 0.2}, {-2.8, 5.4, -0.1}, {0.9, -2.2, 0.2}};
  Matrix<3, 3> desired_result(mat_array_result);
  EXPECT_TRUE(multiplication.approx_eq(desired_result, 1e-6));
}

TEST(matrixTest, matrixApproxEq) {
  float mat_array_a[3][3] = {
      {0.9999, 2.0001, -0.0001}, {-1.0001, -0.500001, 0.142857}, {-1, 0, -1}};
  Matrix<3, 3> matrix_a(mat_array_a);
  float mat_array_b[3][3] = {{1.0001, 1.9999, 0.0001},
                             {-0.9999, -0.499999, 0.1428571},
                             {-0.99999, -0, -1.00001}};
  Matrix<3, 3> matrix_b(mat_array_b);
  EXPECT_TRUE(matrix_a.approx_eq(matrix_b, 1e-3));
  EXPECT_TRUE(matrix_b.approx_eq(matrix_a, 1e-3));
  EXPECT_FALSE(matrix_a.approx_eq(matrix_b, 1e-8));
  EXPECT_FALSE(matrix_b.approx_eq(matrix_a, 1e-8));
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

TEST(matrixTest, matrixTranspose4x4) {
  float mat_array_a[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  Matrix<4, 4> matrix_a(mat_array_a);
  float mat_array_b[4][4] = {
      {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16}};
  Matrix<4, 4> matrix_b(mat_array_b);
  EXPECT_EQ(matrix_a.transpose(), matrix_b);
}

TEST(matrixTest, matrixVectorMultiplication2x2) {
  float mat_array_a[2][2] = {{1, -2}, {-4, 5}};
  Matrix<2, 2> matrix_a(mat_array_a);
  float vector_coords[2] = {1, 4};
  Vector<2> vector(vector_coords);
  float result_coords[2] = {-7, 16};
  Vector<2> result(result_coords);
  EXPECT_EQ(matrix_a * vector, result);
}

TEST(matrixTest, matrixVectorMultiplication3x3) {
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
