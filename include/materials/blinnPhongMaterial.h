#ifndef _BLINN_PHONG_MATERIAL_H_
#define _BLINN_PHONG_MATERIAL_H_

#include "./material.h"
#include "../include/datatype/vector3.h"

class BlinnPhongMaterial : public Material{
    private:
        std::string name;
        Vector3 ambient;
        Vector3 diffuse;
        Vector3 specular;
        double glossiness;
        Vector3 mirror;

    public:
        BlinnPhongMaterial(
            std::string name,
            Vector3 ambient,
            Vector3 diffuse,
            Vector3 specular,
            double glossiness
        );
        void setMirror(Vector3 mirror);
        ~BlinnPhongMaterial() {};
};

#endif