#include "../../include/integrators/flatIntegrator.h"
#include "../../include/integrators/integrator.h"

/*
void FlatIntegrator::render(const Scene &scene)
{ 
}
*/

Color24 FlatIntegrator::Li(Ray &ray, Scene &scene, Color24 color)
{
    Color24 result = color;
    std::vector<Primitive*> objects = scene.getPrimitive();

    for (int i = 0; i < (int)objects.size(); i++)
    {
        if(objects[i]->intersectP(ray)) {
            // TODO::add the geometric primitive that contains a material to change the color here
        }
    }

    return result;
}