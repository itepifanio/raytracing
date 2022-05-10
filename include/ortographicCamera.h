#ifndef _ORTOGRAPHIC_CAMERA_H_
#define _ORTOGRAPHIC_CAMERA_H_

#include "camera.h"
#include "ray.h"

class OrtographicCamera : public Camera{
    public:
        OrtographicCamera(
            std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        Ray generate_ray(int x, int y);
};

#endif
