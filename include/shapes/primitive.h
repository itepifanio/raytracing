#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "../core/ray.h"
// #include "../include/materials/material.h"

class Primitive {
    public:
        //TODO::do the complicated function later
        //virtual bool intersect(const Ray &r, Surfel *sf) const = 0;
        virtual bool intersectP(Ray &r) = 0;
        virtual ~Primitive() {};
        
        //TODO::ommited for now. It may not be used right now.
        //virtual const Material *getMaterial(void) const = { return material };
        //std::shared_ptr<Material> material;
};

#endif
