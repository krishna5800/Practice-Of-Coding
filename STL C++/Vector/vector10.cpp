#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec1 = {10,11,21,51,101};
    int iCnt = 0;

    vector <int> vec2(vec1);      // vec2 is vec1 copy

    for(iCnt = 0; iCnt < vec2.size(); iCnt++)
    {
        cout << vec2[iCnt] << "\t";
    }

    return 0;
}