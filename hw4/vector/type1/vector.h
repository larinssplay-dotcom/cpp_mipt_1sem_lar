#ifndef VECTOR_H
#define VECTOR_H

class vector {
    int sz;          // размер
    double* elem;    // указатель на элементы
public:
    vector(int s);   // конструктор
    ~vector();       // деструктор

    int size() const;
    double get(int n) const;
    void set(int n, double v);
};

#endif