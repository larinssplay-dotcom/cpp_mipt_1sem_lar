#include "vector.h"
#include <algorithm>
#include <utility>

// Конструктор по умолчанию
vector::vector()
    : sz{0}, elem{nullptr}
{
}

// Конструктор с размером
vector::vector(int s)
    : sz{s}, elem{new double[s]}
{
    for (int i = 0; i < sz; ++i)
        elem[i] = 0.0;
}

// Конструктор из списка инициализации
vector::vector(std::initializer_list<double> lst)
    : sz{static_cast<int>(lst.size())}, elem{new double[sz]}
{
    std::copy(lst.begin(), lst.end(), elem);
}

// Копирующий конструктор
vector::vector(const vector& arg)
    : sz{arg.sz}, elem{new double[arg.sz]}
{
    std::copy(arg.elem, arg.elem + arg.sz, elem);
}

// Копирующее присваивание
vector& vector::operator=(const vector& a)
{
    if (this == &a)
        return *this;

    double* p = new double[a.sz];
    std::copy(a.elem, a.elem + a.sz, p);

    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

// Перемещающий конструктор
vector::vector(vector&& a)
    : sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

// Перемещающее присваивание
vector& vector::operator=(vector&& a)
{
    if (this == &a)
        return *this;

    delete[] elem;
    elem = a.elem;
    sz = a.sz;

    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

// Деструктор
vector::~vector()
{
    delete[] elem;
}

int vector::size() const
{
    return sz;
}

double& vector::operator[](int n)
{
    return elem[n];
}

const double& vector::operator[](int n) const
{
    return elem[n];
}