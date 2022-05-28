#include "../include/datatype/pixel.h"

Pixel::Pixel() {}

Pixel::Pixel(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

bool operator==(const Pixel& lhs, const Pixel& rhs)
{
    return lhs.r == rhs.r && lhs.b == rhs.b && lhs.g == rhs.g;
}

bool operator!=(const Pixel& lhs, const Pixel& rhs)
{
    return ! (lhs == rhs);
}
