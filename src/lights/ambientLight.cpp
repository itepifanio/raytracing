#include "../../include/lights/ambientLight.h"
#include "../include/math/vectors.inl"

AmbientLight::AmbientLight(Vector3 l)
{
    this->l = l;
}

Color24 AmbientLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
    // Vector3 contactPoint = hit.p.toVector3();
    // Vector3 l = this->from - contactPoint;
    // l = normalize(l);
    // *wi = i;

    // return l.toColor24();
}