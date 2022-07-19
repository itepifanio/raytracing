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

std::tuple<double, double, double, double> PerspectiveCamera::createScreenWindow(std::string screen_window, double fovy)
{
    std::istringstream iss(screen_window);
    std::vector<std::string> splited(
        (std::istream_iterator<std::string>(iss)),
        std::istream_iterator<std::string>()
    );

    double e0, e1, e2, e3;
    std::istringstream(splited[0]) >> e0;
    std::istringstream(splited[1]) >> e1;
    std::istringstream(splited[2]) >> e2;
    std::istringstream(splited[3]) >> e3;

    double actual_aspect_ratio = 800/600;
    double half_fovy_tan = tan((fovy/2.0)*3.14159265/180);
    double half_height_screen_space = half_fovy_tan * 1.0;

    e0 = -actual_aspect_ratio*half_height_screen_space;
    e1 = actual_aspect_ratio*half_height_screen_space;
    e2 = -half_height_screen_space;
    e3 = half_height_screen_space;

    return std::make_tuple(e0, e1, e2, e3);
 }