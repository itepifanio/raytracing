#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "../core/scene.h"

class Integrator
{
public:
    virtual ~Integrator();
    virtual void render(const Scene &scene) = 0;
};

#endif
