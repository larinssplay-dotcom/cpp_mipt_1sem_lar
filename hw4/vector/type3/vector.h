#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>

template<typename T>
class vector {
    int sz;          // количество элементов
    T* elem;         // указатель на элементы (или nullptr)
    int space;       // размер выделенной памяти
public:
    // --- Конструкторы ---
    vector();                                    // по умолчанию
    explicit vector(int s);                      // с размером
    vector(std::initializer_list<T> lst);        // из списка инициализации

    // --- Копирование ---
    vector(const vector& arg);
    vector& operator=(const vector& a);

    // --- Перемещение ---
    vector(vector&& a);
    vector& operator=(vector&& a);

    // --- Деструктор ---
    ~vector();

    // --- Доступ к элементам ---
    T& operator[](int n);
    const T& operator[](int n) const;

    T& at(int n);                                // с проверкой диапазона
    const T& at(int n) const;

    // --- Размеры и ёмкость ---
    int size() const;
    int capacity() const;

    // --- Управление размером ---
    void reserve(int newalloc);
    void resize(int newsize, T def = T());
    void push_back(const T& d);
};


template<typename T>
vector<T>::vector()
    : sz{0}, elem{nullptr}, space{0}
{
}

template<typename T>
vector<T>::vector(int s)
    : sz{s}, elem{new T[s]{}}, space{s}
{
}

template<typename T>
vector<T>::vector(std::initializer_list<T> lst)
    : sz{static_cast<int>(lst.size())},
      elem{new T[lst.size()]},
      space{sz}
{
    std::copy(lst.begin(), lst.end(), elem);
}

template<typename T>
vector<T>::vector(const vector& arg)
    : sz{arg.sz}, elem{new T[arg.sz]}, space{arg.sz}
{
    std::copy(arg.elem, arg.elem + arg.sz, elem);
}

template<typename T>
vector<T>& vector<T>::operator=(const vector& a)
{
    if (this == &a)
        return *this;

    T* p = new T[a.sz];
    std::copy(a.elem, a.elem + a.sz, p);

    delete[] elem;
    elem = p;
    sz = a.sz;
    space = a.sz;
    return *this;
}

template<typename T>
vector<T>::vector(vector&& a)
    : sz{a.sz}, elem{a.elem}, space{a.space}
{
    a.sz = 0;
    a.elem = nullptr;
    a.space = 0;
}

template<typename T>
vector<T>& vector<T>::operator=(vector&& a)
{
    if (this == &a)
        return *this;

    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    space = a.space;

    a.elem = nullptr;
    a.sz = 0;
    a.space = 0;
    return *this;
}

template<typename T>
vector<T>::~vector()
{
    delete[] elem;
}

template<typename T>
T& vector<T>::operator[](int n)
{
    return elem[n];
}

template<typename T>
const T& vector<T>::operator[](int n) const
{
    return elem[n];
}

template<typename T>
T& vector<T>::at(int n)
{
    if (n < 0 || sz <= n)
        throw std::out_of_range("vector::at: index out of range");
    return elem[n];
}

template<typename T>
const T& vector<T>::at(int n) const
{
    if (n < 0 || sz <= n)
        throw std::out_of_range("vector::at: index out of range");
    return elem[n];
}

template<typename T>
int vector<T>::size() const
{
    return sz;
}

template<typename T>
int vector<T>::capacity() const
{
    return space;
}

template<typename T>
void vector<T>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;

    T* p = new T[newalloc];
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];

    delete[] elem;
    elem = p;
    space = newalloc;
}

template<typename T>
void vector<T>::resize(int newsize, T def)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = def;
    sz = newsize;
}

template<typename T>
void vector<T>::push_back(const T& d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);
    elem[sz] = d;
    ++sz;
}

#endif