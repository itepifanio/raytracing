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
    auto p = hit.p.toVector3();
    std::cout << "hit.p::" << p[0] << " " << p[1] << " " << p[2] << std::endl;
    Vector3 direction = normalize(p - this->from);
    *wi = i;
    std::cout << "direction::" << direction[0] << " " << direction[1] << " " << direction[2] << std::endl;
    
    return direction.toColor24();
}