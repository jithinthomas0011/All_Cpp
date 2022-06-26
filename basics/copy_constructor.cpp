/*Usage of Copy Constructor*/



#include<iostream>
using namespace std;


class Base{

	protected :

		int *ptr_i;
		char *ptr_c;

	public:

		Base(int val=0, char cval=0):ptr_i(new int(val)),ptr_c(new char(cval)){
			cout<<"User defined Parameterized constructor "<<endl;
		}


  
  /*Base class is not part of a hierarhy , so virtual destructor is not actually required. But a user defined destructor is needed to deallocate memory*/
  
		virtual ~Base(){

			cout<<"~Base"<<endl;
			if(nullptr != ptr_i){
				delete(ptr_i);
				ptr_i =nullptr;

			}
			if(nullptr!= ptr_c){
				delete ptr_c;
				ptr_c=nullptr;
			}

		}


		Base(const Base &ref):ptr_i(new int (*(ref.ptr_i))), ptr_c(new char (*(ref.ptr_c))){
			cout<<"Base::Copy Constructor"<<endl;
		}

		void Display()const{
			if(nullptr != ptr_i)
				cout<<"Integer val in heap  ="<<*ptr_i<<endl;
			else
				cout<<"No integer value created dynamoically yet!!"<<endl;

			if(nullptr != ptr_c)
				cout<<"char val in heap ="<<*ptr_c<<endl;
			else
				cout<<"No char value created in heap yet!!"<<endl;
		}

};

void fun_to_invoke_copy_constr(Base b){

	cout<<__func__<<endl;
	b.Display();

	//Here,  ~Base() should be called automatically as the temp obj is exiting function scope.

}

int main(int argc, char * argv[]){


	Base B_obj1(100,'J');

	fun_to_invoke_copy_constr(B_obj1);

	Base B_obj2(B_obj1); //Invokes Copy constr

	B_obj2.Display();

	cout<<"Press any key to exit"<<endl;
	cin.get();
	return 0;
}
