// Functors2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

//A similar template-function add() is available in STL <algorithm>. I just explicitly redefined it here with a different name Jadd() for learning
template<class T, class U>
U Jadd(T first, T last, U func) {
    while (first != last) {
        func(*first); //func is an object of adder. func(*first) will call the functor operator
        ++first;
    }
    return func; //or return std::move(func)  // returning the adder object back to main thread, so that the sum will be copied or moved to the varialbe 'result'
}


struct adder: public unary_function<double, void>  { //Unary_function , binary_function etc are deprecated C++11 onwards. You can simply remove them and code still works. https://youtu.be/zt7ThwVfap0?t=2265
    adder():sum(0) {}
    double sum;
    void operator()(double x) {
        sum += x;
    }

};

int main()
{
    std::cout << "Main Begins..\n";
    vector<double>V(20);
    generate(V.begin(), V.end(), rand); //Here the function pointer "rand" is passed. Dont give rand() as it'll try to look for such a constructor which doesn't exist. just give rand. 

    cout << "\nThe Vector elems are:\n";
    for (auto a : V) {
        cout << a << " ";
    }
    cout << "\n";
    adder j;
    adder res = Jadd(V.begin(), V.end(), j); //or Jadd(V.begin(), V.end(), adder()); //adder() here calls constructor
    cout << "\nThe Vector elem sum is " <<res.sum<<endl;

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
