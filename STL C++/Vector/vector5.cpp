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

    cout << vec.size() << "\n";                 // 5
    cout << vec.capacity() << "\n";             // 8

    cout << "Elements in vector are : \n";

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\n";              // 10,11,21,51,101
    }

    vec.emplace_back(111);                      // new function same as pop_back()
    vec.emplace_back(121);

    cout << "Elements in vector are : \n";

    for(iCnt = 0; iCnt < vec.size(); iCnt++)
    {
        cout << vec[iCnt] << "\n";              // 10,11,21,51,101,111,,121
    }

    return 0;
}