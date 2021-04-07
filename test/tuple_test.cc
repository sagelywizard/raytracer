#include "tuple.h"

#include "gtest/gtest.h"

TEST(tupleTest, basicPoint) {
  float point_coords[3] = {-0.1, 0.0, 9990.3};
  Point<3> point(point_coords);
  EXPECT_NEAR(point[0], point_coords[0], 1e-6);
  EXPECT_NEAR(point[1], point_coords[1], 1e-6);
  EXPECT_NEAR(point[2], point_coords[2], 1e-6);
}

TEST(tupleTest, basicVector) {
  float coords[3] = {-3.1, 0.0, 9999.3};
  Vector<3> vector(coords);
  EXPECT_NEAR(vector[0], coords[0], 1e-6);
  EXPECT_NEAR(vector[1], coords[1], 1e-6);
  EXPECT_NEAR(vector[2], coords[2], 1e-6);
}

TEST(tupleTest, vectorAddition) {
  float coords1[3] = {0.0, 2.0, 4.0};
  float coords2[3] = {-1.0, -2.0, -3.0};
  Vector<3> vector1(coords1);
  Vector<3> vector2(coords2);

  Vector<3> sum = vector1 + vector2;

  EXPECT_NEAR(sum[0], -1.0, 1e-6);
  EXPECT_NEAR(sum[1], 0.0, 1e-6);
  EXPECT_NEAR(sum[2], 1.0, 1e-6);
}

TEST(tupleTest, vectorPointAddition) {
  float vector_coords[3] = {0.0, 2.0, 4.0};
  Vector<3> vector(vector_coords);
  float point_coords[3] = {-1.0, -2.0, -3.0};
  Point<3> point(point_coords);

  Point<3> sum = vector + point;

  EXPECT_NEAR(sum[0], -1.0, 1e-6);
  EXPECT_NEAR(sum[1], 0.0, 1e-6);
  EXPECT_NEAR(sum[2], 1.0, 1e-6);
}

TEST(tupleTest, vectorSubtraction) {
  float vector1_coords[3] = {0.0, 2.0, 4.0};
  float vector2_coords[3] = {-1.0, -2.0, -3.0};
  Vector<3> vector1(vector1_coords);
  Vector<3> vector2(vector2_coords);

  Vector<3> diff = vector1 - vector2;

  EXPECT_NEAR(diff[0], 1.0, 1e-6);
  EXPECT_NEAR(diff[1], 4.0, 1e-6);
  EXPECT_NEAR(diff[2], 7.0, 1e-6);
}

TEST(tupleTest, pointVectorSubtraction) {
  float point_coords[3] = {-1.0, -2.0, -3.0};
  Point<3> point(point_coords);
  float vector_coords[3] = {0.0, 2.0, 4.0};
  Vector<3> vector(vector_coords);

  Point<3> diff = point - vector;

  EXPECT_NEAR(diff[0], -1.0, 1e-6);
  EXPECT_NEAR(diff[1], -4.0, 1e-6);
  EXPECT_NEAR(diff[2], -7.0, 1e-6);
}

TEST(tupleTest, pointSubtraction) {
  float point1_coords[3] = {0.0, 2.0, 4.0};
  float point2_coords[3] = {-1.0, -2.0, -3.0};
  Point<3> point1(point1_coords);
  Point<3> point2(point2_coords);

  Vector<3> diff = point1 - point2;

  EXPECT_NEAR(diff[0], 1.0, 1e-6);
  EXPECT_NEAR(diff[1], 4.0, 1e-6);
  EXPECT_NEAR(diff[2], 7.0, 1e-6);
}

TEST(tupleTest, vectorNegate) {
  float vector_coords[3] = {0.0, 2.0, -4.0};
  Vector<3> vector(vector_coords);

  Vector<3> negative = -vector;

  EXPECT_NEAR(negative[0], 0.0, 1e-6);
  EXPECT_NEAR(negative[1], -2.0, 1e-6);
  EXPECT_NEAR(negative[2], 4.0, 1e-6);
}

