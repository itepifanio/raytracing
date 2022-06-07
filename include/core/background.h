#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "./datatype/pixel.h"
#include "../datatype/vector3.h"
#include "../datatype/point.h"
#include <string>
#include <vector>

class Background {
    private:
        std::string type;
    public:
        int height;
        int width;
        Background();
        Background(int width, int height, std::string type, Point points[4]);
        Background(int width, int height, std::string type, Pixel color);
        Point bottomLeft;
        Point bottomRight;
        Point topLeft;
        Point topRight;
        Vector3 interpolate(double x, double y);
        Vector3 sample(double x, double y);
};

#endif