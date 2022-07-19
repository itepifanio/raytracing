#include "../include/cameras/camera.h"
#include "../include/cameras/ortographicCamera.h"
#include "../include/cameras/perspectiveCamera.h"
#include "../include/math/vectors.inl"

Camera::Camera()
{
    this->screenWindow = std::make_tuple(-1.555, 1.555, -1, 1);
}

Camera::Camera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<double, double, double, double> screenWindow)
{
    this->e = e;
    this->u = u;
    this->v = v;
    this->w = w;
    this->screenWindow = screenWindow;
}

Camera::Camera(
    Point e, Vector3 u, Vector3 v, Vector3 w, 
    std::tuple<double, double, double, double> screenWindow,
    double fovy)
{
    this->e = e;
    this->u = u;
    this->v = v;
    this->w = w;
    this->screenWindow = screenWindow;
    this->fovy = fovy;
}

Camera::~Camera() {}

std::tuple<double, double, double, double> Camera::getScreenWindow()
{
    return this->screenWindow;
}

Camera *Camera::make(
    std::string type, Lookat lookat,
    std::tuple<double, double, double, double> screenWindow)
{
    Vector3 gaze = lookat.look_at - lookat.look_from;

    Vector3 w = normalize(gaze);
    Vector3 u = normalize(cross(lookat.vup, w));
    Vector3 v = normalize(cross(u, w));

    Point e = lookat.look_from.toPoint();

    if (type.compare("orthographic") == 0)
    {
        return new OrtographicCamera(e, u, v, w, screenWindow);
    }
    else if (type.compare("perspective") == 0)
    {
        return new PerspectiveCamera(e, u, v, w, screenWindow);
    }

    std::string cameraException = "Camera type " + type + " is not configured.";

    throw std::invalid_argument(cameraException);
}

std::tuple<double, double, double, double> Camera::string_to_tuple(std::string tuple)
{
    std::istringstream iss(tuple);
    std::vector<std::string> splited(
        (std::istream_iterator<std::string>(iss)),
        std::istream_iterator<std::string>());

    double e0, e1, e2, e3;
    std::istringstream(splited[0]) >> e0;
    std::istringstream(splited[1]) >> e1;
    std::istringstream(splited[2]) >> e2;
    std::istringstream(splited[3]) >> e3;

    return std::make_tuple(e0, e1, e2, e3);
}

/*
Map image space to screen space
i,j are position from the image space
imageWidth, imageHeight are the number of pixels of the image
*/
std::tuple<double, double> Camera::getUVPos(int i, int j)
{
    auto screenWindows = this->getScreenWindow();
    double left = std::get<0>(screenWindows);
    double right = std::get<1>(screenWindows);
    double bottom = std::get<2>(screenWindows);
    double top = std::get<3>(screenWindows);

    double u = left + (right - left)*(i + 0.5)/this->film.getXRes();
    double v = bottom + (top - bottom)*(j + 0.5)/this->film.getYRes();

    return std::make_tuple(u, v);
}

Point Camera::getE()
{
    return this->e;
}

Vector3 Camera::getU()
{
    return this->u;
}

Vector3 Camera::getV()
{
    return this->v;
}

Vector3 Camera::getW()
{
    return this->w;
}
