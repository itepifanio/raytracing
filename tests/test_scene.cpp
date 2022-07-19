#include "../include/libs/doctest.h"
#include "../include/datatype/vector3.h"
#include "../include/datatype/point.h"
#include "../include/core/background.h"
#include "../include/datatype/lookat.h"
#include "../include/shapes/sphere.h"
#include "../include/cameras/camera.h"
#include "../include/core/scene.h"
#include "../include/datatype/lookat.h"
#include "../include/materials/flatMaterial.h"
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

