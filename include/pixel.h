#ifndef _PIXEL_H_ 
#define _PIXEL_H_

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