#pragma once
#include<ostream>
class Singleton
{
	char* str;
	int len;
	Singleton(const char* istr= "");
	~Singleton();
public:
	static Singleton& getInstance(const char* i_str = "");
	friend std::ostream& operator<<(std::ostream& os, const Singleton& singltn);
	Singleton(const Singleton&) = delete;//Singleton shouldn't be copy-able
	Singleton& operator = (const Singleton&) = delete;//Singleton shouldn't be assignable
	Singleton(Singleton&& oth) = delete;//Should not be moveable
	Singleton& operator=(Singleton&&) = delete;
	void Display()const;
};

