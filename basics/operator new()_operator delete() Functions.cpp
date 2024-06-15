#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    // operator new() function, which is similar to c-style malloc(), and it needs proper dereferencing.
    int *ptr = (int *)operator new(sizeof(int));
    *ptr = 10;
    cout << "The val =" << *ptr << endl;

    // operator delete() function
    if (ptr)
    {
        operator delete(ptr);
        ptr = nullptr;
    }

    // operator new[]() function --> For array case
    char *arr = (char *)operator new[](sizeof(char) * 6);
    strncpy(arr, "Hello", 5);

    cout << "The string in char arry is " << arr << endl;

    // operator delete[]() function
    if (arr)
    {
        operator delete[](arr);
        arr = nullptr;
    }

    return 0;
}