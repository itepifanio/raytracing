#include "../include/perspectiveCamera.h"
#include "../include/ray.h"
#include "../include/point.h"
#include "../include/vector3.h"

PerspectiveCamera::PerspectiveCamera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<float, float, float, float> screenWindow
) : Camera(e, u, v, w, screenWindow) {}

Ray PerspectiveCamera::generate_ray(int x, int y)
{
    // TODO::using dummy values, still not implemented
    Point origin(0, 0, 0);
    Vector3 destiny(1, 1, 1);
    Ray r(origin, destiny);
    
    return r;
}
