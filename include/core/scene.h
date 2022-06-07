#ifndef _SCENE_H_
#define _SCENE_H_

#include "../../include/shapes/sphere.h"
#include "../../include/cameras/camera.h"
#include "../../include/core/background.h"
#include "../include/shapes/primitive.h"
#include <memory>

class Scene {
    private:
        Camera *camera;
        Background background;
        std::vector<Primitive*> objList;
    public:
        Scene(
            Camera *camera,
            Background background, 
            std::vector<Primitive*> objList
        );
        Scene();
        ~Scene();
        void render();
        void setCamera(Camera *camera);
        Camera* getCamera();
        Background getBackground();
        void setBackground(Background background);
        void setPrimitive(Primitive *primitive);
        std::vector<Primitive*> getPrimitive();
};

#endif
