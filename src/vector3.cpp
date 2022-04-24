#include "../include/vector3.h"

Vector3::Vector3() {
    for (int i = 0; i < 3; i++)
    {
        this->vector[i] = 0;
    }
}

Vector3::Vector3(double e0, double e1, double e2)
{
    this->vector[0] = e0;
    this->vector[1] = e1;
    this->vector[2] = e2;
}
/*
double operator[](int i) 
{
    return this->vector[i];
}

double& operator[](int i)
{
    return this->vector[i];
}

Vector3 operator+=( Vector3 &v)
{
    this->vector[0] += v.vector[0];
    this->vector[1] += v.vector[1];
    this->vector[2] += v.vector[2];
    
    return *this;
}

Vector3 operator*=( double t)
{
    this->vector[0] *= t;
    this->vector[1] *= t;
    this->vector[2] *= t;
    
    return *this;
}


Vector3& operator/=(const float& s)
{
    return *this *= 1/t;
}
*/

Vector3 operator-(Vector3& in)
{
    return Vector3(-in.vector[0], -in.vector[1], -in.vector[2]);
}

double Vector3::length()
{
    return std::sqrt(length_squared());
}

double Vector3::length_squared()
{
    return this->vector[0]*this->vector[0] + this->vector[1]*this->vector[1] + this->vector[2]*this->vector[2];
}
