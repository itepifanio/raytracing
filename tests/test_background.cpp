#include "../include/libs/doctest.h"
#include "../include/core/background.h"
#include "../include/helpers/ppmread.h"
#include "../include/datatype/pixel.h"
#include "../include/datatype/point.h"
#include <vector>

TEST_CASE("it can init background with a single color") {
    int size = 200;
    Background black(size, size, "image", Pixel(0, 0, 0));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            CHECK(black[i][j]->r == 0);
            CHECK(black[i][j]->g == 0);
            CHECK(black[i][j]->b == 0);
        }
    }
}

TEST_CASE("it can interpolate background") {
    //using values from wikipedia example
    //https://en.wikipedia.org/wiki/Bilinear_interpolation#Example
    Point q11(0, 1, 12);
    Point q12(0, 3, -4);
    Point q21(4, 1, 0);
    Point q22(4, 3, 8);
    
    Point corners[4];
    corners[0] = q11;
    corners[1] = q12;
    corners[2] = q21;
    corners[3] = q22;
    Background background(4, 4, "image", corners);
    Vector3 result = background.interpolate(1, 2);
    CHECK(int(result[1]) == 5);
}
