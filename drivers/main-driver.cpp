#include <iostream>
#include "../include/parser.hpp"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/background.h"
// #include "../src/api.cpp"
// #include "../src/background.cpp"

int main(int argc, char** argv)
{
    Point a(0, 0, 255);
    Point b(81, 0, 91);
    Point c(81, 81, 150);
    Point d(0, 81, 38);
    Point corners[4];
    corners[0] = a;
    corners[1] = b;
    corners[2] = c;
    corners[3] = d;
    Background background(81, 81, "image", corners);
    background.interpolateAll();
    background.toPPM("tmp.ppm");
    return 0;
}
