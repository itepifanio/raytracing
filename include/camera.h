#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ray.h"

class Camera{
    protected:
        // defines the view plane specifing the horizontal and vertical limits:
        // left, right, bottom, top
        std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1);
    public:
        Camera();
        virtual ~Camera();
        virtual Ray generate_ray(int x, int y) = 0;
        std::tuple<float, float, float, float> getScreenWindow();
        static Camera* make(std::string type);
};

#endif
