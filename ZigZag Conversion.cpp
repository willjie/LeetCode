/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

�������Ҫ���ҹ��ɣ�����֮���Σ���Ҫ�������ҵ�ÿ��ÿ���ַ���λ��
*/

class Solution {
public:
    string convert(string s, int numRows) {
       string s1;
       if(numRows == 1)
       {
           return s;
       }
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i; j < s.size(); j += (2 * numRows - 2))   /*��ӡÿһ�У�j����ÿһ�еĵڼ����ַ�*/
			{
				s1.push_back(s[j]);
				if (i != 0 && i != numRows - 1 && (j + (2 * numRows - 2) - (2 * i)) < s.size())  /*��1�к����1�е��ַ�֮������ֵ�ǲ���ģ��м���Ǳ仯�ģ������й���*/
				{
					s1.push_back(s[j + (2 * numRows - 2) - 2 * i]);
				}
			}
		}
		
		return s1;
	}
};