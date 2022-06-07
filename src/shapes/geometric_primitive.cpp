#include "../../include/shapes/geometric_primitive.h"

bool GeometricPrimitive::intersectP(Ray &r)
{
    return this->shape->intersectP(r);
}

Material *GeometricPrimitive::getMaterial()
{
    return this->material;
}
