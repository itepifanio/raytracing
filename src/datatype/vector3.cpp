#include "../include/datatype/vector3.h"
#include "../include/datatype/point.h"

Vector3::Vector3()
{
    for (int i = 0; i < 3; i++)
    {
        this->vector[i] = 0;
    }
}

Vector3::Vector3(Pixel pixel)
{
    this->vector[0] = pixel.r;
    this->vector[1] = pixel.g;
    this->vector[2] = pixel.b;
}

Vector3::Vector3(double e0, double e1, double e2)
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

    double e0, e1, e2;
    std::istringstream(splited[0]) >> e0;
    std::istringstream(splited[1]) >> e1;
    std::istringstream(splited[2]) >> e2;

    return Vector3(e0, e1, e2);
}

double &Vector3::operator[](int const k)
{
    return this->vector[k];
}

double Vector3::operator[](int const k) const
{
    return this->vector[k];
}

Vector3 &operator/=(Vector3 &lhs, double const &rhs)
{
    lhs *= 1 / rhs;

    return lhs;
}

Vector3 &operator*=(Vector3 &lhs, double const &rhs)
{
    lhs.vector[0] *= rhs;
    lhs.vector[1] *= rhs;
    lhs.vector[2] *= rhs;

    return lhs;
}


Vector3 operator*(Vector3 const &lhs, double const rhs)
{
    Vector3 v;
    v.vector[0] = lhs.vector[0] * rhs;
    v.vector[1] = lhs.vector[1] * rhs;
    v.vector[2] = lhs.vector[2] * rhs;

    return v;
}

double operator*(Vector3 const &rhs, Vector3 const &lhs)
{
    Vector3 v;
    return (rhs[0] * lhs[0]) + (rhs[1] * lhs[1]) + (rhs[2] * lhs[2]);
}

Vector3 operator/(Vector3 const &lhs, double const rhs)
{
    double r = 1/rhs;
    Vector3 v;
    v.vector[0] = lhs.vector[0]*r;
    v.vector[1] = lhs.vector[1]*r;
    v.vector[2] = lhs.vector[2]*r;

    return v;
}

Vector3 operator*( double const rhs, Vector3 const &lhs)
{
    return lhs * rhs;
}

Vector3 &operator+=(Vector3 &lhs, Vector3 const &rhs)
{
    lhs.vector[0] += rhs.vector[0];
    lhs.vector[1] += rhs.vector[1];
    lhs.vector[2] += rhs.vector[2];

    return lhs;
}

Vector3 operator+(Vector3 const &lhs, Vector3 const &rhs)
{
    Vector3 temp = lhs;
    temp += rhs;
    return temp;
}

Vector3 &operator-=(Vector3 &lhs, Vector3 const &rhs)
{
    lhs.vector[0] -= rhs.vector[0];
    lhs.vector[1] -= rhs.vector[1];
    lhs.vector[2] -= rhs.vector[2];

    return lhs;
}

Vector3 operator-(Vector3 const &lhs, Vector3 const &rhs)
{
    Vector3 temp = lhs;
    temp -= rhs;
    return temp;
}

double Vector3::length()
{
    return sqrt(this->length_squared());
}

Pixel Vector3::toPixel()
{
    Pixel pixel(this->vector[0], this->vector[1], this->vector[2]);

    return pixel;
}

Color24 Vector3::toColor24()
{
    Color24 color24(this->vector[0], this->vector[1], this->vector[2]);

    return color24;
}

Point Vector3::toPoint()
{
    Point point(this->vector[0], this->vector[1], this->vector[2]);

    return point;
}

double Vector3::length_squared()
{
    return this->vector[0] * this->vector[0] + this->vector[1] * this->vector[1] + this->vector[2] * this->vector[2];
}
