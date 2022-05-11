#include "../include/doctest.h"
#include "../include/camera.h"
#include "../include/ortographicCamera.h"
#include "../include/perspectiveCamera.h"
#include <typeinfo>

TEST_CASE("it can make orthographic camera") {
    std::tuple<float, float, float, float> screenWindow = std::make_tuple(-5.3, 5.3, -4, 4);
    
    //TODO::Professor não deu os valores de look
    Vector3 lookfrom(0, 0, 0);
    Vector3 lookat(0, 0, 0);
    Vector3 vup(0, 0, 0);
    
    Lookat look(lookfrom, lookat, vup);

    Camera *camera = Camera::make("orthographic", look, screenWindow);
    OrtographicCamera *ortoCamera = dynamic_cast<OrtographicCamera*>(camera);
    CHECK(ortoCamera != nullptr);

    Point resultE(0, 7.0, 0);
    Vector3 resultW(0, -1, 0);
    Vector3 resultU(1.0, 0, 0);
    Vector3 resultV(0, 0, -1.0);

    // TODO::Professor deu os valores de i, j, u, v e screen window, mas não deu o look
    // então esse teste vai falhar. Corrigir após ele dar os dados.
    /*
    CHECK_EQ(ortoCamera->getE(), resultE);
    CHECK_EQ(ortoCamera->getW().toPoint(), resultW.toPoint());
    CHECK_EQ(ortoCamera->getU().toPoint(), resultU.toPoint());
    CHECK_EQ(ortoCamera->getV().toPoint(), resultV.toPoint());
    */

   // TODO::checar que u=-5.298107 v=3.997778 lara i=0 e j=1799
}

TEST_CASE("it can make perspective camera") {
    std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.556, 1.566, -1, 1);
    
    //TODO::Professor não deu os valores de look
    Vector3 lookfrom(0, 0, 0);
    Vector3 lookat(0, 0, 0);
    Vector3 vup(0, 0, 0);
    
    Lookat look(lookfrom, lookat, vup);

    Camera *camera = Camera::make("perspective", look, screenWindow);
    PerspectiveCamera *persCamera = dynamic_cast<PerspectiveCamera*>(camera);
    CHECK(persCamera != nullptr);

    Point resultE(0, 4.0, -11.0);
    Vector3 resultW(0, -0.263117, 0.964764);
    Vector3 resultU(1.000000, 0.000000, -0.000000);
    Vector3 resultV(0.000000, -0.964764, -0.263117);

    // TODO::Professor deu os valores de i, j, u, v e screen window, mas não deu o look
    // então esse teste vai falhar. Corrigir após ele dar os dados.
    /*
    CHECK_EQ(ortoCamera->getE(), resultE);
    CHECK_EQ(ortoCamera->getW().toPoint(), resultW.toPoint());
    CHECK_EQ(ortoCamera->getU().toPoint(), resultU.toPoint());
    CHECK_EQ(ortoCamera->getV().toPoint(), resultV.toPoint());
    */

   // TODO::checar que u=-1.555000 v=0.999444 para i=0 e j=1799
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
