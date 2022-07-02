#include "../../include/integrators/blinnPhongIntegrator.h"

BlinnPhongIntegrator::BlinnPhongIntegrator()
{
}

BlinnPhongIntegrator::~BlinnPhongIntegrator()
{
}

Color24 BlinnPhongIntegrator::Li(Ray &ray, Scene &scene, Color24 color)
{
    // TODO::implement

    // [0] FIRST STEP TO INITIATE `L` WITH THE COLOR VALUE TO
    // BE RETURNED.
    // [1] FIND CLOSEST RAY INTERSECTION OR RETURN BACKGROUND
    // RADIANCE
    // [2] SPECIAL SITUATION: IF THE RAY HITS THE SURFACE FROM
    // "BEHIND" (INSIDE), WE DO NOT COLOR.
    // [3] GET THE MATERIAL ASSOCIATED WITH THE HIT SURFACE
    // [4] INITIALIZE COMMON VARIABLES FOR BLINNPHONG INTEGRATOR
    // (COEFFICIENTS AND VECTORS L, N, V, ETC.)
    // [5] CALCULATE & ADD CONTRIBUTION FROM EACH LIGHT SOURCE
    // [6] ADD AMBIENT CONTRIBUTION HERE (if there is any).
    // [7] ADD MIRROR REFLECTION CONTRIBUTION
    Color24 c(255, 255, 255);

    return c;
}