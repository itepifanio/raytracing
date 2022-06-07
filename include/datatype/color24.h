#ifndef _COLOR24_H_ 
#define _COLOR24_H_

/*
Used to define a small piece of an image. 
The color24 holds the r, g, b structure.
*/

class Color24 {
    public:
        int r;
        int g;
        int b;
        Color24();
        Color24(int r, int g, int b);
        ~Color24();
};

#endif