#ifndef _FILM_H_ 
#define _FILM_H_

#include "pixel.h"
#include <string>
#include <vector>
class Film {
    private:
        std::vector<std::vector<Pixel*>> image;
        std::string type;
        std::string filename;
        std::string img_type;
        int x_res;
        int y_res;
    public:
        Film();
        Film(std::vector<std::vector<Pixel*>> image);
        Film(std::string type, std::string filename, std::string img_type, 
            int x_res, int y_res
        );
        int getXres();
        int getYres();
        void toPPM(std::string filename);
};

#endif