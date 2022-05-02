#ifndef VECTOR3_H
#define VECTOR3_H

#include "pixel.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

/*
Used to calculate the pixel or points
*/

class Vector3
{
public:
    double vector[3];
    
    Vector3();

    Vector3(Pixel pixel);

    Vector3(int e0, int e1, int e2);

    static Vector3 string_to_vector(std::string str);

    double operator[](int k) const;

    double &operator[](int k);

    friend Vector3 &operator/=(Vector3 &lhs, double const &rhs);

    friend Vector3 &operator*=(Vector3 &lhs, double const &rhs);

    friend Vector3 &operator-=(Vector3 &lhs, Vector3 const &rhs);

    friend Vector3 &operator+=(Vector3 &lhs, Vector3 const &rhs);

    friend Vector3 operator-(Vector3 const &lhs, Vector3 const &rhs);

    friend Vector3 operator+(Vector3 const &lhs, Vector3 const &rhs);

    friend Vector3 operator*(Vector3 const &lhs, double const rhs);

     friend Vector3 operator*(double const rhs, Vector3 const &lhs);

    double length();

    Pixel toPixel();

    double length_squared();
};

#endif