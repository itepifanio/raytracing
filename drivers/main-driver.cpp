#include <iostream>
#include "../src/parser.cpp"
// #include "../src/api.cpp"
// #include "../src/background.cpp"

int main(int argc, char** argv)
{
    Api api;

    parser(argv[1], api.film, api.background);
    api.render();
    return 0;
}
