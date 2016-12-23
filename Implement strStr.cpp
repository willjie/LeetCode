
/*Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question
*/
/*
�������������һ���ַ���������һ���ַ�����һ�γ��ֵ�λ�ã�����������Ҫ��һЩ�жϣ�
������ַ���Ϊ�գ��򷵻�0��������ַ������ȴ���ĸ�ַ������ȣ��򷵻�-1
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
                if(haystack[k] == '\0')             /*�������������ͻᵼ������ʱ�䳬ʱ����Ϊ���haystack����������û�У��ǿ϶�û�У��Ͳ����ټ�����*/
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