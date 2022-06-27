/*Example of thread synchronisation using 'future' and 'async' in C++ */

#include <iostream>
#include <future>
//#include <mutex>

using namespace std;

unsigned long threadFun_Factorial(int &n){
  int result=1; 
  while(n){
    result *= n--;
  }
  return result;
}


int main(){
  
 cout<<"Main Thread"<<endl;
  
  int inp;
  unsigned long output=0;
  do{
  	cout<<"Enter a positive number to find factorial"<<endl;
  	cin>>inp;
  }while(inp<=0);
  future<unsigned long>f =async(launch::async, threadFun_Factorial, std::ref(inp));
  
  output = f.get();
  
  cout<<"The output from threadFun_Factorial is "<<output<<endl;
  
  return 0;
}
