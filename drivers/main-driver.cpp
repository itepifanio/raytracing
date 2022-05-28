#include <iostream>
#include "../include/core/api.h"
#include "../include/core/rt3.h"
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
            
            Background background = api.getBackground();
            Camera * camera = api.getCamera();

            auto w = camera->film.getXRes();
            auto h = camera->film.getYRes();
            std::cout << "Ray's Origin                         Ray's Direction\n";
            for (int j = h - 1; j >= h-3; j--)
            {
                for (int i = 0; i < w; i+=700)
                {
                    std::cout << "i=" << i << " j=" << j;
                    Ray r2 = camera->generate_ray(i, j);
                    std::cout << std::endl;
                    camera->print(r2);
                    
                }
            }
            for (int j = 2; j >= 0; j--)
            {
                for (int i = 0; i < w; i+=700)
                {
                    std::cout << "i=" << i << " j=" << j;
                    Ray r2 = camera->generate_ray(i, j);
                    std::cout << std::endl;
                    camera->print(r2);
                    
                }
            }
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
