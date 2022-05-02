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

bool operator!=(const Point& lhs, const Point& rhs)
{
    return ! (lhs == rhs);
}
