#include <iostream>
#include "../src/parser.cpp"

int main(int argc, char** argv)
{
    parser(argv[1]);
    std::cout << "Main loop of raytracing" << std::endl;
    return 0;
}
