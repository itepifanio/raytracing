#include "../../include/datatype/color24.h"

Color24::Color24() {}

Color24::Color24(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Vector3 Color24::toVector3()
{
    return Vector3(this->r, this->g, this->b);
}

Color24::~Color24()
{
    
}