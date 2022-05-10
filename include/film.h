#ifndef _FILM_H_ 
#define _FILM_H_

#include "pixel.h"
#include <string>
#include <vector>

class Film {
    private:
        int xRes;
        int yRes;
        std::string filenameOutput;
        std::string type;
    public:
        Film();
        Film(std::string type, int xRes, int yRes, std::string filenameOutput);
        int getXRes();
        int getYRes();
        std::string getType();
        std::string getFilenameOutput();
};

#endif
