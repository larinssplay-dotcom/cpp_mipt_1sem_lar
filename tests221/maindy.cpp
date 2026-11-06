#include <iostream>
#include <vector>
#include <algorithm>

#include "dynamic_array.h"

int main()
{
    std::vector<double> vec(3, 0);
    // 1. Конструктор по умолчанию consructor()
    // 2. Конструктор с заданным размером constructor(size)
    // 3. Конструктор с заданным размером и элементами по умолчанию constructor(size, value)
    // 4. Конструктор копирования, конструктор перемещения
    // 5. Оператор присваиния (копирующий, перемещающий)
    
    vec.assign({1.0, 2.0, 3.0}); // <--- изменение вектора по списку инициализации
    // 6. Метод assign
    vec.assign(5, 2); // <--- изменение вектора по количеству элементов и значениям по умолчанию

    // 7. Метод at
    double firstElement = vec.at(0); // <--- обращение к элементу вектора по индексу
    firstElement = vec[0];

    firstElement = vec.front(); // <--- получить первый элемент
    double lastElement = vec.back(); // <--- получить последний элемент

    // 8. Методы size и capacity
    std::size_t capacity = vec.capacity(); // <--- получить количество зарезервинных ячеек в пямяти
    std::size_t size = vec.size(); // <--- получить количество занятых ячеек

    // 9. Метод clear
    vec.clear(); // <--- очищает вектор полностью (стирает данные, высвобождает память)
    
    double* data = vec.data(); // <--- получить указатель на первую ячейку данных

    // vec.emplace(iterator) <--- замена элемента по итератору
    
    double addedElement = vec.emplace_back(2); // <--- добавить !сконструированный на месте! элемент в конец и получить на него ссылку
    // vec.emplace_back(2.0, 3.0, 4.0); // <--- добавить !сконструированный на месте по набору аргументов! (вызов параметризированного конструктора с аргументами) элемент в конец
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ в данном случае у double нет конструктора с тремя параметрами

    // 10. Метод empty
    bool isEmpty = vec.empty(); // <--- проверить на пустоту

    // vec.erase(iterator) <--- извлечь элемент из вектора по итератору
    // vec.insert(iterator) <--- вставить элемент в вектор по итератору

    size = vec.max_size(); // <--- получить максимально возможный размер вектора

    // 11. Методы push_back и pop_back
    vec.pop_back(); // <--- извекает элемент с конца 
    vec.push_back(1.0); // <--- добавляет элемент в конец без получения ссылки на элемент

    vec.reserve(3); // <--- зарезервировать указанное количество элементов в памяти без изменения заполненных ячеек
    // Если указанное количество ячеек меньше, чем есть в векторе, то ничего не происходит
    // Иначе - увеличение capacity до указанной величины
    vec.resize(5, 1.0); // <--- изменить размер вектора (с указанием элементов или без)
    vec.reserve(10);

    vec.shrink_to_fit(); // <--- уменьшает capacity до значения size (освобождает лишние зарезервированные ячейки в памяти)

    // vec.swap(vector otherVec) // <--- поменять местами экземпляр vec с экземпляром otherVec
    std::swap(vec[0], vec[1]);

    // 12. Деструктор

    // Тест DynamicArray
    DynamicArray arr(10, 3.14);
    std::cout << arr.empty() << std::endl;
    std::cout << arr.at(1) << std::endl;
    arr[1] = 2.71;
    std::cout << arr[1] << std::endl;
    std::cout << arr.size() << std::endl;
    std::cout << arr.capacity() << std::endl;
    arr.pushBack(10.0);
    std::cout << arr.size() << std::endl;
    std::cout << arr[arr.size()-1] << std::endl;
    arr.popBack();
    std::cout << (arr.size() == 10) << std::endl;
    arr.clear();
    std::cout << arr.empty() << std::endl;
    std::cout << arr.size() << std::endl;
    std::cout << arr.capacity() << std::endl;   
    arr = std::move(DynamicArray(5, 5.0));
    std::cout << arr.empty() << std::endl;
    std::cout << arr.size() << std::endl;
    std::cout << arr.capacity() << std::endl;   
    std::cout << arr[arr.size()-1] << std::endl;

    return 0;
}