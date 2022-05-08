#include "../include/doctest.h"
#include "../include/film.h"
#include "../include/ppmread.h"
#include "../include/pixel.h"
#include <vector>

TEST_CASE("it can init film") {
    int xRes = 3;
    int yRes = 2;
    std::string type = "image";
    std::string filenameOutput = "./tests/fixtures/test.ppm";
    
    Film film(xRes, yRes, type, filenameOutput);
    
    CHECK_EQ(film.getXRes(), xRes);
    CHECK_EQ(film.getYRes(), yRes);
    CHECK_EQ(film.getType(), type);
    CHECK_EQ(film.getFilenameOutput(), filenameOutput);
}
