#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../helpers/visibilityTester.h"

class Light {  
public:
    // light_flag_e flags; TODO::add enum
    virtual ~Light();
    virtual Color24 sampleLi(
        Surfel &hit, 
        Vector3 *wi, 
        VisibilityTester visibilityTester
    );
};

#endif