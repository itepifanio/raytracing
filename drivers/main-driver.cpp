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

            /*
            auto w = api.getCamera().film.getXRes();
            auto h = api.getCamera().film.getYRes();

            for (int j = h - 1; j >= 0; j--)
            {
                for (int i = 0; i < w; i++)
                {
                    Ray r2 = camera.generate_ray(i, j);
                    std::cout << "Ray1: " << r1 << ", Ray2: " << r2 << std::endl;
                    std::cout << "Point at t=2, ray(2) = " << r1(2.f) << std::endl;
                    
                    //auto color = background.sample(float(i) / float(w), float(j) / float(h), r1);
                    //camera.film.add(Point2{i, j}, color);
                }
            }
            */
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
