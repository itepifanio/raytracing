#include "../include/api.h"

Api::Api(RunningOptions options)
{
    this->options = options;
}

void Api::parser()
{
}

void Api::render()
{
    /*
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
    */
}
