#ifndef _PERSPECTIVE_CAMERA_H_
#define _PERSPECTIVE_CAMERA_H_

#include "camera.h"
#include "ray.h"

class PerspectiveCamera : public Camera {
    public: 
        PerspectiveCamera(
            std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        Ray generate_ray(int x, int y);
};

#endif
