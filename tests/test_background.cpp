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
    //using values from wikipedia example
    //https://en.wikipedia.org/wiki/Bilinear_interpolation#Example
    Point a(21, 14, 162);
    Point b(20, 14, 91);
    Point c(20, 15, 210);
    Point d(21, 15, 95);
    Point corners[4];
    corners[0] = a;
    corners[1] = b;
    corners[2] = c;
    corners[3] = d;
    Background background("image", corners);
    double result = background.interpolate(20.2, 14.5);
    CHECK(int(result) == int(146.1));
}
