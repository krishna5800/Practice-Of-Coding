#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> Arr;
    vector<int> Ans;
    int i = 0;
    int size = 0;
    int temp = 0;
    int rem = 0;

    Arr.push_back(20);
    Arr.push_back(10);
    Arr.push_back(30);
    Arr.push_back(50);
    Arr.push_back(40);

    // Arr = [20,10,30,50,40]

    size = Arr.size();

    while(!(Arr.empty()))
    {
        temp = Arr[0];
        rem = 0;

        for(i = 0; i < size; i++)
        {
            if(temp > Arr[i])
            {
                temp = Arr[i];
                rem = i;
            }
        }

        Ans.push_back(temp);

        Arr.erase(Arr.begin() + rem);

        size--;
    }

    size = Ans.size();
    i = 0;

    while(i < size)
    {
        cout << Ans[i] << "\n";
        i++;
    }

    return 0;
}