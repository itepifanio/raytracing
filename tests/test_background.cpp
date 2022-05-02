#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/ppmread.h"
#include "../include/pixel.h"
#include "../include/point.h"
#include <vector>

/*
TEST_CASE("it can interpolate") {
    Pixel red(255, 0, 0);
    Pixel blue(0, 255, 0);
    Pixel green(0, 0, 255);
    Pixel black(0, 0, 0);
    Pixel corners[4];
    corners[0] = red;
    corners[1] = blue;
    corners[2] = green;
    corners[3] = black;

    Background background("image", corners);
    background.interpolate(10, 10);
}
*/

TEST_CASE("it can interpolate background") {
    Point a(0, 0, 40);
    Point b(0, 200, 80);
    Point c(200, 0, 200);
    Point d(200, 200, 255);
    Point corners[4];
    corners[0] = a;
    corners[1] = b;
    corners[2] = c;
    corners[3] = d;
    Background background("image", corners);
    double result = background.interpolate(2, 3);
    CHECK(result == 2.0);
    background.interpolateAll();
    background.toPPM("batata.ppm");
}
