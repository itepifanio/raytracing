#ifndef _GEOMETRIC_PRIMITIVE_H_
#define _GEOMETRIC_PRIMITIVE_H_

#include "./primitive.h"
#include "../../include/shapes/shape.h"
#include "../materials/material.h"

class Shape;

class GeometricPrimitive {
    public:
        Material *material;
        Shape *shape;
};

#endif
