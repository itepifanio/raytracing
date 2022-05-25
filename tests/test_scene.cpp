#include "../include/doctest.h"
#include "../include/vector3.h"
#include "../include/point.h"
#include "../include/background.h"
#include "../include/camera.h"
#include "../include/lookat.h"
#include "../include/sphere.h"
#include "../include/scene.h"
#include <vector>

TEST_CASE("it can init scene") {
    Point points[4];
    points[0] = Point(1, 2, 3);
    points[1] = Point(3, 2, 1);
    points[2] = Point(0, 1, 0);
    points[3] = Point(1, 0, 1);
    Background background(400, 600, "image", points);

    Vector3 lookFrom(0, 0, 0);
    Vector3 lookAt(0, 0, 0);
    Vector3 vup(0, 0, 0);
    Lookat lookat(lookFrom, lookAt, vup);
    Camera *camera = Camera::make(
        "ortographic", 
        lookat, 
        std::make_tuple(-1.555, 1.555, -1, 1)
    );
    
    Point center(0, 1, 0);
    Sphere sphere(5, center);

    Scene scene(camera, background, sphere);
    CHECK_EQ(camera, scene.getCamera());
    CHECK_EQ(background, scene.getBackground());
    CHECK_EQ(sphere, scene.getPrimitive());
}

TEST_CASE("it can render scene") {
    // TODO::Check list of primitives
}
