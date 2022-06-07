#ifndef _FLAT_MATERIAL_H_
#define _FLAT_MATERIAL_H_

#include "../../include/materials/material.h"
#include "../../include/datatype/color24.h"

class FlatMaterial : public Material {
    private:
        Color24 color;
    public:
        FlatMaterial(Color24 color);
        Color24 getColor();
};

#endif
