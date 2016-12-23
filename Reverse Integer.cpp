/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
/*这道题看上去简单，实则是考察int的取值范围
具体的取值范围看算法word
*/

class Solution {
public:
    int reverse(int x) {
        int i = 0;
        double num = 0;                       /*不能用int,不然无法判断是否溢出，溢出之后的值无法判断*/
        
        if(x > 0)
        {
            while (x > 0)
            {
                i = x % 10;
                num = num * 10 + i;
                x /= 10;
            }
             if(num > 0x7fffffff)              /*这是关键一步，查看num是否溢出，溢出返回0*/
            {
               num = 0;
            }
           
        }
        else 
        {
            x = 0 - x;
            while (x > 0)
            {
                i = x % 10;
                num = num * 10 + i;
                x /= 10;
            }
            if(num > 0x7fffffff)
            {
               num = 0;
            }
            else 
            {
                num = 0 - num;
            }
        }
        
        return num;
    }
};