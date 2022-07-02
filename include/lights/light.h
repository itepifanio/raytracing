#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../shapes/surfel.h"
#include "../helpers/visibilityTester.h"
#include "../datatype/vector3.h"

class VisibilityTester;

class Light {  
public:
    // light_flag_e flags; TODO::add enum
    virtual Color24 sampleLi(
        Surfel &hit, 
        Vector3 *wi, 
        VisibilityTester visibilityTester
    ) = 0;
};

#endif
