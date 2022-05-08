#ifndef _POINT_H_ 
#define _POINT_H_

/*
Holds the space location i, j and a value.
The value is a integer representation of a rgb value
so it's on the 0..255 range.
*/

class Point {
    public:
        Point();
        Point(int i, int j, int value);
        int i;
        int j;
        int value;
        friend bool operator==(const Point& lhs, const Point& rhs);
        friend bool operator!=(const Point& lhs, const Point& rhs);
};

#endif