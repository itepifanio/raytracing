#include "../../include/shapes/sphere.h"
#include "../../include/math/formula.inl"
#include "../../include/math/vectors.inl"

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

    double delta = deltaBhaskara(a, b, c);
    double time = -1.0;
    
    if(delta > 0) {
        std::pair<double, double> roots = bhaskara(a, b, c);
        double r1 = std::get<0>(roots);
        double r2 = std::get<1>(roots);

        time = std::min(r1, r2);
    } else {
        time = -b/(2*a);
    }

    s->pri = this->primitive;
    s->time = time;
    s->wo = r.getOrigin().toVector3() - r.getDirection();
    s->p = r(time);
    s->n = normalize(s->p - center.toVector3());
    
    return delta > 0;
}
