#include "../include/background.h"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/vector3.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Background::Background() {}

Background::Background(int width, int height, std::string type, Pixel color)
{
    this->height = height;
    this->width = width;
    this->type = type;

    for (int i = 0; i < this->width; i++)
    {
        std::vector<Pixel *> tmp;
        for (int j = 0; j < this->height; j++)
        {
            Pixel *p = new Pixel(color.r, color.g, color.b);
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
}

std::vector<Pixel*> Background::operator[](int const k) const
{
    return this->image[k];
}

Background::Background(int width, int height, std::string type, Point points[4])
{
    this->height = height;
    this->width = width;
    this->type = type;
    this->bottomLeft = points[0];
    this->topLeft = points[1];
    this->topRight = points[2];
    this->bottomRight = points[3];

    // init background image with white pixels
    for (int i = 0; i < width; i++)
    {
        std::vector<Pixel *> tmp;
        for (int j = 0; j < height; j++)
        {
            Pixel *p = new Pixel(255, 255, 255);
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
}

void Background::interpolateAll()
{
    std::vector<std::vector<Pixel *>> result;
    for (int i = 0; i < this->width; i++)
    {
        std::vector<Pixel *> tmp;
        for (int j = 0; j < this->height; j++)
        {
            double r = this->interpolate(i, j);
            double g = this->interpolate(i, j);
            double b = this->interpolate(i, j);
            Pixel *p = new Pixel(int(r), int(g), int(b));
            tmp.push_back(p);
        }
        result.push_back(tmp);
    }

    this->image = result;
}

void Background::toPPM(std::string filename)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        file << "P3\n";
        file << this->width << " " << this->height << "\n";
        file << "255\n";

        for (int i = 0; i < this->width; i++)
        {
            std::string line = "";
            for (int j = 0; j < this->height; j++)
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
    // https://www.omnicalculator.com/math/bilinear-interpolation#:~:text=Bilinear%20interpolation%20formula,-The%20general%20idea&text=Start%20by%20performing%20two%20linear,point%20(x%2C%20y)%20
    auto q11 = this->bottomLeft;
    auto q12 = this->topLeft;
    auto q21 = this->topRight;
    auto q22 = this->bottomRight;

    double x1 = q11.i;
    double x2 = q21.i;
    double y1 = q21.j;
    double y2 = q22.j;

    double p1 = (x2-x1) * (y2 - y1);
    double p2 = (x2-x) * (y2-y);
    double p3 = (x-x1) * (y2-y);
    double p4 = (x2-x) * (y-y1);
    double p5 = (x-x1) * (y-y1);

    double p = ((p2/(double)p1)*q11.value) + ((p3/(double)p1)*q12.value) + ((p4/(double)p1)*q21.value) + ((p5/(double)p1)*q22.value);

    return p;
}
