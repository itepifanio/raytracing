#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "point.h"
#include "vector3.h"
#include "ray.h"
#include "lookat.h"
#include "film.h"

class Camera {
    protected:
        // defines the view plane specifing the horizontal and vertical limits:
        // left, right, bottom, top
        Point e;
        Vector3 u, v, w;
        std::tuple<float, float, float, float> screenWindow;
    public:
        Camera();
        Camera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        virtual ~Camera();
        virtual Ray generate_ray(int x, int y) = 0;

        std::tuple<float, float, float, float> getScreenWindow();
        
        static Camera* make(
            std::string type, Lookat lookat,
            std::tuple<float, float, float, float> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        static Camera* make(std::string type);
        static std::tuple<float, float, float, float> string_to_tuple(std::string tuple);

        Film film;
};

#endif
