#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <utility> // можно подключить пары std::pair<type1, type2>
#include <tuple>
#include <map> // std::map<key_type1, value_type1> my_map словарь ()
#include <unordered_map> 
#include <string>
#include <set>
#include <unordered_set>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <deque>

#define PRINT_(x) (std::cout << (x) << std::endl)

int function1(int a, int b)
{
    return a;
}

int main()
{
char a = 'g';
std::cout << "Type char:" << sizeof(char) << std::endl;
unsigned char b = 'r';
int c = 4;
std::cout << "Type int:" << sizeof(int) << std::endl;
short int d = 2;
std::cout << "Type short int:" << sizeof(short int) << std::endl;
short e = 3 ;
long int f = 5;
std::cout << "Type long int:" << sizeof(long int) << std::endl;
long long int g = 6;
std::cout << "Type long long int:" << sizeof(long long int) << std::endl;

long long int h = 6LL;
unsigned int i = 1U;
unsigned long long int j = 1ULL;

float number_float = 1.2f;
std::cout << "Type float:" << sizeof(float) << std::endl;

double number_double = 3.14;
std::cout << "Type double:" << sizeof(double) << std::endl;

std::cout << std::pow(2,-24) << std::endl;
// comentari
std::cout << std::pow(2,-52) << std::endl;
// точность 10 в -16
long double numver_loung_double = 5.0;

std::cout << "Type long double:" << sizeof(long double) << std::endl;
std::cout << std::pow(2.0L, -116) << std::endl;
// logich peremen
std::cout << "-------------" << std::endl;
bool bool_arg = true;
bool bool_arg1 = false;
std::cout << "Type bool:" << sizeof(bool) << std::endl;
// тип void
double number = 1;
int number_int = 3.14;
std::cout << "Number int from 3.14 " << number_int << std::endl;

double number1 = 1/(double)2;
std::cout << "Number 0.5 from int: " << number1 << std::endl;
double number2 = 1/2;
std::cout << "Number 0.5 : " << number2 << std::endl;

// std::cin >>number;
std::cout << "out" << std::endl;
// std::cout << "out" << '\n';
std::cerr << "error messege" << std::endl;
int number3 = 2+6;
number3 = 6-2;
number3 = (-6 - 2) / 1 * 15;

int cpp = 6;
int number4 = 7;
std::cout << "-------------" << std::endl;
std::cout << "Equatio:" << (number4 == cpp) << std::endl;
std::cout << "" << (number4 != cpp) << std::endl;
std::cout<< "" << (number4 > cpp) << std::endl;
std::cout<< "" << (number4 < cpp) << std::endl;
std::cout << "" << (number4 <= cpp) << std::endl;
std::cout << ":"<< (number4 >= cpp) << std::endl;
std::cout << "-------------" << std::endl;
bool condition =(4 > 5) || (0==0);
bool condition1 =(4 > 5) && (0==0);
bool condition2 =  !condition1;

// int x1 = 0;
// int y = 9;
// int result = y / x1; // NaN
// bool expr1 = (result == result);
// std::cout << "nah" << execl << std::endl;
// bool condition3 = (x1 == 0) || (y / x1);
PRINT_(7);
int parameter2 = (condition) ? (1): (0); // int parameter2 = (condition) ? (true_result): (false_result);

int int_max = std::numeric_limits<int>::max();
std::cout << "int_max:" << int_max << std::endl;
int_max += 1;
std::cout << "int_max + 1:" << int_max << std::endl;
std::cout << "int_min:" << std::numeric_limits<int>::min() << std::endl;
double double_max = std::numeric_limits<double>:: max();

std::cout << "double max:" << double_max << std::endl;
double_max *= 10.0;
std::cout << "double_max: 10.0:" << double_max << std::endl;
std::cout << "double_inf: " << std::numeric_limits<double>::infinity() << std::endl;
// условный оператор
if (condition1)
{
    PRINT_(1);

}
else if (condition2)
{
    PRINT_(2);
}
else
{
    PRINT_(3);
}

enum arrrr
{
    Case1,
    Case2,
    End
};

arrrr enum_par;

int switch_parameter = 13;
switch (enum_par)
{
case 1:
    PRINT_(4);
    break;

case 2:
    /*code1*/
    break;

default:
    PRINT_(101);
    break;
}

while (condition1)
{
    PRINT_(8);
    break;
    continue;
}

do
{
    /* code */
} while (condition2);

// for
for (int counter = 0; counter < 10; counter++)
{
    break;
}

// func
function1(1,2);

}
