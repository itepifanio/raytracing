#ifndef _POINT_H_ 
#define _POINT_H_

#include "../datatype/vector3.h"

class Vector3; // prototyping to avoid cyclic dependencies

/*
Holds the space location i, j and a value.
The value is a integer representation of a rgb value
so it's on the 0..255 range.
*/
class Point {
    public:
        Point();
        Point(double i, double j, double value);
        double i;
        double j;
        double value;
        Vector3 toVector3();
        friend bool operator==(const Point& lhs, const Point& rhs);
        friend bool operator!=(const Point& lhs, const Point& rhs);
};

#endif