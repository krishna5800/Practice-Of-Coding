#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec;   // 0

    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(21);
    vec.push_back(51);
    vec.push_back(101);

    cout << vec.front() << "\n";

    cout << vec.back() << "\n";

    return 0;
}