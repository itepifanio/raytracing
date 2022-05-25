#include "scene.h"
#include "camera.h"
#include "background.h"

Scene::Scene(
    Camera *camera, 
    Background background, 
    std::vector< std::shared_ptr<Primitive>> objList
)
{
    this->camera = camera;
    this->background = background;
    this->objList = objList;
}

Scene::~Scene() {}

void Scene::render()
{

}
