#include<stdio.h>

void ArrayReverse(int * Brr, int Size)
{
    int * ptr1 = NULL;
    int * ptr2 = NULL;
    int temp = 0;
    int i = 0;

    ptr1 = Brr;
    ptr2 = Brr;

    while(i < Size)
    {
        ptr2++;
        i++;
    }

    ptr2--;

    while(ptr1 < ptr2)
    {
        temp = (*ptr1);
        (*ptr1) = (*ptr2);
        (*ptr2) = temp; 

        ptr1++;
        ptr2--;
    }
}

int main()
{
    int iSize = 0;
    printf("Enter size : \n");
    scanf("%d", &iSize);
    int i = 0;

    int Arr[iSize];

    printf("Enter Values : \n");

    for(i = 0; i < iSize; i++)
    {
        printf("Enter value for %d index : \n", i+1);
        scanf("%d", &Arr[i]);
    }

    ArrayReverse(Arr, iSize);

    printf("Array after reverse : \n");
    
    for(i = 0; i < iSize; i++)
    {
        printf("%d\n", Arr[i]);
    }

    return 0;
}