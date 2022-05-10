#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"

Camera::Camera() {}

Camera::~Camera() {}

std::tuple<float, float, float, float> Camera::getScreenWindow()
{
    return this->screenWindow;
}

Camera* Camera::make(std::string type)
{
    if(type == "orthographic") {
        return new OrtographicCamera;
    } 
    if (type == "perspective") {
        return new PerspectiveCamera;
    }

    std::string cameraException = "Camera type " + type + " is not configured.";

    throw std::invalid_argument(cameraException);
}
