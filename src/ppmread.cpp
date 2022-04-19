#include "../include/ppmreader.h"
#include <iostream>
#include <fstream>
#include <sstream>

void PPM3Reader::split(std::string &str, char delim, std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}


PPM3Reader::PPM3Reader(std::string filename) {
    std::ifstream file;
    file.open(filename);
    std::cout << "Opening: " << filename << std::endl;
    if(file.is_open()) {
        std::cout << "File open" << std::endl;
        // get type
        std::string line;
        std::getline(file,line);
        this->type = line;

        std::cout << "Type " << this->type << std::endl;

        // get columns and row
        std::vector<std::string> size;
        std::getline(file,line);
        this->split(line, ' ', size);
        this->columns = stoi(size[0]);
        this->rows = stoi(size[1]);

        // get max color
        std::getline(file,line);
        this->maxColor = stoi(line);
    }
}

std::string PPM3Reader::getType()
{
    return this->type;
}

int PPM3Reader::getColumns()
{
    return this->columns;
}

int PPM3Reader::getRows()
{
    return this->rows;
}

int PPM3Reader::getMaxColor()
{
    return this->maxColor;
}