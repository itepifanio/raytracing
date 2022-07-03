#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

#include "../../include/datatype/color24.h"
#include "../../include/datatype/vector3.h"
#include "./light.h"

class AmbientLight : public Light {
    public:
        Vector3 l;
        AmbientLight(Vector3 l);
        Color24 sampleLi(
            Surfel &hit, 
            Vector3 *wi,
            VisibilityTester visibilityTester
        );
};

#endif