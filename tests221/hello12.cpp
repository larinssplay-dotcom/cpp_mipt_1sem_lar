
#include <iostream>
#include <string>

#include "answ1.h"

#include "hello1.h"

void hello();

void hello()
{
    std::cout << "Hello,World!\nWats your name?\n";
    std::string name2 = answ();
    std::cout << "My name is " << name2 << "\n";

}