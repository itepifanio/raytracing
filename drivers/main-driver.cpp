#include "../include/ppmreader.h"
#include <iostream>


int main()
{
    PPM3Reader reader("./tests/fixtures/test.ppm");
    std::cout << reader.getType() << std::endl;
    return 0;
}
