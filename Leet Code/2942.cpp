// 2942. Find Words Containing Character

class Solution 
{
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    { 
        vector<int> ans;
        int n = words.size();
        int iCnt = 0;
        int j = 0;

        for(iCnt = 0; iCnt < n; iCnt++)
        {
            string str = words[iCnt];
            j = 0;

            while(str[j] != '\0')
            {
                if(str[j] == x)
                {
                    ans.push_back(iCnt);
                    break;
                }

                j++;
            }
        }

        return ans;
    }
};