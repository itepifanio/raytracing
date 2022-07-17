#include "../../include/helpers/visibilityTester.h"

VisibilityTester::VisibilityTester()
{
}

VisibilityTester::VisibilityTester(Surfel *s0, Surfel *s1)
{
    this->s0 = s0;
    this->s1 = s1;
}

bool VisibilityTester::unoccluded(Scene &scene)
{
    bool hit = false;
    std::cout << "16: before primitive loop" << std::endl;
    std::cout << s0->p.vector[0] << std::endl;
    std::cout << "18: s0 sucks" << std::endl;
    Ray *lightRay = new Ray(s0->p.toPoint(), s0->wo);
    std::cout << "18: before primitive loop" << std::endl;
    for (auto *pri : scene.getPrimitive())
    {
        std::cout << "26: primitive loop" << std::endl;
        if (pri->intersectP(*lightRay))
        {
            hit = true;
        }
    }

    std::cout << "26: visibilityTester::unoccluded" << std::endl;

    return hit;
}