#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "../core/scene.h"
#include "../core/color.h"

class FlatIntegrator
{
public:
    ~FlatIntegrator() {};
    void render(const Scene &scene) = 0;
    Color24 Li(const Ray &ray, const Scene &scene, Color24 color) const = 0;
};

#endif
