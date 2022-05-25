#ifndef _FLAT_MATERIAL_H_
#define _FLAT_MATERIAL_H_

#include "material.h"
#include "pixel.h"

class FlatMaterial : public Material {
    public:
        FlatMaterial(std::string type, Pixel color);
};

#endif
