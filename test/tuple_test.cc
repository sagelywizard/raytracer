#include "tuple.h"

#include "gtest/gtest.h"

TEST(tupleTest, basicPoint) {
  float x = -0.1, y = 0.0, z = 9990.3;
  int w = 1;
  Tuple tuple(x, y, z, w);
  EXPECT_NEAR(tuple.getX(), x, 1e-6);
  EXPECT_NEAR(tuple.getY(), y, 1e-6);
  EXPECT_NEAR(tuple.getZ(), z, 1e-6);
  EXPECT_NEAR(tuple.getW(), w, 1e-6);
}

TEST(tupleTest, basicVector) {
  float x = -3.1, y = 0.0, z = 9999.3;
  int w = 0;
  Tuple tuple(x, y, z, w);
  EXPECT_NEAR(tuple.getX(), x, 1e-6);
  EXPECT_NEAR(tuple.getY(), y, 1e-6);
  EXPECT_NEAR(tuple.getZ(), z, 1e-6);
  EXPECT_NEAR(tuple.getW(), w, 1e-6);
}

TEST(tupleTest, vectorAddition) {
  Tuple vector1(0.0, 2.0, 4.0, 0);
  Tuple vector2(-1.0, -2.0, -3.0, 0);

  Tuple sum = vector1 + vector2;

  EXPECT_NEAR(sum.getX(), -1.0, 1e-6);
  EXPECT_NEAR(sum.getY(), 0.0, 1e-6);
  EXPECT_NEAR(sum.getZ(), 1.0, 1e-6);
  EXPECT_NEAR(sum.getW(), 0, 1e-6);
}

TEST(tupleTest, vectorPointAddition) {
  Tuple vector(0.0, 2.0, 4.0, 0);
  Tuple point(-1.0, -2.0, -3.0, 1);

  Tuple sum = vector + point;

  EXPECT_NEAR(sum.getX(), -1.0, 1e-6);
  EXPECT_NEAR(sum.getY(), 0.0, 1e-6);
  EXPECT_NEAR(sum.getZ(), 1.0, 1e-6);
  EXPECT_NEAR(sum.getW(), 1, 1e-6);
}

TEST(tupleTest, vectorSubtraction) {
  Tuple vector1(0.0, 2.0, 4.0, 0);
  Tuple vector2(-1.0, -2.0, -3.0, 0);

  Tuple diff = vector1 - vector2;

  EXPECT_NEAR(diff.getX(), 1.0, 1e-6);
  EXPECT_NEAR(diff.getY(), 4.0, 1e-6);
  EXPECT_NEAR(diff.getZ(), 7.0, 1e-6);
  EXPECT_NEAR(diff.getW(), 0, 1e-6);
}

TEST(tupleTest, pointVectorSubtraction) {
  Tuple point(-1.0, -2.0, -3.0, 1);
  Tuple vector(0.0, 2.0, 4.0, 0);

  Tuple diff = point - vector;

  EXPECT_NEAR(diff.getX(), -1.0, 1e-6);
  EXPECT_NEAR(diff.getY(), -4.0, 1e-6);
  EXPECT_NEAR(diff.getZ(), -7.0, 1e-6);
  EXPECT_NEAR(diff.getW(), 1, 1e-6);
}

TEST(tupleTest, pointSubtraction) {
  Tuple point1(0.0, 2.0, 4.0, 0);
  Tuple point2(-1.0, -2.0, -3.0, 0);

  Tuple diff = point1 - point2;

  EXPECT_NEAR(diff.getX(), 1.0, 1e-6);
  EXPECT_NEAR(diff.getY(), 4.0, 1e-6);
  EXPECT_NEAR(diff.getZ(), 7.0, 1e-6);
  EXPECT_NEAR(diff.getW(), 0, 1e-6);
}

TEST(tupleTest, vectorNegate) {
  Tuple vector(0.0, 2.0, -4.0, 4.4);

  Tuple negative = -vector;

  EXPECT_NEAR(negative.getX(), 0.0, 1e-6);
  EXPECT_NEAR(negative.getY(), -2.0, 1e-6);
  EXPECT_NEAR(negative.getZ(), 4.0, 1e-6);
  EXPECT_NEAR(negative.getW(), -4.4, 1e-6);
}

