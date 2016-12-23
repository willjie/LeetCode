/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*这道题的关键是弄清楚罗马数字的规定以及与阿拉伯数字相对应的关系*/
/*以及学会用map这种关联式容器*/

class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> m1{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};     /*学会用map*/
        
       int res = 0;
   
       for(int i = 0; i < s.size(); i++)
       {
           if (i < s.size() -1)
           {
               if (m1[s[i]] >= m1[s[i+1]])
               {
                   res += m1[s[i]];                     
               }
               else
               {
                   res -= m1[s[i]];
               }
           }
           else
           {
               res += m1[s[i]];
           }
       }
       return res;
       
    }
    
/*写一个Integer to roman*/
  string  IntegerToRoman(int num)  /*输入在0-3999*/
	{
		char s[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };       /*这个地方设计很巧妙*/
		int val[] = { 1000, 500, 100, 50, 10, 5, 1 };
		int n = 0;
		string res = "";
		for (int i = 0; i < 7; i += 2)
		{
			n = num / val[i];            /*分解出来每一位， 依次是千位，百位，十位，个位*/
			if (n < 4)
			{
				for (int j = 0; j < n; j++)
				{
					res += s[i];
				}
			}
			if (n == 4)
			{
				res = res + s[i] + s[i - 1];
			}
			if (n > 4 && n < 9)
			{
				res += s[i - 1];

				for (int j = 6; j < n; j++)
				{
					res += s[i];
				}
			}
			if (n == 9)
			{
				res = res + s[i - 2] + s[i];
			}
			num = num % val[i];
		}
		return res;
	}
};

