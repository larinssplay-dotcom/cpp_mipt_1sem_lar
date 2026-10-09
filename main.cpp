#include <iostream>

#include "shape.h"

#include <cmath>

int main()
{
    Rectangular rec(3.0, 1.0);
    std::cout << rec << std::endl;

    Circle cir(5.0);
    std::cout << cir << std::endl;

    Square sq(5.0, 4.0);
    std::cout << sq << std::endl;

    Triangle tr(1.0, 2.0, 2.0);
    std::cout << tr << std::endl;

    std::cout << (rec == cir) << std::endl;
    std::cout << (rec ^ cir ) << std::endl;
    
}
