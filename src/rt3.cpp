#include "rt3.h"

RunningOptions::RunningOptions() 
{
    this->help = "Usage: rt3 [<options>] <input_scene_file>";
}

RunningOptions::~RunningOptions() {}

RunningOptions::RunningOptions(std::string inputSceneFile) 
{
    this->help = "Usage: rt3 [<options>] <input_scene_file>";
    this->inputSceneFile = inputSceneFile;
}

std::string RunningOptions::getSceneFile() 
{
    return this->inputSceneFile;
}
