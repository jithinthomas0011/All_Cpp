#include<iostream>
using namespace std;


class Base{
  public:
  Virtual ~base(){}
};

classs Der:public Base{
  public:
}

class Stranger{
  public:
};


int main(){
  Base b, Der d , Stranger s;
  Base *pb; 
  Der *pd;
  Stranger *ps;
  pd =&d;
  pb = dynamic_cast<
