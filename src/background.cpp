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
    for (int i = 0; i < 512; i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < 512; j++)
        {
            Pixel *p = new Pixel(255, 255, 255);
            tmp.push_back(p);
        }
        this->image.push_back(tmp);
    }
}

int getG(int index, int imageSize, int gridSize)
{
    double a = index / float(imageSize) * gridSize;
    int b = int(a);
    return a - b;
}

void Background::interpolateAll()
{
    int gridSizeX = 9, gridSizeY = 9; 

    std::vector<std::vector<Pixel*>> result;
    for (int i = 0; i < (int) this->image.size()/3; i++)
    {
        std::vector<Pixel*> tmp;
        for (int j = 0; j < (int)this->image[0].size()/3; j++)
        {
            /*
            auto gx = i / float(this->image.size()) * gridSizeX; // be careful to interpolate boundaries 
            auto gy = j / float(this->image.size()) * gridSizeY; // be careful to interpolate boundaries 
            int gxi = int(gx); 
            int gyi = int(gy); 

            double r = this->interpolate(gx - gxi, gy - gyi);
            double g = this->interpolate(0.2*i+0.2, 0.2*i+0.2);
            double b = this->interpolate(0.2*i+0.4, 0.2*i+0.4);;
            Pixel *p = new Pixel(int(r), int(g), int(b)); // = this->interpolate(gx - gxi, gy - gyi);
            tmp.push_back(p);
            */
            double r = this->interpolate(
                getG(3*i, (int)this->image.size(), gridSizeX), 
                getG(3*j, (int)this->image.size(), gridSizeY)
            );
            double g = this->interpolate(
                getG(3*i+1, (int)this->image.size(), gridSizeX), 
                getG(3*j+1, (int)this->image.size(), gridSizeY)
            );
            double b = this->interpolate(
                getG(3*i+2, (int)this->image.size(), gridSizeX), 
                getG(3*j+2, (int)this->image.size(), gridSizeY)
            );
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
    auto z00 = this->bottomLeft.value;
    auto z10 = this->topLeft.value;
    auto z01 = this->topRight.value;
    auto z11 = this->bottomRight.value;

    return z00*(1-x)*(1-y) + z10*x*(1-y) + z01*(1-x)*y + z11*x*y;
}

