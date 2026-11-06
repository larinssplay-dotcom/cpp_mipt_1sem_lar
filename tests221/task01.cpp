#include <iostream>
int main()
{
    unsigned long long fact = 1;
    int n = 0;
    std::cin>>n;
    if (n>=0){
        for (size_t i = 1; i < n+1; i++)
        {
            fact *= i;
        }
        std::cout << fact << std::endl;
    }

}