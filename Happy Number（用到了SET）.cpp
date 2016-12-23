/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;               /*学会使用SET,因为它查找很方便*/
        int sum = 0;
        while (n != 1)
        {
            sum = 0;
            while(n > 0)
            {
                int temp = n % 10;
                sum = sum + (temp * temp);
                 n /= 10;
            }
            if(s.find(sum) == s.end())   /*判断加起来的数之前有没有出现过*/
            {
                s.insert(sum);        /*这个题主要是要找到不是快乐数满足什么条件，可以找一个数来测试一下，比如11，
                                      它满足的条件就是加起来的数会产生重叠*/
                n = sum;
            }
            else
            {
                break;
            }
        }
        if(n == 1)
        {
            return true;
        }
       
        return false;
        
        