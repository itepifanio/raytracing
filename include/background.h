#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "pixel.h"
#include <string>
#include <vector>

class Background {
    private:
        Pixel color;
    public:
        Background();
        Pixel fromCoord(int i, int j);
        void setColor(Pixel pixel);
        Pixel getColor();
};

#endif