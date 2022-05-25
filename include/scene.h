#ifndef _SCENE_H_
#define _SCENE_H_

#include "primitive.h"
#include <memory>

class Scene {
    private:
        Camera *camera;
        Background background;
        std::vector<std::shared_ptr<Primitive>> objList;
    public:
        Scene(
            Camera *camera,
            Background background, 
            std::vector< std::shared_ptr<Primitive>> objList
        );
        ~Scene();
        void render();
};

#endif
