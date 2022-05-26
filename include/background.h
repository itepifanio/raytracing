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
        
        int height;
        int width;
    public:
        std::vector<std::vector<Pixel*>> image;
        Background();
        Background(int width, int height, std::string type, Point points[4]);
        Background(int width, int height, std::string type, Pixel color);
        Point bottomLeft;
        Point bottomRight;
        Point topLeft;
        Point topRight;
        Vector3 interpolate(double x, double y);
        void interpolateAll();
        void toPPM(std::string filename);
        std::vector<Pixel*> operator[](int k) const;
};

#endif