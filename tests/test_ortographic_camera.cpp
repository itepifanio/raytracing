#include "../include/doctest.h"
#include "../include/ortographicCamera.h"

TEST_CASE("it can init ortographic camera with default screen windows") {
    OrtographicCamera camera;
    std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1);
    CHECK_EQ(camera.getScreenWindow(), screenWindow);
}
