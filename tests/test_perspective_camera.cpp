#include "../include/libs/doctest.h"
#include "../include/cameras/perspectiveCamera.h"

TEST_CASE("it can init perspective camera with default screen windows") {
    PerspectiveCamera camera;
    std::tuple<double, double, double, double> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1);
    CHECK_EQ(camera.getScreenWindow(), screenWindow);
}
