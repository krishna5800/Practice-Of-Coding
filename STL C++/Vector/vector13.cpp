#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec = {10,11,21,51,101};
    int iCnt = 0;

    vec.clear();

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\t";         
    }

    return 0;
}