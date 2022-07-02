#include<iostream>

using namespace std;

template <class U> class Jlist; //fwd declaration

template<class T>
struct Node {
	private:
		T data;
		size_t ln;	
		static Node<T> *current;
		Node *next;
	public:
		Node(T data_):data(data_),next(nullptr){
			if(nullptr != current || ln != 0 )
				current->next = this;

			current = this;	
			++ln;
			cout<<"Node::Constr "<<endl;
		}
		~Node(){cout<<"Node::Destr"<<endl;}

		void self_destruct(){
			Node<T>*temp=this, *prev =temp;
			while(temp){
				temp = temp->next;
				delete prev;
				prev =temp;

			}
		}

		//template <class U>friend class Jlist;   //This works but it'll be a wast generalization for friend classes.
		friend class Jlist<T>;
};

//defining static members outside class scope
template <class T>
Node<T>* Node<T>::current = nullptr;


template<class U>
class Jlist{
	private:
		//U val;
		Node<U> *Start,*End;
		size_t size;
		bool is_empty;

	public:
		Jlist(size_t sz, U def_val):is_empty(true){
			size =sz;
			size ? (is_empty=false):(is_empty =true);
			Node <U>*temp=nullptr;
			while(sz){
				temp = new Node<U>(def_val);
				if(sz == size){
					Start = temp;
				}
				--sz;
			}
			End = temp;
		}

		U back()const{return End->data;};
		bool insert_end(int val){
			if(End = new Node<U>(val))
			{
				++size;
				return true;
			}
			return false;
		}
		size_t getSize()const{return size;}
		virtual ~Jlist(){
			Start->self_destruct();
			Start=nullptr;
			End=nullptr;
			size=0;
			is_empty=true;
		}


};

int main(){
	Jlist<int>*lt= new Jlist<int>(2,2);

	cout<<"lt.back()= "<<lt->back()<<endl;

	lt->insert_end(10);

	cout<<"lt.back()= "<<lt->back()<<endl;
	cout<<"lt.size = "<<lt->getSize()<<endl;

	delete lt;
	//------------------------------------------------------------------------------------------

	Jlist Jl(10,77);

	cout<<"Jl.back()= "<<Jl.back()<<endl;

	Jl.insert_end(10);

	cout<<"Jl.back()= "<<Jl.back()<<endl;
	cout<<"Jl.size = "<<Jl.getSize()<<endl;

	return 0;
}



//TODO: Need to implement Jlist::pop(), Jlist::Display_list(), Jlist::insert_front() etc .
//TODO: Threadsafe implementation. Need to lock static members.
