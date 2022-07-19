#ifndef _SPOT_LIGHT_H_
#define _SPOT_LIGHT_H_

#include "../../include/datatype/color24.h"
#include "../../include/datatype/vector3.h"
#include "../../include/datatype/point.h"
#include "./light.h"

class SpotLight : public Light {
public:
    Vector3 i;
    Vector3 scale;
    Vector3 from;
    Vector3 to;
    double cutoff;
    double falloff;

    SpotLight(
        Vector3 i, 
        Vector3 scale, 
        Vector3 from, 
        Vector3 to, 
        double cutoff = 30,
        double falloff = 15
    );

    Vector3 sampleLi(
        Surfel &hit, 
        Vector3 *wi,
        VisibilityTester *visibilityTester
    );
};

#endif