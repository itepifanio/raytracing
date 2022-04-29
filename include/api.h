#ifndef _API_H_ 
#define _API_H_

#include <iostream>
#include "film.h"
#include "background.h"

class Api
{
    private:
        Background background;
        Film film;
    public:
        static Api& Instance()
        {
            static Api api;
            return api;
        }
        // Api(Api const&) = delete;
        Api();
        Api(Background background, Film film);
        void setBackground(Background Background);
        void setFilm(Film Film);
        void operator=(Api const&) = delete;
        void render() {
            std::cout << "Render not implemented yet." << std::endl;
        }
};
#endif