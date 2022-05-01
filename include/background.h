#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "pixel.h"
#include "vector3.h"
#include <string>
#include <vector>

class Background {
    private:
        std::string type;
        std::vector<std::vector<Pixel*>> image;
    public:
        Background(std::string type, Pixel corners[4]);
        Pixel bottomLeft;
        Pixel bottomRight;
        Pixel topLeft;
        Pixel topRight;
        Pixel interpolate(double x, double y);
        void interpolateAll();
        void toPPM(std::string filename);
        //Pixel operator[](int k) const;
        //Pixel &operator[](int k);
};

#endif