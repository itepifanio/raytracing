#include "../include/api.h"

Api::Api() {
    this->background = Background();
    this->film = Film();
}

Api::Api(Background background, Film film) {
    this->background = background;
    this->film = film;
}

void Api::setBackground(Background Background) {
    this->background = background;
}
void Api::setFilm(Film Film) {
    this->film = film;
}

void Api::render() {
    auto w = this->film.width();
    auto h = this->film.height();

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            // get background color.
            Vector3 pixel = this->background.interpolate(float(i) / float(w), float(j) / float(h));
            this->film.setPixel(i, j, pixel);
        }
    }
    this->film.toPPM();
}