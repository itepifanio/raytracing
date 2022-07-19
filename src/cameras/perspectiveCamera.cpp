#include "../include/cameras/perspectiveCamera.h"
#include "../include/core/ray.h"
#include "../include/datatype/point.h"
#include "../include/datatype/vector3.h"

PerspectiveCamera::PerspectiveCamera(){}

PerspectiveCamera::PerspectiveCamera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<double, double, double, double> screenWindow
) : Camera(e, u, v, w, screenWindow) {}

PerspectiveCamera::PerspectiveCamera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<double, double, double, double> screenWindow,
    double fovy
) : Camera(e, u, v, w, screenWindow, fovy) {}

Ray PerspectiveCamera::generate_ray(int x, int y)
{
    std::tuple<float, float> uv = this->getUVPos(x, y);
    Vector3 direction = this->w + (this->u * std::get<0>(uv)) + (this->v * std::get<1>(uv));
    Ray r(this->e, direction);
    return r;
}

void PerspectiveCamera::print(Ray ray)
{
    std::cout << ray.getOrigin().i << " " << ray.getOrigin().j << " " << ray.getOrigin().value << " ";
    std::cout << ray.getDirection()[0]<< " " << ray.getDirection()[1] << " " << ray.getDirection()[2];
    std::cout << std::endl;
}

void PerspectiveCamera::set_lrbt_from_xres_yres_if_needed() {
    // if (this->fovy < 0.0) return;
    // auto actual_aspect_ratio = 800/600;
    // auto half_fovy_tan = tan((fovy/2)*3.14159265/180);
    // auto half_height_screen_space = half_fovy_tan * 1.0;

    // this->screenWindow[0] = -actual_aspect_ratio*half_height_screen_space;
    // this->screenWindow[1] = actual_aspect_ratio*half_height_screen_space;
    // this->screenWindow[2] = -half_height_screen_space;
    // this->screenWindow[3] = half_height_screen_space;
 }