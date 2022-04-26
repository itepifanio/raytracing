#pragma once

#include <iostream>
#include "../include/film.h"
#include "../include/background.h"


class Api
{
public:
    static Api& Instance()
    {
        static Api api;
        return api;
    }
    Api(Api const&) = delete;
    Api(Background background, Film film) {
        this->background = background;
        this->film = film;
    }
    void operator=(Api const&) = delete;
    void render() {
        std::cout << "Render not implemented yet." << std::endl;
    }
private:
	Api() {};
    Background background;
    Film fiml;
};
