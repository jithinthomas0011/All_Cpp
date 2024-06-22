
#include<iostream>
#include<exception>
using namespace std;

class Excp :public exception {};

void func() {
    int err = true; //toggle true/false based on experimental need
    cout << "func() started\n";
    if (err)
        throw Excp();
    cout << "func() ended\n";
    return;
}

int main() {
    cout << "Main begins..\n";
    try {
        cout << "Error prone func() called\n";
        func();
        cout << "func() returned w/o errors/exceptions\n";
    }
    catch (Excp& e) {
        cout << "Exception received. func() failed: " << e.what() << endl;
    }
    return 0;
}
