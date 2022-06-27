/*const_cast Example*/

#include<iostream>
using namespace std;

class Base{

	private:
		int i;
	public:
		Base(int i_=0):i(i_){cout<<__func__<<endl;}
		int get()const{return i;}
		void set(int i_=0){i=i_;}
		void Display()const{cout<<"i ="<<i<<endl;}

};

int main(){
	const Base b(100);
	cout<<b.get()<<endl;

	//b.set(200); //should give error. const object cant call non const member functions
	const_cast<Base &>(b).set(200); //Creates a non const reference to 'b' object.
	cout<<b.get()<<endl;
	cin.get();
	return 0;

}
