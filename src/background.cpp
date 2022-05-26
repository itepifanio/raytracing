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
            Pixel p = this->interpolate(double(i)/double(this->width), double(j)/double(this->height)).toPixel();
            tmp.push_back(&p);
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

Vector3 Background::interpolate(double x, double y)
{
    // https://www.omnicalculator.com/math/bilinear-interpolation#:~:text=Bilinear%20interpolation%20formula,-The%20general%20idea&text=Start%20by%20performing%20two%20linear,point%20(x%2C%20y)%20
    std::array<int, 2> bl = {0, 1};
    std::array<int, 2> tl = {0, 0};
    std::array<int, 2> tr = {1, 0};
    std::array<int, 2> br = {1, 1};

    auto val_bl = this->bottomLeft.toVector3();
    auto val_tl = this->topLeft.toVector3();
    auto val_tr = this->topRight.toVector3();
    auto val_br = this->bottomRight.toVector3();

    return (
        val_bl * (tr[0] - x) * (tl[1] - y) + val_br * (x - bl[0]) * (tr[1] - y) + val_tl * (br[0] - x) * (y - br[1]) + val_tr * (x - bl[0]) * (y - br[1])) / ((br[0] - bl[0]) * (tr[1] - br[1])
    );
}
