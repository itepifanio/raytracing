#include "../../include/materials/blinnPhongMaterial.h"

BlinnPhongMaterial::BlinnPhongMaterial(
    std::string name,
    Vector3 ambient,
    Vector3 diffuse,
    Vector3 specular,
    double glossiness
) : Material()
{
    this->name = name;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->glossiness = glossiness;
}

void BlinnPhongMaterial::setMirror(Vector3 mirror)
{
    this->mirror = mirror;
}
