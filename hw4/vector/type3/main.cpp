#include "vector1.h"
#include <iostream>
#include <utility>

int main()
{
    // 1. Инициализация списком
    vector<double> v1 = {1.2, 7.89, 12.34};
    std::cout << "v1 (size=" << v1.size()
              << ", capacity=" << v1.capacity() << "): ";
    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << std::endl;

    // 2. Копирующий конструктор
    vector<double> v2 = v1;
    std::cout << "v2 (copy of v1, size=" << v2.size()
              << ", capacity=" << v2.capacity() << "): ";
    for (int i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';
    std::cout << std::endl;

    // 3. Копирующее присваивание
    vector<double> v3;
    v3 = v1;
    std::cout << "v3 (assigned from v1, size=" << v3.size()
              << ", capacity=" << v3.capacity() << "): ";
    for (int i = 0; i < v3.size(); ++i)
        std::cout << v3[i] << ' ';
    std::cout << std::endl;

    // 4. Перемещающий конструктор
    vector<double> v4 = std::move(v1);
    std::cout << "v4 (moved from v1, size=" << v4.size()
              << ", capacity=" << v4.capacity() << "): ";
    for (int i = 0; i < v4.size(); ++i)
        std::cout << v4[i] << ' ';
    std::cout << std::endl;
    std::cout << "v1 after move: size = " << v1.size()
              << ", capacity = " << v1.capacity() << std::endl;

    // 5. Перемещающее присваивание
    vector<double> v5;
    v5 = std::move(v4);
    std::cout << "v5 (moved from v4, size=" << v5.size()
              << ", capacity=" << v5.capacity() << "): ";
    for (int i = 0; i < v5.size(); ++i)
        std::cout << v5[i] << ' ';
    std::cout << std::endl;
    std::cout << "v4 after move: size = " << v4.size()
              << ", capacity = " << v4.capacity() << std::endl;

    // 6. Изменение элемента через operator[]
    v5[0] = 100.0;
    std::cout << "v5 after v5[0] = 100.0: ";
    for (int i = 0; i < v5.size(); ++i)
        std::cout << v5[i] << ' ';
    std::cout << std::endl;

    return 0;
}