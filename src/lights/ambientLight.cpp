#include "../../include/lights/ambientLight.h"
// #include "../include/math/vectors.inl"

AmbientLight::AmbientLight(Vector3 l)
{
    this->l = l;
}

Vector3 AmbientLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
    BlinnPhongMaterial *bm = dynamic_cast<BlinnPhongMaterial*>(hit.pri->getMaterial());
    Vector3 ambient(
        bm->ambient[0] * this->l[0],
        bm->ambient[1] * this->l[1],
        bm->ambient[2] * this->l[2]
    );

    return ambient;
}