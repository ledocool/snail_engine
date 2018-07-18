#include <iostream>
#include "engine/Engine.h"

int main(int argc __attribute__((unused)) , char **argv __attribute__((unused)) )
{
    std::cout << "Hello world!" << std::endl;
    Engine e = Engine();
    e.simpleFunction();
    return 0;
}