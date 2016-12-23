class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int flag = 0;
        string :: reverse_iterator iter = s.rbegin();
       
        for(;iter != s.rend();iter++)
        {
           if(flag == 0)
            {
                if(*iter == ' ')
                {
                    while(*iter == ' ')           /*消除开始连续的空格(华为那个题没有这种情况）*/
                    {
                        iter++;
                        if(iter == s.rend())
                        {
                            return 0;
                        }
                        
                    }
                }
                flag = 1;
            }
            else if(*iter == ' ')
            {
                break;
            }
            count++;
        }
        return count;
        
    }
};