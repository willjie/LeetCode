/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

��������ӳ���ϵ

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        /*������õ���map,��ʵ����һ��ӳ�䣬һ�뵽ӳ���Ӧ���뵽map(��Ҫ��*/
        
        if(s.size() != t.size())
        {
            return false;
        }
        map<char,char> mp;
        /*������s��t��ӳ��*/
        for(int i = 0; i < s.size();i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp.insert(pair<char,char>(s[i],t[i]));
            }
            else if(mp[s[i]] != t[i])
            {
                return false;
            }
        }
        mp.clear();
        /*Ȼ����t��s��ӳ�䣬������֮ǰ��һ��*/
        
        for(int i = 0; i< t.size(); i++)
        {
             if(mp.find(t[i]) == mp.end())
            {
                mp.insert(pair<char,char>(t[i],s[i]));
            }
            else if(mp[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
        
    }
};