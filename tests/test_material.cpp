#include "../include/doctest.h"
#include "../include/material.h"
#include "../include/flatMaterial.h"

TEST_CASE("it can make flat material") {
    std::string type = "flat";
    Pixel color(255, 255, 255);

    Material *material = Material::make(type, color);

    FlatMaterial *flatMaterial = dynamic_cast<FlatMaterial*>(material);
    CHECK(flatMaterial != nullptr);

    CHECK_EQ(flatMaterial->getType(), type);
    CHECK_EQ(flatMaterial->getColor(), color);
}

TEST_CASE("it throw exception if a wrong material is called") {
    try
    {
        std::string type = "wrong_type";
        Pixel color(0, 0, 0);
        
        Material::make(type, color);
    }
    catch(const std::exception& e)
    {
        CHECK_FALSE(false);
    }
}
