#ifndef _SHAPE_
#define _SHAPE_

#include <memory>
#include "./geometric_primitive.h"
#include "../materials/material.h"
#include "../core/ray.h"
#include "../../include/shapes/surfel.h"
#include "../../include/shapes/geometric_primitive.h"

class GeometricPrimitive;

class Shape {
    public:
    // bool flip_normals;

    // Shape(bool flip_n);
    //virtual Bounds3 world_bounds() = 0;
    GeometricPrimitive *primitive = nullptr;
    virtual bool intersect(Ray& r, double * t_hit, Surfel * s) = 0;
    virtual bool intersectP(Ray & r) = 0;
    //virtual void printCenter() = 0;
};

#endif