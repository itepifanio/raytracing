#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "../include/core/film.h"
#include "../include/core/rt3.h"
#include "../include/core/background.h"
#include "../include/core/scene.h"
#include "../include/datatype/lookat.h"
#include "../include/cameras/camera.h"
#include "../include/core/paramset.h"
#include "../include/shapes/sphere.h"
#include "../include/materials/material.h"
#include "../include/materials/flatMaterial.h"
#include "../include/materials/blinnPhongMaterial.h"
#include "../include/integrators/integrator.h"
#include "../include/integrators/flatIntegrator.h"
#include "../include/integrators/blinnPhongIntegrator.h"
#include "../include/lights/light.h"
#include "../include/lights/ambientLight.h"
#include "../include/lights/pointLight.h"
#include "../include/lights/spotLight.h"
#include "../include/lights/directionalLight.h"
#include "../include/libs/tinyxml2.h"
#include "../include/math/vectors.inl"
#include "../include/cameras/ortographicCamera.h"
#include "../include/cameras/perspectiveCamera.h"

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
        void createMaterial(const ParamSet &ps);
        void createIntegrator(const ParamSet &ps);
        void addSphere(const ParamSet &ps);
        void addLight(const ParamSet &ps);
        void readInclude(const ParamSet &ps);
        void render();

        RunningOptions options;
        Background background;
        Lookat lookat;
        Camera * camera;
        Material * material;
        Scene scene;
        Integrator *integrator;

    public:
        Api(RunningOptions options);
        void run();
        Background getBackground();
        Camera * getCamera();
        // Scene getScene();
};
#endif
