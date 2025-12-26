#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};

    // forward loop
    for(auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *(itr) << "\t";
    }

    cout << "\n";
    
    //backword loop
    for(auto itr = vec.rbegin(); itr != vec.rend(); itr++)
    {
        cout << *(itr) << "\t";
    }
    return 0;
}