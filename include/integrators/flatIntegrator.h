#ifndef _FLATINTEGRATOR_H_
#define _FLATINTEGRATOR_H_

#include "./integrator.h"
#include "../core/scene.h"
#include "../../include/datatype/color24.h"

class FlatIntegrator : public Integrator
{
public:
    ~FlatIntegrator() {};
    //void render(const Scene &scene) = 0;
    Color24 Li(Ray &ray, Scene &scene, Color24 color);
};

#endif
