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

        Lookat(Vector3 look_from, Vector3 look_at, Vector3 vup) {
            this->look_from = look_from;
            this->look_at = look_at;
            this->vup = vup;
        }
        ~Lookat();
};
#endif
