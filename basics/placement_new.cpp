#include<iostream>
using namespace std;

int main(){
    int buf[10];

    int *pInt = new (buf)int(3); //Allocates memory within the local array buf.
    int *qInt = new (buf+sizeof(int))int (5);

    char *rChar = new(buf+sizeof(int)*2) char('j');

    cout<<"The entries are "<<*pInt<<","<<*qInt<<","<<*rChar<<endl;

    //no placement delete. The memory will be released when the local array buf goes out of scope
    return 0;
}