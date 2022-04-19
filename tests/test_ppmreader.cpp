#include "../include/doctest.h"
#include "../include/ppmreader.h"

TEST_CASE("it can read ppm file") {
    PPM3Reader reader("./tests/fixtures/test.ppm");
    CHECK(reader.getType() == "P3");
    CHECK(reader.getColumns() == 3);
    CHECK(reader.getRows() == 2);
    CHECK(reader.getMaxColor() == 255);
    //CHECK(reader.content == ...)
}