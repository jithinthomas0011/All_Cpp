#include <iostream>
#include <vector>
using namespace std;

int main()
{

    cout << "Enter the size 'n  and initial value\n";
    unsigned int n = 0, val = 0;
    cin >> n >> val;

    int *arr = new int[n];
    // std::fill(arr,arr+n, val); //When first and last addresses are known
    std::fill_n(arr, n, val); // When first address and array size is known

    cout << "The filled elems are:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;
    vector<int> Vec(n + 1, val + 1); // Vector of size n+1 and initial value val+1

    for (auto a : Vec)
        cout << a << " ";

    cout << endl;

    Vec.push_back(12);

    vector<int>::iterator it;
    for (it = Vec.begin(); it != Vec.end(); ++it)
        cout << *it << " ";

    Vec.clear();

    if (arr) { 
        delete[]arr;
        arr = nullptr;
    }
    
    retutn 0;
}
