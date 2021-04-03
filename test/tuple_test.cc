#include "gtest/gtest.h"
#include "tuple.h"

TEST(tupleTest, basicPoint) {
    float x = -0.1, y = 0.0, z = 9990.3;
    int w = 1;
    Tuple tuple(x, y, z, w);
    EXPECT_NEAR(tuple.x_, x, 1e-6);
    EXPECT_NEAR(tuple.y_, y, 1e-6);
    EXPECT_NEAR(tuple.z_, z, 1e-6);
    EXPECT_NEAR(tuple.w_, w, 1e-6);
}

TEST(tupleTest, basicVector) {
    float x = -3.1, y = 0.0, z = 9999.3;
    int w  = 0;
    Tuple tuple(x, y, z, w);
    EXPECT_NEAR(tuple.x_, x, 1e-6);
    EXPECT_NEAR(tuple.y_, y, 1e-6);
    EXPECT_NEAR(tuple.z_, z, 1e-6);
    EXPECT_NEAR(tuple.w_, w, 1e-6);
}

TEST(tupleTest, vectorAddition) {
    Tuple vector1(0.0, 2.0, 4.0, 0);
    Tuple vector2(-1.0, -2.0, -3.0, 0);

    Tuple sum = vector1 + vector2;

    EXPECT_NEAR(sum.x_, -1.0, 1e-6);
    EXPECT_NEAR(sum.y_, 0.0, 1e-6);
    EXPECT_NEAR(sum.z_, 1.0, 1e-6);
    EXPECT_NEAR(sum.w_, 0, 1e-6);
}

TEST(tupleTest, vectorPointAddition) {
    Tuple vector(0.0, 2.0, 4.0, 0);
    Tuple point(-1.0, -2.0, -3.0, 1);

    Tuple sum = vector + point;

    EXPECT_NEAR(sum.x_, -1.0, 1e-6);
    EXPECT_NEAR(sum.y_, 0.0, 1e-6);
    EXPECT_NEAR(sum.z_, 1.0, 1e-6);
    EXPECT_NEAR(sum.w_, 1, 1e-6);
}

TEST(tupleTest, vectorSubtraction) {
    Tuple vector1(0.0, 2.0, 4.0, 0);
    Tuple vector2(-1.0, -2.0, -3.0, 0);

    Tuple diff = vector1 - vector2;

    EXPECT_NEAR(diff.x_, 1.0, 1e-6);
    EXPECT_NEAR(diff.y_, 4.0, 1e-6);
    EXPECT_NEAR(diff.z_, 7.0, 1e-6);
    EXPECT_NEAR(diff.w_, 0, 1e-6);
}

TEST(tupleTest, pointVectorSubtraction) {
    Tuple point(-1.0, -2.0, -3.0, 1);
    Tuple vector(0.0, 2.0, 4.0, 0);

    Tuple diff = point - vector;

    EXPECT_NEAR(diff.x_, -1.0, 1e-6);
    EXPECT_NEAR(diff.y_, -4.0, 1e-6);
    EXPECT_NEAR(diff.z_, -7.0, 1e-6);
    EXPECT_NEAR(diff.w_, 1, 1e-6);
}

TEST(tupleTest, pointSubtraction) {
    Tuple point1(0.0, 2.0, 4.0, 0);
    Tuple point2(-1.0, -2.0, -3.0, 0);

    Tuple diff = point1 - point2;

    EXPECT_NEAR(diff.x_, 1.0, 1e-6);
    EXPECT_NEAR(diff.y_, 4.0, 1e-6);
    EXPECT_NEAR(diff.z_, 7.0, 1e-6);
    EXPECT_NEAR(diff.w_, 0, 1e-6);
}

TEST(tupleTest, vectorNegate) {
    Tuple vector(0.0, 2.0, -4.0, 4.4);

    Tuple negative = -vector;

    EXPECT_NEAR(negative.x_, 0.0, 1e-6);
    EXPECT_NEAR(negative.y_, -2.0, 1e-6);
    EXPECT_NEAR(negative.z_, 4.0, 1e-6);
    EXPECT_NEAR(negative.w_, -4.4, 1e-6);
}

TEST(tupleTest, tupleNegate) {
    Tuple tuple(0.0, 2.0, -4.0, 9.0);

    Tuple negative = -tuple;

    EXPECT_NEAR(negative.x_, 0.0, 1e-6);
    EXPECT_NEAR(negative.y_, -2.0, 1e-6);
    EXPECT_NEAR(negative.z_, 4.0, 1e-6);
    EXPECT_NEAR(negative.w_, -9.0, 1e-6);
}


TEST(tupleTest, tupleScalarMultiplication) {
    Tuple tuple(-1.0, 2.0, -4.0, 3);

    float multiple = 2.0;
    Tuple negative = multiple*tuple;

    EXPECT_NEAR(negative.x_, -2.0, 1e-6);
    EXPECT_NEAR(negative.y_, 4.0, 1e-6);
    EXPECT_NEAR(negative.z_, -8.0, 1e-6);
    EXPECT_NEAR(negative.w_, 6, 1e-6);
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
    EXPECT_NEAR((vector1 * vector2).x_, result.x_, 1e-6);
    EXPECT_NEAR((vector1 * vector2).y_, result.y_, 1e-6);
    EXPECT_NEAR((vector1 * vector2).z_, result.z_, 1e-6);
    EXPECT_NEAR((vector1 * vector2).w_, result.w_, 1e-6);
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
    EXPECT_NEAR(vector.x_, 0.0, 1e-3);
    EXPECT_NEAR(vector.y_, 0.4472, 1e-3);
    EXPECT_NEAR(vector.z_, 0.8944, 1e-3);
    EXPECT_NEAR(vector.w_, 0.0, 1e-3);
}

TEST(tupleTest, normalizeTest2) {
    Tuple vector(0.0, 1.0, 0.0, 0);
    vector.normalize();
    EXPECT_NEAR(vector.magnitude(), 1.0, 1e-3);
    EXPECT_NEAR(vector.x_, 0.0, 1e-3);
    EXPECT_NEAR(vector.y_, 1.0, 1e-3);
    EXPECT_NEAR(vector.z_, 0.0, 1e-3);
    EXPECT_NEAR(vector.w_, 0.0, 1e-3);
}

TEST(tupleTest, crossProductTest) {
    Tuple vector1(1.0, 2.0, 3.0, 0);
    Tuple vector2(4.0, 5.0, 6.0, 0);
    EXPECT_NEAR(vector1.cross(vector2).x_, -3.0, 1e-6);
    EXPECT_NEAR(vector1.cross(vector2).y_, 6.0, 1e-6);
    EXPECT_NEAR(vector1.cross(vector2).z_, -3.0, 1e-6);
    EXPECT_NEAR(vector1.cross(vector2).w_, 0.0, 1e-6);
}
