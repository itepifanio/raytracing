#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/ppmreader.h"
#include "../include/pixel.h"
#include <vector>

TEST_CASE("it can change background color") {
    Background background;
    Pixel red(255, 0, 0);
    background.setColor(red);
    CHECK(background.getColor().r == 255);
    CHECK(background.getColor().g == 0);
    CHECK(background.getColor().b == 0);
}