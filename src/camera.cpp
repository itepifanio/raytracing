#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"

Camera::Camera() {}

Camera::Camera(
    Point e, Vector3 u, Vector3 v, Vector3 w,
    std::tuple<float, float, float, float> screenWindow
) 
{
    this->e = e;
    this->u = u;
    this->v = v;
    this->w = w;
    this->screenWindow = screenWindow;
}

Camera::~Camera() {}

std::tuple<float, float, float, float> Camera::getScreenWindow()
{
    return this->screenWindow;
}

Camera* Camera::make(
    std::string type, Lookat lookat,
    std::tuple<float, float, float, float> screenWindow
)
{
    Vector3 gaze(
        look_at[0] - look_from[0],
        look_at[1] - look_from[1],
        look_at[2] - look_from[2]
    );

    Vector3 w = normalize(gaze);
    Vector3 u = normalize(cross(vup, w));
    Vector3 v = normalize(cross(w, u));
    Point e = look_from.toPoint();

    if(type == "orthographic") {
        return new OrtographicCamera(e, u, v, w, screenWindow);
    } else f (type == "perspective") {
        return new PerspectiveCamera(e, u, v, w, screenWindow);
    }

    std::string cameraException = "Camera type " + type + " is not configured.";

    throw std::invalid_argument(cameraException);
}

std::tuple<float, float, float, float> Camera::string_to_tuple(std::string tuple)
{
    std::istringstream iss(str);
    std::vector<std::string> splited(
        (std::istream_iterator<std::string>(iss)),
        std::istream_iterator<std::string>()
    );

    float e0, e1, e2;
    std::istringstream(splited[0]) >> e0;
    std::istringstream(splited[1]) >> e1;
    std::istringstream(splited[2]) >> e2;

    return std::make_tuple(e0, e1, e2);
}
