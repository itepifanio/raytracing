#ifndef _RAY_H_
#define _RAY_H_

#include "point.h"
#include "vector3.h"

class Ray
{
public:
    Ray(const Point &origin, const Vector3 &direction);
    Point getOrigin();
    Vector3 getDirection();
    Point operator()(double t);
private:
    Point origin;
    Vector3 direction;
};

#endif
