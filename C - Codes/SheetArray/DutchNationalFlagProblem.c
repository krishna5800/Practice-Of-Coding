#include<stdio.h>

int main()
{
    int Arr[] = {1,0,2,0,1,2};
    int size = 6;
    int Brr[size];
    int iCnt1 = 0, iCnt2 = 0, iCnt3 = 0;

    for(int i = 0; i < size; i++)
    {
        if(Arr[i] == 0)
        {
            iCnt1++;
        }

        if(Arr[i] == 1)
        {
            iCnt2++;
        }

        if(Arr[i] == 2)
        {
            iCnt3++;
        }
    }


    return 0;
}