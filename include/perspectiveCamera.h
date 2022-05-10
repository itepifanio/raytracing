#ifndef _PERSPECTIVE_CAMERA_H_
#define _PERSPECTIVE_CAMERA_H_

#include "camera.h"
#include "ray.h"

class PerspectiveCamera : public Camera {
    public: 
        PerspectiveCamera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<float, float, float, float> screenWindow
        );
        Ray generate_ray(int x, int y);
};

#endif
