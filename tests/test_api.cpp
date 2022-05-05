#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/film.h"
#include "../include/api.h"
#include "../include/rt3.h"

TEST_CASE("it can setup internal states using init_engine") {
    std::string sceneFile = "./tests/fixtures/test.ppm";
    RunningOptions options(sceneFile);
    CHECK(options.getSceneFile() == sceneFile);
    Api api(options);
    // TODO::
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
