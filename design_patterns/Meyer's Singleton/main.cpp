/*  Meyer's(Scott Meyer) Singleton, which is both easy and threadsafe. No additional locking is neeeded for thr function local static instance(C++11 onwards)'
 *  https://stackoverflow.com/questions/1661529/is-meyers-implementation-of-the-singleton-pattern-thread-safe
 *	https://learn.microsoft.com/en-us/cpp/build/reference/zc-threadsafeinit-thread-safe-local-static-initialization?view=msvc-170
 */
#include "Singleton.h"
#include <iostream>
#include <vector>
#include <thread>

constexpr int THREADS = 5;
using namespace std;

int main()
{

	cout << "Main begins..\n";
#if 0
	{
		cout << Singleton::getInstance("Jithin");
		cout << "2nd try. The name and the instance's address shouldn't differ\n";
		cout << Singleton::getInstance("Thomas");
	}//Scope to check whether ~SIngleton() will be called here or after main ends
#endif
	// Calling Singleton::getInstance() from multiple threads to check thread safety. Seems ok. There is threadsafe initialization for local static variables in C++11
	std::vector<std::thread> t;
	char buff[15];
	for (int i = 0; i < THREADS + 20; i++)
	{
		sprintf_s(buff, "Jithin_%d", i);
		std::thread th = std::thread([&]()
									 { std::cout << Singleton::getInstance(const_cast<const char *>(buff)); });
		t.emplace_back(std::move(th));
		printf("Thread started \n");
	}
	for (auto &th : t)
	{
		th.join();
	}

	cout << "Main Ends..The static Singleton Instance will be destricted only after main ends\n";
	return 0;
}