// Functors1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

template<class T, class U>
void Jgenerate(T first, T last, U gen) { //A similar function-template std::generate() is available in STL <algorithm>
    std::cout << "Jgenerate()\n";
    while (first != last) {
        *first = gen();
        ++first;
    }

}
int main()
{
    std::vector<int> V(100);
    std::cout << "The size of vector is " << V.size() << std::endl;
    std::cout << "The vector elems B4 Jgenerate():\n";
    for (auto a : V) {
        std::cout << a << " ";
    }
    Jgenerate(V.begin(), V.end(), std::rand); //rand is passed as a function object/Function-pointer to Jgenerate. 
    std::cout << "The vector elems aftr jgenerate() are:\n";
    for (auto a : V) {
        std::cout << a << " ";
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
