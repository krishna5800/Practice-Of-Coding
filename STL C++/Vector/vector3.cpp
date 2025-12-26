#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> vec;   // 0
    int iCnt = 0;

    cout << vec.size() << "\n";

    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(21);
    vec.push_back(51);
    vec.push_back(101);

    cout << vec.size() << "\n";     
    cout << vec.capacity() << "\n"; 

    cout << "Elements in vector are : \n";

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\n";
    }

    return 0;
}