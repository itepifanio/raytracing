#include "../../include/lights/spotLight.h"
#include "../include/math/vectors.inl"

SpotLight::SpotLight(
    Vector3 i, 
    Vector3 scale, 
    Vector3 from, 
    Vector3 to, 
    double cutoff,
    double falloff
) {
    this->i = i;
    this->scale = scale;
    this->from = from;
    this->to = to;
    this->cutoff = cutoff;
    this->falloff = falloff;
}

Color24 SpotLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester visibilityTester
)
{
    // Vector3 contactPoint = hit.p.toVector3();
    // Vector3 l = this->from - contactPoint;
    // l = normalize(l);
    // *wi = i;

    // return l.toColor24();
}