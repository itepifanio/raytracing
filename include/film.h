#ifndef _FILM_H_ 
#define _FILM_H_

#include "pixel.h"
#include <string>
#include <vector>
#include "vector3.h"

class Film {
    private:
        std::vector<std::vector<Pixel*>> image;
        std::vector<std::vector<Vector3>> img;
        std::string type;
        std::string img_type;
        int x_res;
        int y_res;
    public:
        std::string filename;
        Film();
        Film(std::vector<std::vector<Pixel*>> image);
        Film(std::string type, std::string filename, std::string img_type, 
            int x_res, int y_res
        );
        void setPixel(int i , int j, Vector3 pixel);
        int width();
        int height();
        void toPPM();
};

#endif