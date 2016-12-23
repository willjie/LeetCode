/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
/*leetcode的题大多数都是题目读不懂,没有理解题目的意思*/
/*这道题让我们验证输入的字符串是否为括号字符串，
包括大括号，中括号和小括号。这里我们需要用一个栈，
我们开始遍历输入字符串，如果当前字符为左半边括号时，则将其压入栈中，
如果遇到右半边括号时，若此时栈为空，则直接返回false，
如不为空，则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回false，

这道题的意思是只要（）[] {}这种里面都是含有闭合的就可以*/
/*学会用栈，特别是遍历和迭代的时候*/
class Solution {
public:
    bool isValid(string s) {
       stack<char> slist;                                   /*用栈*/
       for(int i = 0; i < s.size(); i++)
       {
           
           if (s[i] == '(' || s[i] == '[' || s[i] == '{')
           {
               slist.push(s[i]);
           }
           else
           {
               if(slist.empty()) return false;
               if (s[i] == ')' && slist.top() != '(') return false;          /*这个算法很奇妙*/
               if (s[i] == ']' && slist.top() != '[') return false;
               if (s[i] == '}' && slist.top() != '{') return false;
              
               slist.pop();
           }
           
       }
       return slist.empty();                                            /*防止[[]这种情况的发生,栈里面还有元素*/
    }
};