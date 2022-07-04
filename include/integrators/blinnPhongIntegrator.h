#ifndef _BLINN_PHONG_H_
#define _BLINN_PHONG_H_

#include "../materials/blinnPhongMaterial.h"
#include "./integrator.h"

class BlinnPhongIntegrator : public Integrator {
public:
    BlinnPhongIntegrator();
    ~BlinnPhongIntegrator();
    Color24 Li(Ray &ray, Scene &scene, Color24 color);
};

#endif 