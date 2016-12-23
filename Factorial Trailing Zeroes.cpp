/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
       /*这道题主要就是求乘数中10的个数,而10又分为5*2，所以只要求5的个数就行*/
       int res = 0;
       
       while(n > 0)
       {
         res = res + (n / 5);      /*这是求一个数的除数的算法（重要）*/
         n /= 5;
       }
       return res;
        
    }
};