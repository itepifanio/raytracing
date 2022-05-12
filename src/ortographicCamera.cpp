#include "../include/ortographicCamera.h"
#include "../include/ray.h"
#include "../include/point.h"
#include "../include/vector3.h"

OrtographicCamera::OrtographicCamera(){}

OrtographicCamera::OrtographicCamera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<double, double, double, double> screenWindow
) : Camera(e, u, v, w, screenWindow) {}

Ray OrtographicCamera::generate_ray(int x, int y)
{
    std::tuple<float, float> uv = this->getUVPos(x, y);
    Vector3 e(this->e.i, this->e.j, this->e.value); // TODO::Add direct cast
    Vector3 origin = e + (this->u * std::get<0>(uv)) + (this->v * std::get<1>(uv));
    Ray r(origin.toPoint(), this->w);
    std::cout << " u=" << std::get<0>(uv) << " v=" << std::get<1>(uv);
    return r;
}

void OrtographicCamera::print(Ray ray)
{
    std::cout << ray.getOrigin().i << " " << ray.getOrigin().j << " " << ray.getOrigin().value << " ";
    std::cout << ray.getDirection()[0]<< " " << ray.getDirection()[1] << " " << ray.getDirection()[2];
    std::cout << std::endl;
}