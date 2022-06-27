/*Example of thread synchronisation using 'future' and 'async' in C++ */

#include <iostream>
#include <future>
//#include <mutex>

using namespace std;

int threadFun_Factorial(int &n){
  int result=1; 
//Do the factorial logic here ..
  return result;
}


int main(){
  
 cout<<"Main Thread"<<endl;
  
  int inp, output=0;
  cout<<"Enter a positive number to find factyorial"<<endl;
  cin>>inp;
  future<int>f =async(launch::async, threadFun_Factorial, std::ref(inp));
  
  output = f.get();
  
  cout<<"The output from threadFun_Factorial is "<<output<<endl;
  
  return 0;
}
