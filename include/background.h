#ifndef _BACKGROUND_H_ 
#define _BACKGROUND_H_

#include "pixel.h"
#include "vector3.h"
#include <string>
#include <vector>

class Background {
    private:
        Pixel color;
        std::string type;
        Vector3 color_s;
        Vector3 bl;
        Vector3 br;
        Vector3 tl;
        Vector3 tr;

    public:
        Background();
        Background(std::string type, Vector3 color_s, Vector3 bl,
            Vector3 br, Vector3 tl, Vector3 tr
        );
        Pixel fromCoord(int i, int j);
        void setColor(Pixel pixel);
        Pixel getColor();
};

#endif