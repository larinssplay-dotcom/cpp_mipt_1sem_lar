#ifndef VECTOR1_H 
#define VECTOR1_H


#include <memory>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>
#include <iostream>

// Версия вектора с использованием аллокаторов глава 19
// Стандартный алокатор, чек доки
template<typename T, typename A = std::allocator<T>>
class vector {
    A alloc;          // распределитель памяти
    T* elem;          // указатель на элементы (или nullptr)
    int sz;           // количество элементов
    int space;        // размер выделенной памяти
public:
    // --- Конструкторы ---
    vector();
    explicit vector(int s);
    vector(std::initializer_list<T> lst);

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

    T& at(int n);                    // с проверкой рэнджа
    const T& at(int n) const;

    // --- Размеры и ёмкость ---
    int size() const;
    int capacity() const;

    // --- Управление размером ---
    void reserve(int newalloc);
    void resize(int newsize, T def = T());
    void push_back(const T& d);
};

// Реализация

template<typename T, typename A>
vector<T,A>::vector()
    : sz{0}, elem{nullptr}, space{0}
{
}

template<typename T, typename A>
vector<T,A>::vector(int s)
    : sz{s}, elem{alloc.allocate(s)}, space{s}
{
    // инициализируем элементы знач по умолчанию
    for (int i = 0; i < sz; ++i)
        alloc.construct(&elem[i], T());
}

// Конструктор из initializer_listпамять через аллокатор.
template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst)
    : sz(lst.size()),
      elem{alloc.allocate(lst.size())},
      space{sz}
{
    std::uninitialized_copy(lst.begin(), lst.end(), elem);
}

template<typename T, typename A>
vector<T,A>::vector(const vector& arg)
    : sz{arg.sz}, elem{alloc.allocate(arg.sz)}, space{arg.sz}
{
    std::uninitialized_copy(arg.elem, arg.elem + arg.sz, elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& a)
{
    if (this == &a)
        return *this;

    T* p = alloc.allocate(a.sz);
    std::uninitialized_copy(a.elem, a.elem + a.sz, p);

    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);

    elem = p;
    sz = a.sz;
    space = a.sz;
    return *this;
}

template<typename T, typename A>
vector<T,A>::vector(vector&& a)
    : sz{a.sz}, elem{a.elem}, space{a.space}
{
    a.sz = 0;
    a.elem = nullptr;
    a.space = 0;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& a)
{
    if (this == &a)
        return *this;

    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);

    elem = a.elem;
    sz = a.sz;
    space = a.space;

    a.elem = nullptr;
    a.sz = 0;
    a.space = 0;
    return *this;
}

template<typename T, typename A>
vector<T,A>::~vector()
{
    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
}

template<typename T, typename A>
T& vector<T,A>::operator[](int n)
{
    return elem[n];
}

template<typename T, typename A>
const T& vector<T,A>::operator[](int n) const
{
    return elem[n];
}

template<typename T, typename A> //с проверкой на рендж и исключениями
T& vector<T,A>::at(int n)
{
    if (n < 0 || sz <= n)
        throw std::out_of_range("vector::at: index out of range");
    return elem[n];
}

template<typename T, typename A>
const T& vector<T,A>::at(int n) const
{
    if (n < 0 || sz <= n)
        throw std::out_of_range("vector::at: index out of range");
    return elem[n];
}

template<typename T, typename A>
int vector<T,A>::size() const
{
    return sz;
}

template<typename T, typename A>
int vector<T,A>::capacity() const
{
    return space;
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;

    T* p = alloc.allocate(newalloc);
    for (int i = 0; i < sz; ++i)
        alloc.construct(&p[i], elem[i]);   // копируем элементы

    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]);           // уничтожаем старые
    alloc.deallocate(elem, space);         // освобождаем память

    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T def)
{
    reserve(newsize);

    for (int i = sz; i < newsize; ++i)
        alloc.construct(&elem[i], def);    // инициализация новых

    for (int i = newsize; i < sz; ++i)
        alloc.destroy(&elem[i]);           // уничтожение лишних

    sz = newsize;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);

    alloc.construct(&elem[sz], d);         // копируем d в конец
    ++sz;
}

#endif