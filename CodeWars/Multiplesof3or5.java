public class Solution {

  public int solution(int number) 
  {
    //TODO: Code stuff here
    int iCnt = 0;
    int iSum = 0;
    
    for(iCnt = 0; iCnt <= number; iCnt++)
      {
          if(iCnt%3 == 0 || iCnt%5 == 0)
            {
              iSum = iSum + iCnt;
            }
      }
    
    return iSum;
  }
}
