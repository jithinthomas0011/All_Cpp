/*This is an example of User defined datatype streaming using Ostream object with the help of operator overloading and friend functions */

#include<iostream>
using namespace std;

class Base{

	private:
		int a;
	protected :
		int b;
	public:
		int c;

		Base(int _a=0, int _b=0, int _c=0):a(_a),b(_b),c(_c){cout<<"Base::constr"<<endl;}

		friend ostream &operator<<(ostream &os, const Base &ref){		
			os<<"a = "<<ref.a<<", b="<<ref.b<<", c="<<ref.c<<endl;
			return os;
		}

};
class Der:public Base{

	private :
		int d;
	public:
		int e;
		Der(int d_=0, int e_=0):d(d_),e(e_){cout<<"Der::constr"<<endl;}
		void DispD()const{cout<<"Der::d ="<<d<<", Der::e= "<<e<<endl;}


};

int main(int argc, char *argv[]){


	Base b(10,11,12);

	Der d;

	cout<<b;
	cout<<d<<endl;

	cin.get();
	return 0;
}

