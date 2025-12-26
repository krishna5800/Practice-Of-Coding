#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};
    int iCnt = 0;

    vec.erase(vec.begin());  // will delete element at 0th position in vector

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\t";              // 11   21  51  101
    }

    return 0;
}