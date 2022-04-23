#include "../include/background.h"
#include "../include/pixel.h"

Background::Background() {
    Pixel white(255, 255, 255);
    this->color = white;
}

Pixel Background::fromCoord(int i, int j)
{
    return this->color;
}

void Background::setColor(Pixel pixel)
{
    this->color = pixel;
}

Pixel Background::getColor()
{
    return this->color;
}
