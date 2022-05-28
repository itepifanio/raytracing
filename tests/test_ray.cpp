#include "../include/libs/doctest.h"
#include "../include/core/ray.h"
#include "../include/datatype/point.h"
#include "../include/datatype/vector3.h"

TEST_CASE("it can init ray") {
    Point origin(0, 0, 0);
    Vector3 direction(3, 2, -4);
    Ray r(origin, direction);
    CHECK_EQ(r.getOrigin(), origin);
    CHECK_EQ(r.getDirection().toPoint(), direction.toPoint());
}

TEST_CASE("it can positionate ray") {
    Point origin(0, 0, 0);
    Vector3 direction(3, 2, -4);
    Ray r(origin, direction);
    double t = 2.3;
    Point result(6.8999999999999995, 4.6, -9.2);
    CHECK_EQ(r(t), result);
}
