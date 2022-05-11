#ifndef _LOOKAT_H_ 
#define _LOOKAT_H_

#include <iostream>
#include "vector3.h"
#include "point.h"

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
