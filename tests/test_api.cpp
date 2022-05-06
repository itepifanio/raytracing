#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/film.h"
#include "../include/api.h"
#include "../include/rt3.h"

TEST_CASE("it can setup internal states with simple scene") {
    std::string sceneFile = "./tests/fixtures/simple_scene.xml";
    RunningOptions options(sceneFile);
    CHECK(options.getSceneFile() == sceneFile);
    Api api(options);
    api.run();
}

TEST_CASE("it can setup internal states with interpolated scene") {
    std::string sceneFile = "./tests/fixtures/interpolated_background.xml";
    RunningOptions options(sceneFile);
    CHECK(options.getSceneFile() == sceneFile);
    Api api(options);
    api.run();
    CHECK_EQ(api.getBackground().bottomLeft.i, 0);
    CHECK_EQ(api.getBackground().bottomLeft.j, 0);
    CHECK_EQ(api.getBackground().bottomLeft.value, 51);
    
    CHECK_EQ(api.getBackground().topLeft.i, 0);
    CHECK_EQ(api.getBackground().topLeft.j, 255);
    CHECK_EQ(api.getBackground().topLeft.value, 51);

    CHECK_EQ(api.getBackground().topRight.i, 255);
    CHECK_EQ(api.getBackground().topRight.j, 255);
    CHECK_EQ(api.getBackground().topRight.value, 51);

    CHECK_EQ(api.getBackground().bottomRight.i, 255);
    CHECK_EQ(api.getBackground().bottomRight.j, 0);
    CHECK_EQ(api.getBackground().bottomRight.value, 51);
}

TEST_CASE("it output background") {
    //TODO::
}

/*
TEST_CASE("it doesnt create another instance of the api") {
    Background background;
    Film film;
    // Api::init(background, film);

    Api &a = Api::getInstance();
    Api &b = Api::getInstance();
    CHECK_EQ(&a, &b);
}
*/
