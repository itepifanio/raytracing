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
        std::tuple<double, double, double, double> screenWindow;
    public:
        Camera();
        Point getE();
        Vector3 getU();
        Vector3 getV();
        Vector3 getW();
        Camera(
            Point e, Vector3 u, Vector3 v, Vector3 w,
            std::tuple<double, double, double, double> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        virtual ~Camera();
        virtual Ray generate_ray(int x, int y) = 0;
        std::tuple<double, double, double, double> getScreenWindow();

        static Camera* make(
            std::string type, Lookat lookat,
            std::tuple<double, double, double, double> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        static std::tuple<double, double, double, double> string_to_tuple(std::string tuple);
        static Camera* make(std::string type);

        Film film;
};

#endif
