#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "../core/scene.h"

class Integrator
{
public:
    Integrator() {}
    virtual ~Integrator() {};
    //virtual void render(const Scene &scene) = 0;
    virtual Color24 Li(Ray &ray, Scene &scene, Color24 color) = 0;
};

#endif
