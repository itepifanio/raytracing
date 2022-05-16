#include "../include/doctest.h"
#include "../include/sphere.h"

TEST_CASE("it can init sphere") {
    int ray = 5;
    Sphere sphere(ray);
    CHECK_EQ(sphere.getRay(), ray);
}
