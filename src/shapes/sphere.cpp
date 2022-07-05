#include "../include/shapes/sphere.h"
#include "../include/math/formula.inl"

Sphere::Sphere(double r, Point center)
{
    this->r = r;
    this->center = center;
}

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

bool Sphere::intersect(Ray& r, double * t_hit, Surfel * s)
{
    Point center = this->center;

    Vector3 originCenter = r.getOrigin().toVector3() - center.toVector3();
    
    double a = r.getDirection() * r.getDirection();
    double b = (2.0*r.getDirection())*originCenter;
    double c = (originCenter*originCenter) - (this->r*this->r);

    std::pair<double, double> roots = bhaskara(a, b, c);
    double rmin = std::get<0>(roots);
    double rmax = std::get<1>(roots);

    if(rmin < rmax) {
        *t_hit = rmin;
        s->p = r(rmin);
        s->n = s->p.toVector3() - center.toVector3();

        return true;
    } else {
       *t_hit = rmax;
        s->p = r(rmax);
        s->n = s->p.toVector3() - center.toVector3(); 

        return true;
    }    

    return false;
}
