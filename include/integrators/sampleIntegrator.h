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
    SampleIntegrator(std::shared_ptr<const Camera> cam) : camera{cam};
    virtual Color24 Li(const Ray &ray, const Scene &scene, Color24 color) const = 0;
    virtual ~Integrator();
    void render(const Scene &scene)
    {
        auto w = this->camera->film->getXRes();
        auto h = this->camera->film->getYRes();

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                Ray ray = camera->generate_ray(i, j);
                auto backgroundColor = scene->background->sample(
                    double(i) / double(h),
                    double(j) / double(w)
                );

                Vector3 pixelColor = this->Li(ray, scene, backgroundColor);

                camera->film->addSample(i, j, pixelColor.toColor24());
            }
        }

        camera->film->toPPM();
    }
    // virtual void preprocess(const Scene &scene);
};

#endif
