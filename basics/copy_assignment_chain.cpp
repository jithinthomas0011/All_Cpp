/******************************************************************************
Implementation of copy assignment operator with -
selfcopy check and proper memory management
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Base{
    private:
    int a;
    char *str;
    public:
    Base(int val_i=0, char *str_=""):a(val_i), str(strdup(str_)){cout<<__func__<<endl;}
    Base(const Base &ref):a(ref.a){cout<<__func__<<"[copy]"<<endl;}
    Base & operator =(const Base &ref){
        //Avoidiing Self copy first
        if(&ref==this){
            cout<<"Attempt of self copy found. Nothing doing!!"<<endl;
            return *this;
            }

        if(str!=nullptr){
            free(str);; //Using free ,as strdup() has been used for mem allocation.
            str=nullptr;
        }
        str = new char [(strlen(ref.str))]; 
        strncpy(str, ref.str,strlen(ref.str)+1);
   }
   friend ostream & operator<<(ostream &os, const Base & ref){
      os<<"Int val ="<<ref.a<<", String ="<<ref.str;
      return os;
   }
};

int main()
{
    cout<<"Main Begins..."<<endl;

    Base B_obj1(112,"Jithin");
    Base B_obj2(200,"Thomas");

    cout<<B_obj1<<", "<<B_obj2<<endl;
    B_obj1 = B_obj1; //Self Copy Scenario
    B_obj2=B_obj1;
    cout<<B_obj1<<", "<<B_obj2<<endl;
  
    return 0;
}
