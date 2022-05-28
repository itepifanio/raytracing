#include "../include/materials/material.h"
#include "../include/materials/flatMaterial.h"

Material::Material(std::string type, Pixel color)
{
    this->type = type;
    this->color = color;
}

Material::~Material() {}

Material* Material::make(std::string type, Pixel color) 
{
    if(type.compare("flat") == 0)
    {
        return new FlatMaterial(type, color);
    }

    std::string materialException = "Material type " + type + " is not configured.";
    throw std::invalid_argument(materialException);
}

std::string Material::getType()
{
    return this->type;
}

Pixel Material::getColor()
{
    return this->color;
}