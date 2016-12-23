/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*�����Ĺؼ���Ū����������ֵĹ涨�Լ��밢�����������Ӧ�Ĺ�ϵ*/
/*�Լ�ѧ����map���ֹ���ʽ����*/

class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> m1{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};     /*ѧ����map*/
        
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
    
/*дһ��Integer to roman*/
  string  IntegerToRoman(int num)  /*������0-3999*/
	{
		char s[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };       /*����ط���ƺ�����*/
		int val[] = { 1000, 500, 100, 50, 10, 5, 1 };
		int n = 0;
		string res = "";
		for (int i = 0; i < 7; i += 2)
		{
			n = num / val[i];            /*�ֽ����ÿһλ�� ������ǧλ����λ��ʮλ����λ*/
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

