#ifndef _PPMREAD_H_ 
#define _PPMREAD_H_

#include "pixel.h"
#include <string>
#include <vector>

class PPM3Reader {
    private:
        int columns;
        int rows;
        std::string type;
        int maxColor;
        std::vector<std::vector<Pixel*>> image;
    public:
        PPM3Reader(std::string file);
        std::string getType();
        int getColumns();
        int getRows();
        int getMaxColor();
        std::vector<std::vector<Pixel*>> getImage();
};

#endif