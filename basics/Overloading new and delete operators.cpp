// overloading operators new  and delete globally. It can also be done inside a class.

#include <iostream>
#include <cstdlib>
#include <cstring>
// using namespace std;

void *operator new(size_t n)
{
    std::cout << "Custom overloaded new\n";
    void *ptr = (void *)malloc(n);
    return ptr;
}

void operator delete(void *ptr)
{
    std::cout << "Custom overloaded delete\n";
    if (ptr)
    {
        free(ptr);
    }
}

void *operator new[](size_t n, char setV)
{
    std::cout << "Custom overloaded new[]\n";
    void *ptr = operator new(n); // malloc can be used directly as well . Here this will call the custom overloaded new
    memset(ptr, setV, n);
    return ptr;
}

void operator delete[](void *ptr)
{
    std::cout << "Custom Overloaded delete[]\n";
    operator delete(ptr); // free can be used directly as well
}
int main()
{
    std::cout << "Main begins..\n";
    int *ptr = new int;
    delete ptr;
    ptr = nullptr;

    char *str = new ('$') char[5]; //Check how the initial value is passed.
    std::cout << "The array elems are: \n";
    for (int i = 0; i < 5; ++i)
        std::cout << str[i] << " ";

    std::cout<<std::endl;
    delete[] str;
    return 0;
}