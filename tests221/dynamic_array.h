#pragma once

// #include <cstdint> включает нужный cstddef для size_t
#include <cstddef> // Подключим тогда только его 

class DynamicArray
{
private:
    std::size_t size_;
    std::size_t capacity_;
    double* data_;

public:
    DynamicArray(); // 1. Конструктор по умолчанию
    DynamicArray(std::size_t capacity); // 2. Конструктор с заданным количеством ячеек для выделения в пямяти
    DynamicArray(std::size_t size, double value); // 3. Конструктор с заданным размером и элементами по умолчанию

    ~DynamicArray(); // 12. Деструктор
    
    DynamicArray(const DynamicArray& other); // 4.1. Конструктор копирования 
    DynamicArray(DynamicArray&& other);      // 4.2. Конструктор перемещения

    DynamicArray& operator=(const DynamicArray& other); // 5.1. Копирующий оператор присваивания
    DynamicArray& operator=(DynamicArray&& other);      // 5.2. Перемещающий оператор присваивания

    void assign(std::size_t size, double value); // 6. Метод assign - изменение текущего экземпляра до указанного размера с элементами == value

    double& at(std::size_t index);              // 7.1. Получить элемент по ссылке
    const double& at(std::size_t index) const;  // 7.2. Получить элемент по константной ссылке 
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;

    std::size_t size() const;       // 8.1. Получить количество заполненных ячеек
    std::size_t capacity() const;   // 8.2. Получить количество зарезервированных в пямяти ячеек

    void clear(); // 9. Очистить вектор

    bool empty() const; // 10. Узнать, пуст ли вектор (заполнена ли хоть одна ячейка)

    void pushBack(double value);    // 11.1. Положить элемент value в конец вектора (в первую незанятую ячейку)
    void popBack();                 // 11.2. Извлечь элемент с конца (с последней занятой ячейки)
};
