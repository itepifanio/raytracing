#include "scene.h"
#include "camera.h"
#include "background.h"

Scene::Scene(
    Camera *camera,
    Background background,
    std::vector<Primitive *> objList)
{
    this->camera = camera;
    this->background = background;
    this->objList = objList;
}

Scene::~Scene() {}

Camera *Scene::getCamera()
{
    return this->camera;
}

Background Scene::getBackground()
{
    return this->background;
}

std::vector<Primitive *> Scene::getPrimitive()
{
    return this->objList;
}

void Scene::render()
{
    auto w = this->camera->film.getXRes();
    auto h = this->camera->film.getYRes();

    Pixel *red = new Pixel(255, 0, 0);

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            Ray ray = this->camera->generate_ray(i, j);

            for (const Primitive* p : this->objList)
            {
                if (p->intersectP(ray)){
                    std::cout << "Intersect!!!!!" << std::endl;
                    this->background[i][j] = red;
                }
            }
        }
    }

    this->background.toPPM("scene.ppm");
}