TEST(tupleTest, tupleNegate) {
  Tuple tuple(0.0, 2.0, -4.0, 9.0);

  Tuple negative = -tuple;

  EXPECT_NEAR(negative.getX(), 0.0, 1e-6);
  EXPECT_NEAR(negative.getY(), -2.0, 1e-6);
  EXPECT_NEAR(negative.getZ(), 4.0, 1e-6);
  EXPECT_NEAR(negative.getW(), -9.0, 1e-6);
}

TEST(tupleTest, tupleScalarMultiplication) {
  Tuple tuple(-1.0, 2.0, -4.0, 3);

  float multiple = 2.0;
  Tuple negative = multiple * tuple;

  EXPECT_NEAR(negative.getX(), -2.0, 1e-6);
  EXPECT_NEAR(negative.getY(), 4.0, 1e-6);
  EXPECT_NEAR(negative.getZ(), -8.0, 1e-6);
  EXPECT_NEAR(negative.getW(), 6, 1e-6);
}

TEST(tupleTest, vectorDotProduct) {
  Tuple vector1(0.0, 2.0, 4.0, 0);
  Tuple vector2(-1.0, -2.0, -3.0, 0);
  EXPECT_NEAR(vector1.dot(vector2), -16.0, 1e-6);
}

TEST(tupleTest, hadamardProduct) {
  Tuple vector1(0.0, 2.0, 4.0, 0);
  Tuple vector2(-1.0, -2.0, -3.0, 0);
  Tuple result(0.0, -4.0, -12.0, 0);
  EXPECT_NEAR((vector1 * vector2).getX(), result.getX(), 1e-6);
  EXPECT_NEAR((vector1 * vector2).getY(), result.getY(), 1e-6);
  EXPECT_NEAR((vector1 * vector2).getZ(), result.getZ(), 1e-6);
  EXPECT_NEAR((vector1 * vector2).getW(), result.getW(), 1e-6);
}

TEST(tupleTest, magnitudeTest) {
  Tuple vector1(0.0, 2.0, 4.0, 0);
  Tuple vector2(-1.0, -2.0, -3.0, 0);
  Tuple vector3(0.0, -4.0, -12.0, 0);
  EXPECT_NEAR(vector1.magnitude(), 4.4721, 1e-4);
  EXPECT_NEAR(vector2.magnitude(), 3.7417, 1e-4);
  EXPECT_NEAR(vector3.magnitude(), 12.6491, 1e-4);
}

TEST(tupleTest, normalizeTest1) {
  Tuple vector(0.0, 2.0, 4.0, 0);
  vector.normalize();
  EXPECT_NEAR(vector.magnitude(), 1.0, 1e-3);
  EXPECT_NEAR(vector.getX(), 0.0, 1e-3);
  EXPECT_NEAR(vector.getY(), 0.4472, 1e-3);
  EXPECT_NEAR(vector.getZ(), 0.8944, 1e-3);
  EXPECT_NEAR(vector.getW(), 0.0, 1e-3);
}

TEST(tupleTest, normalizeTest2) {
  Tuple vector(0.0, 1.0, 0.0, 0);
  vector.normalize();
  EXPECT_NEAR(vector.magnitude(), 1.0, 1e-3);
  EXPECT_NEAR(vector.getX(), 0.0, 1e-3);
  EXPECT_NEAR(vector.getY(), 1.0, 1e-3);
  EXPECT_NEAR(vector.getZ(), 0.0, 1e-3);
  EXPECT_NEAR(vector.getW(), 0.0, 1e-3);
}

TEST(tupleTest, crossProductTest) {
  Tuple vector1(1.0, 2.0, 3.0, 0);
  Tuple vector2(4.0, 5.0, 6.0, 0);
  EXPECT_NEAR(vector1.cross(vector2).getX(), -3.0, 1e-6);
  EXPECT_NEAR(vector1.cross(vector2).getY(), 6.0, 1e-6);
  EXPECT_NEAR(vector1.cross(vector2).getZ(), -3.0, 1e-6);
  EXPECT_NEAR(vector1.cross(vector2).getW(), 0.0, 1e-6);
}
