#include<iostream>
using namespace std;

int fun(int f3){

    //constexpr int y = 10*f3+2; //Error f3 not availabe at compile time
    const int p = 10*f3+4;
    constexpr int q = 10*12*3;

    return p+q;
}

int main(){
    int inp =20;
    cout<<"out is "<<fun(inp)<<endl;
    return 0;
}
