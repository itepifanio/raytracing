#include "../include/background.h"
#include "../include/pixel.h"

Background::Background(std::string type, Pixel corners[4]) {
    this->type = type;
    this->bottomLeft = corners[0];
    this->topLeft = corners[1];
    this->topRight = corners[2];
    this->bottomRight = corners[3];
}
