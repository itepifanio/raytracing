#include "../include/shapes/sphere.h"
#include "../include/math/formula.inl"

Sphere::Sphere(double r, Point center)
{
    this->r = r;
    this->center = center;
}


// Sphere::Sphere(double r, Vector3 center_vector, Material * material)
// {
//     this->r = r;
//     this->center_vector = center_vector;
//     this->material = material;
// }

Sphere::~Sphere()
{
}

bool Sphere::intersectP(Ray &r)
{
    // Ray ray = r; // handles cont Ray &r
    Point center = this->center;

    Vector3 originCenter = r.getOrigin().toVector3() - center.toVector3();
    
    double a = r.getDirection() * r.getDirection();
    double b = (2.0*r.getDirection())*originCenter;
    double c = (originCenter*originCenter) - (this->r*this->r);

    return deltaBhaskara(a, b, c) > 0;
}

double Sphere::getR()
{
    return this->r;
}
