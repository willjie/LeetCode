/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

/*���ǿ��Ƿ���ģ�˼·�����������ǿ���ת֮���ǲ���һ���ľ��У�������Դ�Сд��*/
class Solution {
public:
    bool isPalindrome(string s) {
        
        string s1 = "";
        for(int i = 0; i < s.size();i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] += 32;
                }
                s1 += s[i];
            }
        }
        string s2 = s1;
        std:reverse(s1.begin(),s1.end());
        if(s2 == s1)
        {
            return true;
        }
        return false;
        
    }
};