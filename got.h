
#include <iostream>
#include <random>

int rd_ges()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> disturb(1, 100);
    int rand_num = disturb(gen);
    int ges;
    std::cin>>ges;
    while (ges != rand_num)
    {
        if(ges > rand_num)
        {
            std::cout << "less" << std::endl;
            std::cin>>ges;
        }
        else if(ges < rand_num)
        {
            std::cout << "more" << std::endl;
            std::cin>>ges;
        }
    }
    std::cout << "gotcha" << std::endl;
    return 0;
}