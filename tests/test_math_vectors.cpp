#include "../include/libs/doctest.h"
#include "../include/math/vectors.inl"

TEST_CASE("it can cross two vectors") {
    Vector3 u(1, 2, -2);
    Vector3 v(3, 0, 1);
    Vector3 result(2, -7, -6);

    CHECK_EQ(result.toPoint(), cross(u, v).toPoint());
}

TEST_CASE("it can cross two vectors special case 01") {
    Vector3 u(0, 1, 0);
    Vector3 v(0, -0.263117, 0.964764);
    Vector3 result(0.964764, 0, 0);

    CHECK_EQ(result.toPoint(), cross(u, v).toPoint());
}

TEST_CASE("it can normalize vectors") {
    Vector3 v(4, 2, 4);
    Vector3 result(2/3.0, 1/3.0, 2/3.0);

    CHECK_EQ(result[0], normalize(v)[0]);
    CHECK_EQ(result[1], normalize(v)[1]);
    CHECK_EQ(result[2], normalize(v)[2]);
}

TEST_CASE("it can normalize vectors special case 01") {
    Vector3 v(0.964764, 0, 0);
    Vector3 result(1.0, 0, 0);

    CHECK_EQ(result[1], normalize(v)[1]);
    CHECK_EQ(result[2], normalize(v)[2]);
}
