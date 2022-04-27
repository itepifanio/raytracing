#include <string>

struct RunningOptions
{
    std::string help;
    int cropwindows[4]; // x0, x1, y0, y1
    bool quick;
    std::string outfile;
};
