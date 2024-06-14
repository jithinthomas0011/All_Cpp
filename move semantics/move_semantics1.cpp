#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class A
{
    int data;
    char *str;

public:
    // User defined default constructor
    A() : data(0), str(nullptr) { cout << "Def constr" << endl; }
    // Parameterised constructor
    A(int i, char *st) : data(i), str(strdup(st)) { cout << "Param constret" << endl; }
    // Copy constroctor, receives an lvalue ref to const obj of A class
    A(const A &ot)
    {
        cout << "Copy constr" << endl;
        data = ot.data;
        str = strdup(ot.str);
    }
    // Copy assignment operator, receives an lvalue ref to const obj of A class
    A &operator=(const A &ot)
    {
        cout << "Copy assnmnt operator" << endl;
        if (this != &ot)
        {
            if (str)
                free(str);

            data = ot.data;
            str = strdup(ot.str);
        }
        else
        {
            cout << "Self Copy cancelled\n";
        }
        return *this;
    }
    // move constructor, receives an rvalue ref.
    A(A &&r_ref) noexcept
    {
        cout << "Move constr" << endl;
        data = r_ref.data;
        str = r_ref.str;
        r_ref.str = nullptr;
    }
    // move assgnmnt operator, receives an rvalue ref.
    A &operator=(A &&ot) noexcept
    {
        if (this != &ot)
        {
            cout << "Move assnmnt operator" << endl;
            data = ot.data;
            str = ot.str;
            ot.str = nullptr;
        }
        else
        {
            cout << "Self Move cancelled\n";
        }
        return *this;
    }

    // user defined destructor
    ~A()
    {
        cout << "Destructor\n";
        if (str)
            free(str);

        str = nullptr;
    }

    //A display func to print the object's state
    void display() const
    {
        if (str) // As part of move, str can be nullified. So objects with str=nullptr can exist. Added this check to avoid crash while printing such nullified str
            cout << "data " << data << " str  " << str << endl;
        else
            cout << "Data:= " << data << endl;
    }
};

int main()
{
    A a;

    A b(10, (char *)"jithin");

    b.display();

    b = b; // Self copy

    A c = std::move(b);

    c = std::move(c); // Self move

    c.display();

    b.display();

    return 0;
}
