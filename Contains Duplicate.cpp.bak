/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

这道题就是映射关系

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        /*这道题用到了map,其实就是一个映射，一想到映射就应该想到map(重要）*/
        
        if(s.size() != t.size())
        {
            return false;
        }
        map<char,char> mp;
        /*首先是s到t的映射*/
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
        /*然后是t到s的映射，必须与之前的一样*/
        
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