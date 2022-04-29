#include "../include/vector3.h"

Vector3::Vector3() {
    for (int i = 0; i < 3; i++)
    {
        this->vector[i] = 0;
    }
}

Vector3::Vector3(int e0, int e1, int e2)
{
    this->vector[0] = e0;
    this->vector[1] = e1;
    this->vector[2] = e2;
}

Vector3 Vector3::string_to_vector(std::string str)
{
    std::istringstream iss(str);
    std::vector<std::string> splited((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    int e0, e1, e2;
    std::istringstream(splited[0]) >> e0;
    std::istringstream(splited[1]) >> e1;
    std::istringstream(splited[2]) >> e2;
    
    return Vector3(e0, e1, e2);
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
