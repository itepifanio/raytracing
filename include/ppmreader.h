#ifndef _PPMREADER_H_ 
#define _PPMREADER_H_

#include <string>
#include <vector>

class PPM3Reader {
    private:
        int columns;
        int rows;
        std::string type;
        int maxColor;
        // TODO::Change from int to Pixel
        std::vector<std::vector<int>> content;
        // TODO::Move to a helpers hpp
        void split(std::string &str, char delim, std::vector<std::string> &out);
    public:
        PPM3Reader(std::string file);
        std::string getType();
        int getColumns();
        int getRows();
        int getMaxColor();
};

#endif