#include "../../include/integrators/flatIntegrator.h"
#include "../../include/integrators/integrator.h"

/*
void FlatIntegrator::render(const Scene &scene)
{ 
}
*/

FlatIntegrator::FlatIntegrator()
{

}

Vector3 FlatIntegrator::Li(Ray &ray, Scene &scene, Vector3 color)
{
    Vector3 result = color;
    //std::cout << "initial color is " << color.r << " " << color.g << " " << color.b << std::endl; 
    std::vector<Primitive*> objects = scene.getPrimitive();

    for (int i = 0; i < (int)objects.size(); i++)
    {
        // if a geometric primitive
        if(dynamic_cast<GeometricPrimitive*>(objects[i]) != nullptr) {
            GeometricPrimitive *primitive = dynamic_cast<GeometricPrimitive*>(objects[i]);

            if(objects[i]->intersectP(ray)) {
                // and the material is flat
                if(dynamic_cast<FlatMaterial*>(primitive->getMaterial())){
                    FlatMaterial *flatMaterial = dynamic_cast<FlatMaterial*>(primitive->getMaterial());
                    result = flatMaterial->getColor().toVector3();
                }
            }
        }
    }

    return result;
}