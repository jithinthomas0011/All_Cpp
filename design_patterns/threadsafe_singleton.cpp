/* Thread safe Singleton Implementation */

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
class Singleton{

	private:
		int m_data;
		static Singleton * Instance;
		static mutex mu;
		static int ref_ct;
		static mutex ref_mu;

		static void incrementRef();
		static void decrementRef();


		Singleton(int val=0):m_data(val){cout<<"Constr:: "<<__func__<<endl;}
		~Singleton(){cout<<"Destr:: "<<__func__<<endl;}

	public:
		static Singleton* getInstance(int val=0);
		static bool relInstance();

		Singleton(const Singleton&) = delete;
		Singleton operator=(const Singleton&) = delete;

		int getVal()const{ return m_data;}


};


Singleton* Singleton::Instance =nullptr;
mutex Singleton::mu;
mutex Singleton::ref_mu;
int Singleton::ref_ct=0;

void Singleton::incrementRef(){
	lock_guard<mutex>lockI(ref_mu);
	cout<<"New ref_ct ="<<++ref_ct<<endl;


}

void Singleton::decrementRef(){
	lock_guard<mutex>lockR(ref_mu);
	cout<<"New ref_ct ="<<--ref_ct<<endl;
}


Singleton * Singleton::getInstance(int val){
	lock_guard<mutex>lockG(mu);
	incrementRef();
	if(nullptr == Instance){
		Instance = new Singleton(val);
	}
	return Instance ;
}


bool Singleton::relInstance(){
	lock_guard<mutex>lockR(mu);
	bool ret=false;
	decrementRef();
	if( (0 == ref_ct) && (nullptr!= Instance) ){
		cout<<"Deleting Singleton Insatnce"<<endl;
		delete Instance;
		ret=true;
	}
	return ret;
}

void ThreadFun1(int val=0){

	this_thread::sleep_for(chrono::milliseconds(1000) );
	Singleton *pS1 = Singleton::getInstance(val);
	cout<<"ThreadFun1:: pS1->data ="<<pS1->getVal()<<endl;

}


void ThreadFun2(int val =0){
	this_thread::sleep_for(chrono::milliseconds(1000) );
	Singleton* pS2 = Singleton::getInstance(val);
	cout<<"ThreadFun2:: pS2->data = "<<pS2->getVal()<<endl;
}

int main(){

	cout<<"main begins .."<<endl;

	thread t1(ThreadFun1, 100);


	thread t2(ThreadFun2, 200);


	t1.join();
	t2.join();
	cin.get();
	return 0;

}
