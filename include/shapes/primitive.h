#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "../core/ray.h"
#include "../../include/shapes/shape.h"
#include "../materials/material.h"

class Primitive {
    public:
        //TODO::do the complicated function later
        //virtual bool intersect(const Ray &r, Surfel *sf) const = 0;
        virtual bool intersectP(Ray &r) = 0;
        virtual ~Primitive() {};
        virtual Material *getMaterial() = 0;
        //std::shared_ptr<Material> material;
};

#endif
