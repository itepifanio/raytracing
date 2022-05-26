#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"
#include "vector3.h"
#include "material.h"

class Sphere : public Primitive {
    private:
        double r;
        Point center;
        Vector3 center_vector;
        Material * material;
    public:
        Sphere(double r, Point center);
        Sphere(double r, Vector3 center_vector, Material *material);
        ~Sphere();
        bool intersectP(const Ray &r) const;
};

#endif
