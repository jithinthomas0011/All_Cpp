// App1.cpp: Program to reverse a string using class template Stack
//
#include <iostream>
#include "Stack.h"
#include <cstring>

int main()
{
	char str[] = "Jithin";
	Stack<char> Sc;
	for (unsigned int i = 0; i < strlen(str); ++i)
		Sc.push(str[i]);

	std::cout << "The reversed string is :\n";
	while (!Sc.isEmpty())
	{
		std::cout << Sc.top();
		Sc.pop();
	}
	std::cin.get();
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
