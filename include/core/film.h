#ifndef _FILM_H_ 
#define _FILM_H_

#include "./datatype/pixel.h"
#include "./datatype/color24.h"
#include <string>
#include <vector>

class Film {
    private:
        int xRes;
        int yRes;
        std::string filenameOutput;
        std::string type;
        
    public:
        std::vector<std::vector<Pixel*>> image;
        Film();
        Film(std::string type, int xRes, int yRes, std::string filenameOutput);
        int getXRes();
        int getYRes();
        void addSample(int i, int j, Color24 color);
        std::string getType();
        std::string getFilenameOutput();
        void toPPM(std::string filename);
};

#endif
