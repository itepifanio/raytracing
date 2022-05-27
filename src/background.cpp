#include "../include/background.h"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/vector3.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <array>

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

std::vector<Pixel *> Background::operator[](int const k) const
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
    for (int j = this->height - 1; j >= 0; j--)
    {
        std::vector<Pixel *> tmp(this->height);
        this->image.push_back(tmp);
        for (int i = 0; i < this->width; i++)
        {
            Vector3 v = this->interpolate(double(i) / double(this->width), double(j) / double(this->height));
            Pixel *p = new Pixel(v[0], v[1], v[2]);
            this->image[i][j] = p;
        }
    }
}

void Background::toPPM(std::string filename)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        file << "P3\n";
        file << this->width << " " << this->height << "\n";
        file << "255\n";

        for (int j = this->height - 1; j >= 0; j--)
        {
            std::string line = "";
            for (int i = 0; i < this->width; i++)
            {
                Pixel *pixel = this->image[i][j];
                auto p = pixel;
                line += std::to_string(pixel->r) + " ";
                line += std::to_string(pixel->g) + " ";
                line += std::to_string(pixel->b) + "\n";
            }
            file << line;
        }

        file.close();
    }
}

Vector3 Background::interpolate(double x, double y)
{
    auto bl = this->bottomLeft.toVector3();
    auto tl = this->topLeft.toVector3();
    auto tr = this->topRight.toVector3();
    auto br = this->bottomRight.toVector3();

    return (bl * (1 - x) * (-y) + br * (x - 0) * (-y) + tl * (1 - x) * (y - 1) + tr * (x) * (y - 1)) / -1;
}
