#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3 {
    public:
        double vector[3];
        Vector3();
        Vector3(double e0, double e1, double e2);

        /*
        friend Vector3 operator-();
        friend double operator[](int i);
        friend double& operator[](int i);

        friend Vector3& operator+=(Vector3 &v);

        friend Vector3& operator*=( double t);

        friend Vector3& operator/=(const float& s);
        */
       friend Vector3 operator-(Vector3& in);

        double length();

        double length_squared();
};

#endif