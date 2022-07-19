#ifndef _PERSPECTIVE_CAMERA_H_
#define _PERSPECTIVE_CAMERA_H_

#include "../include/cameras/camera.h"
#include "../core/ray.h"

class PerspectiveCamera : public Camera {
    public: 
        PerspectiveCamera();
        PerspectiveCamera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<double, double, double, double> screenWindow
        );
        PerspectiveCamera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<double, double, double, double> screenWindow,
            double flav
        );
        Ray generate_ray(int x, int y);
        void print(Ray ray);
        void set_lrbt_from_xres_yres_if_needed();
};

#endif
