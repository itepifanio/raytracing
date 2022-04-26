#pragma once

#include <iostream>
#include "../include/film.h"
#include "../include/background.h"

class Api
{
    Film film;
    Background background;

    static Api &getInstanceImpl(Background *const background = nullptr, Film *const film = nullptr)
    {
        static Api instance{background, film};
        return instance;
    }

    Api(Background *const background, Film *const film)
    {
        this->background = background ? std::move(*background) : Background{};
        this->film = film ? std::move(*film) : Film{};

        if (film == nullptr || background == nullptr) {
            throw std::runtime_error{"Api not initialized"};
        }
    }

public:
    static Api &getInstance()
    {
        return getInstanceImpl();
    }
    
    static void init(Background background, Film film)
    {
        getInstanceImpl(&background, &film);
    }
    Api(Api const &) = delete;
    void operator=(Api const &) = delete;
};
