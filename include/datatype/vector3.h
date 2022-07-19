#ifndef VECTOR3_H
#define VECTOR3_H

#include "./datatype/pixel.h"
#include "./datatype/color24.h"
#include "../datatype/point.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

class Color24;
class Point; // avoiding cyclic definition by prototyping the class 'Point'

/*
Used to calculate the pixel or points
*/
class Vector3
{
public:
    double vector[3];
    
    Vector3();

    Vector3(Pixel pixel);

    Vector3(Point point);

    Vector3(double e0, double e1, double e2);


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

    friend double operator*(Vector3 const &rhs, Vector3 const &lhs);

    friend Vector3 operator/(Vector3 const &lhs, double const rhs);

    double length();

    Pixel toPixel();

    Color24 toColor24(bool convert = false);

    Point toPoint();

    double length_squared();
};

#endif