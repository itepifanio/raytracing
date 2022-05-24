#include "../include/material.h"
#include "../include/flatMaterial.h"

Material::Material(std::string type, Pixel color)
{
    this->type = type;
    this->color = color;
}

Material::~Material() {}

Material* Material::make(std::string type, Pixel color) 
{
    if(strcmp(type, "flat") == 0)
    {
        return new FlatMaterial(type, color);
    }

    std::string materialException = "Material type " + type + " is not configured.";
    throw std::invalid_argument(materialException);
}