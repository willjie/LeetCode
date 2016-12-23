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
        set<int> s;               /*ѧ��ʹ��SET,��Ϊ�����Һܷ���*/
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
            if(s.find(sum) == s.end())   /*�жϼ���������֮ǰ��û�г��ֹ�*/
            {
                s.insert(sum);        /*�������Ҫ��Ҫ�ҵ����ǿ���������ʲô������������һ����������һ�£�����11��
                                      ��������������Ǽ���������������ص�*/
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
        
        