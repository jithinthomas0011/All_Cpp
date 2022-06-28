
/* static_cast examples*/

#include<iostream>

using namespace std;

typedef enum Days{
	eSun=0,
	eMon,
	eTue,
	eWed,
	eThu,
	eFri,
	eSat,
	eTot= 7,
}Days;


Days  operator+(const Days &e1, const Days & e2){
	cout<<__func__<<endl;
	int Sum=static_cast<int>(e1)+static_cast<int>(e2);
	if(Sum >= static_cast<int>(eTot)){

		Sum%=static_cast<int>(eTot);

	}
	return Days(Sum);
}


ostream &operator<<(ostream &os, const Days &Dy){
	switch(Dy){
		case eSun:
			os<<"Sunday";
			break;
		case eMon:
			os<<"Monday";
			break;
		case eTue:
			os<<"Tuesday";
			break;
		case eWed:
			os<<"Wednesday";
			break;
		case eThu:
			os<<"Thursday";
			break;
		case eFri:
			os<<"Friday";
			break;
		case eSat:
			os<<"Saturday";
			break;
	}
	return os;
}


//Class with a conversion operator int.

class Base {
	int value;
	public:
	Base(int i_=0):value(i_){cout<<__func__<<endl;}
	Base (const Base &ref):value(ref.value){cout<<"Copy "<<__func__<<endl;}
	Base & operator =(const Base & ref){
		if(this== &ref){
			cout<<"Self COpy . Nothing Doing!"<<endl;
		}

		else 
			value=ref.value;
		return *this;
	}

	//Operator int()
	operator int(){
		return value;
	}


};


int main(){


	int i1=10;
	double d1=20.10;
	i1 = static_cast<int>(d1); //double to int
	cout<<"i1= "<<i1<<", d1="<<d1<<endl;
//---------------------------------------------------------------------------//
  
	double *pd1=&d1;
	//	i1 = static_cast<int>(pd1); //Double * pointer to int will give error
	//	cout<<"i1= "<<i1<<endl;
  
//---------------------------------------------------------------------------//

	Days dy1 = eTue;
	i1=static_cast<int>(dy1); //Enum to int
	cout<<"i1 = "<<i1<<endl;
  
//---------------------------------------------------------------------------//

	i1=34;
	dy1=static_cast<Days>(i1);
	cout<<"dy1 ="<<dy1<<endl;
  
//---------------------------------------------------------------------------//

	Days d2=eSat, d3=eThu;
	Days d4=d2+d3;
	cout<<"d4 ="<<d4<<endl;

//---------------------------------------------------------------------------//
  
	Base b(199);
	i1=b; //calls operator int();
	cout<<"i1 ="<<i1<<endl;

//---------------------------------------------------------------------------//
	return 0;
}
