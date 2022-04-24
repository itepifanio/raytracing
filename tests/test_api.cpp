#include "../include/doctest.h"
#include "../include/background.h"
#include "../include/film.h"
#include "../include/api.h"

TEST_CASE("it doesnt create another instance of the api") {
    Background background;
    Film film;
    Api::Instance();
    Api::Instance();
    //CHECK(&a == &b);
}