#include<iostream>
#include<vector>
#include<atomic>
#include<thread>

using namespace std;

//Atomic variable to store vector sum
atomic<long>multithreaded_sum(0);

void AddVector(vector<int>&v, int idstart, int idend){
	for(int i = idstart;i<=idend;++i){
		multithreaded_sum += v[i] ;
	}
}

int main(){

	cout<<"Main Begins.."<<endl;

	vector<int>vect(30000);


	cout<<"The size of vector ="<<vect.size()<<endl;

	long sum = 0;

	for(auto i=vect.begin();i!= vect.end();++i){
		*i = rand();
		sum += *i;
	}
	cout<<"sum = "<<sum<<endl;

	thread t1(AddVector,std::ref(vect), 0, 9999);
	thread t2(AddVector,std::ref(vect), 10000, 19999);
	thread t3(AddVector,std::ref(vect), 20000,29999);

	t1.join();
	t2.join();
	t3.join();

	cout<<"The multithreaded sum ="<<multithreaded_sum.load()<<endl;
	cin.get();
	return 0;
}
