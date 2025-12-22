// 3110. Score of a String

int scoreOfString(char s[]) 
{
    int iCnt = 0;
    int iScore = 0;
    char iNo1 = '\0';
    char iNo2 = '\0'; 
    int iDif = 0;

    iCnt = 0;

    while(s[iCnt+1] != '\0')
    {
        iNo1 = s[iCnt];
        iNo2 = s[iCnt+1];

        iDif = ((int)iNo1 - (int)iNo2);

        if(iDif < 0)
        {
            iDif = -iDif;
        }

        iScore = iScore + iDif;

        iCnt++;
    }    

    return iScore;
}