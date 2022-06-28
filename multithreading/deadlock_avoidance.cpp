
/* Deadlock avoidance using std::lock() and std::adopt_lock */

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;


class Base{

	private:
		std::mutex mu1, mu2;
	
  public:
  
		//Base(){}

		void Shared_print1(int i){
			std::lock(mu1,mu2);
			lock_guard<mutex>lock1(mu1, std::adopt_lock);
			lock_guard<mutex>lock2(mu2, std::adopt_lock);
			cout<<"SP1:: "<<i<<endl;
		}
  
		void Shared_print2(int j){
			std::lock(mu1,mu2);
			lock_guard<mutex>lock1(mu2, std::adopt_lock);
			lock_guard<mutex>lock2(mu1, std::adopt_lock);
			cout<<"SP2:: "<<j<<endl;
		}
};

void Threadfunc(Base & B){
	int i=0;
	for (;i<9000;i++)
		B.Shared_print2(i);
}

int main(){
	Base B;
	thread t1(Threadfunc, std::ref(B));
	int j=0;
	for (;j<6000;++j)
		B.Shared_print1(j);
	t1.join();
	cout<<"main ends..."<<endl;
	cin.get();
	return 0;
}


