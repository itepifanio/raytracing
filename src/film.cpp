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

Film::Film(std::string type, std::string filename, std::string img_type, 
    int x_res, int y_res
) {
    this->x_res = x_res;
    this->y_res = y_res;
    this->type = type;
    this->filename = filename;
    this-> img_type = img_type;

    for(int i = 0 ; i < x_res; i++){
        std::vector<Vector3> i_;
        for(int j = 0 ; j < y_res; j++){
            i_.push_back(Vector3::string_to_vector("0 0 0"));
        }
        this->img.push_back(i_);
    } 
}

int Film::width()
{
    return this->x_res;
}

int Film::height()
{
    return this->y_res;
}

void Film::setPixel(int i , int j, Vector3 pixel)
{
    this->img[i][j] = pixel;
}

void Film::toPPM()
{
    // std::cout << this->filename << std::endl;
    std::ofstream file(this->filename);
    // std::cout << this->filename << " aqui\n";

    if (file.is_open())
    {
        file << "P3\n";
        file << this->x_res << " " << this->y_res << "\n";
        file << "255\n";

        for (int i = 0; i < this->x_res; i++)
        {
            std::string line = "";
            for (int j = 0; j < this->y_res; j++)
            {
                Vector3 pixel = this->img[i][j];
                line += std::to_string(pixel[0]) + " "; 
                line += std::to_string(pixel[1]) + " "; 
                line += std::to_string(pixel[2]) + " ";
            }
            line += "\n";
            file << line;
        }

        file.close();
    } else {
        std::cout << "error\n";
    }
}