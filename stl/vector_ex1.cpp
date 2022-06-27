#include <iostream>
#include <vector>

using namespace std;


int main(){

	vector<int>vec_int(10,7);//vector of size 10 with default value 7

	vector<int>::iterator it;

	//OR
	//auto it  = vec_int.begin();

	cout<<"\nVector before modifying =\n";
	for(it=vec_int.begin();it != vec_int.end();++it){
		cout<<*it<<endl;
	}

	//Resizing Vector
	vec_int.resize(15);
	vec_int[13] = vec_int[14] = 77;
	//Resizing vector might change vector memory location in heap, so need to update iterator as well!
	it = vec_int.begin();
	
	vec_int.insert(it+11,10);

	cout<<"Vector after modifying =\n";
	for (; it != vec_int.end(); ++it){
		cout<<*it<<endl;
	}
	cout<<endl;
	
	cin.get();
	return 0;

}
