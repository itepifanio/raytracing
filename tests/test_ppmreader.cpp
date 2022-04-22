#include "../include/doctest.h"
#include "../include/ppmreader.h"
#include "../include/pixel.h"
#include <vector>

TEST_CASE("it can read ppm file") {
    PPM3Reader reader("./tests/fixtures/test.ppm");
    CHECK(reader.getType() == "P3");
    CHECK(reader.getColumns() == 3);
    CHECK(reader.getRows() == 2);
    CHECK(reader.getMaxColor() == 255);

    std::vector<std::vector<Pixel*>> image;
    
    //255 0 0 0 255 0 0 0 255
    //255 255 0 255 255 255 0 0 0
    std::vector<Pixel*> tmp;
    Pixel a(255, 0, 0);
    Pixel b(0, 255, 0);
    Pixel c(0, 0, 255);
    tmp.push_back(&a);
    tmp.push_back(&b);
    tmp.push_back(&c);
    image.push_back(tmp);
    tmp.clear();
    Pixel d(255, 255, 0);
    Pixel e(255, 255, 255);
    Pixel f(0, 0, 0);
    tmp.push_back(&d);
    tmp.push_back(&e);
    tmp.push_back(&f);
    image.push_back(tmp);

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            CHECK(reader.getImage()[i][j]->r == image[i][j]->r);
            CHECK(reader.getImage()[i][j]->g == image[i][j]->g);
            CHECK(reader.getImage()[i][j]->b == image[i][j]->b);
        }
        
    }
}