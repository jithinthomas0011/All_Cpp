/* const_cast Example 2 */

#include <iostream>

int main(){

  int i=10;
  const int &cref_i =i; //const ref to i.
  const_cast<int &>(cref_i) = 20; //OK, Modifies i.
  std::cout<<"i ="<<i<<", cref_i ="<<cref_i<<std::endl;

  const int j = 100;
  int *pj = const_cast<int *>(&i);
  *pj=200; //Undefined Behaviour . Temp memory will be created.
  std::cout<<"j ="<<j<<", *pj="<<*pj<<std::endl; //Values will be different.
  
  int ref_j=const_cast<int &>(j); //Temp memory will be created.
  ref_j =300;
  std::cout<<"ref_j= "<<ref_j<<", j ="<<j<<std::endl; //Values will be different.
  
  return 0;
  
}
