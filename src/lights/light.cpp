#include "../../include/lights/light.h"
#include "../../include/lights/ambientLight.h"
#include "../../include/lights/pointLight.h"
#include "../../include/lights/directionalLight.h"
#include "../../include/lights/spotLight.h"

Light* Light::make(
    std::string type,
    Vector3 i,
    Vector3 scale,
    Vector3 from,
    Vector3 to,
    double cutoff,
    double falloff
) {
    if (type.compare("ambient"))
    {
        return new AmbientLight(i);
    } 
    else if (type.compare("point"))
    {
        return new PointLight(i, scale, from);
    }
    else if (type.compare("directional"))
    {
        return new DirectionalLight(i, scale, from, to);
    }
    else if (type.compare("spot"))
    {
        return new SpotLight(i, scale, from, to, cutoff, falloff);
    }

    std::string cameraException = "Camera type " + type + " is not configured.";
    throw std::invalid_argument(cameraException);
}
