#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "../../include/datatype/color24.h"
#include "../../include/datatype/vector3.h"
#include "../../include/datatype/point.h"
#include "./light.h"

class DirectionalLight : public Light{
public:
    Vector3 l;
    Vector3 scale;
    Vector3 from;
    Vector3 to;

    DirectionalLight(Vector3 l, Vector3 scale, Vector3 from, Vector3 to);
    Color24 sampleLi(
        Surfel &hit, 
        Vector3 *wi,
        VisibilityTester *visibilityTester
    );
};

#endif