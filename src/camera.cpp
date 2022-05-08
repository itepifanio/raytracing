#include "../include/camera.h"

Camera::Camera() {}

Camera::~Camera() {}

std::tuple<float, float, float, float> Camera::getScreenWindow()
{
    return this->screenWindow;
}
