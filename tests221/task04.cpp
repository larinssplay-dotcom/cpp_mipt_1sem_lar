#include <iostream>

int main()
{
    int** my_pointer_to_int_pointers_array = new int* [4];
for (int i = 0; i < 4; i++)
    {
    my_pointer_to_int_pointers_array[i] = new int[5]; 
    for (int j = 0; j < 15; j++)
        my_pointer_to_int_pointers_array[i][j] = i*j;
}
std::cout << my_pointer_to_int_pointers_array[3][2] << std::endl;
}