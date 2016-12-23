/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
������е��� ����ƥ������һ��ʼ��Ӧ���뵽hashmap

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        //�õ�HashMap
        
        map<char,string> m1;
        
        istringstream in(str);                    //�����Ҫ��ס
        int i = 0;
        for(string word; in >> word; ++i)
        {
            if(m1.find(pattern[i]) != m1.end())   //�ҵ�
            {
                if(m1[pattern[i]] != word)
                {
                    return false;
                }
            }
            else                           //û�ҵ�
            {
                for(map<char,string>::iterator it = m1.begin();it != m1.end();it++)
                {
                    if(it->second == word)          //�����ַ���Ӧһ������
                    {
                        return false;
                    }
                }
                m1[pattern[i]] = word;
                
            }
        }
        
        return i == pattern.size();                 //��ֹ�����ַ�����ͬ
        
    }
};