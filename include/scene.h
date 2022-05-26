#ifndef _SCENE_H_
#define _SCENE_H_

#include "sphere.h"
#include "camera.h"
#include "background.h"
#include <memory>

class Scene {
    private:
        Camera *camera;
        Background background;
        std::vector<std::shared_ptr<Sphere>> objList;
    public:
        Scene(
            Camera *camera,
            Background background, 
            std::vector<std::shared_ptr<Sphere>> objList
        );
        ~Scene();
        void render();
        Camera* getCamera();
        Background getBackground();
        std::vector<std::shared_ptr<Sphere>> getPrimitive();
};

#endif
