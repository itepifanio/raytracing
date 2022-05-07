#include "../include/film.h"
#include "../include/ppmread.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Film::Film() {}

Film::Film(int xRes, int yRes, std::string type, std::string ppmFile)
{
    PPM3Reader reader(ppmFile);
    this->xRes = xRes;
    this->yRes = yRes;
    std::cout << "Film::background (width: " << reader.getColumns() << ", height:" << reader.getRows() << ")" << std::endl;
    this->imageWidth = reader.getColumns();
    this->imageHeight = reader.getRows();
    this->type = type;
    this->image = reader.getImage();
}

Film::Film(std::vector<std::vector<Pixel *>> image)
{
    this->image = image;
}

void Film::toPPM(std::string filename)
{
    std::ofstream file(filename);
    int columns = 0;
    int rows = 0;

    columns = this->image.size();
    if (columns)
    {
        rows = this->image[0].size();
    }

    if (file.is_open())
    {
        file << "P3\n";
        file << rows << " " << columns << "\n";
        file << "255\n";

        for (int i = 0; i < columns; i++)
        {
            std::string line = "";
            for (int j = 0; j < rows; j++)
            {
                Pixel *pixel = this->image[i][j];
                line += std::to_string(pixel->r) + " ";
                line += std::to_string(pixel->g) + " ";
                line += std::to_string(pixel->b) + " ";
            }
            line += "\n";
            file << line;
        }

        file.close();
    }
}

int Film::getImageHeight()
{
    return this->imageHeight;
}

int Film::getImageWidth() 
{
    return this->imageWidth;
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
