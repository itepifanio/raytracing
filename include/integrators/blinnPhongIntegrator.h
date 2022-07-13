#ifndef _BLINN_PHONG_H_
#define _BLINN_PHONG_H_

#include "../materials/blinnPhongMaterial.h"
#include "./integrator.h"

class BlinnPhongIntegrator : public Integrator {
public:
    BlinnPhongIntegrator();
    ~BlinnPhongIntegrator();
    Vector3 Li(Ray &ray, Scene &scene, Vector3 color);
};

#endif 