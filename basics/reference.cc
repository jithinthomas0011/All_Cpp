/* A basic example to understand reference in c++ . 'func()' takes an integer reference as input and returns reference to the same variable */

#include<iostream>
using namespace std;

int& func(int &ref){
	cout<<__func__<<endl;

	ref+=20; //Updating Value

	cout<<__func__<<":: ref ="<<ref<<endl; 
	return ref; //return by ref as return type of func is int&
}


int main(){

	cout<<"Main begins.."<<endl;
	int a =10;
	func(a) =400; 
	cout<<"(Final value  of a should be 400) a = "<<a<<endl;

	cout<<"Press any key to exit"<<endl;
	cin.get();
	return 0;
}

