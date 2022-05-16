#include "../include/doctest.h"
#include "../include/sphere.h"

TEST_CASE("it can init sphere") {
    int r = 5;
    Sphere sphere(r);
    CHECK_EQ(sphere.getRay(), ray);
}

TEST_CASE("it can intersect point p ") {
    //TODO:: to implement
}
