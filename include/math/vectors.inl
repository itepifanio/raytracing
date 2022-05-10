#include "../vector3.h"

inline Vector3 cross(Vector3 u, Vector3 v) {
    int uvi, uvj, uvk;
    uvi = u[1] * v[2] - v[1] * u[2];
    uvj = v[0] * u[2] - u[0] * v[2];
    uvk = u[0] * v[1] - v[0] * u[1];

    Vector3 result(uvi, uvj, uvk);

    return result;
}

inline Vector3 normalize(Vector3 v) {
    return v /= sqrtf(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}