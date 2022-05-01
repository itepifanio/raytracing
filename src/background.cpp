#include "../include/background.h"
#include "../include/pixel.h"
#include "../include/vector3.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Background::Background(std::string type, Pixel corners[4]) {
    this->type = type;
    this->bottomLeft = corners[0];
    this->topLeft = corners[1];
    this->topRight = corners[2];
    this->bottomRight = corners[3];

    // init background image with 200x200 pixels and white pixels
    for (int i = 0; i < 20; i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < 20; j++)
        {
            Pixel *p = new Pixel(255, 255, 255);
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
}

void Background::interpolateAll()
{
    for (int i = 0; i < (int)this->image.size(); i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < (int)this->image[0].size(); j++)
        {
            Pixel p = this->interpolate(i, j);
            tmp.push_back(&p);
        }
        this->image.push_back(tmp);
    }
}

// TODO::avoid code repetition
void Background::toPPM(std::string filename)
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

Pixel Background::interpolate(double x, double y)
{
    /*
    Vector3 c00(this->bottomLeft);
    Vector3 c01(this->topLeft);
    Vector3 c11(this->topRight);
    Vector3 c10(this->bottomRight);
    Vector3 a = (c00 * (1 - x)) + (c10 * x); 
    Vector3 b = (c01 * (1 - x)) + (c11 * x); 
    Vector3 c = a * (1 - y) + b * y;
    Pixel pixel(c.vector[0], c.vector[1], c.vector[2]);

    return pixel;
    */
   Pixel point(1,2,3);

   return point;

}

