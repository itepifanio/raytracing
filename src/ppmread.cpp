#include "../include/ppmreader.h"
#include "../include/helpers.h"
#include <iostream>
#include <fstream>
#include <sstream>

PPM3Reader::PPM3Reader(std::string filename)
{
    std::ifstream file;
    file.open(filename);

    if (file.is_open())
    {
        // get type
        std::string line;
        std::getline(file, line);
        this->type = line;

        // get columns and row
        std::vector<std::string> splittedLine;
        std::getline(file, line);
        split(line, ' ', splittedLine);
        this->columns = stoi(splittedLine[0]);
        this->rows = stoi(splittedLine[1]);

        // get max color
        std::getline(file, line);
        this->maxColor = stoi(line);

        // fill image
        splittedLine.clear();
        while (file)
        {
            std::getline(file, line);
            split(line, ' ', splittedLine);
            std::vector<Pixel *> tmp;
            for (int i = 0; i < ((int)splittedLine.size() / 3); i++)
            {
                Pixel *pixel = new Pixel(
                    stoi(splittedLine[3*i]),
                    stoi(splittedLine[3*i + 1]),
                    stoi(splittedLine[3*i + 2]));
                tmp.push_back(pixel);
            }

            this->image.push_back(tmp);
            splittedLine.clear();
        }
    }
}

std::string PPM3Reader::getType()
{
    return this->type;
}

int PPM3Reader::getColumns()
{
    return this->columns;
}

int PPM3Reader::getRows()
{
    return this->rows;
}

int PPM3Reader::getMaxColor()
{
    return this->maxColor;
}

std::vector<std::vector<Pixel *>> PPM3Reader::getImage()
{
    return this->image;
}