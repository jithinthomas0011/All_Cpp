// Exception flow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<exception>
using namespace std;

class MyException:public exception{};
class MyClass {
public:
    MyClass() { cout << "MyClass::Constr\n"; }
    ~MyClass() { cout << "MyClass::Destr\n"; }
};

void h() {
    //Uncomment each of the below throw statements and see the behaviour

    //throw 1; //Line 1
    //throw 2.5; //Line 2
    //throw MyException(); //Line 3
    //throw exception(); //Line 4
    //throw MyClass(); //Line 5
}

void g() {
    try {
        h();
        bool ok = true;
    }
    catch (MyException& ex) {
        cout << "Exception from Line 3\n";
    }
    catch (exception& ex) {
        cout << "Exception from Line 4\n";
    }

    catch (...) {
        throw; //re - throw
    }
}

void f() {
    try {
        g();
        bool ok = true;
    }
    catch (int) { cout << "Exception from Line 1\n"; }
    catch (double) { cout << "Exception from Line 2\n"; }
}

int main()
{
    std::cout << "Hello World!\n";
    try {
        f();
        bool ok = true;
    }

    catch (...) {
        cout << "Exception from Line 5\n";
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
