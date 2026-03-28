class Solution 
{
    public int[] recoverOrder(int[] order, int[] friends) 
    {
        int Arr[] = new int[friends.length];
        int Count = 0;

        for(int i : order)
        {
            for(int j : friends)
            {
                if(i == j)
                {
                    Arr[Count] = i;
                    Count++;
                    break;
                }
            }
        }

        return Arr;
    }
}