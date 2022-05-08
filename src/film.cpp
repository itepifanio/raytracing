#include "../include/film.h"
#include "../include/ppmread.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Film::Film() {}

Film::Film(int xRes, int yRes, std::string type, std::string filenameOutput)
{
    this->filenameOutput = filenameOutput;
    this->xRes = xRes;
    this->yRes = yRes;
    this->type = type;
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
