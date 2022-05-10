#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "film.h"
#include "rt3.h"
#include "background.h"
#include "camera.h"

class Api
{
    private:
        void parser(std::string xmlFile);
        void render();
        RunningOptions options;
        Background background;
        Film film;
        Camera camera;

    public:
        Api(RunningOptions options);
        void run();
        Background getBackground();
};
#endif
