#include "../include/film.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Film::Film() {}

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