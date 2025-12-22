// 3190. Find Minimum Operations to Make All Elements Divisible by Three

int minimumOperations(int nums[], int numsSize) 
{
    int iCnt = 0;
    int iVerify = 0;
    int iSum = 0;

    for(iCnt = 0; iCnt < numsSize; iCnt++)
    {
        if(nums[iCnt]%3 != 0)
        {
            iSum = iSum + 1;
        }

        iSum = iSum+0;
    }


    return iSum;
}