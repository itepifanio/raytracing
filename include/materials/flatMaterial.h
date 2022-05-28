#ifndef _FLAT_MATERIAL_H_
#define _FLAT_MATERIAL_H_

#include "../include/materials/material.h"
#include "./datatype/pixel.h"

class FlatMaterial : public Material {
    public:
        FlatMaterial(std::string type, Pixel color);
};

#endif
