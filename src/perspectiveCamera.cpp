#include "../include/perspectiveCamera.h"
#include "../include/ray.h"
#include "../include/point.h"
#include "../include/vector3.h"

PerspectiveCamera::PerspectiveCamera(){}

PerspectiveCamera::PerspectiveCamera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<double, double, double, double> screenWindow
) : Camera(e, u, v, w, screenWindow) {}

Ray PerspectiveCamera::generate_ray(int x, int y)
{
    std::tuple<float, float> uv = this->getUVPos(x, y);
    Vector3 direction = this->w + (this->u * std::get<0>(uv)) + (this->v * std::get<1>(uv));
    Ray r(this->e, direction);
    
    return r;
}
