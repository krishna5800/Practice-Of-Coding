#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};

    cout << "vec.begin() : " << *(vec.begin()) << "\n";

    cout << "vec.end() : " << *(vec.end()) << "\n";

    return 0;
}