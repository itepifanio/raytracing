#include "../../include/integrators/blinnPhongIntegrator.h"
#include <optional>

BlinnPhongIntegrator::BlinnPhongIntegrator()
{
}

BlinnPhongIntegrator::~BlinnPhongIntegrator()
{
}

// TODO::how to find it's the closest?
std::optional<Primitive *> getClosest(std::vector<Primitive *> primitives, Ray ray)
{
    for (auto primitive : primitives)
    {
        if (primitive->intersectP(ray))
        {
            return primitive;
        }
    }

    return std::nullopt;
}

Color24 BlinnPhongIntegrator::Li(Ray &ray, Scene &scene, Color24 color)
{
    // TODO::implement

    // [0] FIRST STEP TO INITIATE `L` WITH THE COLOR VALUE TO
    // BE RETURNED.
    Color24 l = color;

    // [1] FIND CLOSEST RAY INTERSECTION OR RETURN BACKGROUND
    // RADIANCE
    std::optional<Primitive *> closest = getClosest(scene.getPrimitive(), ray);

    if (closest)
    {
        // [2] SPECIAL SITUATION: IF THE RAY HITS THE SURFACE FROM
        // "BEHIND" (INSIDE), WE DO NOT COLOR.
        // TODO::check how to calculate if it's behind

        // [3] GET THE MATERIAL ASSOCIATED WITH THE HIT SURFACE
        BlinnPhongMaterial *bpm = dynamic_cast<BlinnPhongMaterial *>((*closest)->getMaterial());

        // [4] INITIALIZE COMMON VARIABLES FOR BLINNPHONG INTEGRATOR
        // (COEFFICIENTS AND VECTORS L, N, V, ETC.)
        // [5] CALCULATE & ADD CONTRIBUTION FROM EACH LIGHT SOURCE
        // [6] ADD AMBIENT CONTRIBUTION HERE (if there is any).
        // [7] ADD MIRROR REFLECTION CONTRIBUTION
    }

    return l;
}