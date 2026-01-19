#include<stdio.h>

int FindMax(int * Arr, int Size)
{
    int iCnt = 0;
    int iMax = 0;

    iMax = Arr[0];

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        if(iMax < Arr[iCnt])
        {
            iMax = Arr[iCnt];
        }
    }

    return iMax;
}

int FindMin(int * Arr, int Size)
{
    int iCnt = 0;
    int iMin = 0;

    iMin = Arr[0];

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        if(iMin > Arr[iCnt])
        {
            iMin = Arr[iCnt];
        }
    }

    return iMin;
}

int main()
{
    int iSize = 0;
    printf("Enter size : \n");
    scanf("%d", &iSize);
    int i = 0;
    int minimum = 0;
    int maximum = 0;

    int Arr[iSize];

    printf("Enter Values : \n");

    for(i = 0; i < iSize; i++)
    {
        printf("Enter value for %d index : \n", i+1);
        scanf("%d", &Arr[i]);
    }

    minimum = FindMin(Arr, iSize);
    printf("Minimum is : %d\n", minimum);

    maximum = FindMax(Arr, iSize);
    printf("Maximum is : %d\n", maximum);

    return 0;
}