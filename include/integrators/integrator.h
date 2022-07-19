#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "../core/scene.h"

class Integrator
{
public:
    Integrator() {}
    virtual ~Integrator() {};
    //virtual void render(const Scene &scene) = 0;
    virtual Vector3 Li(Ray &ray, Scene &scene, Vector3 color, int curr_depth = 1) = 0;
};

#endif
