#include "../include/core/scene.h"
#include "../include/cameras/camera.h"
#include "../include/core/background.h"
#include "../include/datatype/vector3.h"

Scene::Scene(
    Camera *camera,
    Background background,
    std::vector<Primitive *> objList)
{
    this->camera = camera;
    this->background = background;
    this->objList = objList;
}

Scene::Scene() {}

Scene::~Scene() {}

Camera *Scene::getCamera()
{
    return this->camera;
}

void Scene::setCamera(Camera *camera)
{
    this->camera = camera;
}

Background Scene::getBackground()
{
    return this->background;
}

void Scene::setBackground(Background background)
{
    this->background = background;
}

void Scene::setPrimitive(Primitive *primitive)
{
    this->objList.push_back(dynamic_cast<Primitive*>(primitive));
}

std::vector<Primitive *> Scene::getPrimitive()
{
    return this->objList;
}

std::vector<Light*> Scene::getLights()
{
    return this->lightList;
}


void Scene::setLights(Light *light)
{
    this->lightList.push_back(light);
}

// TODO::Probably not necessary anymore
void Scene::render()
{
    auto w = this->camera->film.getXRes();
    auto h = this->camera->film.getYRes();
    Color24 red(255, 0, 0);
    bool intersect = false;

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            intersect = false;
            Ray ray = this->camera->generate_ray(i, j);

            for (Primitive* p : this->objList)
            {
                if (p->intersectP(ray)){
                    this->camera->film.addSample(i, j, red);
                    intersect = true;
                }
            }

            if (!intersect)
            {
                Vector3 v = this->background.interpolate(
                    double(i) / double(this->background.width),
                    double(j) / double(this->background.height)
                );
                this->camera->film.addSample(i, j, v.toColor24());
            }
        }
    }

    this->camera->film.toPPM(this->camera->film.getFilenameOutput());
}
