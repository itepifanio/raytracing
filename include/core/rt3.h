#ifndef _RT3_H_ 
#define _RT3_H_

#include <string>

class RunningOptions {
    private:
        std::string help;
        std::string inputSceneFile;
        //int cropwindows[4]; // x0, x1, y0, y1
        //bool quick = false;
        //std::string outfile = "";
    public:
        RunningOptions();
        RunningOptions(std::string inputSceneFile);
        ~RunningOptions();
        std::string getSceneFile();
};

#endif