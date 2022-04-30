#ifndef _FILM_H_ 
#define _FILM_H_

#include "pixel.h"
#include <string>
#include <vector>

class Film {
    private:
        std::vector<std::vector<Pixel*>> image;
    public:
        Film();
        Film(std::vector<std::vector<Pixel*>> image);
        void toPPM(std::string filename);
};

#endif
