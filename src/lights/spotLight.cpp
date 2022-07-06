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
    VisibilityTester *visibilityTester
)
{
    Color24 black(0, 0, 0);
    Vector3 contactPoint = hit.p.toVector3();
    Vector3 contactDirection = normalize(contactPoint - this->from);
    double angleCos = acos(this->to * contactDirection); // radians
    double angleDegree = angleCos*180/3.1415;

    Color24 resultColor;

    if(angleDegree > this->cutoff) {
        resultColor = black;
    } else if(angleDegree > this->falloff) {
        resultColor = (this->i * pow(
            1 - (
                (angleDegree - this->falloff) / (this->cutoff - this->falloff)
            ),
            4
        )).toColor24();
    } else {
        resultColor = this->i.toColor24();
    }

    return resultColor;
}