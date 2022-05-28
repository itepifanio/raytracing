#include "../include/libs/doctest.h"
#include "../include/core/film.h"
#include "../include/helpers/ppmread.h"
#include "../include/datatype/pixel.h"
#include <vector>

TEST_CASE("it can init film") {
    int xRes = 3;
    int yRes = 2;
    std::string type = "image";
    std::string filenameOutput = "./tests/fixtures/test.ppm";
    
    Film film(type, xRes, yRes, filenameOutput);
    
    CHECK_EQ(film.getXRes(), xRes);
    CHECK_EQ(film.getYRes(), yRes);
    CHECK_EQ(film.getType(), type);
    CHECK_EQ(film.getFilenameOutput(), filenameOutput);
}
