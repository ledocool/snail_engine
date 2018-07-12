#include <iostream>
#include "engine/Engine.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
    Engine e = Engine();
    e.simpleFunction();
    return 0;
}