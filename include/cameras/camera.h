#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../datatype/point.h"
#include "../datatype/vector3.h"
#include "../core/ray.h"
#include "./../datatype/lookat.h"
#include "../core/film.h"

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
        virtual void print(Ray ray) = 0;
        std::tuple<double, double, double, double> getScreenWindow();

        static Camera* make(
            std::string type, Lookat lookat,
            std::tuple<double, double, double, double> screenWindow = std::make_tuple(-1.555, 1.555, -1, 1)
        );
        static std::tuple<double, double, double, double> string_to_tuple(std::string tuple);
        std::tuple<double, double> getUVPos(int i, int j);
        Film film;
};

#endif
