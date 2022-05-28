#include "../include/core/film.h"
#include "../include/helpers/ppmread.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Film::Film() {}

Film::Film(std::string type, int xRes, int yRes, std::string filenameOutput)
{
    this->type = type;
    this->xRes = xRes;
    this->yRes = yRes;
    this->filenameOutput = filenameOutput;
}

int Film::getXRes()
{
    return this->xRes;
}

int Film::getYRes()
{
    return this->yRes;
}

std::string Film::getType()
{
    return this->type;
}

std::string Film::getFilenameOutput()
{
    return this->filenameOutput;
}
