#include "vector.h"
#include <iostream>
#include <utility>

int main()
{
    // 1. Инициализация списком
    vector v1 = {1.2, 7.89, 12.34};
    std::cout << "v1: " << std::endl;
    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << std::endl;

    // 2. Копирующий конструктор
    vector v2 = v1;
    std::cout << "v2 (copy of v1): " << std::endl;
    for (int i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';
    std::cout << std::endl;

    // 3. Копирующее присваивание
    vector v3;
    v3 = v1;
    std::cout << "v3 (assigned from v1): ";
    for (int i = 0; i < v3.size(); ++i)
        std::cout << v3[i] << ' ';
    std::cout << std::endl;

    // 4. Перемещающий конструктор
    vector v4 = std::move(v1);
    std::cout << "v4 (moved from v1): ";
    for (int i = 0; i < v4.size(); ++i)
        std::cout << v4[i] << ' ';
    std::cout << std::endl;
    std::cout << "v1 after move: size = " << v1.size() << std::endl;

    // 5. Перемещающее присваивание
    vector v5;
    v5 = std::move(v4);
    std::cout << "v5 (moved from v4): ";
    for (int i = 0; i < v5.size(); ++i)
        std::cout << v5[i] << ' ';
    std::cout << std::endl;
    std::cout << "v4 after move: size = " << v4.size() << std::endl;

    // 6. Изменение элемента через operator[]
    v5[0] = 100.0;
    std::cout << "v5 after v5[0] = 100.0: ";
    for (int i = 0; i < v5.size(); ++i)
        std::cout << v5[i] << ' ';
    std::cout << std::endl;

    return 0;
}
