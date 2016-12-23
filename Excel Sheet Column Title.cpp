/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        /*这实际上是转换成26进制*/
      string str = "";
      while(n > 0)
      {
          char ch = 'A' + (n-1)%26;   
          str.push_back(ch);
          n = (n-1)/26;
      }
      std:reverse(str.begin(),str.end());
      
      return str;
    }
};