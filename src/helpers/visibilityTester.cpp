#include "../../include/helpers/visibilityTester.h"

VisibilityTester::VisibilityTester()
{

}
    
VisibilityTester::VisibilityTester(Surfel& s0, Surfel& s1)
{
    this->s0 = s0;
    this->s1 = s1;
}
    
bool VisibilityTester::unoccluded(Scene& scene)
{
    // TODO::implement
    return false;
}