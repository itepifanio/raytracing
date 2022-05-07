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
    std::cout << "initing background " << width << ", " << height << std::endl;
    for (int i = 0; i < this->height; i++)
    {
        std::vector<Pixel *> tmp;
        for (int j = 0; j < this->width; j++)
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
    std::cout << "Background::points[4]" << std::endl;
    this->height = height;
    this->width = width;
    this->type = type;
    this->bottomLeft = points[0];
    this->topLeft = points[1];
    this->topRight = points[2];
    this->bottomRight = points[3];

    std::cout << "starting to create image background" << std::endl;
    std::cout << "Background::background (width: " << width << ", height:" << height << ")" << std::endl;
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
    std::cout << "Finishing Background::points[4]" << std::endl;
}

void Background::interpolateAll()
{
    std::cout << "Starting Background::interpolateAll()" << std::endl;
    std::vector<std::vector<Pixel *>> result;
    for (int i = 0; i < (int)this->image.size(); i++)
    {
        std::vector<Pixel *> tmp;
        for (int j = 0; j < (int)this->image[0].size(); j++)
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

double Background::interpolate(double x, double y)
{
    // https://www.omnicalculator.com/math/bilinear-interpolation#:~:text=Bilinear%20interpolation%20formula,-The%20general%20idea&text=Start%20by%20performing%20two%20linear,point%20(x%2C%20y)%20
    auto q11 = this->bottomLeft;
    auto q12 = this->topLeft;
    auto q22 = this->topRight;
    auto q21 = this->bottomRight;
    double x1 = q11.i;
    double y1 = q11.j;
    double y2 = q21.j;
    double x2 = q12.i;

    double r1 = (((x2 - x) / (x2 - x1)) * q11.value) + (((x - x1) / (x2 - x1)) * q21.value);
    double r2 = (((x2 - x) / (x2 - x1)) * q12.value) + (((x - x1) / (x2 - x1)) * q22.value);
    double p = (((y2 - y) / (y2 - y1)) * r1) + (((y - y1) / (y2 - y1)) * r2);

    return p;
}
