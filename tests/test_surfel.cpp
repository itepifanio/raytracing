#include "../include/libs/doctest.h"
#include "../include/shapes/surfel.h"
#include "../include/datatype/point.h"
#include "../include/datatype/vector3.h"
#include "../include/shapes/primitive.h"
#include "../include/shapes/sphere.h"

TEST_CASE("it can init surfel") {
    Point p(0, 0, 0);
    Vector3 n(1,1,1);
    Vector3 wo(2,1,2);
    Point center(0, 1, 0);
    Sphere *s = new Sphere(5, center);
    float time = 43.5;
    Point uv(0, 2, 0);

    Surfel surfel(p, n, wo, time, uv, s);
    //TODO::Check properties
}
