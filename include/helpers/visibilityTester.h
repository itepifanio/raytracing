#ifndef _VISIBILITY_TEST_H
#define _VISIBILITY_TEST_H

class Scene;

#include "../../include/core/scene.h"
#include "../../include/shapes/surfel.h"

class VisibilityTester {
public:
    Surfel s0, s1;
    VisibilityTester();
    VisibilityTester(Surfel& s0, Surfel& s1);
    bool unoccluded(Scene &scene);
};

#endif
