#include<iostream>

using namespace std;

template <class U> class Jlist; //fwd declaration

template<class T>
struct Node {
	private:
		T data;
		static size_t ln;	
		static Node<T> *current;
		Node *next;
	public:
		Node(T data_):data(data_),next(nullptr){
			if(nullptr != current || ln != 0 )
				current->next = this;

			current = this;	
			++ln;
			cout<<"Node::Constr::ln ="<<ln<<endl;
		}
	
		~Node(){
			ln=0;
			current =nullptr;
			cout<<"Node::Destr"<<endl;
		}

		void self_destruct(){
			Node<T>*temp=this, *prev =temp;
			while(temp){
				temp = temp->next;
				delete prev;
				prev =temp;

			}
		}

		Node<T>* pop(Node<T>* End){
			auto temp = this;
			if(ln>1){
				while(temp->next != End){
					temp= temp->next;
				}
			}
			temp->next=nullptr;
			delete End;
			--ln;
			return ln? temp:nullptr;
		}

		friend ostream& operator<<(ostream &os , Node<T>&st){
			//cout<<"Node::"<<__func__<<endl;
			auto temp =&st;
			while(temp){
				os<<temp->data<<"->";
				temp=temp->next;
			}
			os<<"<-";
			return os;
		}


		//template <class U>friend class Jlist;   //This works but it'll be a wast generalization for friend classes.
		friend class Jlist<T>;
};

//defining static members outside class scope
template <class T>
Node<T>* Node<T>::current = nullptr;
template<class T>
size_t Node<T>::ln=0;

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
			if(nullptr != Start){
				Start->self_destruct();
				Start=nullptr;
				End=nullptr;
				size=0;
				is_empty=true;
			}
		}

		void pop(){
			cout<<"Jlist::"<<__func__<<endl;
			End = Start->pop(End);
			--size;
			if(End ==nullptr){
				cout<<"No nodes left !! size = "<<size<<endl;
				Start =nullptr;
				size =0;
				is_empty =true;
			}

		}

		friend ostream& operator<<(ostream &os , Jlist<U>&st){
			//cout<<"Jlist::"<<__func__<<endl;
			os<<*st.Start;
			return os;
			//return operator<<(os, *st.Start);
		}
};

int main(){
	Jlist<int>*lt= new Jlist<int>(2,2);

	cout<<"lt.back()= "<<lt->back()<<endl;

	lt->insert_end(10);

	cout<<"lt.back()= "<<lt->back()<<endl;
	cout<<"lt.size = "<<lt->getSize()<<endl;

	lt->pop();
	lt->pop();
	//lt->pop();
	cout<<"lt->getSize = "<<lt->getSize()<<endl;

	delete lt;
	//------------------------------------------------------------------------------------------

#if 0
	Jlist Jl(10,77);
	cout<<"Jl.back()= "<<Jl.back()<<endl;
	Jl.insert_end(10);
	cout<<"Jl.back()= "<<Jl.back()<<endl;
	cout<<"Jl.size = "<<Jl.getSize()<<endl;
	Jl.pop();

#endif

	Jlist<float> Jl2(10,32.8974);
	cout<<"Jl2.getSize()= "<<Jl2.getSize()<<endl;
	Jl2.insert_end(100);
	//cout<<Jl2.back()<<endl;
	cout<<Jl2<<endl; //calls operator<<

	return 0;
}
