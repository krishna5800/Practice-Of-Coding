#include <stddef.h>

int find_odd (size_t length, const int array[length])
{
  unsigned long i = 0;
  unsigned long j = 0;
  int iCount = 0;
  int iVerify = 0;
  
  for(i = 0; i < length; i++)
  {
    iCount = 0;
    iVerify = array[i];
    
    for(j = 0; j < length; j++)
      {
        if(iVerify == array[j])
          {
            iCount++;
          }
      }
    
    if(iCount%2 != 0)
      {
        return iVerify;
      }
   }
  
  return 0;
}