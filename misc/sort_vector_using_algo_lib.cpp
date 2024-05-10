// Cpp_Exps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
    return a > b;
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> Jvec(10,0);
    cout << "Enter the vector elems\n";
    for (vector<int>::iterator it = Jvec.begin(); it != Jvec.end(); ++it) {
        cin >> *it;
    }

    cout << "Jvec initially is\n";
    for (auto a : Jvec) {
        cout<<a<<" ";
    }
    cout << "\n\n";
    sort(Jvec.begin(), Jvec.end(), compare);
    cout << "Jvec finally is \n";
    for (auto a : Jvec) {
        cout << a << " ";
    }
    return 0;
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
