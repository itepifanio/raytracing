#include "../include/doctest.h"
#include "../include/sphere.h"

TEST_CASE("it can init sphere") {
    Point center(0,1,0);
    int r = 5;

    Sphere sphere(r, center);
    //CHECK_EQ(sphere.getRay(), r);
}

TEST_CASE("it can intersect point p ") {
    //TODO:: to implement
}
