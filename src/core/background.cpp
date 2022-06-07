#include "../include/core/background.h"
#include "../include/datatype/pixel.h"
#include "../include/datatype/point.h"
#include "../include/datatype/vector3.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <array>

Background::Background() {}

Background::Background(int width, int height, std::string type, Pixel color)
{
    this->height = height;
    this->width = width;
    this->type = type;
}

Background::Background(int width, int height, std::string type, Point points[4])
{
    this->height = height;
    this->width = width;
    this->type = type;
    this->bottomLeft = points[0];
    this->topLeft = points[1];
    this->topRight = points[2];
    this->bottomRight = points[3];
}

Vector3 Background::interpolate(double x, double y)
{
    auto bl = this->bottomLeft.toVector3();
    auto tl = this->topLeft.toVector3();
    auto tr = this->topRight.toVector3();
    auto br = this->bottomRight.toVector3();

    return (bl * (1 - x) * (-y) + br * (x - 0) * (-y) + tl * (1 - x) * (y - 1) + tr * (x) * (y - 1)) / -1;
}

Vector3 Background::sample(double x, double y)
{
    return this->interpolate(x, y);
}
