#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../shapes/surfel.h"
#include "../helpers/visibilityTester.h"
#include "../datatype/vector3.h"


class VisibilityTester;

enum class light_flag_e : int {
    point = 1,
    directional = 2,
    area = 4,
    ambient = 8,
    spot = 16
};


class Light {  
    public:
        light_flag_e flags; 
        virtual Color24 sampleLi(
            Surfel &hit,
            Vector3 *wi,
            VisibilityTester visibilityTester
        ) = 0;

        static Light* make(
            std::string type,
            Vector3 i,
            Vector3 scale,
            Vector3 from,
            Vector3 to,
            double cutoff = 30,
            double falloff = 15
        );
};

#endif
