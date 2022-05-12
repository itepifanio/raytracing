#include "../vector3.h"

inline Vector3 cross(Vector3 u, Vector3 v) {
    int uvi, uvj, uvk;
    uvi = (u[1] * v[2]) - (u[2] * v[1]);
    uvj = (u[2] * v[0]) - (u[0] * v[2]);
    uvk = (u[0] * v[1]) - (u[1] * v[0]);

    Vector3 result(uvi, uvj, uvk);

    return result;
}

inline Vector3 normalize(Vector3 v) {
    return v /= v.length();
}
