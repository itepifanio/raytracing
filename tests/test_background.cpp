#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/ppmread.h"
#include "../include/pixel.h"
#include <vector>

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

TEST_CASE("it can interpolate background") {
    /*
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
    background.interpolateAll();
    background.toPPM("tmp.ppm");
    */
}
