#include <iostream>
#include "../include/parser.hpp"
#include "../include/pixel.h"
#include "../include/point.h"
#include "../include/background.h"
#include <iostream>
#include <fstream>
#include <sstream>

// #include "../src/api.cpp"
// #include "../src/background.cpp"

int main(int argc, char** argv)
{
    std::ifstream file;
    file.open( argv[1] );
    if (file.is_open())
    {
        std::cout << "File can be opened" << std::endl;
    }
    std::cout << "Opening " << argv[1] << std::endl;
    std::string sceneFile = argv[1];
    RunningOptions options(sceneFile);
    //CHECK(options.getSceneFile() == sceneFile);
    Api api(options);
    api.run();
    /*
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
    */
    return 0;
}
