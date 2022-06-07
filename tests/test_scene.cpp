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

TEST_CASE("it can render scene") {
    Point points[4];
    points[0] = Point(153, 204, 255);
    points[1] = Point(18, 10, 143);
    points[2] = Point(18, 10, 143);
    points[3] = Point(153, 204, 255);
    Background background(800, 600, "image", points);
    
    Vector3 lookFrom(0, 0, 0);
    Vector3 lookAt(0, 0, 10);
    Vector3 vup(0, 1, 0);

    int xRes = 800;
    int yRes = 600;
    std::string type = "image";
    std::string filenameOutput = "./circles.ppm";

    Film film(type, xRes, yRes, filenameOutput);

    Lookat lookat(lookFrom, lookAt, vup);
    Camera *camera = Camera::make(
        "orthographic",
        lookat,
        std::make_tuple(-4, 4, -3, 3)
    );

    camera->film = film;

    Point center(-1, 0.5, 5);
    Sphere *sphere = new Sphere(0.4, center);
    Point center2(-1, 0.5, 8);
    Sphere *sphere2 = new Sphere(0.4, center2);
    Point center3(-1, -1.5, 3.5);
    Sphere *sphere3 = new Sphere(0.4, center3);
    
    CHECK_EQ(center3.j, -1.5);

    Color24 red(255, 0, 0);
    FlatMaterial *flatMaterial = new FlatMaterial(red);

    std::vector<Primitive*> objList;
    GeometricPrimitive *g1 = new GeometricPrimitive(
        dynamic_cast<Shape*>(sphere), 
        flatMaterial
    );
    GeometricPrimitive *g2 = new GeometricPrimitive(
        dynamic_cast<Shape*>(sphere2),
        flatMaterial
    );
    GeometricPrimitive *g3 = new GeometricPrimitive(
        dynamic_cast<Shape*>(sphere3), 
        flatMaterial
    );

    objList.push_back(dynamic_cast<Primitive*>(g1));
    objList.push_back(dynamic_cast<Primitive*>(g2));
    objList.push_back(dynamic_cast<Primitive*>(g3));

    Scene scene(camera, background, objList);

    scene.render();
}
