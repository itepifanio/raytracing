#include "../include/shapes/surfel.h"

Surfel::Surfel() {}

Surfel::Surfel(
    Point &p,
    Vector3 &n,
    Vector3 &wo,
    float time,
    Point &uv,
    Primitive *pri
)
{
    this->p = p;
    this->n = n;
    this->wo = wo;
    this->time = time;
    this->uv = uv;
    this->pri = pri;
}
