#ifndef _ORTOGRAPHIC_CAMERA_H_
#define _ORTOGRAPHIC_CAMERA_H_

#include "../include/cameras/camera.h"
#include "../core/ray.h"

class OrtographicCamera : public Camera{
    public:
        OrtographicCamera();
        OrtographicCamera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<double, double, double, double> screenWindow
        );
        Ray generate_ray(int x, int y);
        void print(Ray ray);
};

#endif
