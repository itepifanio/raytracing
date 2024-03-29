#ifndef _POINT_LIGHT_H_
#define _POINT_LIGHT_H_

#include "../../include/datatype/color24.h"
#include "../../include/datatype/vector3.h"
#include "../../include/datatype/point.h"
#include "../../include/materials/blinnPhongMaterial.h"
#include "./light.h"

class PointLight : public Light{
public:
    Vector3 from;
    Vector3 i;
    Vector3 scale;

    PointLight(Vector3 &i, Vector3 scale, Vector3 from);
    Vector3 sampleLi(
        Surfel &hit, 
        Vector3 *wi,
        VisibilityTester *visibilityTester
    );
};

#endif