#include "rt3.h"

RunningOptions::RunningOptions() {}

RunningOptions::RunningOptions(std::string inputSceneFile) 
{
    this->inputSceneFile = inputSceneFile;
}

std::string RunningOptions::getSceneFile() 
{
    return this->inputSceneFile;
}
