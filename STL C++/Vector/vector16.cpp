#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};

    vector<int>::iterator itr;

    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *(itr) << "\t";
    }
    return 0;
}