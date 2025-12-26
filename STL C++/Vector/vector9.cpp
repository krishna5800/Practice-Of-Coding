#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec(3,10);         // vector of size - 3 with all elements at every position - 10
    int iCnt = 0;

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\t";          // 10  10  10
    }

    return 0;
}