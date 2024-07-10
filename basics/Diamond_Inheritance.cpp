#include<iostream>
using namespace std;
class Person {
	int data_p;
public:
	Person(int x=0) :data_p(x) { cout << "Person::constr\n"; }
	virtual ~Person() {}

	virtual void task() = 0; //PVF
};

class Student : virtual public Person {
	int data_s;
public:
	Student(int x) :data_s(x) { cout << "Student::constr\n"; }
	virtual void task() { cout << "S::task\n"; }
	virtual ~Student() { cout << "~Student()\n"; }
};

class Faculty :virtual public Person {
	int data_f;
public:
	Faculty(int x) :data_f(x) { cout << "Faculty::constr\n"; }
	virtual void task() { cout << "F::task\n"; }
	virtual ~Faculty() { cout << "~Faculty()\n"; }
};

class PTA :public Student, public Faculty {
	int data_pta;
public:
	PTA(int x):data_pta(x), Student(x),Faculty(x)  {} // Constructors of Student and Faculty need to be called explicitly as they dont have default constructors.
	virtual void task()final { //Must be redefined here in the final child class or can create ambiguity
		cout << "PTA::task()\n";
		Faculty::task();
		Student::task();
	}
	~PTA(){ cout << "~PTA()\n"; }
};

int main() {

	PTA* pta = new PTA(10);
	pta->task();

	delete pta;
}
