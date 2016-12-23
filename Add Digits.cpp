/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

class Solution {
public:
    int addDigits(int num) {
          //这道题就是求num的位数一直相加，加到只有一位数
        int sum = 0;
        
        do
        {
            sum = 0;
            while(num > 0)
            {
                int tmp = num % 10;
                sum += tmp;
                num /= 10;
            }
            num = sum;
            
        }while(num >= 10);
        
        return num;
    }
};