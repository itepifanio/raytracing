#include "scene.h"
#include "camera.h"
#include "background.h"

Scene::Scene(
    Camera *camera, 
    Background background, 
    std::vector<Primitive*> objList
)
{
    this->camera = camera;
    this->background = background;
    this->objList = objList;
}

Scene::~Scene() {}

Camera* Scene::getCamera()
{
    return this->camera;
}

Background Scene::getBackground()
{
    return this->background;
}

std::vector<Primitive*> Scene::getPrimitive()
{
    return this->objList;
}

void Scene::render()
{

}
