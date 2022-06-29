#ifndef _LIGHT_H_
#define _LIGHT_H_

class Light {  
public:
    // light_flag_e flags; TODO::add enum
    virtual ~Light();
    Light(int flags);
    virtual Color24 sampleLi(Surfel &hit, Vector3 *wi, );
};

#endif