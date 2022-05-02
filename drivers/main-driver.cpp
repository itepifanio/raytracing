#include <iostream>
#include "../include/parser.hpp"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/background.h"
// #include "../src/api.cpp"
// #include "../src/background.cpp"

int main(int argc, char** argv)
{
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
    background.interpolateAll();
    background.toPPM("batata.ppm");
    return 0;
}
