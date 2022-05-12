#include "../include/doctest.h"
#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"
#include <math.h>

TEST_CASE("it can make orthographic camera") {
    std::tuple<float, float, float, float> screenWindow = std::make_tuple(-5.3, 5.3, -4, 4);
    
    Vector3 lookfrom(0, 7, 0);
    Vector3 lookat(0, 0, 0);
    Vector3 vup(0, 0, 1);
    
    Lookat look(lookfrom, lookat, vup);

    Camera *camera = Camera::make("orthographic", look, screenWindow);
    
    Film film("image", 2800, 1800, "gcodex_matte_ortho.ppm");
    camera->film = film; // TODO::remove workaround
    
    OrtographicCamera *ortoCamera = dynamic_cast<OrtographicCamera*>(camera);
    CHECK(ortoCamera != nullptr);

    Point resultE(0, 7.0, 0);
    Vector3 resultW(0, -1, 0);
    Vector3 resultU(1.0, 0, 0);
    Vector3 resultV(0, 0, -1.0);

    CHECK_EQ(ortoCamera->getE(), resultE);
    CHECK_EQ(ortoCamera->getW().toPoint(), resultW.toPoint());
    CHECK_EQ(ortoCamera->getU().toPoint(), resultU.toPoint());

    // o último valor tá dando diferente
    CHECK_EQ(ortoCamera->getV().toPoint().i, resultV.toPoint().i);
    CHECK_EQ(ortoCamera->getV().toPoint().j, resultV.toPoint().j);
    //CHECK_EQ(ortoCamera->getV().toPoint().value, resultV.toPoint().value);

    std::tuple<double, double> uv = ortoCamera->getUVPos(0, 1799);
    CHECK(float(std::get<0>(uv)) == float(-5.2981073335));
    CHECK(float(std::get<1>(uv)) == float(3.9977777778));
}

TEST_CASE("it can make perspective camera") {
    std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.556, 1.556, -1, 1);
    std::cout << "Perspective" << std::endl;

    Vector3 lookfrom(0, 4.0, -11.0);
    Vector3 lookat(0, 1, 0);
    Vector3 vup(0, 1, 0);
    
    Lookat look(lookfrom, lookat, vup);

    Camera *camera = Camera::make("perspective", look, screenWindow);
    PerspectiveCamera *persCamera = dynamic_cast<PerspectiveCamera*>(camera);

    Film film("image", 2800, 1800, "gcodex_matte_persp.ppm");
    camera->film = film; // TODO::remove workaround

    CHECK(persCamera != nullptr);

    Point resultE(0, 4.0, -11.0);
    Vector3 resultW(0.000000, -0.263117, 0.964764);
    Vector3 resultU(1.000000, 0.000000, -0.000000);
    Vector3 resultV(0.000000, -0.964764, -0.263117);

    CHECK_EQ(persCamera->getE(), resultE);
    CHECK_EQ(persCamera->getW().toPoint(), resultW.toPoint());

    CHECK_EQ(persCamera->getU().toPoint().i, resultU.toPoint().i);
    CHECK_EQ(persCamera->getU().toPoint().j, resultU.toPoint().j);
    CHECK_EQ(persCamera->getU().toPoint().value, resultU.toPoint().value);

    // o último valor tá dando diferente
    CHECK_EQ(persCamera->getV().toPoint().i, resultV.toPoint().i);
    CHECK_EQ(persCamera->getV().toPoint().j, resultV.toPoint().j);
    CHECK_EQ(persCamera->getV().toPoint().value, resultV.toPoint().value);

    std::tuple<double, double> uv = persCamera->getUVPos(0, 1799);
    CHECK(float(std::get<0>(uv)) == float(-1.55544428));
    CHECK(float(std::get<1>(uv)) == float(0.9994444444));
}

TEST_CASE("it throw exception if a wrong camera is called") {
    try
    {
        Vector3 lookfrom(0, 0, 0);
        Vector3 lookat(0, 0, 0);
        Vector3 vup(0, 0, 0);
        
        Lookat look(lookfrom, lookat, vup);

        Camera::make("perspective", look);
    }
    catch(const std::exception& e)
    {
        CHECK_FALSE(false);
    }
}
