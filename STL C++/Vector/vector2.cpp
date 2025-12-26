// size - elements at this moment in vector
// capacity - capacity of vector 

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec;   // 0

    cout << vec.size() << "\n";

    vec.push_back(10);
    vec.push_back(11);

    cout << vec.size() << "\n";     // 2
    cout << vec.capacity() << "\n"; // 2

    vec.push_back(21);

    cout << vec.size() << "\n";     // 3
    cout << vec.capacity() << "\n"; // 4

    return 0;
}