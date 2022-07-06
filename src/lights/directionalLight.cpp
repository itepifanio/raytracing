#include "../../include/lights/directionalLight.h"
#include "../include/math/vectors.inl"

DirectionalLight::DirectionalLight(Vector3 l, Vector3 scale, Vector3 from, Vector3 to)
{
    this->l = l;
    this->scale = scale;
    this->from = from;
    this->to = to;
}

Color24 DirectionalLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
}