TEST(tupleTest, vectorScalarMultiplication) {
  float vector_coords[3] = {-1.0, 2.0, -4.0};
  Vector<3> vector(vector_coords);

  float multiple = 2.0;
  Vector<3> scaled_vector = multiple * vector;

  EXPECT_NEAR(scaled_vector[0], -2.0, 1e-6);
  EXPECT_NEAR(scaled_vector[1], 4.0, 1e-6);
  EXPECT_NEAR(scaled_vector[2], -8.0, 1e-6);
}

TEST(tupleTest, vectorDotProduct) {
  float vector1_coords[3] = {0.0, 2.0, 4.0};
  float vector2_coords[3] = {-1.0, -2.0, -3.0};
  Vector<3> vector1(vector1_coords);
  Vector<3> vector2(vector2_coords);
  EXPECT_NEAR(vector1.dot(vector2), -16.0, 1e-6);
}

TEST(tupleTest, hadamardProduct) {
  float vector1_coords[3] = {0.0, 2.0, 4.0};
  float vector2_coords[3] = {-1.0, -2.0, -3.0};
  float result_coords[3] = {0.0, -4.0, -12.0};
  Vector<3> vector1(vector1_coords);
  Vector<3> vector2(vector2_coords);
  Vector<3> result(result_coords);
  EXPECT_NEAR((vector1 * vector2)[0], result[0], 1e-6);
  EXPECT_NEAR((vector1 * vector2)[1], result[1], 1e-6);
  EXPECT_NEAR((vector1 * vector2)[2], result[2], 1e-6);
}

TEST(tupleTest, magnitudeTest) {
  float vector1_coords[3] = {0.0, 2.0, 4.0};
  float vector2_coords[3] = {-1.0, -2.0, -3.0};
  float vector3_coords[3] = {0.0, -4.0, -12.0};
  Vector<3> vector1(vector1_coords);
  Vector<3> vector2(vector2_coords);
  Vector<3> vector3(vector3_coords);
  EXPECT_NEAR(vector1.magnitude(), 4.4721, 1e-4);
  EXPECT_NEAR(vector2.magnitude(), 3.7417, 1e-4);
  EXPECT_NEAR(vector3.magnitude(), 12.6491, 1e-4);
}

TEST(tupleTest, normalizeTest1) {
  float vector_coords[3] = {0.0, 2.0, 4.0};
  Vector<3> vector(vector_coords);
  vector.normalize();
  EXPECT_NEAR(vector.magnitude(), 1.0, 1e-3);
  EXPECT_NEAR(vector[0], 0.0, 1e-3);
  EXPECT_NEAR(vector[1], 0.4472, 1e-3);
  EXPECT_NEAR(vector[2], 0.8944, 1e-3);
}

TEST(tupleTest, normalizeTest2) {
  float vector_coords[3] = {0.0, 1.0, 0.0};
  Vector<3> vector(vector_coords);
  vector.normalize();
  EXPECT_NEAR(vector.magnitude(), 1.0, 1e-3);
  EXPECT_NEAR(vector[0], 0.0, 1e-3);
  EXPECT_NEAR(vector[1], 1.0, 1e-3);
  EXPECT_NEAR(vector[2], 0.0, 1e-3);
}

TEST(tupleTest, crossProductTest) {
  float vector1_coords[3] = {1.0, 2.0, 3.0};
  float vector2_coords[3] = {4.0, 5.0, 6.0};
  Vector<3> vector1(vector1_coords);
  Vector<3> vector2(vector2_coords);
  EXPECT_NEAR(vector1.cross(vector2)[0], -3.0, 1e-6);
  EXPECT_NEAR(vector1.cross(vector2)[1], 6.0, 1e-6);
  EXPECT_NEAR(vector1.cross(vector2)[2], -3.0, 1e-6);
}
