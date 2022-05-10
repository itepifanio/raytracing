#include "../include/doctest.h"
#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"
#include <typeinfo>

TEST_CASE("it can make perspective camera") {
    Camera *camera = Camera::make("perspective");
    PerspectiveCamera *ortoCamera = dynamic_cast<PerspectiveCamera*>(camera);
    CHECK(ortoCamera != nullptr);
}

TEST_CASE("it can make ortographic camera") {
    Camera *camera = Camera::make("orthographic");
    OrtographicCamera *ortoCamera = dynamic_cast<OrtographicCamera*>(camera);
    CHECK(ortoCamera != nullptr);
}

TEST_CASE("it throw exception if a wrong camera is called") {
    try
    {
        Camera::make("wrongCameraType");
        CHECK_FALSE(true);
    }
    catch(const std::exception& e)
    {
        CHECK_FALSE(false);
    }
}
