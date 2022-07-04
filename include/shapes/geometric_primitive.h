#ifndef _GEOMETRIC_PRIMITIVE_H_
#define _GEOMETRIC_PRIMITIVE_H_

#include "../../include/shapes/primitive.h"
#include "../../include/shapes/shape.h"
#include "../../include/core/ray.h"
#include "../../include/materials/material.h"

class Shape;

class GeometricPrimitive : public Primitive 
{
    private:
        Material *material;
        Shape *shape;
    public:
        GeometricPrimitive(Shape* s, Material* m) : shape{s}, material{m}{}
        ~GeometricPrimitive(){}
        bool intersectP(Ray &r);
        Material *getMaterial();
};

#endif
