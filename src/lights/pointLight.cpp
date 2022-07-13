#include "../../include/lights/pointLight.h"
#include "../include/math/vectors.inl"

PointLight::PointLight(Vector3 &i, Vector3 scale, Vector3 from)
{
    this->i = i;
    this->scale = scale;
    this->from = from;
}

Vector3 PointLight::sampleLi(
    Surfel &hit, 
    Vector3 *wi,
    VisibilityTester *visibilityTester
)
{
    auto p = hit.p.toVector3();

    Vector3 l = normalize(this->from - p);
    Vector3 n = hit.n;
    Vector3 v = hit.wo;
    Vector3 h = normalize(v + l);
    
    double dotNl = std::max(0.0, n * l);
    BlinnPhongMaterial *bm = dynamic_cast<BlinnPhongMaterial*>(hit.pri->getMaterial());
    double dotNh = std::pow(std::max(0.0, n * h), bm->glossiness);

    Vector3 diffuse(
        bm->diffuse[0] * this->i[0] * dotNl,
        bm->diffuse[1] * this->i[1] * dotNl,
        bm->diffuse[2] * this->i[2] * dotNl
    );

    Vector3 specular(
        bm->ambient[0] * this->i[0] * dotNh,
        bm->ambient[1] * this->i[1] * dotNh,
        bm->ambient[2] * this->i[2] * dotNh
    );

    std::cout << (specular + diffuse)[0] << " ";
    std::cout << (specular + diffuse)[1] << " ";
    std::cout << (specular + diffuse)[2] << std::endl;

    return (specular + diffuse);
}