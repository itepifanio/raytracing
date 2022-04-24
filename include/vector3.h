#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3
{
public:
    double vector[3];
    Vector3();
    Vector3(double e0, double e1, double e2);

    /*
    friend double &operator[](Vector3 &in, int i);
    friend double& operator[](int i);



    friend Vector3& operator*=( double t);

    friend Vector3& operator/=(const float& s);
    */
    double operator[](int k) const;

    double &operator[](int k);

    friend Vector3 &operator/=(Vector3 &lhs, double const &rhs);

    friend Vector3 &operator*=(Vector3 &lhs, double const &rhs);

    friend Vector3 &operator-=(Vector3 &lhs, Vector3 const &rhs);

    friend Vector3 &operator+=(Vector3 &lhs, Vector3 const &rhs);

    friend Vector3 operator-(Vector3 const &lhs, Vector3 const &rhs);

    friend Vector3 operator+(Vector3 const &lhs, Vector3 const &rhs);

    // Vector3& operator+=(Vector3& lhs,Vector3 const& rhs);

    double length();

    double length_squared();
};

#endif