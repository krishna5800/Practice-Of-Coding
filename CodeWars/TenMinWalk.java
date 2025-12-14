public class TenMinWalk 
{
  public static boolean isValid(char walk[]) 
  {
    // Insert brilliant code here
    
    int iCount1 = 0;
    int iCount2 = 0;
    int iCount3 = 0;
    int iCount4 = 0;
    int iCnt = 1;
    
    if(walk.length != 10)
      {
        return false;
      }
    
    for(iCnt = 0; iCnt < walk.length; iCnt++)
      {
        if(walk[iCnt] == 'n')
          {
            iCount1++;
          }
        else if(walk[iCnt] == 's')
          {
            iCount2++;
          }
        else if(walk[iCnt] == 'w')
          {
            iCount3++;
          }
        else
          {
            iCount4++;
          }
      }
    
    if(iCount1 == iCount2 && iCount3 == iCount4)
      {
        return true;
      }
    else
      {
        return false;
      }
  }
}