#include "../include/flatMaterial.h"
#include "../include/material.h"
#include "../include/pixel.h"

FlatMaterial::FlatMaterial(
    std::string type, Pixel color
) : Material(type, color) {}
