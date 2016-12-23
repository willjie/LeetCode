/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
/*这道题主要是题目没读太懂，网上找了翻译*/
/*
问题：将字符窜转换成数字
分析：感觉题目不难，但是细节很多，容易想不到
1.数字前面有空格 如s=“    123456”
2.数字前出现了不必要或多于的字符导致数字认证错误，输出0   如s=“   b1234”  ，s=“  ++1233” , s=“ +-1121”
3.数字中出现了不必要的字符，返回字符前的数字 如s=“   12a12” ， s=“ 123  123”
4.数字越界 超过了范围（-2147483648--2147483647) 若超过了负数的 输出-2147483648  超过了正数的输出2147483647
在科普一个知识点，倘若某个数超过了2147483647则会变为负数，反过来一样
*/
class Solution {
public:
    int myAtoi(string str) {
       
       int i = 0;
       int flag = 0;
       double number = 0;
       
       while (str[i] != '\0' && str[i] == ' ')            /*把连续的空格去除*/
       {
           i++;
       }
       
       if (str[i] == '-')                                 /*判断正负*/
       {
           flag = 1;
           i++;
       }
       else if (str[i] == '+')
       {
           
           i++;
       }
       
       for(; i < str.size(); i++)
       {
           if (str[i] >= '0' && str[i] <= '9')
           {
               number = number * 10 + (str[i] - '0');
    
                if(number > 0x7FFFFFFF)
                {
                   number = 0x7FFFFFFF;             /*溢出*/
                   if(flag == 1)
                   {
                       number += 1;                /*如果是负数，溢出的话要加1*/
                   }
                   break;
                }
                
            
           }
           else 
           {
               break;
           }
       }
       
       if(flag == 1)
       {
           number = 0 - number;
       }
       return number;
    }
};