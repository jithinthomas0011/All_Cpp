/* Assertion example in c++ */

#include<iostream>
#include<exception>
#include<cassert>
using namespace std;
int main(){

	cout<<"Main Begins.."<<endl;
	int x=20;
	try{
		assert(x==10);
	}catch(exception e){cout<<e.what()<<endl;} //Even exeption handling can't stop std::terminate() if assertion fails.
  
	int *ptr = new int(60); //Doesn't reach here if above assertion fails.
	assert(*ptr==10);
  
	cin.get();
	return 0;
}
