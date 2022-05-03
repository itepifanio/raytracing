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
    Point q11(0, 1, 12);
    Point q12(4, 1, 0);
    Point q22(4, 3, 8);
    Point q21(0, 3, -4);
    Point corners[4];
    corners[0] = q11;
    corners[1] = q12;
    corners[2] = q22;
    corners[3] = q21;
    Background background(4, 4, "image", corners);
    double result = background.interpolate(1, 2);
    CHECK(int(result) == 5);
}
