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
