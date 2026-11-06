#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <list>
#include <map>


int main()
{
    std::vector<int> vec{4, 0, 2, 1, 3};

    // Проходимся по диапазону [vec.begin, vec.end) || end указывает за конец вектора
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
        // std::cout << it << ' ';
    }
    std::cout << std::endl;

    // Категории итераторов:
    // 1. Output-iterator --- только для записи (единоразовой) элементов || Определена операция ++ --- смещение итератора на один элемент
    // 2. Input-iterator --- чтение (многократное) || Определены операции ++, ==, !=
    // 3. Forward-iterator --- чтение/запись, многопроходные, можно копировать || Пример объекта: односвязный линейный список
    // 4. Bidirectional-iterator --- всё, что выше и определа операция -- || Пример: двусвязный линейный список, set, map
    // 5. Random access - iterator --- всё, что выше и определены операции +, -, [], <, > || Пример объекта: vector

    std::sort(vec.begin(), vec.end());
    for (auto elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    std::list<int> list1{3, 1, 2, 0};
    // std::sort(list1.begin(), list1.end());
    // std::sort(begin(list1), end(list1));
    list1.sort();
    for (auto elem : list1)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    auto begIt = vec.begin();
    std::advance(begIt, 3);
    std::cout << *begIt << std::endl;
    std::advance(begIt, -3);
    std::cout << *begIt << std::endl;
    std::advance(begIt, 6);
    std::cout << *begIt << std::endl;

    auto distance = std::distance(vec.begin(), begIt);
    std::cout << distance << std::endl;

    auto iter1 = std::next(vec.begin(), 2);
    std::cout << *iter1 << std::endl;
    auto iter2 = std::prev(vec.end(), 3);
    std::cout << *iter2 << std::endl;

    for (auto revIt = vec.rbegin(); revIt != vec.rend(); ++revIt)
    {
        std::cout << *revIt << ' ';
    }
    std::cout << std::endl;

    auto iter3 = vec.begin();
    vec.push_back(5);
    std::cout << *iter3 << std::endl;
    iter3 = vec.begin();
    std::cout << *iter3 << std::endl;
    // Надо следить за инвалидацией итераторов при работе с векторами или со строками
    // Векторы/Строки --- при вставке элемента в случае перевыделения памяти инвалидируются все итераторы,
    // при удалении элемента инвалидируются итераторы от точки удаления до конца
    // Двунаправленная очередь (deque) --- инвалидируются все итераторы и при вставке, и при удалении элемента
    // Словарь (map) и множество (set), списки (односвязные и двусвязные) --- вставка не инвалидирует итераторы, 
    // удаление инвалидирует только итератор удаляемого элемента

    std::map<int, int> m{{1, 10}, {2, 20}, {3, 30}};
    auto it = m.begin();
    for (; it != m.end(); )
    {
        if (it->first == 2)
        {
            it = m.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (const auto& [key, value] : m)
    {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << it->first << ": " << it->second << std::endl;
    // it++;
    // std::cout << it->first << ": " << it->second << std::endl;

    // Практическая задача: получить сумму элементов на четных позициях вектора
    for (auto elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    int summ = 0;
    for (auto it = vec.begin() + 1; it < vec.end(); std::advance(it, 2)){
        summ += *it;
    }
    std::cout << summ << std::endl;

}