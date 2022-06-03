#ifndef _SAMPLE_INTEGRATOR_H_
#define _SAMPLE_INTEGRATOR_H_

#include "integrator.h"
#include "../cameras/camera.h"
#include "../datatype/color24.h";

class SampleIntegrator : public Integrator
{
    protected:
        std::shared_ptr<const Camera> camera;
    public:
        SampleIntegrator(std::shared_ptr<const Camera> cam) : camera { cam };
        virtual Color24 Li(const Ray &ray, const Scene &scene) const = 0;
        virtual ~Integrator();
        virtual void render(const Scene &scene);
        virtual void preprocess(const Scene &scene);
};

#endif
