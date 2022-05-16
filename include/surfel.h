#ifndef _SURFEL_H_
#define _SURFEL_H_

#include "point.h"
#include "primitive.h"

class Surfel {
    private:
        Point p; // contact point
        Vector3 n; // surface normal
        Vector3 wo; // outgoing direction of light
        float time; // time of contact
        Point uv; // parametric coordinate (u, v)
        Primitive *pri; // Pointer to the primitive
    public:
        Surfel(
            const Point &p,
            const Vector &n, 
            const Vector &wo, 
            float time,
            const Point& uv, 
            const Primitive *pri = nullptr
        );
};

#endif
