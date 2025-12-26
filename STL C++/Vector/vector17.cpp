#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};

    vector<int>::reverse_iterator itr;

    for(itr = vec.rbegin(); itr != vec.rend(); itr++)
    {
        cout << *(itr) << "\t";
    }
    return 0;
}