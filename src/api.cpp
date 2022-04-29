#include "../include/api.h"

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

void render() {
    std::cout << "Render not implemented yet." << std::endl;
}