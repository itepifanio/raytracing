#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "pixel.h"
#include "vector3.h"
#include <string>
#include <vector>

class Background {
    private:
        std::string type;
    public:
        Background(std::string type, Pixel corners[4]);
        Pixel bottomLeft;
        Pixel bottomRight;
        Pixel topLeft;
        Pixel topRight;
};

#endif