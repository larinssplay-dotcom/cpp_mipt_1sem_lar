#include "vector.h"

vector::vector(int s)
    : sz{s}, elem{new double[s]}
{
    for (int i = 0; i < sz; ++i)
        elem[i] = 0.0;
}

vector::~vector()
{
    delete[] elem;
}

int vector::size() const
{
    return sz;
}

double vector::get(int n) const
{
    return elem[n];
}

void vector::set(int n, double v)
{
    elem[n] = v;
}