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
    //std::cout << "BlinnPhongIntegrator::Li" << std::endl;
    Surfel sf;

    // [0] FIRST STEP TO INITIATE `L` WITH THE COLOR VALUE TO
    // BE RETURNED.
    Color24 l = color;

    // [1] FIND CLOSEST RAY INTERSECTION OR RETURN BACKGROUND
    // RADIANCE
    Vector3 wi;
    VisibilityTester visibilityTester;
    for (int k = 0; k < (int)scene.getPrimitive().size(); k++)
    {
        std::cout << "primitive " << k << std::endl;
        if (scene.getPrimitive()[k]->intersect(ray, &sf))
        {
            //std::cout << "intersect " << k << std::endl;
            //std::cout << "get material" << sf.pri->getMaterial() << std::endl;
            BlinnPhongMaterial *bm = dynamic_cast<BlinnPhongMaterial*>(sf.pri->getMaterial());
            //std::cout << "after *bm " << std::endl;
            for (int j = 0; j < (int)scene.getLights().size(); j++)
            {
                //std::cout << "getting lights " << j << std::endl;
                l = (l.toVector3() + scene.getLights()[j]->sampleLi(
                    sf,
                    &wi, 
                    &visibilityTester
                ).toVector3()).toColor24();

                //std::cout << "scene.getLights().size() = " << scene.getLights().size() << std::endl;
            }
        }

        //std::cout << "scene.getPrimitive().size() = " << scene.getPrimitive().size() << std::endl;
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