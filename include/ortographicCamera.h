#ifndef _ORTOGRAPHIC_CAMERA_H_
#define _ORTOGRAPHIC_CAMERA_H_

#include "camera.h"
#include "ray.h"

class OrtographicCamera : public Camera{
    public:
        OrtographicCamera();
        OrtographicCamera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<float, float, float, float> screenWindow
        );
        Ray generate_ray(int x, int y);
};

#endif
