#ifndef _FILM_H_ 
#define _FILM_H_

#include "pixel.h"
#include <string>
#include <vector>

class Film {
    private:
        std::vector<std::vector<Pixel*>> image;
        int imageHeight;
        int imageWidth;
        int xRes;
        int yRes;
        std::string type;
    public:
        Film();
        Film(int xRes, int yRes, std::string type, std::string ppmFile);
        Film(std::vector<std::vector<Pixel*>> image);
        void toPPM(std::string filename);
        int getImageHeight();
        int getImageWidth();
        int getXRes();
        int getYRes();
        std::string getType();
};

#endif
