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
    for (int i = 0; i < this->xRes; i++)
    {
        std::vector<Pixel *> tmp;
        for(int j = 0; j < this->yRes; j++) {
            Pixel *p = new Pixel();
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
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

void Film::addSample(int i, int j, Color24 color)
{
    // TODO::change all images to a vector of color?
    Pixel *pixel = new Pixel(color.r, color.g, color.b);
    this->image[i][j] = pixel;
}

void Film::toPPM(std::string filename)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        file << "P3\n";
        file << this->getXRes() << " " << this->getYRes() << "\n";
        file << "255\n";

        for (int j = this->getYRes() - 1; j >= 0; j--)
        {
            std::string line = "";
            for (int i = 0; i < this->getXRes(); i++)
            {
                Pixel *pixel = this->image[i][j];
                line += std::to_string(pixel->r) + " ";
                line += std::to_string(pixel->g) + " ";
                line += std::to_string(pixel->b) + "\n";
            }
            file << line;
        }

        file.close();
    }
}
