#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

class vector {
    int sz;          // размер
    double* elem;    // указатель на элементы
public:
    vector();                                       // конструктор по умолчанию

    explicit vector(int s);                         // конструктор с размером

    vector(std::initializer_list<double> lst);      // конструктор из списка

    vector(const vector& arg);                      // копирующий конструктор

    vector& operator=(const vector& a);             // копирующее присваивание

    vector(vector&& a);                             // перемещающий конструктор

    vector& operator=(vector&& a);                  // перемещающее присваивание
    
    ~vector();                                      // деструктор

    int size() const;

    double& operator[](int n);                      // неконстантный доступ
    const double& operator[](int n) const;          // константный доступ
};

#endif