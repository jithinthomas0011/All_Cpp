/* Usage of 'future' and 'promise' to synchronise threads and pass values between 2 threads in cpp */

#include<iostream>
#include<future>

using namespace std;

unsigned long Thread_factorial(future<int>&fp){

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
	future<unsigned long>f = async( launch::async, Thread_factorial, std::ref(fp) );


	//Do other stuff

	
	do{
		cout<<"Enter a positive number\n";
		cin>>num;
	}while(num<=0);
	p.set_value(num);
	unsigned long output=f.get();
	cout<<"The factorial is "<<output<<endl;	

	return 0;
}
