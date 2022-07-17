#include "../include/core/ray.h"

Ray::Ray(const Point &origin, const Vector3 &direction)
{
    //std::cout << "Before origin" << std::endl;
    this->origin = origin;
    //std::cout << "After origin" << std::endl;
    this->direction = direction;
}

Point Ray::getOrigin()
{
    return this->origin;
}

Vector3 Ray::getDirection()
{
    return this->direction;
}

Vector3 Ray::operator()(double t)
{
    Vector3 origin = this->origin.toVector3();
    Vector3 result = origin + t * this->direction;

    return result;
}
