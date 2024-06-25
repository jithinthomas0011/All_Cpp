#include "Singleton.h"
#include <cstring>
#include <iostream>

Singleton::Singleton(const char *istr):str(_strdup(istr)), len(strlen(str)) {
	std::cout << "Singleton::COnstr\n";
}

Singleton& Singleton::getInstance(const char* i_Str) {
	static Singleton sInstance(i_Str);
	std::cout << "Sinleton::getInstance ["<<&sInstance<<"]\n";
	return sInstance;
}

Singleton::~Singleton() {
	if (str)
		free(str);
	str = nullptr;
	std::cout << "Singleton::Destr\n";
}


std::ostream& operator<<(std::ostream& os, const Singleton& singltn) {
	os <<"The string is : " << singltn.str << ", and the len is : " << singltn.len << std::endl;
	return os;
}

void Singleton::Display()const {
	std::cout << "The str is " << str << ", and the len is " << len << std::endl;
}
