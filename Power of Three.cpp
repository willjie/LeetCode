//Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //判断n是否是3的次方数
        
        while(n> 0 && n % 3==0)
        {
            n = n / 3;
        }
        if(n == 1)
        {
            return true;
        }
        return false;
    }
};

//不用循环的方法
题目中的Follow up让我们不用循环，
那么有一个投机取巧的方法，由于输入是int，正数范围是0-231，
在此范围中允许的最大的3的次方数为319=1162261467，那么我们只要看这个数能否被n整除即可，参见代码如下：

 

解法二：

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};