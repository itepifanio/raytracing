#include "../../include/integrators/blinnPhongIntegrator.h"
#include "../include/math/vectors.inl"
#include <optional>

BlinnPhongIntegrator::BlinnPhongIntegrator()
{
}

BlinnPhongIntegrator::BlinnPhongIntegrator(int depth)
{
    this->depth = depth;
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

Vector3 BlinnPhongIntegrator::Li(Ray &ray, Scene &scene, Vector3 color, int curr_depth)
{
    //std::cout << "BlinnPhongIntegrator::Li" << std::endl;
    Surfel sf;

    // [0] FIRST STEP TO INITIATE `L` WITH THE COLOR VALUE TO
    // BE RETURNED.
    Vector3 l = color;

    // [1] FIND CLOSEST RAY INTERSECTION OR RETURN BACKGROUND
    // RADIANCE
    Vector3 wi;
    VisibilityTester visibilityTester;
    const float low_float = 1e-3;
    for (int k = 0; k < (int)scene.getPrimitive().size(); k++)
    {
        //std::cout << "primitive " << k << std::endl;
        if (scene.getPrimitive()[k]->intersect(ray, &sf))
        {
            l = Vector3(0, 0, 0);
            //std::cout << "get material" << sf.pri->getMaterial() << std::endl;
            BlinnPhongMaterial *bm = dynamic_cast<BlinnPhongMaterial*>(sf.pri->getMaterial());
            //std::cout << "after *bm " << std::endl;
            for (int j = 0; j < (int)scene.getLights().size(); j++)
            {
                l = l + (scene.getLights()[j]->sampleLi(
                    sf,
                    &wi,
                    &visibilityTester
                )*100);

                //std::cout << "scene.getLights().size() = " << scene.getLights().size() << std::endl;
            }
            if(curr_depth < this->depth) {
                Vector3 newDir = normalize(ray.getDirection() + (sf.n * (-2 * Vector3::dot_vector3(ray.getDirection(), sf.n))));
                Ray r = Ray((sf.p.toVector3() + newDir * low_float).toPoint(), newDir);
                Vector3 v = this->Li(r, scene, color, curr_depth + 1);
                v.vector[0] = v.vector[0] * bm->mirror[0];
                v.vector[1] = v.vector[1] * bm->mirror[1];
                v.vector[2] = v.vector[2] * bm->mirror[2];

                l = l + v;
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
    //std::cout << "BlinnPhongIntegrator::L(" << l.r << ", " << l.g << ", " << l.b << ")" << std::endl;
    return l;
}