/* Thread synchronisation using condition_variable in cpp. STL container used is Deque */


#include <iostream>
#include <condition_variable>
#include <mutex>
#include <deque>
#include <thread>
using namespace std;

//Common resource (Dq) shared by producer thread and consumer thread
deque<int>Dq;

condition_variable condn;

mutex mu;

void producerT(){
	int ct=10;
	while(ct){
		unique_lock<mutex>locker(mu);
		Dq.push_front(ct--);
		locker.unlock();;
		condn.notify_one();
		this_thread::sleep_for(chrono::milliseconds(3));
	}

}


void consumerT(){

	int data=-1;

	while(data != 1){
		unique_lock<mutex>locker(mu);
		condn.wait(locker,[]{return !Dq.empty();});
		data = Dq.back();
		Dq.pop_back();
		cout<<"Data received at Consumer Thread ="<<data<<endl;
		locker.unlock();
		this_thread::sleep_for(chrono::milliseconds(3));

	}

}


int main(){

	cout<<"Main Thread.."<<endl;
	thread P(producerT);
	thread C(consumerT);


	//Do other stuff 


	if(P.joinable())
		P.join();
	if(C.joinable())
		C.join();

	cout<<"Main Thread:: Press any key to exit Program!"<<endl;	
	cin.get();
	return 0;

}
