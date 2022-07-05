#include "../../include/shapes/geometric_primitive.h"

bool GeometricPrimitive::intersectP(Ray &r)
{
    return this->shape->intersectP(r);
}

Material *GeometricPrimitive::getMaterial()
{
    return this->material;
}

bool GeometricPrimitive::intersect(Ray &r, Surfel *sf)
{
    double hit;

    if(this->shape->intersect(r, &hit, sf))
    {
        if(hit > 0.0){
            sf->pri = this;
            
            return true;
        }
    }

    return true;
}
