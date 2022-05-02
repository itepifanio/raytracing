#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "pixel.h"
#include "vector3.h"
#include "point.h"
#include <string>
#include <vector>

class Background {
    private:
        std::string type;
        std::vector<std::vector<Pixel*>> image;
    public:
        Background(std::string type, Point points[4]);
        Point bottomLeft;
        Point bottomRight;
        Point topLeft;
        Point topRight;
        double interpolate(double x, double y);
        void interpolateAll();
        void toPPM(std::string filename);
        //Pixel operator[](int k) const;
        //Pixel &operator[](int k);
};

#endif