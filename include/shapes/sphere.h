#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../../include/shapes/surfel.h"
#include "../../include/shapes/shape.h"
#include "../datatype/vector3.h"
#include "../../include/materials/material.h"

class Sphere : public Shape {
    private:
        double r;
        Point center;
        Vector3 center_vector;
        Material * material;
    public:
        Sphere(double r, Point center);
        ~Sphere();
        double getR();
        bool intersectP(Ray &r);
        bool intersect(Ray& r, double * t_hit, Surfel * s);
};

#endif
