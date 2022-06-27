/* Usage of 'shared_future', 'future' and 'promise' to synchronise threads and pass values between multiple threads in cpp */

#include<iostream>
#include<future>

using namespace std;

unsigned long Thread_factorial(shared_future<int>fp){

	//cout<<__func__<<endl;
	int num = fp.get();
	unsigned long res =1;
	while(num){
		res *= num--;
	}
	return res;

}

int main(){
	
	cout<<"Main Thread Begins.."<<endl;
	int num=-1;
	promise<int>p;
	future<int>fp = p.get_future();
	shared_future<int>sf=fp.share();
	
	//Multiple thread instantiation 
	future<unsigned long>f1 = async( launch::async, Thread_factorial, sf);
	future<unsigned long>f2 = async( launch::async, Thread_factorial, sf);
	future<unsigned long>f3 = async( launch::async, Thread_factorial, sf);
	future<unsigned long>f4 = async( launch::async, Thread_factorial, sf);

	//Do other stuff

	
	do{
		cout<<"Enter a positive number\n";
		cin>>num;
	}while(num<=0);
	p.set_value(num);
	cout<<"The factorial from f1 "<<f1.get()<<endl;	
	cout<<"The factorial from f2 "<<f2.get()<<endl;	
	cout<<"The factorial from f3 "<<f3.get()<<endl;
	
	// ... 
	// ...
	
	return 0;
}
