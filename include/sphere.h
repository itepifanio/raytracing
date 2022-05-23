#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"

class Sphere : public Primitive {
    private:
        int r;
        Point center;
    public:
        Sphere(int r, Point center);
        ~Sphere();
        bool intersectP(const Ray &r) const;
};

#endif
