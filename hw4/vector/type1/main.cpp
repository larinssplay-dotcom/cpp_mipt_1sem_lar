#include "vector.h"
#include <iostream>

int main()
{
    vector v(5);

    for (int i = 0; i < v.size(); ++i)
        v.set(i, 1.1 * i);

    for (int i = 0; i < v.size(); ++i)
        std::cout << "v[" << i << "] == " << v.get(i) << '\n';

    return 0;
}