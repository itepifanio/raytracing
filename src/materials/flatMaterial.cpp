#include "../../include/materials/flatMaterial.h"
#include "../../include/materials/material.h"
#include "../../include/datatype/color24.h"

FlatMaterial::FlatMaterial(Color24 color) : Material()
{
    this->color = color;
}

Color24 FlatMaterial::getColor()
{
    return this->color;
}
