/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

这道题主要是找规律，它是之字形，主要是依次找到每行每个字符的位置
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
			for (int j = i; j < s.size(); j += (2 * numRows - 2))   /*打印每一行，j代表每一行的第几个字符*/
			{
				s1.push_back(s[j]);
				if (i != 0 && i != numRows - 1 && (j + (2 * numRows - 2) - (2 * i)) < s.size())  /*第1行和最后1行的字符之间间隔的值是不变的，中间的是变化的，但是有规律*/
				{
					s1.push_back(s[j + (2 * numRows - 2) - 2 * i]);
				}
			}
		}
		
		return s1;
	}
};