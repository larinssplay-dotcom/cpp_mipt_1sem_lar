#include <iostream>
#include <vector>

int main()
{
    std::vector<double> vec(3,0);
    vec.assign({1.0, 2.0, 3.0});
    vec.assign(5, 2);

    double firstel = vec.at(0);
    firstel = vec[0];
    firstel = vec.front();
    double lastel = vec.back();

    vec.capacity();
    vec.size();
    // vec.clear();

    vec.data();
    
    double addedel = vec.emplace_back(2);
    vec.emplace_back(2.0, 3.0, 4.0);
    
    bool isempt = vec.empty();

    // vec.erase(iterator)
    // vec.insert(iterator)

    vec.max_size();

    vec.pop_back();
    vec.push_back(1.0);

    vec.reserve(3);

    vec.resize(5, 1.0);

    vec.shrink_to_fit();

    std::swap(vec[0], vec[1]);


    return 0;
}