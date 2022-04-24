#include "../include/doctest.h"
#include "../include/film.h"
#include "../include/ppmreader.h"
#include "../include/pixel.h"
#include <vector>

TEST_CASE("it can parse image to ppm file") {
    std::vector<std::vector<Pixel*>> image;

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

    Film film(image);
    film.toPPM("tmp.ppm");

    PPM3Reader reader("tmp.ppm");
    
    CHECK(reader.getType() == "P3");
    CHECK(reader.getColumns() == 3);
    CHECK(reader.getRows() == 2);
    CHECK(reader.getMaxColor() == 255);

    for (int i = 0; i < (int) image.size(); i++)
    {
        for (int j = 0; j < (int) image[i].size(); j++)
        {
            CHECK(reader.getImage()[i][j]->r == image[i][j]->r);
            CHECK(reader.getImage()[i][j]->g == image[i][j]->g);
            CHECK(reader.getImage()[i][j]->b == image[i][j]->b);
        }
        
    }
}