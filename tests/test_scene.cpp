#include "../include/doctest.h"
#include "../include/vector3.h"
#include "../include/point.h"
#include "../include/background.h"
#include "../include/lookat.h"
#include "../include/sphere.h"
#include "../include/camera.h"
#include "../include/scene.h"
#include "../include/lookat.h"
#include <memory.h>
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
        "orthographic", 
        lookat, 
        std::make_tuple(-1.555, 1.555, -1, 1)
    );
    Point center(0, 1, 0);
    Sphere *sphere = new Sphere(5, center);

    std::vector<Primitive*> objList;
    objList.push_back(dynamic_cast<Primitive*>(sphere));

    Scene scene(camera, background, objList);
    CHECK_EQ(camera, scene.getCamera());
    CHECK_EQ(background.bottomLeft, scene.getBackground().bottomLeft);
    CHECK_EQ(objList, scene.getPrimitive());
}

TEST_CASE("it can render scene") {
    Point points[4];
    points[0] = Point(153, 204, 255);
    points[1] = Point(18, 10, 143);
    points[2] = Point(18, 10, 143);
    points[3] = Point(153, 204, 255);
    Background background(600, 800, "image", points);
    background.interpolateAll();
    
    Vector3 lookFrom(0, 0, 0);
    Vector3 lookAt(0, 0, 10);
    Vector3 vup(0, 1, 0);
    Lookat lookat(lookFrom, lookAt, vup);
    Camera *camera = Camera::make(
        "orthographic", 
        lookat, 
        std::make_tuple(-4, 4, -3, 3)
    );

    Point center(-1, 0.5, 5);
    Sphere *sphere = new Sphere(0.4, center);

    std::vector<Primitive*> objList;
    objList.push_back(dynamic_cast<Primitive*>(sphere));

    Scene scene(camera, background, objList);
    scene.render();
}
