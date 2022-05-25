#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "pixel.h"
#include <string>
#include <iostream>

class Material {
    private: 
        std::string type;
        Pixel color;
    public:
        Material(std::string type, Pixel color);
        virtual ~Material();
        static Material* make(std::string type, Pixel color);
};

#endif
