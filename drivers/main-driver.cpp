#include <iostream>
#include "../include/api.h"
#include "../include/rt3.h"
#include <fstream>
#include <sstream>

// #include "../src/api.cpp"
// #include "../src/background.cpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::ifstream file;
        file.open(argv[1]);
        if (file.is_open())
        {
            std::string sceneFile = argv[1];
            RunningOptions options(sceneFile);
            Api api(options);
            api.run();
        }
        else
        {
            std::cout << "Couldn't open the file. Please verify your path and try it again" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid number of argument, please provide the filename only" << std::endl;
    }
    
    return 0;
}
