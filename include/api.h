#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "film.h"
#include "background.h"

class Api
{
    private:
    public:
        Background background;
        Film film;
        // static Api& Instance()
        // {
        //     static Api api;
        //     return api;
        // }
        // Api(Api const&) = delete;
        Api(Background background, Film film);
        void setBackground(Background background);
        void setFilm(Film Film);
        void operator=(Api const&) = delete;
        void render();
};
#endif
