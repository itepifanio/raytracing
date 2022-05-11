#include "../include/doctest.h"
#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"
#include <typeinfo>

TEST_CASE("it can make perspective camera") {
    Camera *camera = new PerspectiveCamera;
    PerspectiveCamera *ortoCamera = dynamic_cast<PerspectiveCamera*>(camera);
    CHECK(ortoCamera != nullptr);
}

TEST_CASE("it can make ortographic camera") {
    Camera *camera = new OrtographicCamera;
    OrtographicCamera *ortoCamera = dynamic_cast<OrtographicCamera*>(camera);
    CHECK(ortoCamera != nullptr);
}

TEST_CASE("it throw exception if a wrong camera is called") {
    try
    {
        Camera::make("wrongCameraType");
    }
    catch(const std::exception& e)
    {
        CHECK_FALSE(false);
    }
}