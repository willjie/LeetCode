
/*Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question
*/
/*
这道题让我们在一个字符串中找另一个字符串第一次出现的位置，那我们首先要做一些判断，
如果子字符串为空，则返回0，如果子字符串长度大于母字符串长度，则返回-1
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.empty())
        {
            return 0;
        }
      
        int i, j,count;
        count = i = j = 0;
        for(; haystack[i] != '\0'; i++)
        {
            if(haystack[i] == needle[0])
            {
                
                int pos = i;
                int k = i;
                while (haystack[k] != '\0' && needle[j] != '\0' )
                {
                    if(haystack[k] != needle[j])
                    {
                        break;
                    }
                    count++;
                    k++;
                    j++;
                    if(count == needle.size())
                    {
                        return pos;
                    }
                }
                if(haystack[k] == '\0')             /*如果不加这个，就会导致运行时间超时，因为如果haystack都遍历完了没有，那肯定没有，就不用再继续了*/
                {
                    return -1;
                }
                count = 0;
                j = 0;
            }
        }
        return -1; 
        
        
    }
};