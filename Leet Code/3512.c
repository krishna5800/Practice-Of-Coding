// 3512. Minimum Operations to Make Array Sum Divisible by K

int minOperations(int nums[], int numsSize, int k) 
{
    int iMax = 0;
    int iSum = 0;
    int iCnt = 0;
    int iVerify = 0;

    for(iCnt = 0, iMax = nums[0]; iCnt < numsSize; iCnt++)
    {
        if(iMax < nums[iCnt])
        {
            iMax = nums[iCnt];
        }

        iSum = iSum + nums[iCnt];
    }

    if(iSum%k == 0)
    {
        return 0;
    }

    while(iSum%k != 0)
    {
        iSum--;
        iVerify++;
    }

    return iVerify;
}