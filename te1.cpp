#include <iostream>
#include <string>
#include <array>

int main()
{
    std::array <std::string, 12> mnth{"jan","feb","mar","apr","may",
        "jun","jul","aug","sep","oct","nov","dec"};
    int n;
    std::cin>>n;
    std::cout << mnth[n-1] << std::endl;


}
