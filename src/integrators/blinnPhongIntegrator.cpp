#include "../../include/integrators/blinnPhongIntegrator.h"
#include "../include/math/vectors.inl"
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
    Surfel sf;

    // [0] FIRST STEP TO INITIATE `L` WITH THE COLOR VALUE TO
    // BE RETURNED.
    Color24 l = color;

    // [1] FIND CLOSEST RAY INTERSECTION OR RETURN BACKGROUND
    // RADIANCE
    // std::optional<Primitive *> closest = getClosest(scene.getPrimitive(), ray);
    for (int i = 0; i < (int)scene.getPrimitive().size(); i++)
    {
        if (scene.getPrimitive()[i]->intersect(ray, &sf))
        {
            Vector3 c;
            Vector3 wi;
            Point origin = ray.getOrigin();
            Vector3 *rayOrigin = new Vector3(origin.i, origin.j, origin.value);
            BlinnPhongMaterial *bm = dynamic_cast<BlinnPhongMaterial*>(sf.pri->getMaterial());
            Vector3 n = normalize(sf.n);

            for (int j = 0; j < (int)scene.getLights().size(); j++)
            {
                VisibilityTester *visibilityTester;

                scene.getLights()[i]->sampleLi(
                    sf, 
                    rayOrigin, 
                    visibilityTester
                );
            }
        }
    }

    /*
    if (closest)
    {
        // [2] SPECIAL SITUATION: IF THE RAY HITS THE SURFACE FROM
        // "BEHIND" (INSIDE), WE DO NOT COLOR.
        // TODO::check how to calculate if it's behind

        // [3] GET THE MATERIAL ASSOCIATED WITH THE HIT SURFACE
        BlinnPhongMaterial *bpm = dynamic_cast<BlinnPhongMaterial *>((*closest)->getMaterial());

        // [4] INITIALIZE COMMON VARIABLES FOR BLINNPHONG INTEGRATOR
        // (COEFFICIENTS AND VECTORS L, N, V, ETC.)

        //!!!!!!!!!! TODO::WE NEED TO CREATE THE intersect() FUNCTION THAT INSTANCIATES THE SURFEL!!!!!!!!!!!!
        Surfel *surfel;

        // [5] CALCULATE & ADD CONTRIBUTION FROM EACH LIGHT SOURCE
        // [6] ADD AMBIENT CONTRIBUTION HERE (if there is any).
        // [7] ADD MIRROR REFLECTION CONTRIBUTION
    }
    */

    return l;
}