#include "../include/materials/flatMaterial.h"
#include "../include/materials/material.h"
#include "../include/datatype/pixel.h"

FlatMaterial::FlatMaterial(
    std::string type, Pixel color
) : Material(type, color) {}
