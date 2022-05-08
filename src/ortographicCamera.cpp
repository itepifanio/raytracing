#include "../include/ortographicCamera.h"
#include "../include/ray.h"
#include "../include/point.h"
#include "../include/vector3.h"

OrtographicCamera::OrtographicCamera(std::tuple<float, float, float, float> screenWindow)
{
    this->screenWindow = screenWindow;
}

Ray OrtographicCamera::generate_ray(int x, int y)
{
    // TODO::using dummy values, still not implemented
    Point origin(0, 0, 0);
    Vector3 destiny(1, 1, 1);
    Ray r(origin, destiny);
    
    return r;
}
