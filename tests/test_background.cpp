#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/ppmread.h"
#include "../include/pixel.h"
#include <vector>

TEST_CASE("it can start background from corners") {
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

    CHECK(background.bottomLeft == red);
    CHECK(background.topLeft == blue);
    CHECK(background.topRight == green);
    CHECK(background.bottomRight == black);
}