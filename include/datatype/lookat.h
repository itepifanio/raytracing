#ifndef _LOOKAT_H_ 
#define _LOOKAT_H_

#include <iostream>
#include "../datatype/vector3.h"
#include "../datatype/point.h"

class Lookat
{
    public:
        Vector3 look_from;
        Vector3 look_at;
        Vector3 vup;

        Lookat();
        Lookat(Vector3 look_from, Vector3 look_at, Vector3 vup);
        ~Lookat();
};
#endif
