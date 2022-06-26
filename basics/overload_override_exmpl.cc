/*overload_override_inside_classes_in_hierarchy*/
#include<iostream>
#include<string>
using namespace std;


class Base{
	public:
		void f(int val){cout<<"base::f:val = "<<val<<endl;}
		void g(int val){cout<<"Base::g::val ="<<val<<endl;}
};
class Der:public Base{

	public:
		void f(int val){cout<<"Der::f::val ="<<val<<endl;}
		void f(string &&str){cout<<"Der::f(str&&)::str="<<str<<endl;}
		void h(int val){cout<<"der::h::val="<<val<<endl;}
};

int main(){
	Base b; Der d;
	b.f(1);
	b.g(2);
	d.f(3);
	d.f(string("Jithin"));

	d.g(4);
	d.h(5);

	cin.get();
	return 0;
}


