
//#define NDEBUG //--> Uncomment this line, to remove assert() calls i.e to generate a release build rather than debug build
#include<iostream>
#include<cassert>

using namespace std;

int main(){
    int i=0;
    assert(++i == 2);
    cout<<"i is "<<i<<endl;
    return 0;
}


void _assert(){
    cout<<"jithin"<<endl;
}