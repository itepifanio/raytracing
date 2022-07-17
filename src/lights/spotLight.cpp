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

Vector3 SpotLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
    std::cout << "SPOTLIGHT" << std::endl;
    Vector3 black(0, 0, 0);
    Vector3 contactPoint = hit.p;
    Vector3 contactDirection = normalize(contactPoint - this->from);
    double angleCos = acos(this->to * contactDirection); // radians
    double angleDegree = angleCos*180/3.1415;

    Vector3 resultColor;

    if(angleDegree > this->cutoff) {
        resultColor = black;
    } else if(angleDegree > this->falloff) {
        resultColor = (this->i * pow(
            1 - (
                (angleDegree - this->falloff) / (this->cutoff - this->falloff)
            ),
            4
        ));
    } else {
        resultColor = this->i;
    }

    return resultColor;
}