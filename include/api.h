#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "film.h"
#include "rt3.h"
#include "background.h"

class Api
{
    private:
        void parser();
        RunningOptions options;
        //Background background;
        //Film film;
    public:
        Api(RunningOptions options);
        void render();
};
#endif
