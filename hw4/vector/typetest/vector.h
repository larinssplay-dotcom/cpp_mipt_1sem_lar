#ifndef VECTOR1_H
#define VECTOR1_H

#include <memory>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>

// Версия вектора с аллокатором (глава 19)
template<typename T, typename A = std::allocator<T>>
class vector {
    using AT = std::allocator_traits<A>;

    A alloc;
    T* elem;
    int sz;
    int space;

public:
    vector();
    explicit vector(int s);
    vector(std::initializer_list<T> lst);

    vector(const vector& arg);
    vector& operator=(const vector& a);

    vector(vector&& a);
    vector& operator=(vector&& a);

    ~vector();

    T& operator[](int n);
    const T& operator[](int n) const;

    T& at(int n);
    const T& at(int n) const;

    int size() const;
    int capacity() const;

    void reserve(int newalloc);
    void resize(int newsize, T def = T());
    void push_back(const T& d);
};

// --- Реализация ---

template<typename T, typename A>
vector<T,A>::vector()
    : sz{0}, elem{nullptr}, space{0}
{
}

template<typename T, typename A>
vector<T,A>::vector(int s)
    : sz{s}, elem{alloc.allocate(s)}, space{s}
{
    for (int i = 0; i < sz; ++i)
        AT::construct(alloc, &elem[i], T());
}

template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst)
    : sz{static_cast<int>(lst.size())},
      elem{alloc.allocate(lst.size())},
      space{sz}
{
    std::uninitialized_copy(lst.begin(), lst.end(), elem);  // ✅
}

template<typename T, typename A>
vector<T,A>::vector(const vector& arg)
    : sz{arg.sz}, elem{alloc.allocate(arg.sz)}, space{arg.sz}
{
    std::uninitialized_copy(arg.elem, arg.elem + arg.sz, elem);  // ✅
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& a)
{
    if (this == &a) return *this;

    T* p = alloc.allocate(a.sz);
    std::uninitialized_copy(a.elem, a.elem + a.sz, p);

    for (int i = 0; i < sz; ++i)
        AT::destroy(alloc, &elem[i]);
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
    if (this == &a) return *this;

    for (int i = 0; i < sz; ++i)
        AT::destroy(alloc, &elem[i]);
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
        AT::destroy(alloc, &elem[i]);
    alloc.deallocate(elem, space);
}

template<typename T, typename A>
T& vector<T,A>::operator[](int n) { return elem[n]; }

template<typename T, typename A>
const T& vector<T,A>::operator[](int n) const { return elem[n]; }

template<typename T, typename A>
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
int vector<T,A>::size() const { return sz; }

template<typename T, typename A>
int vector<T,A>::capacity() const { return space; }

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;

    T* p = alloc.allocate(newalloc);
    std::uninitialized_copy(elem, elem + sz, p);

    for (int i = 0; i < sz; ++i)
        AT::destroy(alloc, &elem[i]);
    alloc.deallocate(elem, space);

    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T def)
{
    reserve(newsize);

    for (int i = sz; i < newsize; ++i)
        AT::construct(alloc, &elem[i], def);

    for (int i = newsize; i < sz; ++i)
        AT::destroy(alloc, &elem[i]);

    sz = newsize;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);

    AT::construct(alloc, &elem[sz], d);
    ++sz;
}

#endif // VECTOR1_H