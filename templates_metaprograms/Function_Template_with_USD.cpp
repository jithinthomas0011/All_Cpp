// Function_Template_Max_with_User_defined_Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;


class Complex {
	double re, im;
public:
	Complex(double x = 0, double y = 0) :re(x), im(y) { cout << "Complex::Constr\n"; }
	int norm()const {
		return (sqrt((im * im) + (re * re)));
	}
	bool operator > (Complex& c) {
		return norm() > c.norm() ? true : false;
	}
	friend ostream & operator <<(ostream& os, const Complex& c) {
		os << c.re << "+i" << c.im;
		return os;
	}
	Complex(const Complex& oth):re(oth.re),im(oth.im) {
		cout << "Copy Constructor\n";
	}
	Complex& operator = (const Complex& oth) {
		cout << "Copy Assignment Operator\n";
		cout << "Copy Assignment Operator\n";
		if (this != &oth) {
			re = oth.re;
			im = oth.im;
		}
		return *this;
	}
	~Complex() { cout << "Complex::Destr\n"; }
};

template<typename T>
T Max(T x, T y) {
	return x > y ? x : y;
}

template<>
char* Max(char* x, char* y) {
	return strcmp(x, y) > 0 ? x : y;
}

template<typename T, int size>
void Max(T arr[size]) {
	cout << "Not currently implemented for array case\n";
	return;
}

int main() {
	cout << "Main Begins..\n";
	Complex c1(32.2, 30.16), c2(12.56, 10.78);
	cout << "The max bw c1 and c2 is " << Max(c1, c2) << endl;
	cout << "Main Ends..\n";
	cin.get();
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
