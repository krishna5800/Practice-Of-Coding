#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec;   // 0

    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(21);

    cout << vec[0] << "\n";
    cout << vec[1] << "\n";

    // similarly we have at() function

    cout << vec.at(2) << "\n";

    return 0;
}