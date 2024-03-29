#include "../include/libs/doctest.h"
#include "../include/datatype/vector3.h"
#include "../include/datatype/pixel.h"

TEST_CASE("it can init vector3 with pixel") {
    Pixel p(1,2,3);
    Vector3 v(p);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("it can mult vector") {
    Vector3 a(1, 2, 3);
    Vector3 c = a * 2;
    CHECK(c.vector[0] == 2.0);
    CHECK(c.vector[1] == 4.0);
    CHECK(c.vector[2] == 6.0);
}

TEST_CASE("it can neg vector") {
    Vector3 v(1, 2, 3);
    CHECK(-v.vector[0] == -1);
    CHECK(-v.vector[1] == -2);
    CHECK(-v.vector[2] == -3);
}

TEST_CASE("it can sub vectors") {
    Vector3 a(1, 2, 3);
    Vector3 b(3, 2, 1);
    a -= b;
    CHECK(a.vector[0] == -2);
    CHECK(a.vector[1] == 0);
    CHECK(a.vector[2] == 2);
}

TEST_CASE("it can sum vectors") {
    Vector3 a(1, 2, 3);
    Vector3 b(3, 2, 1);
    a += b;
    CHECK(a.vector[0] == 4);
    CHECK(a.vector[1] == 4);
    CHECK(a.vector[2] == 4);
}

TEST_CASE("it can multiply vectors") {
    Vector3 a(1, 2, 3);
    double b = 2;
    a *= b;
    CHECK(a.vector[0] == 2.0);
    CHECK(a.vector[1] == 4.0);
    CHECK(a.vector[2] == 6.0);
}

TEST_CASE("it can div vectors") {
    Vector3 a(1, 2, 3);
    double b = 2;
    a /= b;
    CHECK(a.vector[0] == 0.5);
    CHECK(a.vector[1] == 1.0);
    CHECK(a.vector[2] == 1.5);
}

TEST_CASE("it can access class as array") {
    Vector3 v(1, 2, 3);
    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("it can calculate dot product") {
    Vector3 v1(7, 3, 5);
    Vector3 v2(-8, 4, 2);
    double v3 = v1 * v2;
    CHECK_EQ(v3, -34);
}
