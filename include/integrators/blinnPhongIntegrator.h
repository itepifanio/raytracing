#ifndef _BLINN_PHONG_H_
#define _BLINN_PHONG_H_

#include "../materials/blinnPhongMaterial.h"
#include "./integrator.h"
class BlinnPhongIntegrator : public Integrator {
private:
    int depth;

public:
    BlinnPhongIntegrator();
    BlinnPhongIntegrator(int depth);
    ~BlinnPhongIntegrator();
    Vector3 Li(Ray &ray, Scene &scene, Vector3 color, int curr_depth);
};

#endif 