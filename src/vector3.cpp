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

double& Vector3::operator[](int const k)
{
    return this->vector[k];
}

double Vector3::operator[](int const k) const
{
    return this->vector[k];
}

Vector3& operator/=(Vector3& lhs, double const& rhs)
{
   lhs *= 1/rhs;

    return lhs; 
}

Vector3& operator*=(Vector3& lhs, double const& rhs)
{
    lhs.vector[0] *= rhs;
    lhs.vector[1] *= rhs;
    lhs.vector[2] *= rhs;
    
    return lhs;
}

Vector3& operator+=(Vector3& lhs,Vector3 const& rhs)
{
    lhs.vector[0] += rhs.vector[0];
    lhs.vector[1] += rhs.vector[1];
    lhs.vector[2] += rhs.vector[2];
    
    return lhs;
}

Vector3 operator+(Vector3 const& lhs, Vector3 const& rhs)
{
    Vector3 temp=lhs;
    temp+=rhs;
    return temp;
}

Vector3& operator-=(Vector3& lhs,Vector3 const& rhs)
{
    lhs.vector[0] -= rhs.vector[0];
    lhs.vector[1] -= rhs.vector[1];
    lhs.vector[2] -= rhs.vector[2];
    
    return lhs;
}

Vector3 operator-(Vector3 const& lhs, Vector3 const& rhs)
{
    Vector3 temp=lhs;
    temp-=rhs;
    return temp;
}

double Vector3::length()
{
    return std::sqrt(length_squared());
}

double Vector3::length_squared()
{
    return this->vector[0]*this->vector[0] + this->vector[1]*this->vector[1] + this->vector[2]*this->vector[2];
}
