#include <iostream>
int fib(int a,int b,int n)
{
    if (n>=1)
    {
        return fib(b,a+b,n-=1);
    }
    else
    {
        return b;
    }
}

int main()
{
    int n;
    std::cin>>n;
    std::cout << fib(0,1,n) << std::endl;
}