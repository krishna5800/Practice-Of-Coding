#include<iostream>
using namespace std;

int main()
{
    pair <int, int> p1 = {1,3};

    cout << p1.first << endl;
    cout << p1.second << endl;

    pair <char, int> p2 = {'a', 1};

    cout << p2.first << endl;
    cout << p2.second << endl;

    return 0;
}