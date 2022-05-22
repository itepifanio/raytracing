#include "../include/point.h"

Point::Point() {}

Point::Point(int i, int j, int value)
{
    this->i = i;
    this->j = j;
    this->value = value;
}

bool operator==(const Point& lhs, const Point& rhs)
{
    return lhs.i == rhs.i && lhs.j == rhs.j && lhs.value == rhs.value;
}

Vector3 Point::toVector3()
{
    return Vector3(this->i, this->j, this->value);
}

bool operator!=(const Point& lhs, const Point& rhs)
{
    return ! (lhs == rhs);
}
