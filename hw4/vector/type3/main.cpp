#include "vector.h"
#include <iostream>
#include <string>

template<typename T>
void print(const std::string& label, const vector<T>& v)
{
    std::cout << label << " (size=" << v.size()
              << ", capacity=" << v.capacity() << "): ";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

int main()
{
    try {
        // 1. vector<int> и push_back
        vector<int> vi;
        for (int i = 0; i < 10; ++i)
            vi.push_back(i * i);
        print("vi", vi);

        // 2. vector<std::string> из списка инициализации
        vector<std::string> vs = {"alpha", "beta", "gamma"};
        print("vs", vs);

        // 3. resize с значением по умолчанию
        vs.resize(5, "?");
        print("vs after resize(5, \"?\")", vs);

        // 4. reserve
        vi.reserve(100);
        print("vi after reserve(100)", vi);

        // 5. Копирование
        vector<int> vi2 = vi;
        print("vi2 (copy of vi)", vi2);

        // 6. at() в пределах диапазона
        std::cout << "vi.at(3) = " << vi.at(3) << '\n';

        // 7. at() с выходом за границы — ожидаем исключение
        std::cout << "vi.at(100) = " << vi.at(100) << '\n'; // сюда не дойдём
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Перехвачено std::out_of_range: " << e.what() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Перехвачено std::exception: " << e.what() << '\n';
    }

    // 8. Перемещение
    vector<double> vd = {1.1, 2.2, 3.3};
    vector<double> vd2 = std::move(vd);
    print("vd2 (moved from vd)", vd2);
    std::cout << "vd.size() after move = " << vd.size() << '\n';

    return 0;
}