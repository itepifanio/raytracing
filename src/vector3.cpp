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

Vector3 Vector3::operator-()
{
    return Vector3(-this->vector[0], -this->vector[1], -this->vector[2]);
}

double Vector3::operator[](int i) const
{
    return this->vector[i];
}

double& Vector3::operator[](int i)
{
    return this->vector[i];
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    this->vector[0] += v.vector[0];
    this->vector[1] += v.vector[1];
    this->vector[2] += v.vector[2];
    
    return *this;
}

Vector3 Vector3::&operator*=(const double t)
{
    this->vector[0] *= t;
    this->vector[1] *= t;
    this->vector[2] *= t;
    
    return *this;
}

Vector3 &Vector3::operator/=(const double t)
{
    return *this *= 1/t;
}

double Vector3::length()
{
    return std::sqrt(length_squared());
}

double Vector3::length_squared()
{
    return this->vector[0]*this->vector[0] + this->vector[1]*this->vector[1] + this->vector[2]*this->vector[2];
}
