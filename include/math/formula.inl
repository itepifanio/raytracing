#include <limits>
#include <utility>
#include <math.h>

double bhaskaraDelta(double a, double b, double c)
{
    return (b*b) - (4*a*c);
}

std::pair<int, int> bhaskara(double a, double b, double c)
{
    double delta = bhaskaraDelta(a, b, c);

    if(delta == 0) {
        double root = (-b)/(2*a);
        
        return std::make_pair(root, root);
    } else if(delta > 0) {
        double root1 = ((-b) - sqrt(delta))/(2*a);
        double root2 = ((-b) + sqrt(delta))/(2*a);
    
        return std::make_pair(root1, root2);
    }

    // doesnt have real roots
    double inf = std::numeric_limits<double>::infinity();
    
    return std::make_pair(inf, inf);
}