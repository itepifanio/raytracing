#ifndef _FLATINTEGRATOR_H_
#define _FLATINTEGRATOR_H_

#include "./integrator.h"
#include "../core/scene.h"
#include "../../include/datatype/color24.h"
#include "../../include/materials/flatMaterial.h"

class FlatIntegrator : public Integrator
{
public:
    FlatIntegrator();
    ~FlatIntegrator() {};
    //void render(const Scene &scene) = 0;
    Vector3 Li(Ray &ray, Scene &scene, Vector3 color, int depth = 1);
};

#endif
