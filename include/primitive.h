#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "ray.h"
// #include "material.h"

class Primitive {
    public:
        //TODO::do the complicated function later
        virtual bool intersect(const Ray &r, Surfel *sf) const = 0;
        virtual bool intersectP(const Ray &r) const = 0;
        virtual ~Primitive() {};
        
        //TODO::ommited for now. It may not be used right now.
        //virtual const Material *getMaterial(void) const = { return material };
        //std::shared_ptr<Material> material;
};

#endif
