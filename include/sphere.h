#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"

class Sphere : public Primitive {
    private:
        int r;
    public:
        Sphere(int r);
        ~Sphere();
        bool intersectP(const Ray &r) const;
};

#endif
