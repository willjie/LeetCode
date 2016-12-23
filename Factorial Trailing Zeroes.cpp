/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
       /*�������Ҫ�����������10�ĸ���,��10�ַ�Ϊ5*2������ֻҪ��5�ĸ�������*/
       int res = 0;
       
       while(n > 0)
       {
         res = res + (n / 5);      /*������һ�����ĳ������㷨����Ҫ��*/
         n /= 5;
       }
       return res;
        
    }
};