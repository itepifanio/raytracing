#include "../include/doctest.h"
#include "../include/vector3.h"

TEST_CASE("it can neg vector") {
    Vector3 v(1, 2, 3);
    CHECK(-v == {-1, -2, -3});
}