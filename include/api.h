#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "film.h"
#include "rt3.h"
#include "background.h"
#include "lookat.h"
#include "camera.h"
#include "paramset.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class Api
{
    private:
        void parser(std::string xmlFile);

        ParamSet getParams(XMLElement *e, int size_elements = 1);
        void createFilm(const ParamSet &ps);
        void createBackground(const ParamSet &ps);
        void createLookat(const ParamSet &ps);
        void createCamera(const ParamSet &ps);
        void render();

        RunningOptions options;
        Background background;
        Lookat lookat;
        Camera * camera;
    public:
        Api(RunningOptions options);
        void run();
        Background getBackground();
        Camera * getCamera();
};
#endif
