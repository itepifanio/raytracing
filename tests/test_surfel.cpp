#include "../include/doctest.h"
#include "../include/surfel.h"
#include "../include/point.h"
#include "../include/vector3.h"
#include "../include/primitive.h"
#include "../include/sphere.h"

TEST_CASE("it can init surfel") {
    Point p(0, 0, 0);
    Vector n(1,1,1);
    Vector wo(2,1,2);
    Sphere sphere(ray);
    float time = 43.5;
    Point uv(0, 2, 0);
    Sphere s(5);

    Surfel surfel(p, n, wo, sphere, time, uv, s);
    //TODO::Check properties
}
