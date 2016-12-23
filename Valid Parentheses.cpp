/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
/*leetcode��������������Ŀ������,û�������Ŀ����˼*/
/*�������������֤������ַ����Ƿ�Ϊ�����ַ�����
���������ţ������ź�С���š�����������Ҫ��һ��ջ��
���ǿ�ʼ���������ַ����������ǰ�ַ�Ϊ��������ʱ������ѹ��ջ�У�
��������Ұ������ʱ������ʱջΪ�գ���ֱ�ӷ���false��
�粻Ϊ�գ���ȡ��ջ��Ԫ�أ���Ϊ��Ӧ���������ţ������ѭ������֮����false��

��������˼��ֻҪ����[] {}�������涼�Ǻ��бպϵľͿ���*/
/*ѧ����ջ���ر��Ǳ����͵�����ʱ��*/
class Solution {
public:
    bool isValid(string s) {
       stack<char> slist;                                   /*��ջ*/
       for(int i = 0; i < s.size(); i++)
       {
           
           if (s[i] == '(' || s[i] == '[' || s[i] == '{')
           {
               slist.push(s[i]);
           }
           else
           {
               if(slist.empty()) return false;
               if (s[i] == ')' && slist.top() != '(') return false;          /*����㷨������*/
               if (s[i] == ']' && slist.top() != '[') return false;
               if (s[i] == '}' && slist.top() != '{') return false;
              
               slist.pop();
           }
           
       }
       return slist.empty();                                            /*��ֹ[[]��������ķ���,ջ���滹��Ԫ��*/
    }
};