#include "../../include/lights/pointLight.h"
#include "../include/math/vectors.inl"

PointLight::PointLight(Vector3 &i, Vector3 scale, Vector3 from)
{
    this->i = i;
    this->scale = scale;
    this->from = from;
}

Color24 PointLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
}