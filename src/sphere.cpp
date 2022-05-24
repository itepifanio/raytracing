#include "../include/sphere.h"
#include "../include/math/formula.inl"

Sphere::Sphere(double r, Point center)
{
    this->r = r;
    this->center = center;
}


Sphere::Sphere(double r, Vector3 center_vector)
{
    this->r = r;
    this->center_vector = center_vector;
}

Sphere::~Sphere()
{
}

bool Sphere::intersectP(const Ray &r) const
{
    Ray ray = r; // handles cont Ray &r
    Point center = this->center;

    Vector3 originCenter = ray.getOrigin().toVector3() - center.toVector3();
    
    double a = ray.getDirection() * ray.getDirection();
    double b = 2.0*(originCenter * ray.getDirection());
    double c = (originCenter*originCenter) - (this->r*this->r);

    return deltaBhaskara(a, b, c) > 0;
}

