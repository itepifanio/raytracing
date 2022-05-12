#include "../include/ray.h"

Ray::Ray(const Point &origin, const Vector3 &direction)
{
    this->origin = origin;
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

Point Ray::operator()(double t)
{
    Vector3 origin(this->origin.i, this->origin.j, this->origin.value);
    Vector3 result = origin + t*this->direction;

    return result.toPoint();
}
