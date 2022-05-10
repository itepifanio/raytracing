#include "../include/doctest.h"
#include "../include/vector3.h"
#include "../include/math/vectors.h"

TEST_CASE("it can cross two vectors") {
    Vector3 u(1, 2, -2);
    Vector3 v(3, 0, 1);
    Vector3 result(2, -7, -6);

    CHECK_EQ(result.toPoint(), cross(u, v).toPoint());
}

TEST_CASE("it can normalize vectors") {
    Vector3 v(4, 2, 4);
    Vector3 result(2/3, 1/3, 2/3);

    CHECK_EQ(result.toPoint(), normalize(v).toPoint());
}
