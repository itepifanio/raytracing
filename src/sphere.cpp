#include "../include/sphere.h"
#include "../include/math/vectors.inl"
#include "../include/math/formula.inl"

Sphere::Sphere(int r, Point center)
{
    this->r = r;
    this->center = center;
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(Ray &r, Surfel *sf)
{
    Vector3 originCenter = r.getOrigin() - this->center;
    double a = ray.getDirection() * ray.getDirection();
    double b = 2.0*(originCenter * ray.getDirection());
    double c = (originCenter*originCenter) - (this->r*this->r);
    double delta = deltaBhaskara(a, b, c);
    std::pair<double, double> bhaskara = bhaskara(a, b, c);
    double max = std::get<0>(bhaskara);
    double min = std::get<1>(bhaskara);

    if(std::get<1> > std::get<0>) {
        max = std::get<1>;
        min = std::get<0>;
    }

    if(delta > 0){
        Point contact;

        if(max > 0) {
            contact = (r.getOrigin().toVector3() + r.getDirection() * max).toPoint();
        } else if(min > 0) {
            contact = (r.getOrigin().toVector3() + r.getDirection() * min).toPoint();
        } else {
            return false;
        }

        Vector3 normal = normalize(contact - this->center);

        // TODO::how to get the primitives?
        //sf = new Surfel(contact, normal, r.getDirection() * (-1), max));
        
        return true;
    }
        
    return false;
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

