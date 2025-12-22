// 1920. Build Array from Permutation

int* buildArray(int nums[], int numsSize, int* returnSize) 
{
    int *ptr = (int*)malloc(numsSize * sizeof(int));
    int iCnt = 0;

    if (ptr == NULL)
        return NULL;

    for (iCnt = 0; iCnt < numsSize; iCnt++)
    {
        ptr[iCnt] = nums[nums[iCnt]];
    }

    *returnSize = numsSize;
    return ptr;
}
