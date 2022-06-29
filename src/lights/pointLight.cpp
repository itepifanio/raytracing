#include "../../include/lights/pointLight.h"

PointLight::PointLight(Vector3 &i, Vector3 scale, Vector3 from)
{
    this->i = i;
    this->scale = scale;
    this->from = from;
}

Color24 PointLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester visibilityTester
)
{
    // TODO::implement
    Color24 color(255, 255, 255);

    return color;
}