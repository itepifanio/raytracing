#ifndef _SURFEL_H_
#define _SURFEL_H_

#include "../datatype/point.h"
#include "primitive.h"

// TODO::add const back
class Surfel
{
private:
    Point p;        // contact point
    Vector3 n;      // surface normal
    Vector3 wo;     // outgoing direction of light
    float time;     // time of contact
    Point uv;       // parametric coordinate (u, v)
    Primitive *pri; // Pointer to the primitive
public:
    Surfel();
    Surfel(
        Point &p,
        Vector3 &n,
        Vector3 &wo,
        float time,
        Point &uv,
        Primitive *pri
    );
};

#endif
