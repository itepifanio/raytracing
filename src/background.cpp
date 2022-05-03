#include "../include/background.h"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/vector3.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Background::Background(std::string type, Point points[4]) {
    this->type = type;
    this->bottomLeft = points[0];
    this->topLeft = points[1];
    this->topRight = points[2];
    this->bottomRight = points[3];

    // init background image with 200x200 pixels and white pixels
    for (int i = 0; i < 27*3; i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < 27*3; j++)
        {
            Pixel *p = new Pixel(255, 255, 255);
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
}

void Background::interpolateAll()
{
    std::vector<std::vector<Pixel*>> result;
    for (int i = 0; i < (int) this->image.size(); i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < (int)this->image[0].size(); j++)
        {
            double r = this->interpolate(3*i, 3*j);
            double g = this->interpolate(3*i+1, 3*i+1);
            double b = this->interpolate(3*i+2, 3*j+2);
            Pixel *p = new Pixel(int(r), int(g), int(b));
            tmp.push_back(p);
        }
        result.push_back(tmp);
    }

    this->image = result;
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

    std::cout << "toPPM::columns: " << columns << std::endl;
    std::cout << "toPPM::rows: " << rows << std::endl;

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

double Background::interpolate(double x, double y)
{
    //https://en.wikipedia.org/wiki/Bilinear_interpolation#Example
    double halfFirtPoint = ((this->topRight.j - y)/(this->topRight.j - this->topLeft.j))*this->topLeft.value;
    double anotherHalfFirstPoint = ((y - this->topLeft.j)/(this->topRight.j - this->topLeft.j))*this->topRight.value;
    double firstPoint = halfFirtPoint + anotherHalfFirstPoint;

    double halfSecondPoint = ((this->bottomRight.j - y)/(this->bottomRight.j-this->bottomLeft.j))*this->bottomLeft.value;
    double secondHalfPoint = ((y - bottomLeft.j)/(this->bottomRight.j - this->bottomLeft.j))*this->bottomRight.value;
    double secondPoint = halfSecondPoint + secondHalfPoint;

    double halfFinalPoint = ((this->bottomLeft.i - x)/(this->bottomLeft.i - this->topLeft.i))*firstPoint;
    double secondHalfFinalPoint = ((x - this->topLeft.i)/(this->bottomLeft.i - this->topLeft.i))*secondPoint;

    return halfFinalPoint + secondHalfFinalPoint;
}

