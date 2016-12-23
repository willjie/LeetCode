/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
/*����⿴��ȥ�򵥣�ʵ���ǿ���int��ȡֵ��Χ
�����ȡֵ��Χ���㷨word
*/

class Solution {
public:
    int reverse(int x) {
        int i = 0;
        double num = 0;                       /*������int,��Ȼ�޷��ж��Ƿ���������֮���ֵ�޷��ж�*/
        
        if(x > 0)
        {
            while (x > 0)
            {
                i = x % 10;
                num = num * 10 + i;
                x /= 10;
            }
             if(num > 0x7fffffff)              /*���ǹؼ�һ�����鿴num�Ƿ�������������0*/
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