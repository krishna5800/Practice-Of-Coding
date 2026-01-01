// 2011. Final Value of Variable After Performing 

class Solution {
    public int finalValueAfterOperations(String[] operations) 
    {
        int X = 0;
        int iCnt = 0;

        for(iCnt = 0; iCnt < operations.length; iCnt++)
        {
            if(operations[iCnt].equals("++X") || operations[iCnt].equals("X++"))
            {
                X++;
            }
            else if(operations[iCnt].equals("X--") || operations[iCnt].equals("--X"))
            {
                X--;
            }
        }

        return X;
    }
}