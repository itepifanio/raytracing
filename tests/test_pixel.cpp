#include "../include/doctest.h"
#include "../include/pixel.h"

TEST_CASE("it can compare two pixels that are equals") 
{
    Pixel a(0, 0, 0);
    Pixel b(0, 0, 0);
    CHECK(a == b);
}

TEST_CASE("it can compare two pixels that are not equals") 
{
    Pixel black(0, 0, 0);
    Pixel white(255, 255, 255);
    CHECK(black != white);
}
