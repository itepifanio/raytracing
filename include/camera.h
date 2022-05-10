#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "point.h"
#include "vector3.h"
#include "ray.h"

class Camera {
    protected:
        // defines the view plane specifing the horizontal and vertical limits:
        // left, right, bottom, top
        std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1);
    public:
        Point e;
        Vector3 u, v, w;
        Camera();
        Camera(Point e, Vector3 u, Vector3 v, Vector3 w);
        ~Camera();
        Ray generate_ray(int x, int y);
        std::tuple<float, float, float, float> getScreenWindow();
        static Camera* make(std::string type);
};

#endif
