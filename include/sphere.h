#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "surfel.h"
#include "primitive.h"

class Sphere : public Primitive {
    private:
        int r;
        Point center;
    public:
        Sphere(int r, Point center);
        ~Sphere();
        bool intersectP(const Ray &r) const;
        bool intersect(Ray &r, Surfel *sf);
};

#endif
