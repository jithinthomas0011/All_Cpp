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
  void *pv = nullptr;
  Stranger *ps;
  pd =&d;
  pb = dynamic_cast<Base*>(pd);
  cout<< pd<<" casts to "<< pb<<"Upcast::valid"<<endl;
  pb = &d;
  
  pd = dynamic_cast<Der*>(pb);
  
  cout<<pb<<" casts to "<<pd<<"Downcast::valid"<<endl;
  
  //pb= &b; 
  //pd= dynamic_cast<Der*>(pb);
  //cout<<pb<<" casts to "<<pd<<"Downcast:Invalid"<<endl;
  
  //pb = (Base*)&s;
  //ps = dynamic_cast<Stranger*>(pb);
  //cout<<pb<<" casts to "<<ps<<"Unrelated class:invalid"<<endl;
  
  pb= &b;
  pv=dynamic_cast<void*>(pb);
  cout<<pb<<" casts to "<<pv<<"Cast to void *::Valid"<<endl;
 
  //pa = dynamic_cast<Base*>(pv);
  //cout<<pv<<" casts to "<<pb<<" Cast source is not a pointer to polymorphic hierarchy:Invalid cats"<<endl;
 
  pb=0;
  ps =dynamic_cast<Stranger*>(pb);
  cout<<pb<<" casts to "<<ps<<"Unrelated cast::Valid for null/0"<<endl;
}
  
return 0;
}
