#ifndef _PIXEL_H_ 
#define _PIXEL_H_

/*
Used to define a small piece of an image. 
The pixel holds the r, g, b structure.
*/

class Pixel {
    public:
        Pixel();
        Pixel(int r, int g, int b);
        int r;
        int g;
        int b;
        friend bool operator==(const Pixel& lhs, const Pixel& rhs);
        friend bool operator!=(const Pixel& lhs, const Pixel& rhs);
};

#endif