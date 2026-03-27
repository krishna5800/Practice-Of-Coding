class Solution 
{
    public void moveZeroes(int[] nums) 
    {
        int Arr[] = new int[nums.length];
        int j = 0;

        for(int i : nums)
        {
            Arr[j] = i;
            j++;
        }

        j = 0;
        int iCount = 0;

        for(int i : Arr)
        {
            if(i == 0)
            {
                iCount++;
            }
        }

        for(int i : Arr)
        {
            if(i != 0)
            {
                nums[j] = i;
                j++;
            }
        }

        for(int i = (nums.length-iCount); i < nums.length; i++)
        {
            nums[i] = 0;
        }
    }
}