/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

 

��������Ͷ������⻹�ǵ�һ������������ͦ���ӣ���ʵ��ϸһ�����㷨�ܼ򵥣����Ƕ���ǰһ������
�ҳ���ͬԪ�صĸ������Ѹ����͸�Ԫ�ش浽�µ�string��������£�
*/

class Solution {
public:
    string countAndSay(int n) {
        
        string s = "11";
        if(n == 1)
        {
            return "1";
        }
        if(n == 2)
        {
            return "11";
        }
      
        for(int i = 3;i <= n;i++)
        {
           string temp = "";
            for(int j = 0;j<s.size();j++)
            {
              
              if(j+1 < s.size()) 
              {  
                  if (s[j] != s[j+1])
                  {
                     temp += "1";
                     temp += s[j];
                  }
                 else
                 {
                     int count = 1;
                     int k = j;
                     j++;
                    while(j < s.size())
                    {
                        if(s[k] == s[j])
                        {
                            count++;
                        }
                        else
                        {
                            break;
                        }
                        j++;
                    }
                    char c = count + 48;
                    temp += c;
                    temp += s[k];
                    j--;
                   
                 }
              }
              else
              {
                  temp += "1";
                  temp += s[j];
              }
            }
            s = temp;
        }
        
        return s;
        
    }
};