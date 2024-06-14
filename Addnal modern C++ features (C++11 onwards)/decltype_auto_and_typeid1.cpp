#include<iostream>
#include<typeinfo> //for typeid operator
using namespace std;

int main(){

    int x =12;
    double y =34.65;
    decltype(y) p =43.67;
    auto out  = x*y;

    //decltype(y)::_;
    cout<<"p = "<<p<<", out ="<<out<<endl;

    cout<<"typeid(x).name = "<<typeid(x).name()<<endl;
#if 0 //
    if(decltype(x) == decltype(y)){
        cout<<"Same type vars\n";
    } else {
        cout<<"Different type vars..\n";
    }
#endif
    return 0;
}