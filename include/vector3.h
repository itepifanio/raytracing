#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3 {
    public:
        double vector[3];
        Vector3();
        Vector3(double e0, double e1, double e2);

        Vector3 operator-();
        double operator[](int i);
        double& operator[](int i);

        Vector3& operator+=(const Vector3 &v);

        Vector3& operator*=(const double t);

        Vector3& operator/=(const double t);

        double length();

        double length_squared();
};

#endif